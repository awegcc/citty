#include "mainwindow.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include <QDesktopWidget>
#include <QTabBar>

#include <QStyle>

MainWindow::MainWindow(MainWindow *parent)
    : QMainWindow(parent)
{
    m_tab = new QTabWidget(this);
    QWidget *tabPage01 = new QWidget();
    QWidget *tabPage02 = new QWidget();
    QWidget *tabPage03 = new QWidget();
    QWidget *tabPage04 = new QWidget();


    m_tab->addTab(tabPage01, "tab01");
    m_tab->addTab(tabPage02, "tab02");
    m_tab->addTab(tabPage03, "tab02");
    m_tab->addTab(tabPage04, "tab02");
}

MainWindow::~MainWindow()
{

}

bool MainWindow::centerAndResize()
{
    // get the dimension available on this screen
    QSize availableSize = qApp->desktop()->availableGeometry().size();
    QDesktopWidget *qdw = qApp->desktop();
    qdw->availableGeometry();
    int width = availableSize.width();
    int height = availableSize.height();
    //qDebug() << "Available dimensions " << width << "x" << height;
    width *= 0.6; // 60% of the screen size
    height *= 0.6; // 60% of the screen size
    //qDebug() << "Computed dimensions " << width << "x" << height;
    QSize newSize( width, height );

    setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    newSize,
                    qApp->desktop()->availableGeometry()
                    )
                );

    return true;
}
