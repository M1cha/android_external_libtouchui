LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
touchui_local_path := $(LOCAL_PATH)

LOCAL_SRC_FILES := \
    threads/Thread.cpp \
    threads/RedrawThread.cpp \
    threads/EventThread.cpp \
    events/KeyEvent.cpp \
    events/TouchEvent.cpp \
    views/View.cpp \
    views/ViewGroup.cpp \
    views/AbsoluteLayout.cpp \
    views/ImageView.cpp \
    Context.cpp \
    UiMain.cpp \
    Activity.cpp \
    Canvas.cpp \
    Color.cpp \
    Image.cpp
    

LOCAL_MODULE := libtouchui
LOCAL_MODULE_TAGS := optional

include $(LOCAL_PATH)/libtouchui.mk
include $(BUILD_STATIC_LIBRARY)


#####################################
# Include minui

include $(call all-makefiles-under,$(touchui_local_path))

