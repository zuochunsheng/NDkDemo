//
// Created by DELL on 2017/3/9.
//

#include <jni.h>
#include <stdlib.h>
#include <stdio.h>
#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

/**
 * 把一个jstring转换成一个c语言的char* 类型.
 */
char* _JString2CStr(JNIEnv* env, jstring jstr) {
    char* rtn = NULL;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env,"GB2312");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode); // String .getByte("GB2312");
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if(alen > 0) {
        rtn = (char*)malloc(alen+1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen]=0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba,0);
    return rtn;
}



JNIEXPORT void JNICALL
Java_com_dell_android_utils_JNICallback_callbackvoidmethod(JNIEnv *env, jobject clazz) {

//jclass      (*FindClass)(JNIEnv*, const char*);
    //① 获取字节码对象
    jclass claz = (*env)->FindClass(env,"com/dell/android/utils/JNICallback");
    //②获取Method对象
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID methodID =(*env)->GetMethodID(env,claz,"helloFromJava","()V");
    //③通过字节码对象创建一个Object
    //④通过对象调用方法
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    LOGD("result void");
    (*env)->CallVoidMethod(env,clazz,methodID);

}

JNIEXPORT void JNICALL Java_com_dell_android_utils_JNICallback_callbackintmethod(JNIEnv *env, jobject clazz) {

//① 获取字节码对象
    jclass claz =(*env)->FindClass(env,"com/dell/android/utils/JNICallback");
    //②获取Method对象
    jmethodID methodID = (*env)->GetMethodID(env,claz,"add","(II)I");
    //jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
    int result =(*env)->CallIntMethod(env,clazz,methodID,3,4);
    LOGD("int  result = %d",result);
}
JNIEXPORT void JNICALL Java_com_dell_android_utils_JNICallback_callbackStringmethod(JNIEnv *env, jobject clazz) {

//① 获取字节码对象
    jclass claz =(*env)->FindClass(env,"com/dell/android/utils/JNICallback");
    //② 获取Method对象
    jmethodID methodid =(*env)->GetMethodID(env,claz,"printString","(Ljava/lang/String;)V");//(Ljava/lang/String;)V

    jstring result =(*env)->NewStringUTF(env,"hello from c");
    (*env)->CallVoidMethod(env,clazz,methodid,result);

}

JNIEXPORT void JNICALL Java_com_dell_android_utils_JNICallback_callbackShowToast(JNIEnv *env, jobject clazz) {
    // TODO

    jclass claz =(*env)->FindClass(env,"com/dell/android/utils/JNICallback");
    jmethodID methodid =(*env)->GetMethodID(env,claz,"showToast","(Ljava/lang/String;)V");
    //jobject     (*AllocObject)(JNIEnv*, jclass);
    //通过字节码对象创建 java对象 在这儿就是创建了mainactivity的对象
    //jobject obj =(*env)->AllocObject(env,claz);
    jstring result =(*env)->NewStringUTF(env,"hello from c");
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    (*env)->CallVoidMethod(env,clazz,methodid,result);

}



JNIEXPORT void JNICALL Java_com_dell_android_utils_JNICallback_getMethod(JNIEnv *env, jobject clazz) {
    jclass claz;
    jmethodID instanceMethodID;
    jmethodID staticMethodID;
    jstring instanceMethodResult;
    jstring staticMethodResult;
    claz = (*env)->GetObjectClass(env, clazz);
//  claz = (*env)->FindClass(env,"com/example/jni/JavaClass");
    instanceMethodID = (*env)->GetMethodID(env, claz, "instanceMethod",
                                           "()Ljava/lang/String;");
    staticMethodID = (*env)->GetStaticMethodID(env, claz, "staticMethod",
                                               "()Ljava/lang/String;");
    instanceMethodResult = (*env)->CallObjectMethod(env,clazz,instanceMethodID);
    staticMethodResult = (*env)->CallStaticObjectMethod(env,claz,staticMethodID);
    //jstring转为C字符串然后打印出来
    const jbyte* str1;
    const jbyte* str2;
    str1 = (*env)->GetStringUTFChars(env, instanceMethodResult, 0);
    str2 = (*env)->GetStringUTFChars(env, staticMethodResult, 0);
    LOGI("the string is :%s", str1);
    LOGI("the string is :%s", str2);

}


