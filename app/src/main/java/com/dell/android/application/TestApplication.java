package com.dell.android.application;

import android.app.Application;

import com.dell.android.SdkManager;

/**
 * Created by DELL on 2017/4/28.
 */

public class TestApplication extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
      /*  if (BuildConfig.DEBUG) {
            Stetho.initializeWithDefaults(this);
        }*/
        SdkManager.init(this);

    }
}
