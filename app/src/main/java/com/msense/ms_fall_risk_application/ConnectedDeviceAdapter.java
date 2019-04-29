package com.msense.ms_fall_risk_application;
// Array adapter hold information about each device connection as well as displaying it on the screen

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ProgressBar;
import android.widget.TextView;

public class ConnectedDeviceAdapter extends ArrayAdapter<DeviceState> {
    public ConnectedDeviceAdapter(Context context, int resource) {
        super(context, resource);
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder viewHolder;

        // Initalize an array item, by associating each element in layout
        if (convertView == null) {
            convertView= LayoutInflater.from(getContext()).inflate(R.layout.sensor_list, parent, false);

            viewHolder= new ViewHolder();
            viewHolder.deviceAddress= convertView.findViewById(R.id.status_mac_address);
            viewHolder.sensorLoco = convertView.findViewById(R.id.sensorLoco);
            viewHolder.xVal = convertView.findViewById(R.id.xVal);
            viewHolder.yVal = convertView.findViewById(R.id.yVal);
            viewHolder.zVal = convertView.findViewById(R.id.zVal);
            viewHolder.connectingText= convertView.findViewById(R.id.text_connecting);
            viewHolder.connectingProgress= convertView.findViewById(R.id.connecting_progress);

            convertView.setTag(viewHolder);
        } else {
            viewHolder= (ViewHolder) convertView.getTag();

        }


        DeviceState state= getItem(position);

        // Set position name based on order of connection, will be automated in a future version using calibration process
        if ( position <= 0 ){
            viewHolder.sensorLoco.setText("Medial Chest");
        }
        else {
            viewHolder.sensorLoco.setText("Anterior Thigh");
        }

        // set the last two characters of the device address to text view
        viewHolder.deviceAddress.setText(state.btDevice.getAddress().substring(15, 17));

        // holds state of connection for progress bar, once connected shows x, y, z components of accel
        if (state.connecting) {
            viewHolder.connectingProgress.setVisibility(View.VISIBLE);
            viewHolder.connectingText.setVisibility(View.VISIBLE);
        } else {
            viewHolder.xVal.setVisibility(View.VISIBLE);
            viewHolder.yVal.setVisibility(View.VISIBLE);
            viewHolder.zVal.setVisibility(View.VISIBLE);
            if (state.xVal != null) {
                viewHolder.xVal.setText(state.xVal);
                viewHolder.yVal.setText(state.yVal);
                viewHolder.zVal.setText(state.zVal);
            }
            viewHolder.connectingProgress.setVisibility(View.GONE);
            viewHolder.connectingText.setVisibility(View.GONE);
        }
        return convertView;
    }

    // Initializes the elements the view will be handling
    private class ViewHolder {
        TextView deviceAddress, connectingText, xVal, yVal, zVal, sensorLoco;
        ProgressBar connectingProgress;
    }


    // updates the elements that are not static (x,y,z components of accel)
    public void update(DeviceState newState) {
        int pos= getPosition(newState);
        if (pos == -1) {
            add(newState);
        } else {
            DeviceState current= getItem(pos);
            current.xVal= newState.xVal;
            current.yVal= newState.yVal;
            current.zVal= newState.zVal;
            notifyDataSetChanged();
        }
    }
}
