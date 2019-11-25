#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;             //QMainWindow继承QWidget。
    w.show();
//    QWidget *pnewwidget = new QWidget(0,Qt::Dialog);    //指定窗口类型为Qt::Dialog 类型 和默认的有差别
//    QWidget *pnewwidget = new QWidget(0,0);     //默认方式，0=不嵌入父窗口，0=Qt::Widget类型
//    pnewwidget->show();
    return a.exec();
}
