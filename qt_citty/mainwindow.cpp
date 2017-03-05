#include "mainwindow.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include <QDesktopWidget>
#include <QTabBar>
#include <QStyle>

MainWindow::MainWindow(MainWindow *parent)
    : QTabWidget(parent)
{
    m_tab = this;

    m_tab->setTabPosition(QTabWidget::North);
    QWidget *tabPage01 = new ConnectionPage();
    QWidget *tabPage02 = new ConnectionPage();
    QWidget *tabPage03 = new ConnectionPage();
    QWidget *tabPage04 = new ConnectionPage();

    m_tab->addTab(tabPage01, "connection 01");
    m_tab->addTab(tabPage02, "connection 02");
    m_tab->addTab(tabPage03, "connection 03");
    m_tab->addTab(tabPage04, "connection 04");

    this->centerAndResize();
    m_tab->setFixedSize(m_size);
}

MainWindow::~MainWindow()
{
    //delete m_tab;
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
    m_size.setWidth(width);
    m_size.setHeight(height);

    setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    m_size,
                    qApp->desktop()->availableGeometry()
                    )
                );

    return true;
}
