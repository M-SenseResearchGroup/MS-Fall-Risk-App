package com.msense.ms_fall_risk_application;
// This is the main activity of the entire app. Every other class is called from within this one


import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.bluetooth.BluetoothDevice;
import android.content.Context;
import android.content.Intent;
import android.support.v4.app.NotificationCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.os.Build;
import com.jjoe64.graphview.GraphView;
import com.jjoe64.graphview.Viewport;
import com.jjoe64.graphview.helper.DateAsXAxisLabelFormatter;
import com.jjoe64.graphview.series.DataPoint;
import com.jjoe64.graphview.series.PointsGraphSeries;
import com.mbientlab.metawear.MetaWearBoard;
import java.text.SimpleDateFormat;
import java.util.Date;
import android.support.v4.app.NotificationManagerCompat;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {

    // Initialize variable used in bluetooth scan
    public static final int REQUEST_START_BLE_SCAN = 1;

    // Initialize metawear board object
    private MetaWearBoard newBoard;

    // Intialize notification channel
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

    // To be incremented over number of connections
    private int i = 0;

    // Initialize graphview
    GraphView mScatterPlot;
    PointsGraphSeries<DataPoint> series;
    SimpleDateFormat sdf = new SimpleDateFormat("hh:mm:ss");

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.i("metawear", "MA: View created");

        // Create notification channel
        createNotificationChannel();
        notificationManager = NotificationManagerCompat.from(this);

        // Attach layout to activity
        setContentView(R.layout.activity_main);

        // Attach toolbar and set nav icon to go back a screen
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        toolbar.setTitle(getString(R.string.app_name));
        toolbar.setNavigationIcon(R.drawable.back_24dp);
        toolbar.setNavigationOnClickListener(view -> finish(
        ));

        // Set msense logo to load info modal
        ImageView infoImg = findViewById(R.id.logoLanding);
        infoImg.setOnClickListener(this::myClickHandler);

        // Attach graphview to object in layout
        final GraphView graph = (GraphView) findViewById(R.id.chart1);
        graph.setVisibility(View.VISIBLE);

        // Initialize scatter plot specs
        series = new PointsGraphSeries();
        graph.addSeries(series);
        Viewport viewport = graph.getViewport();
        viewport.setYAxisBoundsManual(true);
        viewport.setMinY(0);
        viewport.setMaxY(1.1);
        viewport.setXAxisBoundsManual(true);
        viewport.setScrollable(true);
        viewport.scrollToEnd();
        viewport.setScalable(true);
        graph.getGridLabelRenderer().setLabelFormatter(
                new DateAsXAxisLabelFormatter(this,
                        SimpleDateFormat.getDateInstance(SimpleDateFormat.LONG)) {
                    @Override
                    public String formatLabel(double value, boolean isValueX) {
                        if (isValueX)
                            return sdf.format(new Date((long) value));
                        else
                            return super.formatLabel(value, isValueX);
                    }
                });
        graph.getGridLabelRenderer().setNumHorizontalLabels(3);

        // Add on click listener to plus symbol to navigate to scanner
        ImageView plus = findViewById(R.id.plus);
        plus.setOnClickListener(view -> startActivityForResult(new Intent(MainActivity.this, Scanner.class), REQUEST_START_BLE_SCAN));

        // start scanner upon launch and iterate twice to connect two sensors
        if (i < 2) {
            startActivityForResult(new Intent(MainActivity.this, Scanner.class), REQUEST_START_BLE_SCAN);

        }


    }

    // Create thread to handle fall risk event: add point to graph series, call notification
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
    };


    // Add entry to graph (x = date, y = 1 for fall)
    private void addEntry() {
        double  y;
        y = 1;
        series.appendData(new DataPoint(new Date().getTime(), y), true, 50);
        Log.i("metawear", "MA: appended new Fall Event!");
    }


    // Upon result of bluetooth scan call method "add new device" within fragment
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

        // After connection increment sensor connected count i and either restart scan or proceed to landing
        i = i + 1;
        Log.i("metawear", "MAF: Connected Device Count: " + i);
        if (i < 2) {
            Log.i("metawear", "MAF: Selecting Second Device");
            startActivityForResult(new Intent(MainActivity.this, Scanner.class), REQUEST_START_BLE_SCAN);


        }
        if (i==2) {
            startActivity(new Intent(MainActivity.this, info.class));
        }

    }



    // on click handler for the msense logo, that navigates to the info modal
    public void myClickHandler(View v) {
        startActivity(new Intent(MainActivity.this, info.class));
        Log.i("metawear","MA: info popup");
    }
}