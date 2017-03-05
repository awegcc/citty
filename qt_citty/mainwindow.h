#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QApplication>
#include <QMainWindow>
#include <QTabWidget>

#include "connectionpage.h"

class MainWindow : public QTabWidget
{
    Q_OBJECT

public:
    MainWindow(MainWindow *parent = nullptr);
    ~MainWindow();

public:
    bool centerAndResize();

private:
    QTabWidget *m_tab;
    QSize m_size;
};

#endif // MAINWINDOW_H
