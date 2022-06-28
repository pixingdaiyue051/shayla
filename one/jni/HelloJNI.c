#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "HelloJNI.h"

// #include <android/log.h>
// #define LOG_TAG "System.out"
// #define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
// #define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

jstring Java_HelloJNI_test__Ljava_lang_String_2(JNIEnv *env, jobject o, jstring jstr)
{

  char* rtn = NULL;
  jclass clsstring = (*env)->FindClass(env, "java/lang/String");
  jstring strencode = (*env)->NewStringUTF(env,"UTF-8");
  jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
  jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode); // String.getByte("UTF-8");
  jsize alen = (*env)->GetArrayLength(env, barr);
  jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
  if(alen > 0) 
  {
        rtn = (char*)malloc(alen+1); //多出一位是c语言字符串结束符\0
        memcpy(rtn, ba, alen);
        rtn[alen]=0;
  }
  (*env)->ReleaseByteArrayElements(env, barr, ba, 0);
  printf("输入%s\n", rtn);
  return NULL;
}

jint Java_HelloJNI_test__I(JNIEnv *e, jobject o, jint ji)
{
  printf("输入:%d\n", ji);
  return 0;
}

void Java_HelloJNI_ctime(JNIEnv *e, jobject o)
{
  time_t now;
  struct tm *tm_now;
  time(&now);
  tm_now = localtime(&now);
  printf("%d-%d-%d %d:%d:%d\n",tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
}