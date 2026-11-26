#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>


#include "WorkerThread.h"
#include "DataProcessor.h"
#include "DataProcessorWorker.h"

#if 0
int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    auto thread = std::make_unique<WorkerThread>();
    thread->setObjectName("Worker Thread");
    QThread::currentThread()->setObjectName("Main Thread");

    QObject::connect(
        thread.get(), &QThread::finished,
        &app, [](){ qInfo() << "Work is finished."; }
    );
    
    
    qInfo() << "Main thread name: " << QThread::currentThread()->objectName();
    qInfo() << thread->objectName() << "is running: " << thread->isRunning();
    thread->start();    // internally calls our run override
    qInfo() << "Starting thread " << thread->objectName();
    qInfo() << thread->objectName() << "is running: " << thread->isRunning();
    qInfo() << thread->objectName() << "wait for finish";
    thread->wait();     // like .join()
    qInfo() << thread->objectName() << "thread work is finished";
    qInfo() << thread->objectName() << "is running: " << thread->isRunning();
    qInfo() << thread->objectName() << "is finished: " << thread->isFinished();

    return app.exec();
}
#endif

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("DataProcessor", "Main");

    return app.exec();
}