#include <QString>
#include <QRegExp>
#include "PinyinFormatter.h"
#include "HanyuPinyinOutputFormat.h"
#include "HanyuPinyinToneType.h"

QString PinyinFormatter::formatHanyuPinyin(QString pinyinStr, HanyuPinyinOutputFormat *outputFormat)
{
    Q_UNUSED(outputFormat);
    QString pattern("[1-5]");
    QRegExp rx(pattern);
    return pinyinStr.replace(rx,"");
}
