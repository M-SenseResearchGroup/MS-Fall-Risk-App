package com.msense.ms_fall_risk_application;
//This the activity that performs the bluetooth scan

import android.app.ProgressDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import com.mbientlab.metawear.AsyncDataProducer;
import com.mbientlab.metawear.Data;
import com.mbientlab.metawear.Route;
import com.mbientlab.metawear.Subscriber;
import com.mbientlab.metawear.builder.RouteBuilder;
import com.mbientlab.metawear.builder.RouteComponent;
import com.mbientlab.metawear.data.Acceleration;
import com.mbientlab.metawear.data.SensorOrientation;
import com.mbientlab.metawear.module.Accelerometer;
import com.mbientlab.metawear.module.AccelerometerBosch;
import com.mbientlab.bletoolbox.scanner.BleScannerFragment;
import com.mbientlab.metawear.MetaWearBoard;
import com.mbientlab.metawear.android.BtleService;

import java.util.HashMap;
import java.util.UUID;

import bolts.Capture;
import bolts.Continuation;
import bolts.Task;

public class MainActivity extends AppCompatActivity implements BleScannerFragment.ScannerCommunicationBus, ServiceConnection {

    private BtleService.LocalBinder serviceBinder;
    private MetaWearBoard board;
    private final HashMap<String, MetaWearBoard> stateToBoards; //for hashmap
    private BtleService.LocalBinder binder;
    public String NUMBER_DEVICES = "NUMBER_DEVICES_1" ;


    public MainActivity() {
        stateToBoards = new HashMap<>();
    } //for hashmap
//    private AccelerometerBosch accBosch;


    @Override
    protected void onCreate(Bundle savedInstanceState) { //This sets the layout for this activity and binds the service on its creation
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);
        Log.i("metawear","mAOncreate");
        getApplicationContext().bindService(new Intent(this, BtleService.class), this, BIND_AUTO_CREATE);


    }

    @Override
    public void onDestroy() { //on activities conclusions service is unbinded
        super.onDestroy();
        Log.i("metawear","mAOndestroy");
        ///< Unbind the service when the activity is destroyed
        getApplicationContext().unbindService(this);
    }

    @Override
    public void onServiceConnected(ComponentName name, IBinder service) { //automatically created
        serviceBinder = (BtleService.LocalBinder) service;
        Log.i("metawear","mA BLE Service Connected");




    }

    @Override
    public void onServiceDisconnected(ComponentName name) {//automatically created
        Log.i("metawear","mA disconnect");

    }

    @Override
    public UUID[] getFilterServiceUuids() {
        //filters bluetooth devices for just the metawear boards
        Log.i("metawear","UUID filter");
        return new UUID[] {MetaWearBoard.METAWEAR_GATT_SERVICE};
    }

    @Override
    public long getScanDuration() {
        return 10000L;
    }

    @Override
    public void onDeviceSelected(final BluetoothDevice device) {
        Context context = getApplicationContext();
        CharSequence text = "We've selected a device! Yay Toast!";
        int duration = Toast.LENGTH_SHORT;

        Toast toast = Toast.makeText(context, text, duration);
        toast.show();
        board = serviceBinder.getMetaWearBoard(device); //binds mac address associated with selected device

        //FOR HASH MAP ----------------
        String newDeviceState = NUMBER_DEVICES;
        stateToBoards.put(board.getMacAddress(), board);
//        Log.i("metawear", NUMBER_DEVICES);
        Log.i("metawear",board.getMacAddress());


        //-----------------------------

        Log.i("metawear","mA open connect dialog");
        //Connection Dialog
        final ProgressDialog connectDialog = new ProgressDialog(this);
        connectDialog.setTitle(getString(R.string.title_connecting));
        connectDialog.setMessage(getString(R.string.message_wait));
        connectDialog.setCancelable(false);
        connectDialog.setCanceledOnTouchOutside(false);
        connectDialog.setIndeterminate(true);
        connectDialog.setButton(DialogInterface.BUTTON_NEGATIVE, getString(android.R.string.cancel), (dialogInterface, i) -> board.disconnectAsync());
        connectDialog.show();
        Log.i("metawear","connection dialog done for");
        //Connection request, including if task is faulted
        board.connectAsync().continueWithTask(task -> task.isCancelled() || !task.isFaulted() ? task : reconnect(board))
                .continueWith(task -> {
                    if (!task.isCancelled()) { //to do, to connect
                        //dismiss connection dialog

                        Log.i("metawear","connect");

                        runOnUiThread(connectDialog::dismiss);



                        //call device setup activity
//                        Intent navActivityIntent = new Intent(MainActivity.this, DeviceSetupActivity.class);
                        //include device as extra bluetooth device
//                        navActivityIntent.putExtra(DeviceSetupActivity.EXTRA_BT_DEVICE, device);
                        //starts the activity above, and requests a result (navActivity Intent), REQUEST_START_APP is an integer code to identify request
//                        startActivityForResult(navActivityIntent, REQUEST_START_APP);
                        if (stateToBoards.size() == 2){


                            Intent navActivityIntent = new Intent(MainActivity.this, calibration.class);
                            navActivityIntent.putExtra(calibration.EXTRA_BT_DEVICE, device);
                            startActivity(navActivityIntent);

                        }
                        else {
                            String NUMBER_DEVICES = "NUMBER_DEVICES_2" ;
                            Log.i("metawear",NUMBER_DEVICES);

                        }
//                        accelerometer= board.getModule(Accelerometer.class);
//                        // enable low-g detection, use sum criteria,
//                        // detect when sum < 0.333g
//                        accelerometer.configure()
//                                .odr(32.5f)       // Set sampling frequency to 25Hz, or closest valid ODR
//                                .range(4f)      // Set data range to +/-4g, or closet valid range
//                                .commit();
//
//                        Log.i("metawear", "Actual Odr = " + accelerometer.getOdr());
//                        Log.i("metawear", "Actual Range = " + accelerometer.getRange());
//                        accelerometer.acceleration().addRouteAsync(new RouteBuilder() {
//                            @Override
//                            public void configure(RouteComponent source) {
//                                source.stream(new Subscriber() {
//                                    @Override
//                                    public void apply(Data data, Object... env) {
//                                        Log.i("metawear", data.value(Acceleration.class).toString());
//                                    }
//                                });
//                            }
//                        });
//                        AccelerometerBosch accBosch = board.getModule(AccelerometerBosch.class);
//                        accBosch.orientation().addRouteAsync(new RouteBuilder() {
//                            @Override
//                            public void configure(RouteComponent source) {
//                                source.stream(new Subscriber() {
//                                    @Override
//                                    public void apply(Data data, Object... env) {
//                                        Log.i("metawear", "Orientation = " + data.value(SensorOrientation.class));
//                                    }
//                                });
//                            }
//                        });
                    }
                    Log.i("metawear","mA task continued");
                    return null; //if task is cancelled
                });
        Log.i("metawear","mAondevselected");
    }

    //    public void addNewDevice(BluetoothDevice btDevice) {
////
////        final MetaWearBoard newBoard = binder.getMetaWearBoard(btDevice);
////        if (stateToBoards.size() != 2) {
////            stateToBoards.put("Board 1", newBoard);
////
////        } else {
////            stateToBoards.put("Board 2", newBoard);
////        }
////
////
////        final Capture<AsyncDataProducer> orientCapture = new Capture<>();
////        final Capture<Accelerometer> accelCapture = new Capture<>();
////        Log.i("metawear", "mAF addNewdevice");
////        newBoard.onUnexpectedDisconnect(status -> getActivity().runOnUiThread(() -> connectedDevices.remove(newDeviceState)));
////        newBoard.connectAsync().onSuccessTask(task -> {
////
////        });
////
////    }
    public static Task<Void> reconnect(final MetaWearBoard board) {
        return board.connectAsync().continueWithTask(task -> task.isFaulted() ? reconnect(board) : task);
    }
}
