#ifndef DATA_PROCESSOR_H
#define DATA_PROCESSOR_H

#include <QObject>
#include <QQmlEngine>
#include <QThread>

#include "DataProcessorWorker.h"

class DataProcessor: public QObject{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString itemName MEMBER m_itemName)
public:
    explicit DataProcessor(QObject *parent = nullptr);
    ~DataProcessor();

    Q_INVOKABLE void startProcessing();

signals:
    void startRequested();
    void progressUpdated(int current, int total);
    void workFinished();

private slots:
    void on_progressUpdate(int current, int total);
    void on_workFinished();

private:
    QThread m_workerThread;
    DataProcessorWorker *m_dataProcessWorker;
    QString m_itemName;
};

#endif