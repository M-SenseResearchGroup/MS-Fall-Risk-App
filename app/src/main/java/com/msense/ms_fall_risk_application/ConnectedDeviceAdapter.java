package com.msense.ms_fall_risk_application;

import android.content.Context;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ProgressBar;
import android.widget.RadioGroup;
import android.widget.TextView;

public class ConnectedDeviceAdapter extends ArrayAdapter<DeviceState> {
    public ConnectedDeviceAdapter(Context context, int resource) {
        super(context, resource);
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        Log.i("metawear","CDA View");
        ViewHolder viewHolder;

        if (convertView == null) {
            convertView= LayoutInflater.from(getContext()).inflate(R.layout.activity_calibration, parent, false);

            viewHolder= new ViewHolder();
            viewHolder.deviceAddress= convertView.findViewById(R.id.status_mac_address);
            viewHolder.deviceOrientation= convertView.findViewById(R.id.accelValue);

            convertView.setTag(viewHolder);
        } else {
            viewHolder= (ViewHolder) convertView.getTag();
        }

        DeviceState state= getItem(position);
        final String deviceName= state.btDevice.getName();

        if (deviceName != null && deviceName.length() > 0) {
            viewHolder.deviceName.setText(deviceName);
        } else {
            viewHolder.deviceName.setText(R.string.label_unknown_device);
        }
        viewHolder.deviceAddress.setText(state.btDevice.getAddress());

        if (state.connecting) {

            viewHolder.deviceOrientation.setVisibility(View.GONE);

        } else {
            viewHolder.deviceOrientation.setVisibility(View.VISIBLE);


            if (state.deviceOrientation != null) {
                viewHolder.deviceOrientation.setText(state.deviceOrientation);
            }




        }
        Log.i("metawear","CDA ViewEnd");
        return convertView;
    }

    private class ViewHolder {
        TextView deviceName, deviceAddress, deviceOrientation;


    }

    public void update(DeviceState newState) {
        int pos= getPosition(newState);
        Log.i("metawear","update");
        if (pos == -1) {
            add(newState);
        } else {
            Log.i("metawear","else");
            DeviceState current= getItem(pos);

            current.deviceOrientation= newState.deviceOrientation;
            notifyDataSetChanged();
        }
    }

}
