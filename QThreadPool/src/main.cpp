#include <QThreadPool>
#include <QCoreApplication>

#include "Runnable.h"

int main(int argc, char *argv[]){
    QCoreApplication app(argc, argv);

    QThreadPool *pool = QThreadPool::globalInstance();

    qInfo() << "Ideal thread count is: " << QThread::idealThreadCount();
    qInfo() << "Max thread count is: " << pool->maxThreadCount();
    pool->setMaxThreadCount(4);
    qInfo() << "Max thread count is: " << pool->maxThreadCount();
    qInfo() << "Active thread count is: " << pool->activeThreadCount();


    QThreadPool::globalInstance()->reserveThread();
    qInfo() << "\nAfter reservation, Max thread count is: " << pool->maxThreadCount();
    qInfo() << "After reservation, Active thread count is: " << pool->activeThreadCount();

    for(int i = 0; i < 5; i++){
        Runnable *task = new Runnable();
        pool->start(task);
    }
    QThread::msleep(100);
    qInfo() << "Active thread count is: " << pool->activeThreadCount();
    qInfo() << "Waiting for tasks to be finished///";

    pool->waitForDone();
    qInfo() << "All tasks finished.";

    pool->startOnReservedThread(new Runnable("run on reserved thread"));
    pool->waitForDone();

    return app.exec();
}