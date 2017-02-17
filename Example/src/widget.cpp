#include "widget.h"
#include "ui_widget.h"
#include "ncommon.h"
#include <QDebug>
#include <QLabel>
#include <QColor>
#include <QLineEdit>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    qDebug()<<"*********************************截屏保存到本地测试开始******************************************";
    bool ret = NCommon::screenShotToFile();
    qDebug() << "是否保存到本地成功:" << ret;
    ui->listWidget->addItem("截图已经保存到本地");
    qDebug()<<"*********************************截屏保存到本地测试结束******************************************";
}

void Widget::on_pushButton_4_clicked()
{
    qDebug()<<"*********************************截屏保存到粘贴板测试开始*****************************************";
    bool ret = NCommon::screenShotToClipBoard();
    qDebug() << "是否保存到粘贴板成功:" << ret;
    ui->listWidget->addItem("截图已经保存到粘贴板");
    qDebug()<<"*********************************截屏保存到粘贴板测试结束*****************************************";
}

void Widget::on_pushButton_3_clicked()
{
    qDebug()<<"*********************************截屏后并全屏显示测试开始*****************************************";
    bool ret = NCommon::screenShotToShow(2);
    qDebug() << "是否截取后全屏显示成功:" << ret;
    ui->listWidget->addItem("截图已经全屏显示了");
    qDebug()<<"*********************************截屏后并全屏显示测试结束*****************************************";
}

void Widget::on_pushButton_5_clicked()
{
    qDebug()<<"*********************************发布APP脚本创建测试开始*****************************************";
    bool ret = NCommon::deployWindowsApp();
    qDebug() << "是否发布程序成功:" << ret;
    ui->listWidget->addItem("本程序的依赖包已经拷贝到本地目录下可直接对外发布了");
    qDebug()<<"*********************************发布APP脚本创建测试结束*****************************************";
}

void Widget::on_pushButton_6_clicked()
{
    qDebug()<<"*********************************获取汉字拼音测试开始********************************************";
    qDebug() << "我是测试数据的拼音是:" << testInstance.getPinyin(QString("我是测试数据"));
    QWidget *demo_case_002_w = new QWidget;
    pinyinEdit = new QLineEdit(demo_case_002_w);
    pinyinEdit->setGeometry(0,0,200,30);
    pinyinEdit->setFont(QFont("微软雅黑", 10, QFont::Bold));
    pinyinEdit->setPlaceholderText("请输入你想要转换成拼音的汉字");
    pinyinButton = new QPushButton(demo_case_002_w);
    pinyinButton->setGeometry(0,31,200,30);
    pinyinButton->setText("开始转换");
    pinyinButton->setFont(QFont("微软雅黑", 10, QFont::Bold));
    pinyinLabel = new QLabel(demo_case_002_w);
    pinyinLabel->setFont(QFont("微软雅黑", 10, QFont::Bold));
    pinyinLabel->setGeometry(0,62,200,30);
    demo_case_002_w->move(x()+width()/2,y()+height()/2);
    demo_case_002_w->show();
    connect(pinyinButton, SIGNAL(clicked(bool)),this,SLOT(pinyinDemo()));
    qDebug()<<"*********************************获取汉字拼音测试结束********************************************";
}

void Widget::on_pushButton_clicked()
{
    qDebug()<<"*********************************获取随机颜色测试开始********************************************";
    QStringList tempList = testInstance.getRandomColor();
    QLabel *demo_case_001 = new QLabel;
    demo_case_001->setWindowFlags(Qt::FramelessWindowHint);
    demo_case_001->setStyleSheet(tr("background-color:%1;color:white;").arg(tempList[1]));
    demo_case_001->setText(tempList[0]);
    demo_case_001->setAlignment(Qt::AlignCenter);
    demo_case_001->setFont(QFont("微软雅黑", 20, QFont::Bold));
    demo_case_001->setPixmap(testInstance.getColorImage(testInstance.getPinyin(tempList[0])));
    demo_case_001->setGeometry(x()+width() + 10,y(),200,400);
    demo_case_001->show();
    // 5秒后关闭
    QTimer::singleShot(5000, demo_case_001, SLOT(deleteLater()));
    ui->listWidget->addItem(tr("获取随机颜色:%1-5秒后关闭").arg(tempList[0]));
    qDebug()<<"*********************************获取随机颜色测试结束********************************************";
}

void Widget::pinyinDemo()
{
    qDebug()<<"123";
    pinyinLabel->setText(testInstance.getPinyin(pinyinEdit->text()));
    pinyinEdit->clear();
}
