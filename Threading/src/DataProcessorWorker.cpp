#include "DataProcessorWorker.h"

#include <QDebug>
#include <chrono>

DataProcessorWorker::DataProcessorWorker(QObject *parent): QObject{parent}{
    static int i{1};
    QObject::setObjectName("DataProcessorWoker number: " + QString::number(i++));
    qInfo() << QObject::objectName() << " created";
}

DataProcessorWorker::~DataProcessorWorker(){
    qInfo() << QObject::objectName() << " destroyed";

}

void DataProcessorWorker::doHeavyWork(){
    const int STEP_NUMBERS{50};
    for(int i = 0; i < STEP_NUMBERS; i++){
        if(QThread::currentThread()->isInterruptionRequested()){
            qInfo() << "Work interrupted at step: " << i << " in thread " << QThread::currentThread()->objectName();
            return;
        }
        QThread::sleep(std::chrono::milliseconds(250));
        emit progressUpdate(i, STEP_NUMBERS);
    }
    qInfo() << "Worker ended in thread: " << QThread::currentThread()->objectName() << " using object " << QObject::objectName(); 
    emit workFinished();
}