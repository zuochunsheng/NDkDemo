package com.dell.android;

import android.content.Context;

import com.facebook.stetho.Stetho;

/**
 * Created by DELL on 2017/4/28.
 */

public class SdkManager {
    public static void init(Context context) {
        Stetho.initializeWithDefaults(context);
    }
}
