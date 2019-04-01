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
import android.support.v7.widget.Toolbar;
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
import com.mbientlab.metawear.module.Haptic;

import org.w3c.dom.Text;

import bolts.Continuation;
import bolts.Task;

public class calibration extends AppCompatActivity implements ServiceConnection {
    public final static String EXTRA_BT_DEVICE= "com.msense.ms_fall_risk_application.calibration.EXTRA_BT_DEVICE";
    private Accelerometer accelerometer;
    //    private AccelerometerBosch accBosch;
    private BtleService.LocalBinder serviceBinder;
    private BluetoothDevice btDevice;
    private MetaWearBoard metawear;

    TextView accelValue;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_calibration);
        btDevice= getIntent().getParcelableExtra(EXTRA_BT_DEVICE);
        getApplicationContext().bindService(new Intent(this, BtleService.class), this, BIND_AUTO_CREATE);

        accelValue = (TextView) findViewById(R.id.accelValue);


        findViewById(R.id.start).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                accelerometer.acceleration().start();
                accelerometer.start();

            }
        });
        findViewById(R.id.stop).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                accelerometer.acceleration().stop();
                accelerometer.stop();

            }
        });
//
        ((TextView) findViewById(R.id.status_mac_address)).setText(btDevice.getAddress());
//
//

        findViewById(R.id.vib_button).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                metawear.getModule(Haptic.class).startMotor(100.f, (short) 1000);
                metawear.getModule(Haptic.class).startMotor(50.f, (short) 1000);
                metawear.getModule(Haptic.class).startMotor(100.f, (short) 1000);
                metawear.getModule(Haptic.class).startMotor(50.f, (short) 1000);


                accelerometer = metawear.getModule(Accelerometer.class);
                // enable low-g detection, use sum criteria,
                // detect when sum < 0.333g

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
            }
        });

        Toolbar mToolbar = (Toolbar) findViewById(R.id.toolbar);
        mToolbar.setTitle(getString(R.string.app_name));
        mToolbar.setNavigationIcon(R.drawable.back_24dp);

        mToolbar.setNavigationOnClickListener(view -> finish(



        ));

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
                        accelValue.setText(" " + data.value(Acceleration.class));
                    }
                });
            }
        });

        serviceBinder = (BtleService.LocalBinder) service;
        Log.i("metawear","mA BLE Service Connected");
    }

    @Override
    public void onServiceDisconnected(ComponentName name) {//automatically created
        Log.i("metawear","mA disconnect");

    }

}
