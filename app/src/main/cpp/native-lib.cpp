#include <jni.h>
#include <string>
#include <android/log.h>
#include <pthread.h>
#include <unistd.h>
#include <l_sdk.h>
#include <l_sdk_discover.h>



extern "C" JNIEXPORT jstring

JNICALL
Java_com_afscope_sloptoelectronic_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C" JNIEXPORT jint

JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_login(
        JNIEnv *env,
        jobject /* this */, jstring string) {
    std::string test = "{\n"
            "      \"cmd\": \"support,support_1,support_3,hello,hello_2,encrypt,system,ipv4,set_wireless\"\n"
            "}";

    __android_log_print(ANDROID_LOG_INFO, "login", "login.c_str()=%s", string);
//    sleep(3);
    int id = 0;
    jboolean jboolean1 = true;
    int ret = l_sdk_login(&id, env->GetStringUTFChars(string, &jboolean1));
    return ret;
//    if (0 == ret)
//    {
//        __android_log_print(ANDROID_LOG_INFO, "native", "login ok!,id=%d\n", id);
//
//        char* p_res = NULL;
//        if (0 == l_sdk_request(id, test.c_str(), &p_res))
//        {
//            __android_log_print(ANDROID_LOG_INFO, "native", "request ok!,res=%s\n", p_res);
//
//            l_sdk_free(p_res);
//        }
//    } else{
//        __android_log_print(ANDROID_LOG_INFO, "native", "login error!ret=%d\n", ret);
//    }
}
extern "C" JNIEXPORT jint
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_decOpen(
        JNIEnv *env,
        jobject /* this */) {

    return l_sdk_dec_open(100, "");
}

extern "C" JNIEXPORT jint
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_requestPicStream(
        JNIEnv *env,
        jobject /* this */) {
    std::string open_stream = "{\n"
            "      \"cmd\": \"open_stream\",\n"
            "      \"open_stream\": {\n"
            "            \"chnn\": 0, \n"
            "            \"idx\": 64\n"
            "      }\n"
            "}";

    char *p_res = NULL;
    return l_sdk_request(1000, open_stream.c_str(), &p_res);
}
extern "C" JNIEXPORT jbyteArray
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_getPicStream(
        JNIEnv *env,
        jobject /* this */) {

    jbyteArray jarray = NULL;
    l_md_buf_t *p_buf = NULL;
    l_sdk_md_clear(1000, 0, 64, 0);
    int state;
    int count = 0;
    while (true) {
        state = l_sdk_md_get(1000, 0, 64, 0, &p_buf);
        if (state == 0) {
            break;
        }
        if (count >= 60) {
            break;
        }
        usleep(50 * 1000);
        count++;
    }
    __android_log_print(ANDROID_LOG_INFO, "native", "state=%d\n", state);
    if (0 == state) {
        char *ptr = p_buf->p_buf + p_buf->start;
        int len = p_buf->f_v1.len;

        jbyte *by = (jbyte *) ptr;
        jarray = env->NewByteArray(len);
        env->SetByteArrayRegion(jarray, 0, len, by);
        //L_FMT_JPEG p_buf->f_v1.fmt



        l_sdk_md_buf_sub(p_buf);
    }

    return jarray;
}
extern "C" JNIEXPORT jint
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_decBind(
        JNIEnv *env,
        jobject /* this */) {

    return l_sdk_dec_bind(100, 1000, 0, 0, 0);
}
extern "C" JNIEXPORT jint
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_openWnd(
        JNIEnv *env,
        jobject /* this */) {

    return l_sdk_dec_open_wnd(100);
}
extern "C" JNIEXPORT jint
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_render(
        JNIEnv *env,
        jobject /* this */) {
//    l_md_data_t* p = NULL;
//    int i = l_sdk_dec_get_md_data(100, &p);
//    __android_log_print(ANDROID_LOG_INFO, "native", "l_sdk_dec_get_md_data=%d",i);
    return l_sdk_dec_render(100);
}
extern "C" JNIEXPORT jint
JNICALL
Java_com_afscope_sloptoelectronic_JfGLSurfaceView_getYuvMediaData(
        JNIEnv *env,
        jobject jobject1/* this */) {
    jclass jclazz = env->FindClass("com/afscope/sloptoelectronic/JfGLSurfaceView");

    jmethodID jmethod = env->GetMethodID(jclazz, "setYUVData", "(II[B[B[B)V");

//    jobject jobject1 = env->AllocObject(jclazz);
    l_md_data_t *p_res = NULL;
    int i = l_sdk_dec_get_md_data(100, &p_res);
    __android_log_print(ANDROID_LOG_INFO, "native", "l_sdk_dec_get_md_data=%d", i);
    if (i == 0) {
        jbyteArray y = env->NewByteArray(p_res->w * p_res->h);
        env->SetByteArrayRegion(y, 0, p_res->w * p_res->h, reinterpret_cast<const jbyte *>(p_res->p_y));
        jbyteArray u = env->NewByteArray(p_res->w * p_res->h / 4);
        env->SetByteArrayRegion(u, 0, p_res->w * p_res->h / 4, reinterpret_cast<const jbyte *>(p_res->p_u));
        jbyteArray v = env->NewByteArray(p_res->w * p_res->h / 4);
        env->SetByteArrayRegion(v, 0, p_res->w * p_res->h / 4, reinterpret_cast<const jbyte *>(p_res->p_v));

        env->CallVoidMethod(jobject1, jmethod, p_res->w, p_res->h, y, u, v);
        env->DeleteLocalRef(y);
        env->DeleteLocalRef(u);
        env->DeleteLocalRef(v);
        l_sdk_dec_free_md_data(p_res);
    }
    return i;
}
extern "C" JNIEXPORT jint
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_streamRequest(
        JNIEnv *env,
        jobject /* this */) {
    std::string open_stream = "{\n"
            "      \"cmd\": \"open_stream\",\n"
            "      \"open_stream\": {\n"
            "            \"chnn\": 0, \n"
            "            \"idx\": 0\n"
            "      }\n"
            "}";

    char *p_res = NULL;
    int ret = l_sdk_request(1000, open_stream.c_str(), &p_res);


    if (NULL != p_res) {
        __android_log_print(ANDROID_LOG_INFO, "native", "streamRequest1=%d", ret);
        __android_log_print(ANDROID_LOG_INFO, "native", "streamRequest2=%s\n", p_res);
        l_sdk_free(p_res);
    }

    return ret;
}
/**
     * 组播发现ip地址
     */
extern "C" JNIEXPORT jint
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_multicastOpen(
        JNIEnv *env,
        jobject /* this */) {
//打开组播
    return l_sdk_discover_open("");
}
extern "C" JNIEXPORT jint
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_multicastClose(
        JNIEnv *env,
        jobject /* this */) {
//关闭组播
    return l_sdk_discover_close();
}
extern "C" JNIEXPORT jint
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_multicastScanner(
        JNIEnv *env,
        jobject /* this */) {
//开始扫描
    return l_sdk_discover_run(true);
}
extern "C" JNIEXPORT jint
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_sdkInit(
        JNIEnv *env,
        jobject /* this */) {
//初始化同時開啓廣播
    int i = l_sdk_init("");
    l_sdk_discover_open("");
    l_sdk_discover_run(true);
    return i;
}
extern "C" JNIEXPORT jstring
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_getDeviceIp(
        JNIEnv *env,
        jobject /* this */) {
//获取ip地址list
    char *p_res = NULL;
    l_sdk_discover_get_devs(&p_res);
    return env->NewStringUTF(p_res);
}
extern "C" JNIEXPORT void
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_sdkQuit(
        JNIEnv *env,
        jobject /* this */) {
    l_sdk_logout(1000);
    l_sdk_quit();
}
//客户端发起固件升级
extern "C" JNIEXPORT jint
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_clientRequestUpdate(
        JNIEnv *env,
        jobject /* this */, jstring path) {
    char *rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("utf-8");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(path, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    char *p_res = NULL;
    int state;
    state = l_sdk_request(0, rtn, &p_res);
    __android_log_print(ANDROID_LOG_INFO, "native", "clientRequestUpdate=%sresult=%s", rtn, p_res);
    return state;
}

static int cb_l_sdk_media(void* p_obj, int protocol, int id, int chnn, int idx, int md_id, l_md_buf_t* p_data)
{
    char* data= p_data->p_buf;
    if (data!=NULL){
        __android_log_print(ANDROID_LOG_INFO, "native", "cb_l_sdk_media");
    }
}


extern "C" JNIEXPORT jint
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_mediaListener(
        JNIEnv *env,
        jobject /* this */) {
    char* name = "mediaListener";
    int code = l_sdk_md_add_listener(name, cb_l_sdk_media, NULL);
    return code;
}


extern "C" JNIEXPORT jint
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_startRecord(
        JNIEnv *env,
        jobject /* this */,jstring string) {
//    jboolean jboolean1 = true;
//    const char *path = env->GetStringUTFChars(string, &jboolean1);
//    fr_h264_t *pT = fr_h264_open(path, 0);
//    char* p_h264=NULL;
//    int frame_type=0;
//    fr_h264_key_t* p_key=NULL;
//    int i = fr_h264_get_next(pT, &p_h264, &frame_type, p_key);
//    char *data = pT->p_data;
//    if (data!=NULL){
//        __android_log_print(ANDROID_LOG_INFO, "native", "cb_l_sdk_media=%d",i);
//    }
    return 0;
}
extern "C" JNIEXPORT jint
JNICALL
Java_com_afscope_sloptoelectronic_OptoelecJinV2_stopRecord(
        JNIEnv *env,
        jobject /* this */) {

}