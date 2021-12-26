# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

set(pathPROJECT /home/lsh/android_opencv_ndk) # 수정필요
set(pathOPENCV ${pathPROJECT}/opencv)
set(pathTensorflow /home/lsh/work123/tensorflow/)
set(pathFlatbuffers ${pathTensorflow}/tensorflow/lite/tools/make/downloads/flatbuffers/include)
set(pathAbsl ${pathTensorflow}/tensorflow/lite/tools/make/downloads/absl)
set(pathLIBOPENCV_JAVA ${pathOPENCV}/native/libs/${ANDROID_ABI}/libopencv_java4.so)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

include_directories(
        ${pathOPENCV}/native/jni/include
        ${pathTensorflow}
        ${pathFlatbuffers}
        ${pathAbsl}
        )


# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

#add_library( # Sets the name of the library.
#        native-lib
#
#        # Sets the library as a shared library.
#        SHARED
#
#        # Provides a relative path to your source file(s).
#        ${pathPROJECT}/app/src/main/cpp/native-lib.cpp )

add_library( # Sets the name of the library.
                tensorflow

                # Sets the library as a shared library.
                SHARED

                # Provides a relative path to your source file(s).
                ${pathPROJECT}/app/src/main/cpp/tensorflow.cpp )

#add_library( # Sets the name of the library.
#        tensorflow_face
#
#        # Sets the library as a shared library.
#        SHARED
#
#        # Provides a relative path to your source file(s).
#        ${pathPROJECT}/app/src/main/cpp/tensorflow_face.cpp )

add_library( lib_opencv SHARED IMPORTED )

set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${pathLIBOPENCV_JAVA})


# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        z
        log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

#target_link_libraries( # Specifies the target library.
#        tensorflow_face
#        ${pathTensorflow}/bazel-bin/tensorflow/lite/c/libtensorflowlite_c.so
#        ${log-lib}
#        )
#
#target_link_libraries( # Specifies the target library.
#        tensorflow
#        tensorflow_face
#        )

target_link_libraries( # Specifies the target library.
        tensorflow
        lib_opencv
        # Links the target library to the log library
        # included in the NDK.
        ${pathTensorflow}/bazel-bin/tensorflow/lite/c/libtensorflowlite_c.so
        /home/lsh/edgetpu/libedgetpu/throttled/armv7a/libedgetpu.so.1
        /home/lsh/edgetpu/libedgetpu/throttled/armv7a/libedgetpu.so.1.0
        ${log-lib}
        )




























#
#
## For more information about using CMake with Android Studio, read the
## documentation: https://d.android.com/studio/projects/add-native-code.html
#
## Sets the minimum version of CMake required to build the native library.
#
#cmake_minimum_required(VERSION 3.10.2)
#
## Declares and names the project.
#
#project("opencv_test4")
#
## Creates and names a library, sets it as either STATIC
## or SHARED, and provides the relative paths to its source code.
## You can define multiple libraries, and CMake builds them for you.
## Gradle automatically packages shared libraries with your APK.
#
#add_library( # Sets the name of the library.
#        opencv_test4
#
#        # Sets the library as a shared library.
#        SHARED
#
#        # Provides a relative path to your source file(s).
#        native-lib.cpp)
#
## Searches for a specified prebuilt library and stores the path as a
## variable. Because CMake includes system libraries in the search path by
## default, you only need to specify the name of the public NDK library
## you want to add. CMake verifies that the library exists before
## completing its build.
#
#find_library( # Sets the name of the path variable.
#        log-lib
#
#        # Specifies the name of the NDK library that
#        # you want CMake to locate.
#        log)
#
## Specifies libraries CMake should link to your target library. You
## can link multiple libraries, such as libraries you define in this
## build script, prebuilt third-party libraries, or system libraries.
#
#target_link_libraries( # Specifies the target library.
#        opencv_test4
#
#        # Links the target library to the log library
#        # included in the NDK.
#        ${log-lib})