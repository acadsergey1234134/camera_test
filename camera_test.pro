QT += core multimedia
QT -= gui
TARGET = camera_test
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tests.cpp \
    test_types.cpp \
    videodev1.cpp \
    videodev2.cpp \
    videodev_qt.cpp

HEADERS += \
    tests.h \
    test_types.h \
    videodev1.h \
    videodev2.h \
    videodev_qt.h
