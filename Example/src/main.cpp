#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget testDemo;
    testDemo.show();
    return a.exec();
}
