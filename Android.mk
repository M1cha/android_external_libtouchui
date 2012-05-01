LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
guiproject_local_path := $(LOCAL_PATH)

LOCAL_SRC_FILES := \
    main.cpp \
    threads/Thread.cpp \
    threads/RedrawThread.cpp \
    threads/EventThread.cpp \
    events/KeyEvent.cpp \
    events/TouchEvent.cpp \
    Context.cpp \
    UiMain.cpp \
    Activity.cpp \
    View.cpp \
    Canvas.cpp \
    Color.h
    

LOCAL_MODULE := guiproject
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(PRODUCT_OUT)/system/bin

LOCAL_STATIC_LIBRARIES := libminui_touchui libpixelflinger_static libpng libz libstlport_static
LOCAL_STATIC_LIBRARIES += libstdc++ libc libcutils
LOCAL_FORCE_STATIC_EXECUTABLE := true

LOCAL_C_INCLUDES +=\
    external/libpng\
    external/zlib
    
LOCAL_CFLAGS += -std=gnu++0x

include external/stlport/libstlport.mk
include $(BUILD_EXECUTABLE)


#####################################
# Include minui

include $(call all-makefiles-under,$(guiproject_local_path))

