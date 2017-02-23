#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QApplication>
#include <QMainWindow>
#include <QTabWidget>

#include "connectionpage.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(MainWindow *parent = 0);
    ~MainWindow();

public:
    bool centerAndResize();

private:
    QTabWidget *m_tab;
};

#endif // MAINWINDOW_H
