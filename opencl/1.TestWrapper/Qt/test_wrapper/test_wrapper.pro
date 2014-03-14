TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

#Add CONFIG+=linuxPC or CONFIG+=imx6qSabreAuto in qmake inovocation.
#In qtcreator in left plane goto Projects -> under Build Steps add
#   CONFIG+=linuxPC in Additional Arguments section
imx6qSabreAuto {
    target.files = test_wrapper
    target.path = /home/root
    INSTALLS += target
    INCLUDEPATH += /usr/include/
    LIBS += -L/usr/lib/\
            -lOpenCL
}

linuxPC {
    QT_CONFIG -= no-pkg-config
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
    DEFINES += PLATFORM_LINUX EGL_LINUX BOOST_MT
    LIBS += -L/usr/local/lib/
    LIBS += -lGLESv2 -lEGL -lm -lX11 -lboost_system -lboost_thread -lOpenCL

    INCLUDEPATH += /usr/local/cuda-5.5/include/ #For CL Header on Nvidia Machine
}

########################################################################
#                   i-Vizon Template Section                           #
########################################################################

IVIZON_TRUNK    = /opt/i-vizon/trunk
UTILS           = $$IVIZON_TRUNK/utils
COMMON          = $$IVIZON_TRUNK/common

#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Common

HEADERS += $$COMMON/inc/Common.h

INCLUDEPATH += $$COMMON/inc/

#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>OpenCL

OPENCL          = $$IVIZON_TRUNK/opencl
OPENCL_WRAPPER  = $$IVIZON_TRUNK/opencl/Wrapper

SOURCES += $$OPENCL_WRAPPER/src/CLWrapper.cpp

HEADERS += $$OPENCL_WRAPPER/inc/CLWrapper.hpp

INCLUDEPATH += $$OPENCL_WRAPPER/inc/

#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>GLES

GLES            = $$IVIZON_TRUNK/gles
GLES_WRAPPER    = $$GLES/Wrapper/

SOURCES += $$GLES_WRAPPER/src/GLESWrapper.cpp \
           $$GLES_WRAPPER/src/EGLLinuxAPIs.cpp \
           $$GLES_WRAPPER/src/GLESAPIs.cpp \

HEADERS += $$GLES_WRAPPER/inc/GLESWrapper.h \
           $$UTILS/inc/MatrixOperations.h


INCLUDEPATH += $$GLES_WRAPPER/inc/ \
                $$UTILS/inc

#<<<<<<<<<<<<<<<<<<<<<<<<<<<<GLES

########################################################################
#                          Project Section                             #
########################################################################

SOURCES += ../../test_wrapper.cpp

OTHER_FILES += ../../rotation.cl

DEFINES += IVIZON_DEBUG CL_INFO_PRINT



#target.path += $$INSTALL_DIR/lib # get the library file
#headers.path = $$INSTALL_DIR/include
#headers.extra = "cp $$BUILD_DIR/ui_*.h $$INSTALL_DIR/include"
#headers.files = \
#src/app/*.h
#INSTALLS += headers target
