#-------------------------------------------------
#
# Project created by QtCreator 2016-08-26T10:35:19
#
#-------------------------------------------------

QT       += widgets

TARGET = NCommon
TEMPLATE = lib
DEFINES += NCOMMON_LIBRARY
CONFIG += c++11

include($$PWD/NCommon_src.pri)

include($$PWD/../3rdparty/pinyin/pinyin_inc.pri)

# 引入版本信息
RC_FILE += ./NCommon_resource.rc

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

message(Qt is installed in $$[QT_INSTALL_PREFIX])
message(the NCommon will create in folder: $$target_path)

RESOURCES += \
    colorimage.qrc
