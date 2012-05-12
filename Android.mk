LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	main.cpp
    
LOCAL_STATIC_LIBRARIES := libminui_fonttest libpixelflinger_static libpng libz libft2
LOCAL_STATIC_LIBRARIES += libstdc++ libc libcutils libm

LOCAL_C_INCLUDES +=\
    external/libpng \
    external/zlib \
    external/libtouchui \
    external/freetype/include

LOCAL_MODULE := fonttest
LOCAL_MODULE_TAGS := optional
LOCAL_FORCE_STATIC_EXECUTABLE := true

include $(BUILD_EXECUTABLE)


#####################################
# Include minui

include $(call all-makefiles-under,$(LOCAL_PATH))

