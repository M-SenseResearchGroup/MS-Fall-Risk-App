package com.msense.ms_fall_risk_application;

import android.app.Activity;
import android.app.Notification;
import android.bluetooth.BluetoothDevice;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.support.annotation.Nullable;
import android.support.design.widget.Snackbar;
import android.support.v4.app.DialogFragment;
import android.support.v4.app.Fragment;
import android.os.Bundle;
import android.support.v4.app.NotificationCompat;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ListView;

import com.mbientlab.metawear.AsyncDataProducer;
import com.mbientlab.metawear.Data;
import com.mbientlab.metawear.MetaWearBoard;
import com.mbientlab.metawear.Route;
import com.mbientlab.metawear.Subscriber;
import com.mbientlab.metawear.android.BtleService;
import com.mbientlab.metawear.builder.RouteBuilder;
import com.mbientlab.metawear.builder.RouteComponent;
import com.mbientlab.metawear.data.Acceleration;
import com.mbientlab.metawear.module.Accelerometer;
import com.mbientlab.metawear.module.AccelerometerBosch;
import com.mbientlab.metawear.module.AccelerometerMma8452q;
import com.mbientlab.metawear.module.Debug;
import com.mbientlab.metawear.module.Haptic;
import com.mbientlab.metawear.module.Switch;


import java.util.HashMap;

import bolts.Capture;
import bolts.Continuation;
import bolts.Task;



public class MainActivityFrag extends Fragment implements ServiceConnection {

    private final HashMap<DeviceState, MetaWearBoard> stateToBoards;
    private BtleService.LocalBinder binder;

    private ConnectedDeviceAdapter connectedDevices= null;

    public MainActivityFrag() {
        stateToBoards = new HashMap<>();
    }

    private String s;

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        Log.i("metawear","MAF: View Created");
        super.onCreate(savedInstanceState);

        Activity owner= getActivity();
        owner.getApplicationContext().bindService(new Intent(owner, BtleService.class), this, Context.BIND_AUTO_CREATE);


    }


    @Override
    public void onDestroy() {
        super.onDestroy();

        getActivity().getApplicationContext().unbindService(this);
    }


    public void addNewDevice(BluetoothDevice btDevice) {
        final DeviceState newDeviceState= new DeviceState(btDevice);
        final MetaWearBoard newBoard= binder.getMetaWearBoard(btDevice);

        newDeviceState.connecting= true;
        Log.i("metawear","MAF: Atempting to connect to  "+newDeviceState);
        connectedDevices.add(newDeviceState);
        stateToBoards.put(newDeviceState, newBoard);

        final Capture<AsyncDataProducer> orientCapture = new Capture<>();
        final Capture<Accelerometer> accelCapture = new Capture<>();



        newBoard.onUnexpectedDisconnect(status -> {
//            ReconnectDialogFragment dialogFragment= ReconnectDialogFragment.newInstance(btDevice);
//            dialogFragment.show(getSupportFragmentManager(), RECONNECT_DIALOG_TAG);
            Log.i("metawear","MAF: Unexpected Disconnect Detected");
            Log.i("metawear","MAF: Connection lost, reconnecting to " + btDevice.getAddress());
            newBoard.connectAsync().continueWithTask(task -> task.isCancelled() || !task.isFaulted() ? task : MainActivityFrag.reconnect(newBoard))
                    .continueWith((Continuation<Void, Void>) task -> {

                        if (!task.isCancelled()) {
//                            runOnUiThread(() -> {
//                                ((DialogFragment) getSupportFragmentManager().findFragmentByTag(RECONNECT_DIALOG_TAG)).dismiss();
//                                ((DeviceSetupActivityFragment) getSupportFragmentManager().findFragmentById(R.id.device_setup_fragment)).reconnected();
//                                Log.i("metawear","Reconnection Successful");
//                            });
                            Log.i("metawear","MAF: Successful reconnection to: "+ btDevice.getAddress());

                        } else {
                            Log.i("metawear","MAF: Successful reconnection to: "+ btDevice.getAddress());
//                            finish();
                        }

                        return null;
                    });
        });


        newBoard.connectAsync().onSuccessTask(task -> {
                Log.i("metawear","MAF: Device succesfully connected: " + btDevice.getAddress());

                    getActivity().runOnUiThread(() -> {
                        newDeviceState.connecting= false;
                        connectedDevices.notifyDataSetChanged();
                    });

            newBoard.getModule(Haptic.class).startMotor(100.f, (short) 1000);
            newBoard.getModule(Haptic.class).startMotor(50.f, (short) 1000);
            newBoard.getModule(Haptic.class).startMotor(100.f, (short) 1000);
            newBoard.getModule(Haptic.class).startMotor(50.f, (short) 1000);
            newBoard.getModule(Haptic.class).startMotor(100.f, (short) 1000);
            newBoard.getModule(Haptic.class).startMotor(50.f, (short) 1000);
            newBoard.getModule(Haptic.class).startMotor(100.f, (short) 1000);
            newBoard.getModule(Haptic.class).startMotor(50.f, (short) 1000);

            final Accelerometer accelerometer = newBoard.getModule(Accelerometer.class);
            accelerometer.configure()
                    .odr(32.5f)       // Set sampling frequency to 25Hz, or closest valid ODR
                    .range(4f)      // Set data range to +/-4g, or closet valid range
                    .commit();

            Log.i("metawear", "MAF: Accel frequency = " + accelerometer.getOdr());
            Log.i("metawear", "MAF: Accel range = " + accelerometer.getRange());

            accelCapture.set(accelerometer);

            final AsyncDataProducer orientation;
            if (accelerometer instanceof AccelerometerBosch) {
                orientation = ((AccelerometerBosch) accelerometer).acceleration();
            } else {
                orientation = ((AccelerometerMma8452q) accelerometer).acceleration();
            }
            orientCapture.set(orientation);

            return orientation.addRouteAsync(source -> source.stream((data, env) -> {
                getActivity().runOnUiThread(() -> {
                    //Log.i("metawear", data.value(Acceleration.class).toString());
                    s = data.value(Acceleration.class).toString();

//                    Log.i("metawear",s.substring(0,6));
                    newDeviceState.xVal = s.substring(4,10);
                    newDeviceState.yVal = s.substring(15,21);
                    newDeviceState.zVal = s.substring(26,32);



                    connectedDevices.notifyDataSetChanged();

                });
            }));

        })

//        .onSuccessTask(task ->
//                setOnClickListener(new View.OnClickListener() {
//                    @@ -67,46 +67,49 @@ public void onClick(View v) {
//
//                                                                     }
//                        newBoard.getModule(Haptic.class).startMotor(100.f, (short) 1000);
//                        newBoard.getModule(Haptic.class).startMotor(50.f, (short) 1000);
//                        newBoard.getModule(Haptic.class).startMotor(100.f, (short) 1000);
//                        newBoard.getModule(Haptic.class).startMotor(50.f, (short) 1000);
//
//                    });
//        );


//        newBoard.getModule(Haptic.class).startMotor(100.f, (short) 1000);
//
//                .onSuccessTask(task -> newBoard.getModule(Switch.class).state().addRouteAsync(source -> source.stream((Subscriber) (data, env) -> {
//                    getActivity().runOnUiThread(() -> {
//                        newDeviceState.pressed = data.value(Boolean.class);
//                        connectedDevices.notifyDataSetChanged();
//                    });
//                })))

                .continueWith((Continuation<Route, Void>) task -> {
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




                orientCapture.get().start();
                accelCapture.get().start();
            }



            return null;

        });
    };


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
//        Log.i("metawear","mAF onCreateView");
        connectedDevices= new ConnectedDeviceAdapter(getActivity(), R.id.sensor_list);
        connectedDevices.setNotifyOnChange(true);
        setRetainInstance(true);
        View view = inflater.inflate(R.layout.fragment_main_activity, container, false);


        return view;
}

    @Override
    public void onViewCreated(View view, Bundle savedInstanceState) {
//        Log.i("metawear","mAF onViewCreated");
        ListView connectedDevicesView= view.findViewById(R.id.connected_devices);
        connectedDevicesView.setAdapter(connectedDevices);
        connectedDevicesView.setOnItemLongClickListener((parent, view1, position, id) -> {
            DeviceState current= connectedDevices.getItem(position);
            final MetaWearBoard selectedBoard= stateToBoards.get(current);

            Accelerometer accelerometer = selectedBoard.getModule(Accelerometer.class);
            accelerometer.stop();



            selectedBoard.tearDown();
            selectedBoard.getModule(Debug.class).disconnectAsync();
//            Log.i("metawear","mAF onViewCreated2");
            connectedDevices.remove(current);


            Button button = (Button) view.findViewById(R.id.vib_button);
            button.setOnClickListener(new View.OnClickListener()
            {
                @Override
                public void onClick(View v)
                {
                    selectedBoard.getModule(Haptic.class).startMotor(100.f, (short) 1000);

                    Log.i("metawear","clickckckc");
                }
            });
            return false;
        });
    }

    @Override
    public void onServiceConnected(ComponentName name, IBinder service) {
        binder= (BtleService.LocalBinder) service;
        Log.i("metawear","MAF: Bluetooth service connected");
    }

    @Override
    public void onServiceDisconnected(ComponentName name) {

    }

    public static Task<Void> reconnect(final MetaWearBoard board) {
        return board.connectAsync().continueWithTask(task -> task.isFaulted() ? reconnect(board) : task);
    }

    public void myClickHandler(View v)
    {

//        Log.i("metawear","click!");
//        long[] pattern = {500, 500, 500, 500, 500, 500, 500, 500, 500};
//        Notification notification = new NotificationCompat.Builder(this, CHANNEL_ID)
//                .setSmallIcon(R.drawable.ic_walk)
//                .setContentTitle("HIGH FALL RISK DETECTED")
//                //.setPriority(NotificationCompat.PRIORITY_HIGH)
//                //.setCategory(NotificationCompat.CATEGORY_MESSAGE)
//                .setVibrate(pattern)
//                .setStyle(new NotificationCompat.InboxStyle()
//                        .addLine("Find A Place To Sit")
//                        .addLine("Focus on your balance"))
//                .build();
//        notificationManager.notify(115, notification);

    }

}
