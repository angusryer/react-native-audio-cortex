#include <jni.h>
#include "react-native-audio-cortex.h"

extern "C"
JNIEXPORT jint JNICALL
Java_com_audiocortex_AudioCortexModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return audiocortex::multiply(a, b);
}
