TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

########################################################################
#                   i-Vizon Template Section                           #
########################################################################

IVIZON_TRUNK    = /opt/i-vizon/trunk
UTILS           = $$IVIZON_TRUNK/utils
COMMON          = $$IVIZON_TRUNK/common

unix {
    QT_CONFIG -= no-pkg-config
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
    DEFINES += PLATFORM_LINUX EGL_LINUX BOOST_MT
    LIBS += -L/usr/local/lib/
    LIBS += -lGLESv2 -lEGL -lm -lX11 -lboost_system -lboost_thread
    INCLUDEPATH += /usr/local/cuda-5.5/include/ #For CL Header on Nvidia Machine
}

###########################Common#####################################

HEADERS += $$COMMON/inc/Common.h

INCLUDEPATH += $$COMMON/inc/

###########################OpenCL#####################################

OPENCL          = $$IVIZON_TRUNK/opencl
OPENCL_WRAPPER  = $$IVIZON_TRUNK/opencl/Wrapper

SOURCES += $$OPENCL_WRAPPER/src/CLWrapper.cpp

HEADERS += $$OPENCL_WRAPPER/inc/CLWrapper.hpp

INCLUDEPATH += $$OPENCL_WRAPPER/inc/

LIBS += -L/usr/local/lib/\
        -lOpenCL

###########################GLES#######################################

GLES            = $$IVIZON_TRUNK/gles
GLES_WRAPPER    = $$GLES/Wrapper/

SOURCES += $$GLES_WRAPPER/src/GLESWrapper.cpp \
           $$GLES_WRAPPER/src/EGLLinuxAPIs.cpp \
           $$GLES_WRAPPER/src/GLESAPIs.cpp \
           $$GLES_WRAPPER/src/MatrixOperations.cpp

HEADERS += $$GLES_WRAPPER/inc/GLESWrapper.h \
           $$UTILS/inc/MatrixOperations.h


INCLUDEPATH += $$GLES_WRAPPER/inc/ \
                $$UTILS/inc

###########################GLES#######################################

########################################################################
#                          Project Section                             #
########################################################################

SOURCES += ../test_wrapper.cpp

DEFINES += IVIZON_DEBUG CL_INFO_PRINT
