package com.msense.ms_fall_risk_application;
// Purpose of this page is to show connected sensor MAC ADDRESS (maybe remove this function at the end)
//1) Use a pop dialog to ask the user to sit down for calibration
//2) Take 1 minute of accelerometer values and automatically select sensors (chest & thigh)
//2.5) Show which sensor (mac address) is which, for internal validation purposes
//3) Alert user to calibration success and proceed to a landing page

import android.bluetooth.BluetoothDevice;
import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.RadioGroup;
import android.widget.TextView;

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

import bolts.Continuation;
import bolts.Task;

public class calibration extends AppCompatActivity implements ServiceConnection {
    public final static String EXTRA_BT_DEVICE= "com.mbientlab.metawear.starter.DeviceSetupActivity.EXTRA_BT_DEVICE";
    private Accelerometer accelerometer;
    //    private AccelerometerBosch accBosch;
    private BtleService.LocalBinder serviceBinder;
    private BluetoothDevice btDevice;
    private MetaWearBoard metawear;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_calibration);
        btDevice= getIntent().getParcelableExtra(EXTRA_BT_DEVICE);
        getApplicationContext().bindService(new Intent(this, BtleService.class), this, BIND_AUTO_CREATE);

        findViewById(R.id.start).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                accelerometer.acceleration().start();
                accelerometer.start();

//                accBosch.orientation().start();
//                accBosch.start();
            }
        });
        findViewById(R.id.stop).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                accelerometer.acceleration().stop();
                accelerometer.stop();

//                accBosch.orientation().stop();
//                accBosch.stop();
            }
        });
//        findViewById(R.id.connection).setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                Intent intent = new Intent(this, MainActivity.class);
//                Log.i("metawear","chyea1");
//                startActivity(intent);
//
//            }
//        });

        // copy the data into the fields
        ((EditText) findViewById(R.id.status_mac_address)).setText(btDevice.getAddress());
//
//        public View getView(int position, View convertView, ViewGroup parent) {
//            Log.i("metawear", "CDA View");
//            RecyclerView.ViewHolder viewHolder;
//
//            if (convertView == null) {
//                convertView = LayoutInflater.from(getContext()).inflate(R.layout.activity_device_state, parent, false);
//
//                viewHolder = new RecyclerView.ViewHolder();
//                viewHolder.deviceName = convertView.findViewById(R.id.status_device_name);
//                viewHolder.deviceAddress = convertView.findViewById(R.id.status_mac_address);
//
//                convertView.setTag(viewHolder);
//            }
//
//            final String deviceName= btDevice.getName();
//
//            viewHolder.deviceAddress.setText(btDevice.getAddress());
//            return convertView;
//        };
//        private class ViewHolder {
//            TextView deviceName, deviceAddress;
//
//        }

    }


    public void toSensorConnection(View view) {
        Intent intent = new Intent(this, MainActivity.class);
        String keyIdentifer  = null;
        Log.i("metawear","chyea1");
        intent.putExtra("numba2",keyIdentifer);
        startActivity(intent);

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
        metawear = ((BtleService.LocalBinder) service).getMetaWearBoard(btDevice);


        accelerometer= metawear.getModule(Accelerometer.class);
        // enable low-g detection, use sum criteria,
        // detect when sum < 0.333g
        accelerometer.configure()
                .odr(32.5f)       // Set sampling frequency to 25Hz, or closest valid ODR
                .range(4f)      // Set data range to +/-4g, or closet valid range
                .commit();

        Log.i("metawear", "Actual Odr = " + accelerometer.getOdr());
        Log.i("metawear", "Actual Range = " + accelerometer.getRange());
        accelerometer.acceleration().addRouteAsync(new RouteBuilder() {
            @Override
            public void configure(RouteComponent source) {
                source.stream(new Subscriber() {
                    @Override
                    public void apply(Data data, Object... env) {
                        Log.i("metawear", data.value(Acceleration.class).toString());
                    }
                });
            }
        });


//        AccelerometerBosch accBosch = metawear.getModule(AccelerometerBosch.class);
//        accBosch.orientation().addRouteAsync(new RouteBuilder() {
//            @Override
//            public void configure(RouteComponent source) {
//                source.stream(new Subscriber() {
//                    @Override
//                    public void apply(Data data, Object... env) {
//                        Log.i("MainActivity", "Orientation = " + data.value(SensorOrientation.class));
//                    }
//                });
//            }
//        }).continueWith(new Continuation<Route, Void>() {
//            @Override
//            public Void then(Task<Route> task) throws Exception {
//                accBosch.orientation().start();
//                accBosch.start();
//                return null;
//            }
//        });

        serviceBinder = (BtleService.LocalBinder) service;
        Log.i("metawear","mA BLE Service Connected");
    }

    @Override
    public void onServiceDisconnected(ComponentName name) {//automatically created
        Log.i("metawear","mA disconnect");

    }
}
