#ifndef TYPES_H
#define TYPES_H

#include <QObject>
#include <QThread>
#include <QDebug>

class Types: public QObject{
    Q_OBJECT
public:
    Types(QObject *parent = nullptr, const QString &name =  QString());

signals:
    void event();

public slots:
    void on_event();

private:

};

#endif