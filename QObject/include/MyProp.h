#ifndef MY_PROP_H
#define MY_PROP_H

#include <QObject>

class MyProp: public QObject{
    Q_OBJECT
    Q_PROPERTY(
        QString information
        MEMBER m_info
        NOTIFY informationChanged
    )
    Q_PROPERTY(
        int value
        READ getValue
        WRITE setValue
        NOTIFY valueChanged
    )
public:
    explicit MyProp(QObject *parent = nullptr);

    enum MyEnum{
        Value1,
        Value2,
        Value3
    };  Q_ENUM(MyEnum)

    int getValue() const;
    void setValue(int newValue);

signals:
    void informationChanged();
    void valueChanged();

public slots:
    void on_informationChanged();
    void on_valueChanged();

private:
    QString m_info{};
    int m_value{0};
};

#endif  // MY_PROP_H