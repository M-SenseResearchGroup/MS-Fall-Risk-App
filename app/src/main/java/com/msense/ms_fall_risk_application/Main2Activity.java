package com.msense.ms_fall_risk_application;
// Contrary to the title of the activity, this is actually the first view you see on app launch

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class Main2Activity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // Attach the layout to this activity
        setContentView(R.layout.activity_main2);
        Log.i("metawear","Launch:  App launched");
    }

    // This is the method that starts the main activity class, which does the bluetooth connections & more
    public void toConnectionPage(View view) {
        Intent intent = new Intent(this, MainActivity.class );
        startActivity(intent);
    }

}