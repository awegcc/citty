#ifndef CONNECTIONPAGE_H
#define CONNECTIONPAGE_H

#include <QWidget>
#include <QTabWidget>
#include <QTextEdit>

#include "sessionpage.h"

class ConnectionPage:public QTabWidget
{
public:
    ConnectionPage();
    ConnectionPage(QWidget *parent);
    ~ConnectionPage();

private:
    SessionPage *m_sessionTab;
};

#endif // CONNECTIONPAGE_H
