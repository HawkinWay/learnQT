#include "Runnable.h"
#include <QThread>

Runnable::Runnable(const QString &welcomeMsg): m_welcomeMsg{welcomeMsg}{
    static int i{0};
    m_runnableName = "runnable obj nr " + QString::number(i++);
    qInfo() << m_runnableName<< " created.";
}

Runnable::~Runnable(){
    qInfo() << "Destroyed Runnable: " << m_runnableName;
}

void Runnable::run(){
    QThread::currentThread()->setObjectName("Thread for " + m_runnableName);
    qInfo() << QThread::currentThread()->objectName() << " start working...";
    if(!m_welcomeMsg.isEmpty()){
        qInfo() << "Welcome message " << m_welcomeMsg << " for thread " << QThread::currentThread()->objectName();
    }
    QThread::sleep(7);
    qInfo() << QThread::currentThread()->objectName() << " end working.";

}
