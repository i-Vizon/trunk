TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

#Add CONFIG+=linuxPC or CONFIG+=imx6qSabreAuto in qmake inovocation.

#In qtcreator in left plane goto Projects -> Build -> Steps add
#   CONFIG+=linuxPC in Additional Arguments section
#In qtcreator in left plane goto Projects -> Run -> Arguments add
#   path/to/wrk_grp_info.cl

imx6qSabreAuto {
    target.files = test_wrapper
    target.path = /home/root
    INSTALLS += target
    LIBS += -lOpenCL -lGAL
    copyfiles.commands = cp ../../wrk_grp_info.cl <to>
}

linuxPC {
    QT_CONFIG -= no-pkg-config
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
    DEFINES += PLATFORM_LINUX EGL_LINUX BOOST_MT
    LIBS += -L/usr/local/lib/
    LIBS += -lGLESv2 -lEGL -lm -lX11 -lboost_system -lboost_thread -lOpenCL

    INCLUDEPATH += /usr/local/cuda-5.5/include/ #For CL Header on Nvidia Machine

    copydata.commands = $(COPY_DIR) ../../wrk_grp_info.cl $$OUT_PWD
    first.depends = $(first) copydata
    export(first.depends)
    export(copydata.commands)
    QMAKE_EXTRA_TARGETS += first copydata

#The meaning of the different names in the above are as follows:
#   $(COPY_DIR) – Holds a platform-dependent copy-command that makes
#                 sure to copy recursively.
#   $$PWD       – Holds the name of the source code directory,
#                 where your .pro file resides.
#   $$OUT_PWD   – Holds the name of the build directory.
#                 Note that this may not work if you are running
#                 qmake and make in the same directory as your source code,
#                 as you will be copying into the same folder as you copy from.
#   copydata    – Just a name we choose. You can replace this with whatever you want.
#   first       - This is a build step that already exists in the Makefile generated by qmake. We attach the copy build step to this build step.
#   export      – Makes the variable in the argument of the function available
#                 in a global scope.
#   QMAKE_EXTRA_TARGETS - Tells qmake that you want to build more targets than the ones it adds by default to the Makefile.
}

QMAKE_EXTRA_TARGETS += copyfiles
POST_TARGETDEPS += copyfiles
########################################################################
#                   i-Vizon Template Section                           #
########################################################################

IVIZON_TRUNK    = /opt/i-vizon/trunk
UTILS           = $$IVIZON_TRUNK/utils
COMMON          = $$IVIZON_TRUNK/common

#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Common

HEADERS += $$COMMON/inc/common.h \
    ../../../wrapper/inc/buffer.h \
    ../../../wrapper/inc/kernel_launcher.h \
    ../../../wrapper/inc/program.h

SOURCES += $$COMMON/src/common.cpp

INCLUDEPATH += $$COMMON/inc/

#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>OpenCL

OPENCL          = $$IVIZON_TRUNK/opencl
OPENCL_WRAPPER  = $$IVIZON_TRUNK/opencl/wrapper

SOURCES += $$OPENCL_WRAPPER/src/cl_wrapper.cpp \
    ../../../wrapper/src/buffer.cpp \
    ../../../wrapper/src/kernel_launcher.cpp \
    ../../../wrapper/src/program.cpp

HEADERS += $$OPENCL_WRAPPER/inc/CLWrapper.hpp

INCLUDEPATH += $$OPENCL_WRAPPER/inc/

#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>GLES

#GLES            = $$IVIZON_TRUNK/gles
#GLES_WRAPPER    = $$GLES/Wrapper/

#SOURCES += $$GLES_WRAPPER/src/GLESWrapper.cpp \
#           $$GLES_WRAPPER/src/EGLLinuxAPIs.cpp \
#           $$GLES_WRAPPER/src/GLESAPIs.cpp \

#HEADERS += $$GLES_WRAPPER/inc/GLESWrapper.h \
#           $$UTILS/inc/MatrixOperations.h


#INCLUDEPATH += $$GLES_WRAPPER/inc/ \
#                $$UTILS/inc

#<<<<<<<<<<<<<<<<<<<<<<<<<<<<GLES

########################################################################
#                          Project Section                             #
########################################################################

SOURCES += ../../test_wrapper.cpp

OTHER_FILES += \
    ../../wrk_grp_info.cl

DEFINES += IVIZON_DEBUG CL_INFO_PRINT
