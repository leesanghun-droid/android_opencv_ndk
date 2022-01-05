#include <jni.h>
#include "edgetpu_c.h"
#include "tensorflow/lite/c/c_api.h"
#include <opencv2/opencv.hpp>
#include <android/log.h>
#define  LOG_TAG    "NDK_TEST"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace cv;

uint8_t face_image[sizeof(uint8_t)*320*320*3];
TfLiteInterpreter* interpreter;

extern "C"
JNIEXPORT void JNICALL
Java_com_example_opencv_1test4_MainActivity_AI_1INIT(JNIEnv *env, jobject thiz) {

    char strBuffer[500] = { 0, };
    char *pstrBuffer = NULL;

    pstrBuffer = getcwd(pstrBuffer,500);

    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "%s",pstrBuffer);

    TfLiteModel* model = TfLiteModelCreateFromFile("/data/tflite/ssd_mobilenet_v2_face_quant_postprocess.tflite");
        if (model == nullptr) {
            __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "model nullptr");
        }else
        {
            __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "model load");
        }

    TfLiteInterpreterOptions* options = TfLiteInterpreterOptionsCreate();
// Create the interpreter.
    interpreter = TfLiteInterpreterCreate(model, options);


    size_t num_devices;
    std::unique_ptr<edgetpu_device, decltype(&edgetpu_free_devices)> devices(edgetpu_list_devices(&num_devices), &edgetpu_free_devices);
    const auto &device = devices.get()[0];
    TfLiteDelegate* delegate_ = edgetpu_create_delegate(device.type, device.path, nullptr, 0);
    TfLiteInterpreterOptionsAddDelegate(options, delegate_);

    TfLiteInterpreterAllocateTensors(interpreter);


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

    TfLiteTensor* input_tensor =
            TfLiteInterpreterGetInputTensor(interpreter, 0);
    TfLiteTensorCopyFromBuffer(input_tensor, face_image,
                               320*320*3);
    TfLiteInterpreterInvoke(interpreter);

    float num[100];

    const TfLiteTensor* output_tensor =
        TfLiteInterpreterGetOutputTensor(interpreter, 3);
    TfLiteTensorCopyToBuffer(output_tensor, (void *)num,sizeof(float));

    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "num %f\r\n",num[0]);


}