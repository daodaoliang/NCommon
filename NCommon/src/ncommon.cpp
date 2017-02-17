#include "ncommon.h"
#include <QPixmap>
#include <QScreen>
#include <QGuiApplication>
#include <QApplication>
#include <QtWidgets>
#include <QDateTime>
#include <QLabel>
#include <QFile>
#include <QProcessEnvironment>
#include <QProcess>
#include <QDebug>
#include <QTimer>
#include <QEventLoop>
#include <QDir>
#include "HanyuPinyinOutputFormat.h"
#include "PinyinHelper.h"


NCommon::NCommon()
{
    chinaColorMap.insert("艳红",QColor(204, 53, 54));
    chinaColorMap.insert("猩红",QColor(196, 55, 57));
    chinaColorMap.insert("绛紫",QColor(112, 77, 78));
    chinaColorMap.insert("银朱",QColor(221, 59, 68));
    chinaColorMap.insert("浅血牙",QColor(234, 205, 209));
    chinaColorMap.insert("月季红",QColor(187, 28, 51));
    chinaColorMap.insert("玫瑰红",QColor(151, 52, 68));
    chinaColorMap.insert("枣红",QColor(137, 48, 63));
    chinaColorMap.insert("洋红",QColor(220, 20, 60));
    chinaColorMap.insert("紫粉",QColor(165, 67, 88));
    chinaColorMap.insert("茄皮紫",QColor(103, 73, 80));
    chinaColorMap.insert("深烟红",QColor(100, 52, 65));
    chinaColorMap.insert("雪紫",QColor(121, 72, 90));
    chinaColorMap.insert("玫瑰灰",QColor(121, 61, 86));
    chinaColorMap.insert("洋葱紫",QColor(156, 102, 128));
    chinaColorMap.insert("元青",QColor(62, 60, 61));
    chinaColorMap.insert("品红",QColor(167, 19, 104));
    chinaColorMap.insert("紫薇花",QColor(238, 165, 209));
    chinaColorMap.insert("牵牛紫",QColor(162, 32, 118));
    chinaColorMap.insert("紫水晶",QColor(195, 166, 203));
    chinaColorMap.insert("浅石英紫",QColor(171, 150, 197));
    chinaColorMap.insert("柏坊灰蓝",QColor(78, 24, 146));
    chinaColorMap.insert("紫藤灰",QColor(133, 126, 149));
    chinaColorMap.insert("浅藤紫",QColor(196, 195, 203));
    chinaColorMap.insert("宝蓝",QColor(31, 54, 150));
    chinaColorMap.insert("靛蓝",QColor(27, 84, 242));
    chinaColorMap.insert("藏蓝",QColor(37, 56, 107));
    chinaColorMap.insert("粗晶皂",QColor(67, 69, 74));
    chinaColorMap.insert("孔雀蓝",QColor(0, 65, 165));
    chinaColorMap.insert("浅海昌蓝",QColor(60, 94, 145));
    chinaColorMap.insert("花青",QColor(84, 107, 131));
    chinaColorMap.insert("鹊灰",QColor(69, 86, 103));
    chinaColorMap.insert("海蓝",QColor(23, 80, 125));
    chinaColorMap.insert("黛蓝",QColor(48, 71, 88));
    chinaColorMap.insert("深竹月",QColor(37, 120, 181));
    chinaColorMap.insert("绒蓝",QColor(49, 103, 141));
    chinaColorMap.insert("北京毛蓝",QColor(39, 104, 147));
    chinaColorMap.insert("沙青",QColor(43, 94, 125));
    chinaColorMap.insert("钴蓝",QColor(100, 147, 175));
    chinaColorMap.insert("铁灰",QColor(55, 68, 75));
    chinaColorMap.insert("红皂",QColor(79, 83, 85));
    chinaColorMap.insert("正灰",QColor(147, 162, 169));
    chinaColorMap.insert("玉石蓝",QColor(80, 120, 131));
    chinaColorMap.insert("天青",QColor(46, 195, 231));
    chinaColorMap.insert("灰蓝",QColor(93, 130, 138));
    chinaColorMap.insert("春蓝",QColor(123, 161, 168));
    chinaColorMap.insert("织锦灰",QColor(116, 138, 141));
    chinaColorMap.insert("碧玉石",QColor(86, 149, 151));
    chinaColorMap.insert("沙绿",QColor(0, 91, 90));
    chinaColorMap.insert("灰绿",QColor(92, 137, 135));
    chinaColorMap.insert("翠绿",QColor(0, 110, 95));
    chinaColorMap.insert("卡其绿",QColor(100, 115, 112));
    chinaColorMap.insert("果灰",QColor(136, 174, 163));
    chinaColorMap.insert("鹦鹉绿",QColor(0, 142, 89));
    chinaColorMap.insert("鸭蛋青",QColor(209, 227, 219));
    chinaColorMap.insert("三绿",QColor(144, 202, 175));
    chinaColorMap.insert("承德皂",QColor(90, 92, 91));
    chinaColorMap.insert("老绿",QColor(61, 110, 83));
    chinaColorMap.insert("奶绿",QColor(175, 200, 186));
    chinaColorMap.insert("淡灰绿",QColor(174, 196, 183));
    chinaColorMap.insert("水貂灰",QColor(148, 156, 151));
    chinaColorMap.insert("油绿",QColor(69, 85, 74));
    chinaColorMap.insert("锈绿",QColor(184, 200, 183));
    chinaColorMap.insert("水黄",QColor(190, 210, 182));
    chinaColorMap.insert("银箔",QColor(88, 90, 87));
    chinaColorMap.insert("苍绿",QColor(78, 95, 69));
    chinaColorMap.insert("黄灰",QColor(176, 183, 172));
    chinaColorMap.insert("春绿",QColor(227, 239, 209));
    chinaColorMap.insert("军绿",QColor(202, 212, 186));
    chinaColorMap.insert("大赤金",QColor(109, 115, 88));
    chinaColorMap.insert("芦灰",QColor(169, 176, 143));
    chinaColorMap.insert("米色",QColor(245, 245, 220));
    chinaColorMap.insert("油烟墨",QColor(63, 63, 60));
    chinaColorMap.insert("承德灰",QColor(117, 117, 112));
    chinaColorMap.insert("橄榄绿",QColor(106, 104, 52));
    chinaColorMap.insert("枯绿",QColor(183, 178, 120));
    chinaColorMap.insert("柠檬黄",QColor(233, 219, 57));
    chinaColorMap.insert("蜡白",QColor(231, 229, 208));
    chinaColorMap.insert("草黄",QColor(219, 206, 84));
    chinaColorMap.insert("灰米",QColor(182, 177, 150));
    chinaColorMap.insert("藤黄",QColor(242, 222, 118));
    chinaColorMap.insert("胡粉",QColor(235, 232, 219));
    chinaColorMap.insert("丹东石",QColor(215, 193, 107));
    chinaColorMap.insert("库金",QColor(133, 121, 79));
    chinaColorMap.insert("甘草黄",QColor(228, 207, 142));
    chinaColorMap.insert("灯草灰",QColor(54, 53, 50));
    chinaColorMap.insert("米灰",QColor(197, 191, 173));
    chinaColorMap.insert("姜黄",QColor(180, 148, 54));
    chinaColorMap.insert("选金",QColor(121, 111, 84));
    chinaColorMap.insert("浅棕灰",QColor(225, 219, 205));
    chinaColorMap.insert("将校呢",QColor(109, 97, 74));
    chinaColorMap.insert("卡其黄",QColor(213, 184, 132));
    chinaColorMap.insert("相思灰",QColor(98, 92, 82));
    chinaColorMap.insert("中棕灰",QColor(169, 152, 124));
    chinaColorMap.insert("土黄",QColor(206, 147, 53));
    chinaColorMap.insert("浅驼色",QColor(201, 174, 140));
    chinaColorMap.insert("棕茶",QColor(184, 132, 79));
    chinaColorMap.insert("雄黄",QColor(208, 133, 61));
    chinaColorMap.insert("纸棕",QColor(188, 165, 144));
    chinaColorMap.insert("浅桔黄",QColor(218, 149, 88));
    chinaColorMap.insert("浅黄棕",QColor(222, 168, 122));
    chinaColorMap.insert("金黄",QColor(199, 122, 58));
    chinaColorMap.insert("米红",QColor(225, 189, 162));
    chinaColorMap.insert("桔黄",QColor(232, 133, 59));
    chinaColorMap.insert("苍黄",QColor(198, 83, 6));
    chinaColorMap.insert("雄精",QColor(228, 117, 66));
    chinaColorMap.insert("甘石粉",QColor(234, 220, 214));
    chinaColorMap.insert("章丹",QColor(235, 101, 45));
    chinaColorMap.insert("桔红",QColor(231, 105, 63));
    chinaColorMap.insert("奶棕",QColor(193, 162, 153));
    chinaColorMap.insert("血红",QColor(160, 62, 40));
    chinaColorMap.insert("辰砂",QColor(175, 94, 83));
    chinaColorMap.insert("十样锦",QColor(252, 177, 170));
    chinaColorMap.insert("蕃茄红",QColor(196, 71, 61));
    chinaColorMap.insert("榴花红",QColor(213, 75, 68));
    chinaColorMap.insert("胭脂",QColor(192, 63, 60));
    chinaColorMap.insert("妃红",QColor(195, 86, 85));
    chinaColorMap.insert("锈红",QColor(77, 25, 25));
    chinaColorMap.insert("深烟",QColor(90, 76, 76));
    chinaColorMap.insert("雪色",QColor(255, 250, 250));
    chinaColorMap.insert("百草霜",QColor(48, 48, 48));
}

bool NCommon::screenShotToFile(const QString &param_file)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    if (!screen) return false;
    QPixmap tempMap = screen->grabWindow(0);
    tempMap.save(param_file + QString("/%1.png").arg(QDateTime::currentMSecsSinceEpoch()));
    return true;
}

bool NCommon::screenShotToClipBoard()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    if (!screen) return false;
    QPixmap tempMap = screen->grabWindow(0);
    QClipboard *pixClipboard = QApplication::clipboard();
    pixClipboard->setPixmap(tempMap);
    return true;
}

bool NCommon::screenShotToShow(quint32 param_int)
{
    Q_UNUSED(param_int);
    QLabel *innerLabel = new QLabel;
    innerLabel->setAttribute(Qt::WA_TranslucentBackground);
    innerLabel->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    QScreen *screen = QGuiApplication::primaryScreen();
    if (!screen) return false;
    QPixmap tempMap = screen->grabWindow(0);
    innerLabel->setGeometry(screen->geometry());
    innerLabel->setPixmap(tempMap.scaled(innerLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    innerLabel->show();
    return true;
}

bool NCommon::deployWindowsApp()
{
    // 创建发布脚本
    QString qtDir = QProcessEnvironment::systemEnvironment().value("QTDIR");
    QString deployCMD = qtDir + "/bin/windeployqt.exe " + QCoreApplication::applicationName() + ".exe";
    QString appPath = QCoreApplication::applicationDirPath();
    QString joinAppPath = appPath.left(2) + "\r\ncd " + appPath + "\r\n";
    QString filePath = QCoreApplication::applicationDirPath() + "/deploy.bat";
    QFile deployBat(filePath);
    if(deployBat.open(QFile::WriteOnly)){
        QString tempStr = joinAppPath + deployCMD;
        deployBat.write(tempStr.toLocal8Bit().data(), tempStr.toLocal8Bit().length());
        deployBat.flush();
    }
    deployBat.close();
    // 运行发布脚本
    bool ret = QProcess::startDetached(QCoreApplication::applicationDirPath()+"/deploy.bat");
    Sleep(500);
    QFile::remove(filePath);
    return ret;
}

bool NCommon::upxWindowsApp(const QString &appPath)
{
    QFileInfoList tempList = getFileList(appPath);
    QString batString;
    foreach (QFileInfo item, tempList) {
        batString += QCoreApplication::applicationDirPath() + "/upx/upx.exe -9 " +item.absoluteFilePath() + "\r\n";
    }
    QFile upxBat(QCoreApplication::applicationDirPath() + "/upx.bat");
    if(upxBat.open(QFile::WriteOnly)){
        upxBat.write(batString.toLocal8Bit().data(), batString.toLocal8Bit().length());
        upxBat.flush();
    }
    upxBat.close();
    return true;
}

QStringList NCommon::getRandomColor()
{
    QStringList tempStrList;
    quint16 tempIndex = getRandom(0, chinaColorMap.size());
    QString tempName = chinaColorMap.keys()[tempIndex];
    tempStrList.push_back(tempName);
    tempStrList.push_back(chinaColorMap[tempName].name());
    return tempStrList;
}

QPixmap NCommon::getColorImage(const QString &colorName)
{
    QPixmap temp;
    temp.load(QObject::tr(":/res/%1.png").arg(colorName));
    return temp;
}

void NCommon::sleepNow(quint16 paramMillSecond)
{
    QEventLoop eventloop;
    QTimer::singleShot(paramMillSecond, &eventloop, SLOT(quit()));
    eventloop.exec();
}

qint32 NCommon::getRandom(qint32 paramBegin, qint32 paramEnd)
{
    QTime time = QTime::currentTime();
    qsrand((quint64)time.msec());
    sleepNow(2);
    if(paramBegin > 0){
        return paramBegin + qrand() % (paramEnd - paramBegin);
    } else {
        return paramBegin + qrand() % (qAbs(paramBegin) + paramEnd);
    }
}

QString NCommon::getPinyin(QString paramSource)
{
    QString paramRet;
    foreach (QChar item, paramSource) {
        HanyuPinyinOutputFormat outputFormat;
        QList<QString> *pinyinList=new QList<QString>();
        PinyinHelper::toHanyuPinyinStringArray(item, &outputFormat, pinyinList);
        // 只获取多音字的第一个
        if(! pinyinList->isEmpty()) {
            QString temp = pinyinList->at(0);
            if(temp.right(1) == ":") temp = temp.left(temp.count() - 2) + "v";
            paramRet += temp;
        }
    }
    return paramRet;
}

QFileInfoList NCommon::getFileList(const QString filePath)
{
    QDir dir(filePath);
    QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    for(int i = 0; i != folder_list.size(); i++)
    {
         QString name = folder_list.at(i).absoluteFilePath();
         QFileInfoList child_file_list = getFileList(name);
         file_list.append(child_file_list);
    }
    return file_list;
}
