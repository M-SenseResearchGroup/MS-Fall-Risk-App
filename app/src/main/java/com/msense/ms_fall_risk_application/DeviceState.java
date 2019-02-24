package com.msense.ms_fall_risk_application;

import android.bluetooth.BluetoothDevice;
import android.util.Log;


class DeviceState {
    final BluetoothDevice btDevice;
    String deviceOrientation;
    boolean pressed, connecting;

    DeviceState(BluetoothDevice btDevice) {
        this.btDevice= btDevice;
        this.deviceOrientation= null;
        pressed= false;
        Log.i("metawear","DS DeviceState");
    }

    @Override
    public boolean equals(Object obj) {
        Log.i("metawear","DS equals");
        return (obj == this) ||
                ((obj instanceof DeviceState) && btDevice.equals(((DeviceState) obj).btDevice));
    }
}