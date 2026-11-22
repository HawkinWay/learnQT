#include "MyProp.h"

#include <QDebug>

MyProp::MyProp(QObject *parent): QObject{parent}{

}

int MyProp::getValue() const{
    return m_value;
}

void MyProp::setValue(int newValue){
    if(m_value == newValue)     return;

    m_value = newValue;
    emit valueChanged();
}

void MyProp::on_informationChanged(){
    qInfo() << "[on_informationChanged] information changed";
}

void MyProp::on_valueChanged(){
    qInfo() << "[on_valueChanged] value changed to: " << m_value;
}