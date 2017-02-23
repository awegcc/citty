#include "sessionpage.h"

SessionPage::SessionPage()
    : QWidget(nullptr)
{
    m_str = "no Contents";
}

SessionPage::SessionPage(QWidget *parent = nullptr)
    : QWidget(parent)
{
    m_str = "no Contents";
    m_text = new QTextEdit(m_str, this);
}

SessionPage::~SessionPage()
{
}
