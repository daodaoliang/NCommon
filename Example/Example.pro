#-------------------------------------------------
#
# Project created by QtCreator 2016-08-26T10:35:43
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NCommon_Example
TEMPLATE = app


SOURCES += $$PWD/src/main.cpp\
        $$PWD/src/widget.cpp

HEADERS  += $$PWD/inc/widget.h

FORMS    += $$PWD/ui/widget.ui

INCLUDEPATH += $$PWD/inc/

# 定义输出
win32{
    CONFIG += debug_and_release
    CONFIG(release, debug|release) {
            target_path = ./build_/dist
        } else {
            target_path = ./build_/debug
        }
        DESTDIR = ../bin
        MOC_DIR = $$target_path/moc
        RCC_DIR = $$target_path/rcc
        OBJECTS_DIR = $$target_path/obj
}

include($PWD/../../NCommon/NCommon_inc.pri)

