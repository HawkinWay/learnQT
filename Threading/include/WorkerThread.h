#ifndef WORKER_THREAD_H
#define WORKER_THREAD_H

#include <QThread>

class WorkerThread: public QThread{
    Q_OBJECT
public:
    WorkerThread() = default;

protected:
    void run() override;

private:
    void doSth();
};

#endif