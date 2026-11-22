#include <QApplication>

#include <thread>
#include <chrono>

#include "Sender.h"
#include "Reciever.h"
#include "Dialog.h"
#include "Types.h"

using chs = std::chrono::seconds;

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    Sender *sender = new Sender(&app);
    Reciever *reciever = new Reciever(&app);

    QObject::connect(
        sender, &Sender::event,
        reciever, &Reciever::on_event
    );

    emit sender->event("Hello!");

#if 0
    Dialog d;

    qDebug() << "Wait for 3 seconds...";
    std::this_thread::sleep_for(chs(3));

    d.show();
#endif

    qDebug() << "\n-----------Connect Types---------------";

    QThread::currentThread()->setObjectName("Main Thread");

    Types *source = new Types(nullptr, "source");
    Types *destination = new Types(nullptr, "destination");
    
    QThread thread;
    QObject::connect(&thread, &QThread::finished, destination, &QObject::deleteLater);
    QObject::connect(&thread, &QThread::finished, source, &QObject::deleteLater);
    thread.start();
    thread.setObjectName("Seperate thread");
    destination->moveToThread(&thread);


    QObject::connect(
        source, &Types::event,
        destination, &Types::on_event,
        static_cast<Qt::ConnectionType>(Qt::QueuedConnection | Qt::UniqueConnection)
    );
    QObject::connect(
        source, &Types::event,
        destination, &Types::on_event,
        static_cast<Qt::ConnectionType>(Qt::QueuedConnection | Qt::UniqueConnection)
    );

    qInfo() << "\nEmitting signal event() from " << QThread::currentThread();
    emit source->event();

    thread.wait(3000);
    thread.quit();

    return app.exec();
}