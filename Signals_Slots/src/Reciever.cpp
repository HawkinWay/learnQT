#include "Reciever.h"

#include <QDebug>

Reciever::Reciever(QObject *parent): QObject{parent}{

}

void Reciever::on_event(QString message){
    qInfo() << "Executing slot inside: " << this;
    qInfo() << "[on_event] Recieve message: " << message;
}