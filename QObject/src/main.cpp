#include <QCoreApplication>
#include <QMetaObject>
#include <QMetaProperty>

#include <memory>

#include "MyProp.h"
#include "MemMana.h"

int main(int argc, char* argv[]){
    QCoreApplication app(argc, argv);

    auto obj = std::make_unique<MyProp>(&app);
    QObject::connect(
        obj.get(), &MyProp::informationChanged,
        obj.get(), &MyProp::on_informationChanged
    );
    qDebug() << "obj->setProperty('information', 'Hello, world!')"; obj->setProperty("information", "Hello, world!");
    qDebug() << "obj->property('information'): " << obj->property("information");

    QObject::connect(
        obj.get(), &MyProp::valueChanged,
        obj.get(), &MyProp::on_valueChanged
    );
    qDebug() << "obj->getValue(): " << obj->getValue();
    qDebug() << "obj->setValue(369)"; obj->setValue(369);
    qDebug() << "obj->getValue(): " << obj->getValue();
    qDebug() << "obj->property('value'): " << obj->property("value");

    qInfo() << "---------- OBJECT INFO ----------";
    qInfo() << "Class name: " << obj->metaObject()->className();
    qInfo() << "Method count: " << obj->metaObject()->methodCount();
    qInfo() << "Superclass name: " << obj->metaObject()->superClass()->className();
    qInfo() << "Property count: " << obj->metaObject()->propertyCount();
    qInfo() << "Enumerator count: " << obj->metaObject()->enumeratorCount();

    qInfo() << "\n---------- PROPERTIES ----------";
    const auto* metaObj = obj->metaObject();
    for(int i = 0; i < metaObj->propertyCount(); i++){
        qInfo() << "Property[" << i << "]: " << metaObj->property(i).name();
    }

    qInfo() << "\n---------- METHODS ----------";
    for(int i = 0; i < metaObj->methodCount(); i++){
        qInfo() << "Method[" << i << "]: " << metaObj->method(i).name();
    }

    qInfo() << "\n---------- ENUMERATORS ----------";
    for(int i = 0; i < metaObj->enumeratorCount(); i++){
        qInfo() << "Enumerator[" << i << "]: " << metaObj->enumerator(i).name();
    }

    qInfo() << "\nMemory Management:";
    MemMana *grandparent = new MemMana("grandparent");
    MemMana *parent = new MemMana("parent", grandparent);
    MemMana *child1 = new MemMana("child1", parent);
    MemMana *child2 = new MemMana("child2", parent);
    MemMana *child3 = new MemMana("child3");
    child3->setParent(parent);
    delete grandparent;

    return app.exec();
}