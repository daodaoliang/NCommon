#-------------------------------------------------
#
# Project created by QtCreator 2015-03-31T21:40:45
#
#-------------------------------------------------

QT       -= gui

TARGET = pinyin
TEMPLATE = lib

DEFINES += PINYIN4CPP_LIBRARY

# 引入源码
include($$PWD/pinyin_src.pri)

# 定义输出
win32{
    CONFIG += debug_and_release
    CONFIG(release, debug|release) {
            target_path = ./build_/dist
        } else {
            target_path = ./build_/debug
        }
        DESTDIR = ../../bin
        MOC_DIR = $$target_path/moc
        RCC_DIR = $$target_path/rcc
        OBJECTS_DIR = $$target_path/obj
}

message(Qt is installed in $$[QT_INSTALL_PREFIX])
message(the pinyin will create in folder: $$target_path)
