LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := Demo
LOCAL_SRC_FILES := Demo.cpp

include $(BUILD_SHARED_LIBRARY)
