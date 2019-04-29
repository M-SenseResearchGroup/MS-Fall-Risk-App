package com.msense.ms_fall_risk_application;
// Class that performs the bluetooth scan and inflates the listview of nearby devices

import android.app.Activity;
import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.util.Log;

import com.mbientlab.bletoolbox.scanner.BleScannerFragment.ScannerCommunicationBus;
import com.mbientlab.metawear.MetaWearBoard;

import java.util.UUID;

public class Scanner extends AppCompatActivity implements ScannerCommunicationBus {
    public static final String EXTRA_DEVICE= "com.msense.MS_Fall_Risk_Application.Scanner.EXTRA_DEVICE";
    private final static UUID[] SERVICE_UUIDS;

    // initialize specific UUID associated with metawear boards
    static {
        SERVICE_UUIDS = new UUID[] {
                MetaWearBoard.METAWEAR_GATT_SERVICE,
        };
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Log.i("metawear","SA: Scanner view created");
        super.onCreate(savedInstanceState);

        // Attach scanner layout to class
        setContentView(R.layout.activity_scanner);
        // Attach toolbar and back navigation
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        toolbar.setTitle(getString(R.string.app_name));
        toolbar.setNavigationIcon(R.drawable.back_24dp);
        toolbar.setNavigationOnClickListener(view ->
        {Intent returnIntent = new Intent();
        setResult(Activity.RESULT_CANCELED, returnIntent);
        finish(); finish();
        });
    }

    // Filter out non-metawear bluetooth devices
    @Override
    public UUID[] getFilterServiceUuids() {
        return SERVICE_UUIDS;
    }

    // Set duration of scan
    @Override
    public long getScanDuration() {
        return 10000L;
    }

    // Pass device back to MAF once selected
    @Override
    public void onDeviceSelected(BluetoothDevice device) {
        Log.i("metawear","SA: Device Selected");
        Intent result= new Intent();
        result.putExtra(EXTRA_DEVICE, device);
        setResult(RESULT_OK, result);
        finish();
    }

    // on back pressed navigates back to main activity
    @Override
    public void onBackPressed() {
        Intent returnIntent = new Intent();
        setResult(Activity.RESULT_CANCELED, returnIntent);
        finish(); finish();
        return;
    }
}
