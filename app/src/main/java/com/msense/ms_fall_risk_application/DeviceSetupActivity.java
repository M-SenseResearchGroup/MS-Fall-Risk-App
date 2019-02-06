package com.msense.ms_fall_risk_application;

import android.app.Dialog;
import android.app.ProgressDialog;
import android.bluetooth.BluetoothDevice;
import android.content.ComponentName;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.support.annotation.NonNull;
import android.support.v4.app.DialogFragment;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

import com.mbientlab.metawear.Data;
import com.mbientlab.metawear.Route;
import com.mbientlab.metawear.Subscriber;
import com.mbientlab.metawear.builder.RouteBuilder;
import com.mbientlab.metawear.data.Acceleration;
import com.mbientlab.metawear.module.Accelerometer;

import com.mbientlab.metawear.MetaWearBoard;
import com.mbientlab.metawear.android.BtleService;
import com.msense.ms_fall_risk_application.DeviceSetupActivityFragment.FragmentSettings;
//import com.mbientlab.metawear.tutorial.starter.DeviceSetupActivityFragment.FragmentSettings;

import bolts.Continuation;
import bolts.Task;

import static android.content.DialogInterface.*;

public class DeviceSetupActivity extends AppCompatActivity implements ServiceConnection, DeviceSetupActivityFragment.FragmentSettings {
    public final static String EXTRA_BT_DEVICE= "com.mbientlab.metawear.starter.DeviceSetupActivity.EXTRA_BT_DEVICE";
    private Accelerometer accelerometer; //for accelerometer in onService Connected
    public static class ReconnectDialogFragment extends DialogFragment implements  ServiceConnection {


        private static final String KEY_BLUETOOTH_DEVICE = "com.mbientlab.metawear.starter.DeviceSetupActivity.ReconnectDialogFragment.KEY_BLUETOOTH_DEVICE";

        private ProgressDialog reconnectDialog = null;
        private BluetoothDevice btDevice = null;
        private MetaWearBoard currentMwBoard = null;

        public static ReconnectDialogFragment newInstance(BluetoothDevice btDevice) {
            Bundle args = new Bundle();
            args.putParcelable(KEY_BLUETOOTH_DEVICE, btDevice);

            ReconnectDialogFragment newFragment = new ReconnectDialogFragment();
            newFragment.setArguments(args);

            return newFragment;
        }

        @NonNull
        @Override
        public Dialog onCreateDialog(Bundle savedInstanceState) {
            Log.i("metawear","DS Recoonect frag");
            btDevice = getArguments().getParcelable(KEY_BLUETOOTH_DEVICE);
            getActivity().getApplicationContext().bindService(new Intent(getActivity(), BtleService.class), this, BIND_AUTO_CREATE);

            reconnectDialog = new ProgressDialog(getActivity());
            reconnectDialog.setTitle(getString(R.string.title_reconnect_attempt));
            reconnectDialog.setMessage(getString(R.string.message_wait));
            reconnectDialog.setCancelable(false);
            reconnectDialog.setCanceledOnTouchOutside(false);
            reconnectDialog.setIndeterminate(true);
            reconnectDialog.setButton(BUTTON_NEGATIVE, getString(android.R.string.cancel), (dialogInterface, i) -> {
                currentMwBoard.disconnectAsync();
                getActivity().finish();
            });

            return reconnectDialog;
        }

        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            currentMwBoard= ((BtleService.LocalBinder) service).getMetaWearBoard(btDevice);
            Log.i("metawear","DS on serv connected");
        }

        @Override
        public void onServiceDisconnected(ComponentName name) { }
    }

    private BluetoothDevice btDevice;
    private MetaWearBoard metawear;

    private final String RECONNECT_DIALOG_TAG= "reconnect_dialog_tag";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_device_setup);
        Log.i("metawear","DS oncreate (not recconect)");
        Toolbar toolbar = findViewById(R.id.toolbar);
        Log.i("metawear","DS 1");
        setSupportActionBar(toolbar);
        Log.i("metawear","DS2");
        btDevice= getIntent().getParcelableExtra(EXTRA_BT_DEVICE);
        Log.i("metawear","DS 3");
        getApplicationContext().bindService(new Intent(this, BtleService.class), this, BIND_AUTO_CREATE);
        Log.i("metawear","DS 4");
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        Log.i("metawear","DS menu"); //this happens after connection to sensor
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_device_setup, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) { //If you click disconnect, this brings to connection page
        Log.i("metawear","DS disconnect menu");
        switch(item.getItemId()) {
            case R.id.action_disconnect:
                metawear.disconnectAsync();
                finish();
                return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onBackPressed() {
        Log.i("metawear","DS onBackPressed");
        metawear.disconnectAsync();
        super.onBackPressed();
    }

    @Override
    public void onServiceConnected(ComponentName name, IBinder service) {
        metawear = ((BtleService.LocalBinder) service).getMetaWearBoard(btDevice);
        accelerometer= metawear.getModule(Accelerometer.class);
        accelerometer.configure()
                .odr(32.2f)       // Set sampling frequency to 25Hz, or closest valid ODR
                .commit();
        Log.i("metawear","DS service connection device setup");
        metawear.onUnexpectedDisconnect(status -> {
            ReconnectDialogFragment dialogFragment= ReconnectDialogFragment.newInstance(btDevice);
            dialogFragment.show(getSupportFragmentManager(), RECONNECT_DIALOG_TAG);
            Log.i("metawear","DS ununnexpecteddisconnect");
            metawear.connectAsync().continueWithTask(task -> task.isCancelled() || !task.isFaulted() ? task : MainActivity.reconnect(metawear))
                    .continueWith((Continuation<Void, Void>) task -> {
                        if (!task.isCancelled()) {
                            runOnUiThread(() -> {
                                ((DialogFragment) getSupportFragmentManager().findFragmentByTag(RECONNECT_DIALOG_TAG)).dismiss();
                                ((DeviceSetupActivityFragment) getSupportFragmentManager().findFragmentById(R.id.device_setup_fragment)).reconnected();
                            });
                            Log.i("metawear","DS connectasyn");
                        } else {
                            finish();
                        }

                        return null;
                    });
        });
    }

    @Override
    public void onServiceDisconnected(ComponentName name) {
        Log.i("metawear","DS disconnect2");

    }


    @Override
    public BluetoothDevice getBtDevice() {
        return btDevice;
    }
}