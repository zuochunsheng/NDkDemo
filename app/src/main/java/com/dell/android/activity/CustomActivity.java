package com.dell.android.activity;

import android.app.Activity;
import android.os.Bundle;

import com.dell.android.R;

public class CustomActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_custom);

    }
}
