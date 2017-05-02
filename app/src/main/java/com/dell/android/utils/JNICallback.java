package com.dell.android.utils;

import android.content.Context;
import android.util.Log;
import android.widget.Toast;

import static android.content.ContentValues.TAG;
import static android.icu.lang.UCharacter.GraphemeClusterBreak.L;

/**
 * Created by DELL on 2017/3/9.
 */

public class JNICallback {
    static{
        System.loadLibrary("hello-l2c");
    }
    private Context mContext;
    public JNICallback(Context context){
        mContext = context;
    }
    public native void callbackvoidmethod();

    public native void callbackintmethod();

    public native void callbackStringmethod();

    public native void callbackShowToast();
    //C调用java空方法
    public void helloFromJava(){
        Log.e("tag", "helloFromJava: ++c ");
        //System.out.println("hello from java");
    }
    //C调用java中的带两个int参数的方法
    public int add(int x,int y) {
        Log.e("tag", "add: ++c ");
        return x+y;
    }
    //C调用java中参数为string的方法
    public void printString(String s){
        //System.out.println(s);
        Log.e("tag", "printString: ++c ");
    }

    public void showToast(String s){
       // Toast.makeText(mContext, s, Toast.LENGTH_SHORT).show();
        Log.e("tag", "showToast: ++c ");
    }

    public native void getMethod();
    public String instanceMethod(){
        return "Instance Method";
    }
    public static String staticMethod(){
        return "static Method";
    }

}
