package com.msense.ms_fall_risk_application;
// This fragment handles the connection with the bluetooth devices and communicates with the array adapter where they are kept track of

import android.app.Activity;
import android.bluetooth.BluetoothDevice;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.support.annotation.Nullable;
import android.support.design.widget.Snackbar;
import android.support.v4.app.Fragment;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;
import com.mbientlab.metawear.AsyncDataProducer;
import com.mbientlab.metawear.MetaWearBoard;
import com.mbientlab.metawear.Route;
import com.mbientlab.metawear.android.BtleService;
import com.mbientlab.metawear.data.Acceleration;
import com.mbientlab.metawear.module.Accelerometer;
import com.mbientlab.metawear.module.AccelerometerBosch;
import com.mbientlab.metawear.module.AccelerometerMma8452q;
import com.mbientlab.metawear.module.Debug;
import com.mbientlab.metawear.module.Haptic;
import java.util.HashMap;
import bolts.Capture;
import bolts.Continuation;
import bolts.Task;



public class MainActivityFrag extends Fragment implements ServiceConnection {

    // Initialize map that contains each bluetooth device as well as bind bluetooth service
    private final HashMap<DeviceState, MetaWearBoard> stateToBoards;
    private BtleService.LocalBinder binder;
    private ConnectedDeviceAdapter connectedDevices= null;
    public MainActivityFrag() {
        stateToBoards = new HashMap<>();
    }

    // For parsing accelerometer data within method "add new device"
    private String s;

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        Log.i("metawear","MAF: View Created");
        super.onCreate(savedInstanceState);
        Activity owner= getActivity();

        // bind bluetooth service
        owner.getApplicationContext().bindService(new Intent(owner, BtleService.class), this, Context.BIND_AUTO_CREATE);

    }

    // Unbind btle service on app closure or back navigation
    @Override
    public void onDestroy() {
        super.onDestroy();
        getActivity().getApplicationContext().unbindService(this);
    }


    // Add new device method includes connection to device, data route setep, and reconnection
    public void addNewDevice(BluetoothDevice btDevice) {
        final DeviceState newDeviceState= new DeviceState(btDevice);
        final MetaWearBoard newBoard= binder.getMetaWearBoard(btDevice);
        Log.i("metawear","MAF: Atempting to connect to  "+newDeviceState);

        // For progress bar
        newDeviceState.connecting= true;

        // Add device to connected device adapter class as well as add to hashmap
        connectedDevices.add(newDeviceState);
        stateToBoards.put(newDeviceState, newBoard);

        // initalize captures
        final Capture<AsyncDataProducer> orientCapture = new Capture<>();
        final Capture<Accelerometer> accelCapture = new Capture<>();


        // On undexpected disconnect, attempt to reconnect to device
        newBoard.onUnexpectedDisconnect(status -> {
            Log.i("metawear","MAF: Unexpected Disconnect Detected");
            Log.i("metawear","MAF: Connection lost, reconnecting to " + btDevice.getAddress());
            newBoard.connectAsync().continueWithTask(task -> task.isCancelled() || !task.isFaulted() ? task : MainActivityFrag.reconnect(newBoard))
                    .continueWith((Continuation<Void, Void>) task -> {

                        if (!task.isCancelled()) {
                            Log.i("metawear","MAF: Successful reconnection to: "+ btDevice.getAddress());

                        } else {
                            Log.i("metawear","MAF: Successful reconnection to: "+ btDevice.getAddress());
                        }

                        return null;
                    });
        });


        // Inital connection established:
        newBoard.connectAsync().onSuccessTask(task -> {
                Log.i("metawear","MAF: Device succesfully connected: " + btDevice.getAddress());

                    getActivity().runOnUiThread(() -> {
                        newDeviceState.connecting= false;
                        connectedDevices.notifyDataSetChanged();
                    });


            // Configure accelerometer on board device
            final Accelerometer accelerometer = newBoard.getModule(Accelerometer.class);
            accelerometer.configure()
                    .odr(32.5f)       // Set sampling frequency to 25Hz, or closest valid ODR
                    .range(4f)      // Set data range to +/-4g, or closet valid range
                    .commit();

            Log.i("metawear", "MAF: Accel frequency = " + accelerometer.getOdr());
            Log.i("metawear", "MAF: Accel range = " + accelerometer.getRange());

            // set capture
            accelCapture.set(accelerometer);

            // Following code is necessary to configure the accelerometer to stream (not entirely sure why)
            final AsyncDataProducer orientation;
            if (accelerometer instanceof AccelerometerBosch) {
                orientation = ((AccelerometerBosch) accelerometer).acceleration();
            } else {
                orientation = ((AccelerometerMma8452q) accelerometer).acceleration();
            }
            orientCapture.set(orientation);

            // orienation is actually acceleration values, set up data stream:
            return orientation.addRouteAsync(source -> source.stream((data, env) -> {
                getActivity().runOnUiThread(() -> {

                    // parse accel values to get x, y, z components
                    s = data.value(Acceleration.class).toString();
                    newDeviceState.xVal = s.substring(4,10);
                    newDeviceState.yVal = s.substring(15,21);
                    newDeviceState.zVal = s.substring(27,32);

                    connectedDevices.notifyDataSetChanged();

                });
            }));

        }).continueWith((Continuation<Route, Void>) task -> {
            // if unable to establish connection, remove from adapter and in turn from screen layout
            if (task.isFaulted()) {
                if (!newBoard.isConnected()) {
                    getActivity().runOnUiThread(() -> connectedDevices.remove(newDeviceState));
                } else {
                    Snackbar.make(getActivity().findViewById(R.id.activity_main_layout), task.getError().getLocalizedMessage(), Snackbar.LENGTH_SHORT).show();
                    newBoard.tearDown();
                    newBoard.disconnectAsync().continueWith((Continuation<Void, Void>) task1 -> {
                        connectedDevices.remove(newDeviceState);
                        return null;
                    });
                }
            } else {
                // Otherwise connection established, begin accel stream
                orientCapture.get().start();
                accelCapture.get().start();
            }
            return null;

        });
    };


    // Create fragment view, called once
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        connectedDevices= new ConnectedDeviceAdapter(getActivity(), R.id.sensor_list);
        connectedDevices.setNotifyOnChange(true);
        setRetainInstance(true);
        View view = inflater.inflate(R.layout.fragment_main_activity, container, false);
        return view;
}

    // once view is created, can be called multiple times
    @Override
    public void onViewCreated(View view, Bundle savedInstanceState) {
        ListView connectedDevicesView= view.findViewById(R.id.connected_devices);
        connectedDevicesView.setAdapter(connectedDevices);

        // if you click on item, it will vibrate:
        connectedDevicesView.setOnItemClickListener((parent, view1, position, id) -> {
            Log.i("metawear","I've been clicked!");
            DeviceState current= connectedDevices.getItem(position);
            final MetaWearBoard newBoard= stateToBoards.get(current);

            newBoard.getModule(Haptic.class).startMotor(100.f, (short) 1000);
            newBoard.getModule(Haptic.class).startMotor(50.f, (short) 1000);
            newBoard.getModule(Haptic.class).startMotor(100.f, (short) 1000);
            newBoard.getModule(Haptic.class).startMotor(50.f, (short) 1000);
            newBoard.getModule(Haptic.class).startMotor(100.f, (short) 1000);
            newBoard.getModule(Haptic.class).startMotor(50.f, (short) 1000);
            newBoard.getModule(Haptic.class).startMotor(100.f, (short) 1000);
            newBoard.getModule(Haptic.class).startMotor(50.f, (short) 1000);

        });

        // if you click on the item and hold for a while, it will disconnect, probably don't need this code, but also helpful if you connect to the wrong board by accident
        connectedDevicesView.setOnItemLongClickListener((parent, view1, position, id) -> {
            DeviceState current= connectedDevices.getItem(position);
            final MetaWearBoard selectedBoard= stateToBoards.get(current);
            Accelerometer accelerometer = selectedBoard.getModule(Accelerometer.class);
            accelerometer.stop();
            selectedBoard.tearDown();
            selectedBoard.getModule(Debug.class).disconnectAsync();
            connectedDevices.remove(current);
            return false;
        });
    }

    // necessary to establish bluetooth service connection
    @Override
    public void onServiceConnected(ComponentName name, IBinder service) {
        binder= (BtleService.LocalBinder) service;
        Log.i("metawear","MAF: Bluetooth service connected");
    }

    @Override
    public void onServiceDisconnected(ComponentName name) {
    }

    // method called for reconnection
    public static Task<Void> reconnect(final MetaWearBoard board) {
        return board.connectAsync().continueWithTask(task -> task.isFaulted() ? reconnect(board) : task);
    }

}
