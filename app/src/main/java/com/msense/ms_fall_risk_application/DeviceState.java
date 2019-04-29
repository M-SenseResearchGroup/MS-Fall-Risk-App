package com.msense.ms_fall_risk_application;
// Class that initializes all fields before they are populated

import android.bluetooth.BluetoothDevice;


class DeviceState {
    final BluetoothDevice btDevice;
    String xVal;
    String yVal;
    String zVal;
    boolean connecting;

    DeviceState(BluetoothDevice btDevice) {
        this.btDevice= btDevice;
        this.xVal = null;
        this.yVal = null;
        this.zVal = null;
    }

    @Override
    public boolean equals(Object obj) {

        return (obj == this) ||
                ((obj instanceof DeviceState) && btDevice.equals(((DeviceState) obj).btDevice));
    }
}