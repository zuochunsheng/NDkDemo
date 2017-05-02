package com.dell.android.activity;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import com.dell.android.R;
import com.dell.android.utils.JNI;
import com.dell.android.utils.JNICallback;

/*
* 传数据给c
* */
public class SecondActivity extends Activity {

    private TextView tvShow;
    public JNI jni;
    public JNICallback jniCallback;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
        tvShow = (TextView) findViewById(R.id.tv_show);



        jni = new JNI();
        jniCallback = new JNICallback(this);


    }

    public void click(View v){
        tvShow.setText(jni.add(3, 4)+"");
        Toast.makeText(getApplicationContext(), jni.add(3, 4)+"", Toast.LENGTH_SHORT).show();
    }

    public void passString(View v){
        tvShow.setText(jni.sayHelloInC("abcd"));
        Toast.makeText(getApplicationContext(), jni.sayHelloInC("abcd"), Toast.LENGTH_SHORT).show();
    }

    public void passIntArray(View v){
        int[] array = new int[]{1,2,3,4,5};
        jni.arrElementsIncrease(array);
        for(int i: array){
            Log.e("test", i+"");
        }
        tvShow.setText(jni.arrElementsIncrease(array)+"");
    }



    public void callbackvoid(View v){
        jniCallback.callbackvoidmethod();
    }

    public void callbackint(View v){
        jniCallback.callbackintmethod();
    }

    public void callbackString(View v){
        jniCallback.callbackStringmethod();
    }

    public void callbackshowtoast(View v){
        jniCallback.callbackShowToast();
    }

    public void callbackinstanceMethod(View v){
        jniCallback.getMethod();
    }


}
