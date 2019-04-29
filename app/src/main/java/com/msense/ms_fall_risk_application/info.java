package com.msense.ms_fall_risk_application;
// Class creates information modal

import android.app.Activity;
import android.os.Bundle;
import android.util.DisplayMetrics;

public class info extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);

        // attach view to class
        setContentView(R.layout.fragment_info);

        // set modal to be 4/5 width and 1/2 height of screen
        DisplayMetrics dm = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(dm);
        int width = dm.widthPixels;
        int height = dm.heightPixels;
        getWindow().setLayout((int)(width*.8),(int)(height*.5));

    }
}
