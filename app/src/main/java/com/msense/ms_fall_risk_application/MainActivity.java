package com.msense.ms_fall_risk_application;
//This the activity that performs the bluetooth scan

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.ProgressDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;

import android.graphics.Color;
import android.os.IBinder;
import android.support.design.widget.FloatingActionButton;

import android.support.v4.app.NotificationCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.os.Build;

import com.jjoe64.graphview.GraphView;
import com.jjoe64.graphview.Viewport;
import com.jjoe64.graphview.series.DataPoint;
import com.jjoe64.graphview.series.LineGraphSeries;
import com.jjoe64.graphview.series.PointsGraphSeries;
import com.mbientlab.metawear.MetaWearBoard;
import com.mbientlab.metawear.android.BtleService;
import com.mbientlab.metawear.module.Haptic;

import java.sql.Time;
import java.util.Date;
import java.util.HashMap;
import java.util.concurrent.TimeUnit;

import android.app.NotificationManager;
import android.support.v4.app.NotificationManagerCompat;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {
    public static final int REQUEST_START_BLE_SCAN = 1;
    private MetaWearBoard newBoard;

    private NotificationManagerCompat notificationManager;
    public static final String CHANNEL_ID = "FALL RISK CHANNEL";

    private void createNotificationChannel() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            NotificationChannel fallchannel = new NotificationChannel(
                    CHANNEL_ID, "Fall Risk Channel", NotificationManager.IMPORTANCE_HIGH);
            fallchannel.enableVibration(true);
            fallchannel.setDescription("This is channel allows for notifcations to occur in the event of a detected increased fall risk");
            NotificationManager manager = getSystemService(NotificationManager.class);
            manager.createNotificationChannel(fallchannel);
        }
    }


    private int i = 0;


//    // for plotting purpose, could be a complete failure
//    private LineChart mchart;
//    private Thread thread;
//    private boolean plotData = true;

    //    LineGraphSeries<DataPoint>series;
    GraphView mScatterPlot;
    PointsGraphSeries<DataPoint> series;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);

        createNotificationChannel();
        notificationManager = NotificationManagerCompat.from(this);

        setContentView(R.layout.activity_main);

        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        toolbar.setTitle(getString(R.string.app_name));
        toolbar.setNavigationIcon(R.drawable.back_24dp);

        toolbar.setNavigationOnClickListener(view -> finish(

        ));

//        mchart = (LineChart) findViewById(R.id.chart1);
//        LineData data = new LineData();
//        mchart.setData(data);
//        startPlot();

        Button fallRisk = findViewById(R.id.genFall);
//        fallRisk.setOnClickListener(this::myClickHandler);


        final GraphView graph = (GraphView) findViewById(R.id.chart1);
        graph.setVisibility(View.VISIBLE);

        series = new PointsGraphSeries();

//        series = new LineGraphSeries<DataPoint>();
        graph.addSeries(series);

        Viewport viewport = graph.getViewport();
        viewport.setYAxisBoundsManual(true);
        viewport.setMinY(0);
        viewport.setMaxY(1.1);
        viewport.setXAxisBoundsManual(true);
//        viewport.setMinX(1556262000);
//        viewport.setMaxX(1556263000);
        viewport.setScrollable(true);

        Log.i("metawear", "MA: View created");

        ImageView plus = findViewById(R.id.plus);
        plus.setOnClickListener(view -> startActivityForResult(new Intent(MainActivity.this, Scanner.class), REQUEST_START_BLE_SCAN));


        if (i < 2) {
            startActivityForResult(new Intent(MainActivity.this, Scanner.class), REQUEST_START_BLE_SCAN);

        }


    }
    final Context context = this;
    protected void onResume() {
        super.onResume();
        new Thread(new Runnable() {
            @Override
            public void run() {
                Button fallRisk = findViewById(R.id.genFall);
                fallRisk.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Log.i("metawear", "MAF: High Fall Risk Clicked!");
                        addEntry();

                        long[] pattern = {500, 500, 500, 500, 500, 500, 500, 500, 500};
                        Notification notification = new NotificationCompat.Builder(context, CHANNEL_ID)
                                .setSmallIcon(R.drawable.ic_walk)
                                .setContentTitle("HIGH FALL RISK DETECTED")
                                //.setPriority(NotificationCompat.PRIORITY_HIGH)
                                //.setCategory(NotificationCompat.CATEGORY_MESSAGE)
                                .setVibrate(pattern)
                                .setStyle(new NotificationCompat.InboxStyle()
                                        .addLine("Find A Place To Sit")
                                        .addLine("Focus on your balance"))
                                .build();
                        notificationManager.notify(115, notification);

                    }
                });
                try {
                    Thread.sleep(600);
                } catch (InterruptedException e) {

                }
            }

            ;
        }).start();
    }

    ;

    private void addEntry() {
        long now = TimeUnit.MILLISECONDS.toSeconds(System.currentTimeMillis());
        double x, y;
        x = now;
        Log.i("metawear", Long.toString(now));
        y = 1;
        Log.i("metawear", "appending");
        series.appendData(new DataPoint(x, y), true, 10);
        Log.i("metawear", "appended!");
    }


    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        switch (requestCode) {
            case REQUEST_START_BLE_SCAN:
                BluetoothDevice selectedDevice = data.getParcelableExtra(Scanner.EXTRA_DEVICE);


                if (selectedDevice != null) {
                    ((MainActivityFrag) getSupportFragmentManager().findFragmentById(R.id.main_activity_content)).addNewDevice(selectedDevice);
                }
                break;

        }

        i = i + 1;
        Log.i("metawear", "MAF: Connected Device Count: " + i);
        if (i < 2) {
            Log.i("metawear", "MAF: Selecting Second Device");
            startActivityForResult(new Intent(MainActivity.this, Scanner.class), REQUEST_START_BLE_SCAN);

        }


    }


    public void myClickHandler(View v) {

        Log.i("metawear", "click!");
        long[] pattern = {500, 500, 500, 500, 500, 500, 500, 500, 500};
        Notification notification = new NotificationCompat.Builder(this, CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_walk)
                .setContentTitle("HIGH FALL RISK DETECTED")
                //.setPriority(NotificationCompat.PRIORITY_HIGH)
                //.setCategory(NotificationCompat.CATEGORY_MESSAGE)
                .setVibrate(pattern)
                .setStyle(new NotificationCompat.InboxStyle()
                        .addLine("Find A Place To Sit")
                        .addLine("Focus on your balance"))
                .build();
        notificationManager.notify(115, notification);
    }
}