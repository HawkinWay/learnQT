#ifndef MEM_MANA_H
#define MEM_MANA_H

#include <QObject>

class MemMana: public QObject{
    Q_OBJECT
public:
    explicit MemMana(QString objName, QObject* parent = nullptr);

    ~MemMana();
};

#endif