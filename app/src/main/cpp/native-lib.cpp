//#include <jni.h>
//#include <android/log.h>
//#include <opencv2/opencv.hpp>

#define  LOG_TAG    "NDK_TEST"

//using namespace cv;

//extern "C"
//JNIEXPORT void JNICALL
//Java_com_example_opencv_1test4_MainActivity_AI_1RUN(JNIEnv *env, jobject thiz,
//                                                    jlong mat_addr_input) {
//    Mat &matInput = *(Mat *)mat_addr_input;
//}

//extern "C"
//JNIEXPORT void JNICALL
//Java_com_example_opencv_1test4_MainActivity_ConvertRGBtoGray(JNIEnv *env, jobject thiz,
//                                                             jlong mat_addr_input,
//                                                             jlong mat_addr_result) {
//    Mat &matInput = *(Mat *)mat_addr_input;
//    Mat &matResult = *(Mat *)mat_addr_result;
//
//    cvtColor(matInput, matResult, COLOR_RGBA2GRAY);
//
//    test_num++;
//
//    if(test_num<10)
//    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "work%d\r\n",test_num);
//
//    // TODO: implement ConvertRGBtoGray()
//}

//extern "C"
//JNIEXPORT void JNICALL
//Java_com_example_opencv_1test4_MainActivity_tensorflow_1lite_1init(JNIEnv *env, jobject thiz) {
//
//    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "tensorflow_lite_init\r\n");
//}
//
//
//
//extern "C"
//JNIEXPORT void JNICALL
//Java_com_example_opencv_1test4_MainActivity_tensorflow_1lite_1run(JNIEnv *env, jobject thiz,
//                                                                  jlong mat_addr_input) {
//    Mat &matInput = *(Mat *)mat_addr_input;
//}