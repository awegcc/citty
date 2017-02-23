#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.setGeometry(300, 200, 800, 400);
    //w.setCentralWidget(nullptr);
    w.centerAndResize();
    w.show();

    return a.exec();
}
