#ifndef SESSIONPAGE_H
#define SESSIONPAGE_H

#include <QWidget>
#include <QTextEdit>
#include <QTabWidget>

class SessionPage: public QTabWidget
{
public:
    SessionPage();
    SessionPage(QWidget *parent);
    ~SessionPage();
private:
    QString m_str;
    QTextEdit *m_text;
};

#endif // SESSIONPAGE_H
