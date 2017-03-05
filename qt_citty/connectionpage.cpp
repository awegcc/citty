#include "connectionpage.h"

ConnectionPage::ConnectionPage()
    :QTabWidget(nullptr)
{
}

ConnectionPage::ConnectionPage(QWidget *parent)
    :QTabWidget(parent)
{
    this->setTabPosition(QTabWidget::South);
    this->setFixedSize(100, 80);

    m_sessionTab = new SessionPage();
}

ConnectionPage::~ConnectionPage()
{
    //delete m_tab;
}
