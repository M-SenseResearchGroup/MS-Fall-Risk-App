package com.msense.ms_fall_risk_application;
// in between page to confirm connection process (likely unnecessary)


import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class Activity_ConnectionPage extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity__connection_page);
        Log.i("metawear","chyea");
    }
    public void toSensorConnection(View view) {
        Intent intent = new Intent(this, MainActivity.class);
        Log.i("metawear","chyea1");
        startActivity(intent);
    }
}
