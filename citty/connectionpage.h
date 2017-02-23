#ifndef CONNECTIONPAGE_H
#define CONNECTIONPAGE_H

#include <QWidget>
#include <QTabWidget>

#include "sessionpage.h"

class ConnectionPage:public QWidget
{
public:
    ConnectionPage();
    ConnectionPage(QWidget *parent);
    ~ConnectionPage();

private:
    QTabWidget *m_tab;
};

#endif // CONNECTIONPAGE_H
