LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	BbtManagerServiceTest.cpp

LOCAL_SHARED_LIBRARIES := \
	libbbtmanagerservice \
	libcutils \
	libutils  \
	libbinder 

LOCAL_C_INCLUDES += \
	vendor/agpc/frameworks/bbtmanager/include

LOCAL_MODULE:= bbtservice-test

LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)
