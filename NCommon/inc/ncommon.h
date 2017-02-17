#ifndef NCOMMON_H
#define NCOMMON_H

#include "ncommon_global.h"
#include <QCoreApplication>
#include <QColor>
#include <QFileInfoList>
#include <QMap>

class NCOMMONSHARED_EXPORT NCommon
{

public:
    NCommon();

public:
    /**
     * @brief screenShotToFile 截取全屏并保存为文件
     * @param param_file 文件路径
     * @return
     */
    static bool screenShotToFile(const QString &param_file = QCoreApplication::applicationDirPath());

    /**
     * @brief screenShotToClipBoard 截取全屏并保存到粘贴板
     * @return
     */
    static bool screenShotToClipBoard();

    /**
     * @brief screenShotToShow 截取全屏并显示
     * @param param_int倒计时
     * @return
     */
    static bool screenShotToShow(quint32 param_int);

    /**
     * @brief deployWindowsApp 创建发布包的脚本并执行
     * @return
     */
    static bool deployWindowsApp();

    /**
     * @brief upxWindowsApp 进行UPX程序的压缩
     * @return
     */
    static bool upxWindowsApp(const QString &appPath);

    /**
     * @brief getRandomColor 随机获取一个颜色
     * @return
     */
    QStringList getRandomColor();

    /**
     * @brief getColorImage 获取颜色名字图片
     * @param colorName
     * @return
     */
    QPixmap getColorImage(const QString &colorName);

    /**
     * @brief sleepNow 睡眠指定毫秒
     * @param paramMillSecond 毫秒
     */
    static void sleepNow(quint16 paramMillSecond);

    /**
     * @brief getRandom 获取指定范围内的一个随机数
     * @param paramBegin 随机数的开始范围点
     * @param paramEnd 随机数的结束范围点
     */
    static qint32 getRandom(qint32 paramBegin, qint32 paramEnd);

    /**
     * @brief getPinyin 获取汉字的拼音
     * @param paramSource
     * @return
     */
    QString getPinyin(QString paramSource);

private:
    /**
     * @brief getFileList 获取指定目录下面所有的文件信息
     * @param filePath
     * @return
     */
    static QFileInfoList getFileList(const QString filePath);

private:
    /**
     * @brief chinaColorMap 颜色映射
     */
    QMap<QString, QColor> chinaColorMap;
};

#endif // NCOMMON_H
