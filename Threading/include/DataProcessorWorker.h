#ifndef DATA_PROCESSOR_WORKER_H
#define DATA_PROCESSOR_WORKER_H

#include <QObject>
#include <QThread>

class DataProcessorWorker : public QObject
{
    Q_OBJECT
public:
    explicit DataProcessorWorker(QObject *parent = nullptr);
    ~DataProcessorWorker();
    
signals:
    void progressUpdate(int current, int total);
    void workFinished();

public slots:
    void doHeavyWork();
};

#endif