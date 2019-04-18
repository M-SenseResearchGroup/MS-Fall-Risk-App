package com.msense.ms_fall_risk_application;
//This the activity that performs the bluetooth scan

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.ProgressDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;

import android.content.Intent;

import android.support.design.widget.FloatingActionButton;

import android.support.v4.app.NotificationCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.os.Build;

import com.mbientlab.metawear.MetaWearBoard;

import java.util.HashMap;
import android.app.NotificationManager;
import android.support.v4.app.NotificationManagerCompat;



public class MainActivity extends AppCompatActivity {
    public static final int REQUEST_START_BLE_SCAN= 1;


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


    @Override
    protected void onCreate(Bundle savedInstanceState) {
         final HashMap<DeviceState, MetaWearBoard> numBoards;
         super.onCreate(savedInstanceState);

        createNotificationChannel();
        notificationManager = NotificationManagerCompat.from(this);

        setContentView(R.layout.activity_main);
//        Toolbar toolbar = findViewById(R.id.toolbar);
//        setSupportActionBar(toolbar);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        toolbar.setTitle(getString(R.string.app_name));
        toolbar.setNavigationIcon(R.drawable.back_24dp);

        toolbar.setNavigationOnClickListener(view -> finish(

        ));




        Log.i("metawear","MA: View created");
        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(view -> startActivityForResult(new Intent(MainActivity.this, Scanner.class), REQUEST_START_BLE_SCAN));




//        if (numBoards.size()< 2) {
//            startActivityForResult(new Intent(MainActivity.this, Scanner.class), REQUEST_START_BLE_SCAN)
//
//        }




    }



    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        switch (requestCode) {
            case REQUEST_START_BLE_SCAN:
                BluetoothDevice selectedDevice= data.getParcelableExtra(Scanner.EXTRA_DEVICE);
                if (selectedDevice != null) {
                    ((MainActivityFrag) getSupportFragmentManager().findFragmentById(R.id.main_activity_content)).addNewDevice(selectedDevice);
                }
                break;

        }


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