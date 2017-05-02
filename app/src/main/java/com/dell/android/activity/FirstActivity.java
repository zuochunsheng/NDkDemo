package com.dell.android.activity;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

import com.dell.android.R;

public class FirstActivity extends Activity {

    private TextView tvShow;
    static {
        System.loadLibrary("hello-l2c");
    }

    private native String stringFromJNI();



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_first);
        tvShow = (TextView) findViewById(R.id.tv_show);

        Toast.makeText(this, stringFromJNI(), Toast.LENGTH_LONG).show();

        tvShow.setText(stringFromJNI());
    }
}
