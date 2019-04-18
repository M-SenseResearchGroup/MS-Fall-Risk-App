package com.msense.ms_fall_risk_application;
//This is the first page you seen on launch

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class Main2Activity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        Log.i("metawear","Launch:  App launched");
    }

    public void toConnectionPage(View view) {

        Intent intent = new Intent(this, MainActivity.class );
        startActivity(intent);
    }

}