LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := Demo
LOCAL_SRC_FILES := Demo.cpp
LOCAL_SRC_FILES += $(addprefix ../../source/,Game.cpp)
LOCAL_SRC_FILES += $(addprefix ../../source/,Player.cpp)
    
LOCAL_C_INCLUDES+=$(LOCAL_PATH)/../../source

include $(BUILD_SHARED_LIBRARY)
