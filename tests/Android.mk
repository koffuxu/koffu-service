LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	kfservicetest.cpp

LOCAL_SHARED_LIBRARIES := \
	libkfservice \
	libcutils \
	libutils  \
	libbinder 

LOCAL_MODULE:= test-kfservice

LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)
