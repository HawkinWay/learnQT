#ifndef RUNNABLE_H
#define RUNNABLE_H

#include <QRunnable>
#include <QDebug>

class Runnable: public QRunnable{
public:
    Runnable(const QString &welcomeMsg = "");
    ~Runnable();

    void run() override;

private:
    QString m_welcomeMsg;
    QString m_runnableName;
};

#endif