package com.msense.ms_fall_risk_application;

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
import android.widget.AdapterView;
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
import com.mbientlab.metawear.data.SensorOrientation;
import com.mbientlab.metawear.module.Accelerometer;
import com.mbientlab.metawear.module.AccelerometerBosch;
import com.mbientlab.metawear.module.AccelerometerMma8452q;
import com.mbientlab.metawear.module.Debug;
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

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        Log.i("metawear","mAF onCreate");
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
        Log.i("metawear","this "+newDeviceState);
        connectedDevices.add(newDeviceState);
        stateToBoards.put(newDeviceState, newBoard);

        final Capture<AsyncDataProducer> accelCapture = new Capture<>();
//        final Capture<Accelerometer> accelCapture = new Capture<>();
        Log.i("metawear","mAF addNewdevice");
//        newBoard.onUnexpectedDisconnect(status -> getActivity().runOnUiThread(() -> connectedDevices.remove(newDeviceState)));
        newBoard.connectAsync().continueWithTask(task -> task.isCancelled() || !task.isFaulted() ? task : reconnect(newBoard))
                .onSuccessTask(task -> {
                    getActivity().runOnUiThread(() -> {
                        newDeviceState.connecting= false;
                        connectedDevices.notifyDataSetChanged();
                    });
                    final Accelerometer accelerometer = newBoard.getModule(Accelerometer.class);
                    // enable low-g detection, use sum criteria,
                    // detect when sum < 0.333g
                    accelerometer.configure()
                            .odr(32.5f)       // Set sampling frequency to 25Hz, or closest valid ODR
                            .range(4f)      // Set data range to +/-4g, or closet valid range
                            .commit();

                    Log.i("metawear", "Actual Odr = " + accelerometer.getOdr());
                    Log.i("metawear", "Actual Range = " + accelerometer.getRange());


                    final AsyncDataProducer acceleration;
                    acceleration = accelerometer.acceleration();
                    accelCapture.set(acceleration);

                    return acceleration.addRouteAsync(source -> source.stream((data, env) -> {
                        getActivity().runOnUiThread(() -> {
                            Log.i("metawear", data.value(Acceleration.class).toString());
                            newDeviceState.deviceOrientation = data.value(Acceleration.class).toString();
//                    Log.i("metawear", data.value(Acceleration.class).toString());
                            connectedDevices.notifyDataSetChanged();
                        });
                    }));
                }).continueWith((Continuation<Route, Void>) task -> {
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

                accelCapture.get().start();
            }


            Log.i("metawear", "mAF addNewdevice");
            return null;
//
//                        return acceleration.addRouteAsync(new RouteBuilder() {
//                            @Override
//                            public void configure(RouteComponent source) {
//                                source.stream(new Subscriber() {
//                                    @Override
//                                    public void apply(Data data, Object... env) {
//                                        Log.i("metawear", data.value(Acceleration.class).toString());
//                                        newDeviceState.deviceOrientation = data.value(SensorOrientation.class).toString();
//                                        connectedDevices.notifyDataSetChanged();
//                                    }
//                                });
//                            }
//                        });
//
//            final Accelerometer accelerometer = newBoard.getModule(Accelerometer.class);
//            accelCapture.set(accelerometer);
//
//            final AsyncDataProducer orientation;
//            if (accelerometer instanceof AccelerometerBosch) {
//                orientation = ((AccelerometerBosch) accelerometer).orientation();
//            } else {
//                orientation = ((AccelerometerMma8452q) accelerometer).orientation();
//            }
//            orientCapture.set(orientation);
//
//            return orientation.addRouteAsync(source -> source.stream((data, env) -> {
//                getActivity().runOnUiThread(() -> {
//                    newDeviceState.deviceOrientation = data.value(SensorOrientation.class).toString();
//                    connectedDevices.notifyDataSetChanged();
//                });
//            }));


//        newBoard.onUnexpectedDisconnect(status -> getActivity().runOnUiThread(() -> connectedDevices.remove(newDeviceState)));
//        newBoard.connectAsync().onSuccessTask(task -> {
//            getActivity().runOnUiThread(() -> {
//                newDeviceState.connecting= false;
//                connectedDevices.notifyDataSetChanged();
//            });
//
//            //this is other -------------->
//
//            final Accelerometer accelerometer = newBoard.getModule(Accelerometer.class);
//            accelCapture.set(accelerometer);
//
//            final AsyncDataProducer orientation;
//            if (accelerometer instanceof AccelerometerBosch) {
//                orientation = ((AccelerometerBosch) accelerometer).orientation();
//            } else {
//                orientation = ((AccelerometerMma8452q) accelerometer).orientation();
//            }
//            orientCapture.set(orientation);
//
//            return orientation.addRouteAsync(source -> source.stream((data, env) -> {
//                getActivity().runOnUiThread(() -> {
//                    newDeviceState.deviceOrientation = data.value(SensorOrientation.class).toString();
//                    connectedDevices.notifyDataSetChanged();
//                });
//            }));
//        }).onSuccessTask(task -> newBoard.getModule(Switch.class).state().addRouteAsync(source -> source.stream((Subscriber) (data, env) -> {
//            getActivity().runOnUiThread(() -> {
//                newDeviceState.pressed = data.value(Boolean.class);
//                connectedDevices.notifyDataSetChanged();
//            });
//        }))).continueWith((Continuation<Route, Void>) task -> {
//            if (task.isFaulted()) {
//                if (!newBoard.isConnected()) {
//                    getActivity().runOnUiThread(() -> connectedDevices.remove(newDeviceState));
//                } else {
//                    Snackbar.make(getActivity().findViewById(R.id.activity_main_layout), task.getError().getLocalizedMessage(), Snackbar.LENGTH_SHORT).show();
//                    newBoard.tearDown();
//                    newBoard.disconnectAsync().continueWith((Continuation<Void, Void>) task1 -> {
//                        connectedDevices.remove(newDeviceState);
//                        return null;
//                    });
//                }
//            } else {
//                orientCapture.get().start();
//                accelCapture.get().start();
//            }


//                    Log.i("metawear", "mAF addNewdevice");
//                    return null;
        });
    };


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        Log.i("metawear","mAF onCreateView");
        connectedDevices= new ConnectedDeviceAdapter(getActivity(), R.id.sensor_list);
        connectedDevices.setNotifyOnChange(true);
        setRetainInstance(true);
        return inflater.inflate(R.layout.fragment_main_activity, container, false);
    }

    @Override
    public void onViewCreated(View view, Bundle savedInstanceState) {
        Log.i("metawear","mAF onViewCreated");
        ListView connectedDevicesView= view.findViewById(R.id.connected_devices);
        connectedDevicesView.setAdapter(connectedDevices);
        connectedDevicesView.setOnItemLongClickListener((parent, view1, position, id) -> {
            DeviceState current= connectedDevices.getItem(position);
            final MetaWearBoard selectedBoard= stateToBoards.get(current);

            Accelerometer accelerometer = selectedBoard.getModule(Accelerometer.class);
            accelerometer.stop();
            if (accelerometer instanceof AccelerometerBosch) {
                ((AccelerometerBosch) accelerometer).orientation().stop();
            } else {
                ((AccelerometerMma8452q) accelerometer).orientation().stop();
            }

            selectedBoard.tearDown();
            selectedBoard.getModule(Debug.class).disconnectAsync();
            Log.i("metawear","mAF onViewCreated2");
            connectedDevices.remove(current);
            return false;
        });
    }

    @Override
    public void onServiceConnected(ComponentName name, IBinder service) {
        binder= (BtleService.LocalBinder) service;
        Log.i("metawear","mAF onServiceConnected");
    }

    @Override
    public void onServiceDisconnected(ComponentName name) {

    }

    public static Task<Void> reconnect(final MetaWearBoard board) {
        return board.connectAsync().continueWithTask(task -> task.isFaulted() ? reconnect(board) : task);
    }
}
