LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	com_android_bbtmanager_BbtManager.cpp

LOCAL_C_INCLUDES += \
	$(JNI_H_INCLUDE) \
	vendor/agpc/frameworks/bbtmanager/include

LOCAL_SHARED_LIBRARIES := \
	libandroid_runtime \
	libcutils \
	libnativehelper \
	libutils \
	libui \
	libbinder \
	libbbtmanager

ifeq ($(WITH_MALLOC_LEAK_CHECK),true)
	LOCAL_CFLAGS += -DMALLOC_LEAK_CHECK
endif

LOCAL_MODULE:= libbbtmanager_jni
LOCAL_MODULE_TAGS:= optional
include $(BUILD_SHARED_LIBRARY)
