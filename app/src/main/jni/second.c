//
// Created by DELL on 2017/3/9.
//日志
//
#include <stdlib.h>
#include <stdio.h>
#include <jni.h>
#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

jstring Java_com_dell_android_utils_NdkJniUtils_getCLanguageString( JNIEnv* env,jobject thiz ) {
    LOGI("info\n");
    LOGD("debug\n");
    return (*env)->NewStringUTF(env, "Hello World  from JNI---------util");
}

