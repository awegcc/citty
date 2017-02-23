#include "connectionpage.h"

ConnectionPage::ConnectionPage()
    :QWidget(nullptr)
{
}

ConnectionPage::ConnectionPage(QWidget *parent = nullptr)
    :QWidget(parent)
{
    m_tab = new QTabWidget(this);
    m_tab->setTabPosition(QTabWidget::South);
    QWidget *tabPage01 = new SessionPage();
    QWidget *tabPage02 = new SessionPage();
    QWidget *tabPage03 = new SessionPage();
    QWidget *tabPage04 = new SessionPage();

    m_tab->addTab(tabPage01, "tab01");
    m_tab->addTab(tabPage02, "tab02");
    m_tab->addTab(tabPage03, "tab02");
    m_tab->addTab(tabPage04, "tab02");
}

ConnectionPage::~ConnectionPage()
{
}
