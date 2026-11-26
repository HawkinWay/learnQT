#include "DataProcessor.h"
#include "DataProcessorWorker.h"

#include <QDebug>

DataProcessor::DataProcessor(QObject *parent): QObject{parent}{
    m_dataProcessWorker = new DataProcessorWorker();
    m_dataProcessWorker->moveToThread(&m_workerThread);

    connect(
        &m_workerThread, &QThread::finished,
        m_dataProcessWorker, &QObject::deleteLater
    );
    connect(
        this, &DataProcessor::startRequested,
        m_dataProcessWorker, &DataProcessorWorker::doHeavyWork,
        Qt::QueuedConnection
    );

    connect(
        m_dataProcessWorker, &DataProcessorWorker::progressUpdate,
        this, &DataProcessor::on_progressUpdate
    );
    connect(
        m_dataProcessWorker, &DataProcessorWorker::workFinished,
        this, &DataProcessor::on_workFinished
    );

    m_workerThread.start();     // Begins execution of the thread by calling run().
    // run() default implementation simply calls exec().
    // exec() enters the event loop
}

DataProcessor::~DataProcessor(){
    qInfo() << "Destructor of DataProcessor associated with: " << m_itemName;
    m_workerThread.requestInterruption();
    m_workerThread.quit();
    m_workerThread.wait();
}

void DataProcessor::startProcessing(){
    qInfo() << "User started processing for item with name: " << m_itemName;
    m_workerThread.setObjectName(m_itemName + " thread");
    emit startRequested();
}

void DataProcessor::on_progressUpdate(int current, int total){
    emit progressUpdated(current, total);
}

void DataProcessor::on_workFinished(){
    qInfo() << "Data Processor with name: " << m_itemName << " recieved workFinished() signal from thread: " << m_workerThread.objectName(); 
    emit workFinished();
}