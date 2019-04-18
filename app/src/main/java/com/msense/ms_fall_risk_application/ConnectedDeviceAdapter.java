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
//        Log.i("metawear","CDA View");
        ViewHolder viewHolder;


        if (convertView == null) {
            convertView= LayoutInflater.from(getContext()).inflate(R.layout.sensor_list, parent, false);

            viewHolder= new ViewHolder();
            viewHolder.deviceName= convertView.findViewById(R.id.status_device_name);
            viewHolder.deviceAddress= convertView.findViewById(R.id.status_mac_address);
            viewHolder.deviceOrientation= convertView.findViewById(R.id.accelValue);

            viewHolder.connectingText= convertView.findViewById(R.id.text_connecting);
            viewHolder.connectingProgress= convertView.findViewById(R.id.connecting_progress);

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
            viewHolder.connectingProgress.setVisibility(View.VISIBLE);
            viewHolder.connectingText.setVisibility(View.VISIBLE);
            viewHolder.deviceOrientation.setVisibility(View.GONE);

        } else {
            viewHolder.deviceOrientation.setVisibility(View.VISIBLE);


            if (state.deviceOrientation != null) {
                viewHolder.deviceOrientation.setText(state.deviceOrientation);
            }



            viewHolder.connectingProgress.setVisibility(View.GONE);
            viewHolder.connectingText.setVisibility(View.GONE);
        }
//        Log.i("metawear","CDA ViewEnd");
        return convertView;
    }

    private class ViewHolder {
        TextView deviceName, deviceAddress, deviceOrientation, connectingText;

        ProgressBar connectingProgress;

    }

    public void update(DeviceState newState) {
        int pos= getPosition(newState);
//        Log.i("metawear","CDA: Device Selected 4"+pos);
//        Log.i("metawear","update");

        if (pos == -1) {
            add(newState);
        } else {
//            Log.i("metawear","else");
            DeviceState current= getItem(pos);

            current.deviceOrientation= newState.deviceOrientation;
            notifyDataSetChanged();
        }
    }
}
