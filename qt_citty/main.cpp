#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mw;
    //mw.centerAndResize();
    mw.show();

    return a.exec();
}
