#include "MemMana.h"

#include <QDebug>

MemMana::MemMana(QString objName, QObject* parent): QObject{parent}{
    this->setObjectName(objName);
    qInfo() << this->objectName() << "created!";
}


MemMana::~MemMana(){
    qInfo() << this->objectName() << "destroyed!";
}