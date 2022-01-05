# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

#define __ANDROID__
set(pathPROJECT /home/lsh/android_opencv_ndk) # 수정필요
set(pathOPENCV ${pathPROJECT}/opencv)
set(pathLIBOPENCV_JAVA ${pathOPENCV}/native/libs/${ANDROID_ABI}/libopencv_java4.so)


set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")


set(EDGETPUDIR /home/lsh/edgetpu/libedgetpu/)
set(BUILDROOT /home/lsh/work1234/docker_home/home/libedgetpu/) # 수정필요
set(BUILDDIR ${BUILDROOT}/out/home/libedgetpu/)
set(TFROOT /home/lsh/work1234/docker_home/home/tensorflow)
set(FLATBUFFERS ${TFROOT}/tensorflow/lite/tools/make/downloads/flatbuffers/include/)
set(ABLS /home/lsh/android_opencv_ndk/app/src/main/cpp/abseil-cpp/)
set(USB /home/lsh/work1234/docker_home/home/libusb-1.0.24/install/include/)



include_directories(
        ${pathOPENCV}/native/jni/include

        ${EDGETPUDIR}
        ${BUILDROOT}
        ${BUILDDIR}
        ${TFROOT}
        ${FLATBUFFERS}
        ${ABLS}
        ${USB}
        )

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        z
        log )


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
                ${pathPROJECT}/app/src/main/cpp/tensorflow.cpp)

#add_library( # Sets the name of the library.
#        tensorflow_face
#
#        # Sets the library as a shared library.
#        SHARED
#
#        # Provides a relative path to your source file(s).
#        ${pathPROJECT}/app/src/main/cpp/tensorflow_face.cpp )


add_library( lib_opencv SHARED IMPORTED )

add_library(edgetpu SHARED
       ${BUILDROOT}/api/allocated_buffer.cc                                    #LogMessageFatal
       ${BUILDROOT}/api/buffer.cc                                             #HandleInvalidStatusCtorArg
        ${BUILDROOT}/api/driver_options_helper.cc                               #ok
       ${BUILDROOT}/api/layer_information.cc                                   #LogMessageFatal
       ${BUILDROOT}/api/tensor_util.cc                                         #CheckOpMessageBuilder
       ${BUILDROOT}/api/watchdog.cc                                            #internal_statusor
       ${BUILDROOT}/driver/aligned_allocator.cc                                #CheckOpMessageBuilder
       ${BUILDROOT}/driver/allocator.cc                                        #AllocatedBuffer
       ${BUILDROOT}/driver/beagle/beagle_kernel_top_level_handler.cc           #LogMessage
       ${BUILDROOT}/driver/beagle/beagle_pci_driver_provider.cc                #EnumerateSysfs
        ${BUILDROOT}/driver/beagle/beagle_pci_driver_provider_linux.cc
        ${BUILDROOT}/driver/beagle/beagle_top_level_handler.cc
        ${BUILDROOT}/driver/beagle/beagle_top_level_interrupt_manager.cc
        ${BUILDROOT}/driver/beagle/beagle_usb_driver_provider.cc
        ${BUILDROOT}/driver/device_buffer.cc
        ${BUILDROOT}/driver/device_buffer_mapper.cc
        ${BUILDROOT}/driver/dma_chunker.cc
        ${BUILDROOT}/driver/dma_info.cc
        ${BUILDROOT}/driver/dma_info_extractor.cc
        ${BUILDROOT}/driver/driver.cc
        ${BUILDROOT}/driver/driver_factory.cc
        ${BUILDROOT}/driver/driver_factory_default.cc
        ${BUILDROOT}/driver/executable_util.cc
        ${BUILDROOT}/driver/instruction_buffers.cc
        ${BUILDROOT}/driver/interrupt/grouped_interrupt_controller.cc
        ${BUILDROOT}/driver/interrupt/interrupt_controller.cc
        ${BUILDROOT}/driver/interrupt/top_level_interrupt_manager.cc
        ${BUILDROOT}/driver/kernel/kernel_coherent_allocator.cc
        ${BUILDROOT}/driver/kernel/kernel_event_handler.cc
        ${BUILDROOT}/driver/kernel/kernel_interrupt_handler.cc
        ${BUILDROOT}/driver/kernel/kernel_mmu_mapper.cc
        ${BUILDROOT}/driver/kernel/kernel_registers.cc
        ${BUILDROOT}/driver/kernel/linux/kernel_coherent_allocator_linux.cc
        ${BUILDROOT}/driver/kernel/linux/kernel_event_handler_linux.cc
        ${BUILDROOT}/driver/kernel/linux/kernel_event_linux.cc
        ${BUILDROOT}/driver/kernel/linux/kernel_registers_linux.cc
        ${BUILDROOT}/driver/memory/buddy_address_space.cc
        ${BUILDROOT}/driver/memory/buddy_allocator.cc
        ${BUILDROOT}/driver/memory/dual_address_space.cc
        ${BUILDROOT}/driver/memory/mmio_address_space.cc
        ${BUILDROOT}/driver/memory/mmu_mapper.cc
        ${BUILDROOT}/driver/memory/nop_address_space.cc
        ${BUILDROOT}/driver/mmio/coherent_allocator.cc
        ${BUILDROOT}/driver/mmio_driver.cc
        ${BUILDROOT}/driver/package_registry.cc
        ${BUILDROOT}/driver/package_verifier.cc
        ${BUILDROOT}/driver/real_time_dma_scheduler.cc
        ${BUILDROOT}/driver/registers/registers.cc
        ${BUILDROOT}/driver/request.cc
        ${BUILDROOT}/driver/run_controller.cc
        ${BUILDROOT}/driver/scalar_core_controller.cc
        ${BUILDROOT}/driver/single_queue_dma_scheduler.cc
        ${BUILDROOT}/driver/single_tpu_request.cc
        ${BUILDROOT}/driver/usb/libusb_options_default.cc
        ${BUILDROOT}/driver/usb/local_usb_device.cc
        ${BUILDROOT}/driver/usb/usb_dfu_commands.cc
        ${BUILDROOT}/driver/usb/usb_dfu_util.cc
        ${BUILDROOT}/driver/usb/usb_driver.cc
        ${BUILDROOT}/driver/usb/usb_io_request.cc
        ${BUILDROOT}/driver/usb/usb_ml_commands.cc
        ${BUILDROOT}/driver/usb/usb_registers.cc
        ${BUILDROOT}/driver/usb/usb_standard_commands.cc
        ${BUILDROOT}/driver_shared/time_stamper/driver_time_stamper.cc
        ${BUILDROOT}/port/blocking_counter.cc
        ${BUILDROOT}/port/default/port_from_tf/logging.cc
        ${BUILDROOT}/port/default/port_from_tf/status.cc
        ${BUILDROOT}/port/default/port_from_tf/statusor.cc
        ${BUILDROOT}/port/default/stringprintf.cc
        ${BUILDROOT}/port/shared_mutex.cc
        ${BUILDROOT}/port/timer_portable.cc
        ${BUILDROOT}/tflite/custom_op.cc                                        #CheckOpMessageBuilder
        ${BUILDROOT}/tflite/custom_op_data.cc
        ${BUILDROOT}/tflite/custom_op_direct.cc
        ${BUILDROOT}/tflite/custom_op_user_data_direct.cc
        ${BUILDROOT}/tflite/edgetpu_c.cc
        ${BUILDROOT}/tflite/edgetpu_delegate_for_custom_op.cc
        ${BUILDROOT}/tflite/edgetpu_delegate_for_custom_op_tflite_plugin.cc
        ${BUILDROOT}/tflite/edgetpu_context_direct.cc
        ${BUILDROOT}/tflite/edgetpu_manager_direct.cc
        ${TFROOT}/tensorflow/lite/util.cc
        )

set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${pathLIBOPENCV_JAVA})


# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.



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

#target_link_libraries( # Specifies the target library.
#        rk
#        #/home/lsh/libedgetpu/out/direct/aarch64/libc.so
#        #/home/lsh/libedgetpu/out/direct/aarch64/ld-linux.so.3
#        #/home/lsh/libedgetpu/out/direct/aarch64/libld-linux.so
#        #/home/lsh/libedgetpu/out/direct/aarch64/libpthread.so
#        #/home/lsh/libedgetpu/out/direct/armv7a/libedgetpu.so.1
#        #/home/lsh/libedgetpu/out/direct/armv7a/libusb-1.0.so.0
#        ${log-lib}
#        )

add_subdirectory(abseil-cpp)

target_link_libraries(
        edgetpu
        absl::flags_internal
        absl::strings_internal
        absl::flags_reflection
        absl::flags_marshalling
        absl::hash
        absl::hashtablez_sampler
        absl::raw_hash_set
        absl::log_severity
        absl::str_format_internal
        absl::str_format
        absl::strings
        absl::synchronization
        /home/lsh/libusb/android/libs/armeabi-v7a/libusb1.0.so
        ${TFROOT}/bazel-bin/tensorflow/lite/c/libtensorflowlite_c.so
)

target_link_libraries( # Specifies the target library.
        tensorflow
        lib_opencv
        edgetpu
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