#ifndef RECIEVER_H
#define RECIEVER_H

#include <QObject>

class Reciever: public QObject{
    Q_OBJECT
public:
    explicit Reciever(QObject *parent = nullptr);

public slots:
    void on_event(QString message); 

private:


};

#endif
