//#include "tensorflow/lite/c/c_api.h"
//#include <jni.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <cstdlib>
//#include <iostream>
//#include <android/log.h>
//#define  LOG_TAG    "NDK_TEST"
//
//
//TfLiteInterpreter* interpreter;
//uint8_t face_image[sizeof(uint8_t)*320*320*3];
//
//void face_init()
//{
//    //char * cStr = "face.tflite";
//    TfLiteModel* model = TfLiteModelCreateFromFile("face.tflite");
//
//    if (model == nullptr)
//        __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "model nullptr\r\n");
//
//    TfLiteInterpreterOptions* options = TfLiteInterpreterOptionsCreate();
//    TfLiteInterpreterOptionsSetNumThreads(options, 2);
//// Create the interpreter.
//    interpreter = TfLiteInterpreterCreate(model, options);
//    TfLiteInterpreterAllocateTensors(interpreter);
//}
//
//void face_run()
//{
//    TfLiteTensor* input_tensor =
//            TfLiteInterpreterGetInputTensor(interpreter, 0);
//    TfLiteTensorCopyFromBuffer(input_tensor, face_image,
//                               320*320*3 * sizeof(float));
//    TfLiteInterpreterInvoke(interpreter);
//}

/*
 *   model_ = TfLiteModelCreateFromFile(params_.model.c_str());
  options_ = TfLiteInterpreterOptionsCreate();

  interpreter_ = TfLiteInterpreterCreate(model_, options_);

  delegate_ = edgetpu_create_delegate(device.type, device.path, nullptr, 0);
  TfLiteInterpreterOptionsAddDelegate(options_, delegate_);
 */