#include "Types.h"

Types::Types(QObject *parent, const QString &name): QObject{parent}{
    setObjectName(name);
    qInfo() << this << "created on" << QThread::currentThread();
}

void Types::on_event(){
    qInfo() << "Executing slot on_event() on: " << QThread::currentThread();
}