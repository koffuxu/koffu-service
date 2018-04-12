#define LOG_TAG "libbbtmanager_jni"
#include "utils/Log.h"

#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <utils/threads.h>
#include "jni.h"
#include "JNIHelp.h"
#include "android_runtime/AndroidRuntime.h"
#include "android_runtime/android_view_Surface.h"
#include "utils/Errors.h"  // for status_t
#include "utils/KeyedVector.h"
#include "utils/String8.h"
#include "sys/types.h"

#include <binder/Parcel.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

#include "IBbtManagerService.h"

using namespace android;

static jint
android_letvmanager_LetvManager_native_getTestValue(JNIEnv *env, jobject thiz, jint x, jint y)
{
	int ret;
	sp<IServiceManager> sm = defaultServiceManager();
	sp<IBinder> binder;
	binder = sm->checkService(String16("bbtmanager"));
	if (binder == 0) {
		ALOGE("can't get BbtManager service!\n");
		return -1;
	}
	const sp<IBbtManagerService>& service(interface_cast<IBbtManagerService>(binder));
	ret = service->add(x,y);
	return ret;
}

static jint
android_letvmanager_LetvManager_native_setLedStatus(JNIEnv *env, jobject thiz, jint a, jint b, jint c, jint d)
{
	int ret;
	sp<IServiceManager> sm = defaultServiceManager();
	sp<IBinder> binder;
	binder = sm->checkService(String16("bbtmanager"));
	if (binder == 0) {
		ALOGE("can't get BbtManager service!\n");
		return -1;
	}
	const sp<IBbtManagerService>& service(interface_cast<IBbtManagerService>(binder));
	ret = service->setLedStatus(a,b,c,d);
	return ret;
}


static JNINativeMethod gMethods[] = {
	{"_getTestValue", "(II)I", (void *)android_letvmanager_LetvManager_native_getTestValue},
	{"_setLedStatus", "(IIII)I", (void *)android_letvmanager_LetvManager_native_setLedStatus},
};

static const char* const kClassPathName = "com/android/bbtmanager/BbtManager";
static int register_android_bbtmanager_BbtManager(JNIEnv *env)
{
	return AndroidRuntime::registerNativeMethods(env, kClassPathName, gMethods, NELEM(gMethods));
}

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	JNIEnv* env = NULL;
	jint result = -1;

	if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
		ALOGE("ERROR: GetEnv failed\n");
		goto bail;
	}
	assert(env != NULL);

	if (register_android_bbtmanager_BbtManager(env) < 0) {
		ALOGE("ERROR: LetvManager native registration failed\n");
		goto bail;
	}

	/* success -- return valid version number */
	result = JNI_VERSION_1_4;
bail:
	return result;
}
