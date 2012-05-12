LOCAL_STATIC_LIBRARIES += libminui_touchui libpixelflinger_static libpng libz libstlport_static
LOCAL_STATIC_LIBRARIES += libstdc++ libc libcutils
LOCAL_FORCE_STATIC_EXECUTABLE := true

LOCAL_C_INCLUDES +=\
    external/libpng \
    external/zlib \
    external/libtouchui
    
LOCAL_CFLAGS += -std=gnu++0x

include external/stlport/libstlport.mk