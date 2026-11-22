#include "Dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QDialog *parent): QDialog{parent}, ui{new Ui::Dialog}{
    ui->setupUi(this);
    m_timer = new QTimer();
    QObject::connect(
        m_timer, &QTimer::timeout,
        this, &Dialog::on_timeout
    );
    m_timer->start(1000);
}

Dialog::~Dialog(){
    delete ui;
}

void Dialog::on_timeout(){
    m_counter++;
    ui->lcdNumber->display(m_counter);
}
