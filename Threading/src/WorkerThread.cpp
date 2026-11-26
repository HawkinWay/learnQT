#include "WorkerThread.h"

#include <QDebug>

void WorkerThread::run(){
    doSth();
}

void WorkerThread::doSth(){
    for (int i = 0; i < 500000; ++i) {
        volatile double result = 0;
        for (int j = 0; j < 10000; ++j) {
            result += sqrt(i * j);
        }

        if(i % 100'000 == 0){
            qInfo() << "Working Iteration [" << i << "] on thread: " << QThread::currentThread()->objectName();
        }
    }
}