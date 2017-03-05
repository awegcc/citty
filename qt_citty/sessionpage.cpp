#include "sessionpage.h"

SessionPage::SessionPage()
    : QTabWidget(nullptr)
{
    m_str = "no Contents";
    m_text = new QTextEdit(m_str, this);
}

SessionPage::SessionPage(QWidget *parent)
    : QTabWidget(parent)
{
    m_str = "no Contents";
    m_text = new QTextEdit(m_str, this);
}

SessionPage::~SessionPage()
{
    //delete m_text;
}
