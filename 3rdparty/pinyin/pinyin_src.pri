
HEADERS += \
    inc/ChineseToPinyinResource.h \
    inc/HanyuPinyinCaseType.h \
    inc/HanyuPinyinOutputFormat.h \
    inc/HanyuPinyinToneType.h \
    inc/HanyuPinyinVCharType.h \
    inc/PinyinFormatter.h \
    inc/PinyinHelper.h \
    inc/ResourceHelper.h \
    $$PWD/inc/pinyin_global.h

RESOURCES += \
    res/res.qrc

SOURCES += \
    src/ChineseToPinyinResource.cpp \
    src/HanyuPinyinCaseType.cpp \
    src/HanyuPinyinOutputFormat.cpp \
    src/HanyuPinyinToneType.cpp \
    src/HanyuPinyinVCharType.cpp \
    src/PinyinFormatter.cpp \
    src/PinyinHelper.cpp \
    src/ResourceHelper.cpp

INCLUDEPATH += $$PWD/inc/ \
