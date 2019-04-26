package com.msense.ms_fall_risk_application;

import android.content.Context;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

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
//            viewHolder.deviceName= convertView.findViewById(R.id.status_device_name);
            viewHolder.deviceAddress= convertView.findViewById(R.id.status_mac_address);

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

        final String deviceName= state.btDevice.getName();

//        if (deviceName != null && deviceName.length() > 0) {
//            viewHolder.deviceName.setText(deviceName);
//        } else {
//            viewHolder.deviceName.setText(R.string.label_unknown_device);
//        }
        viewHolder.deviceAddress.setText(state.btDevice.getAddress());

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
//        viewHolder.button.setTag(position);


//        viewHolder.button.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                Toast.makeText(getContext(), "Row " + position + " was clicked!", Toast.LENGTH_SHORT).show();
//                Log.i("metawear","why");
//            }
//        });



        return convertView;
    }

    private class ViewHolder {
        TextView deviceAddress, connectingText, xVal, yVal, zVal;
//        Button button;

        ProgressBar connectingProgress;


    }


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
