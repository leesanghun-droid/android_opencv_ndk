# android_opencv_ndk
 PC 개발 환경
 
 리눅스
 
 OS : Ubuntu 20.04.3 LTS (focal)
 
 CPU : x86_64
 
 kernel : 5.11.0-43-generic
 
 
 안드로이드 스튜디오
 
 Android Studio Arctic Fox | 2020.3.1. Patch 4

 ndk opencv 개발환경
 
 ANDROID 8.0(Oreo)
 
 NDK(Side by side)
 
 Android Emulator 31.1.4
 
 Android SDK Platform-Tools 31.0.3
 
gradle:7.0.4 (or 7.0.2)

compileSdk 32

minSdk 26

targetSdk 32


Opencv SDK

name : opencv-4.1.0-android-sdk.zip

url : https://github.com/opencv/opencv/releases?page=3


--------------- opencv ndk 예제 -----------------------

(1) 동영상 ndk 셋팅 참조

	https://webnautes.tistory.com/1090
	
(2) 소스코드 참조

	https://webnautes.tistory.com/1054
	
	
	
	
------------------ android ndk 용 edgetpu 라이브러리 빌드 ---------------------


/**중요 사항
edgetpu usb 타입의 경우 안드로이드에서 해당 usb를 반드시 지원하는지는 먼저 체크 해야함. !!
adb shell dmesg  명령으로 usb 연결시 unsuport devices 라고 나오면 안되는 것임
**/


1. 소스코드 참조
   (1) android_opencv_ndk/app/src/main/cpp/CMakeLists.txt (가장중요)
   (2) abseil-cpp 라이브러리 cpp 폴더 내에서 git clone https://github.com/abseil/abseil-cpp.git
   (3) 



