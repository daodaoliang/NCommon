#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ncommon.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QNetworkReply>
#include <QNetworkRequest>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    /**
     * @brief on_pushButton_2_clicked 截取全屏到到本地
     */
    void on_pushButton_2_clicked();

    /**
     * @brief on_pushButton_4_clicked 截取全屏到粘贴板
     */
    void on_pushButton_4_clicked();

    /**
     * @brief on_pushButton_3_clicked 截取全屏并显示
     */
    void on_pushButton_3_clicked();

    /**
     * @brief on_pushButton_5_clicked 程序部署
     */
    void on_pushButton_5_clicked();

    /**
     * @brief on_pushButton_6_clicked 汉字转拼音
     */
    void on_pushButton_6_clicked();

    /**
     * @brief on_pushButton_clicked 获取随机颜色
     */
    void on_pushButton_clicked();

    /**
     * @brief pinyinDemo 拼音demo页面
     */
    void pinyinDemo();

private:
    Ui::Widget *ui;
    NCommon testInstance;
    QLineEdit *pinyinEdit;
    QLabel *pinyinLabel;
    QPushButton *pinyinButton;
};

#endif // WIDGET_H
