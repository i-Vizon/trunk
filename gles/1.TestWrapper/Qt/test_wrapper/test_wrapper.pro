####################################
# Template Section                 #
####################################

IVIZON_TRUNK = /opt/i-vizon/trunk
GLES = $$IVIZON_TRUNK/gles
GLES_WRAPPER = $$GLES/Wrapper/

TEST_WRAPPER = $$GLES/1.TestWrapper/

unix {
    QT_CONFIG -= no-pkg-config
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
    DEFINES += PLATFORM_LINUX EGL_LINUX BOOST_MT
    LIBS += -L/usr/local/lib/
    LIBS += -lGLESv2 -lEGL -lm -lX11 -lboost_system -lboost_thread
}

SOURCES += $$GLES_WRAPPER/src/GLESWrapper.cpp \
           $$GLES_WRAPPER/src/EGLLinuxAPIs.cpp \
           $$GLES_WRAPPER/src/GLESAPIs.cpp


HEADERS += $$GLES_WRAPPER/inc/GLESWrapper.h

INCLUDEPATH += $$GLES_WRAPPER/inc/


####################################
# Project Section                  #
####################################

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += $$TEST_WRAPPER/test_wrapper.cpp

