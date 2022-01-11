#include <jni.h>
//#include "tensorflow/lite/c/c_api.h"
#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/model.h"
#include "tensorflow/lite/builtin_op_data.h"
#include "edgetpu_c.h"
#include "tensorflow/lite/tools/gen_op_registration.h"

#include <opencv2/opencv.hpp>
#include <android/log.h>
#define  LOG_TAG    "NDK_TEST"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace cv;

uint8_t face_image[sizeof(uint8_t)*320*320*3];

std::unique_ptr<tflite::Interpreter> interpreter_edge;
std::unique_ptr<tflite::FlatBufferModel> model;
tflite::ops::builtin::BuiltinOpResolver resolver;

extern "C"
JNIEXPORT void JNICALL
Java_com_example_opencv_1test4_MainActivity_AI_1INIT(JNIEnv *env, jobject thiz) {

    char strBuffer[500] = { 0, };
    char *pstrBuffer = NULL;

    pstrBuffer = getcwd(pstrBuffer,500);

    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "%s",pstrBuffer);

    model = tflite::FlatBufferModel::BuildFromFile("/data/tflite/gender/fourteen.tflite");
    tflite::InterpreterBuilder(*model, resolver)(&interpreter_edge);



    size_t num_devices;
    std::unique_ptr<edgetpu_device, decltype(&edgetpu_free_devices)> devices(edgetpu_list_devices(&num_devices), &edgetpu_free_devices);

        __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "tpu_num : %d\r\n",num_devices);

    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "DEBUG1\r\n");

    const auto &device = devices.get()[0];

    auto* delegate = edgetpu_create_delegate(device.type, device.path, nullptr, 0);


    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "DEBUG2\r\n");


    interpreter_edge->ModifyGraphWithDelegate(delegate);
    //interpreter_edge->ModifyGraphWithDelegate(delegate);

    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "DEBUG3\r\n");

    interpreter_edge->SetNumThreads(1);

    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "DEBUG4\r\n");

    interpreter_edge->AllocateTensors();


    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "DEBUG5\r\n");


}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_opencv_1test4_MainActivity_AI_1RUN(JNIEnv *env, jobject thiz, jlong mat_addr_input,
                                                    jlong mat_addr_result) {
    Mat &matInput = *(Mat *)mat_addr_input;
    Mat &matResult = *(Mat *)mat_addr_result;
    Mat frame;

    cvtColor(matInput, matResult, COLOR_RGBA2GRAY);
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "matInput.rows : %d,matInput.cols: %d\r\n",matInput.rows,matInput.cols);

    resize(matInput,frame, Size(320, 320));

    for (int row = 0; row < frame.rows; row++)
    {
        uchar* p_data = matInput.ptr<uchar>(row);
        for (int col = 0; col < frame.cols; col++)
        {
            face_image[row*320*3+col*3+2]=p_data[col * 3 + 0];
            face_image[row*320*3+col*3+1]=p_data[col * 3 + 1];
            face_image[row*320*3+col*3+0]=p_data[col * 3 + 2];
        }
    }
//
//    TfLiteTensor* input_tensor =
//            TfLiteInterpreterGetInputTensor(interpreter, 0);
//
//    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "TfLiteInterpreterGetInputTensor(interpreter, 0);\r\n");
//
//    TfLiteTensorCopyFromBuffer(input_tensor, face_image,
//                               320*320*3);
//
//    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "TfLiteTensorCopyFromBuffer\r\n");
//
//    TfLiteInterpreterInvoke(interpreter);
//
//    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "TfLiteInterpreterInvoke(interpreter);\r\n");
//
//    float num[100];
//
//    const TfLiteTensor* output_tensor =
//        TfLiteInterpreterGetOutputTensor(interpreter, 3);
//    TfLiteTensorCopyToBuffer(output_tensor, (void *)num,sizeof(float));
//
//    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "num %f\r\n",num[0]);


}