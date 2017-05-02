package com.dell.android.utils;

/**
 * Created by DELL on 2017/3/9.
 *
 */

public class JNI {

    static{
        System.loadLibrary("hello-l2c");
    }
    //传递两个int类型的变量给C 让C加一下返回来
    public native int add(int x, int y);
    //传递String类型的参数给C 处理一下返回来
    public native String sayHelloInC(String s);
    //传递int类型的数组给C
    public native int[] arrElementsIncrease(int[] intArray);

}
