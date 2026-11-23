#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QDial>
#include <QSlider>

class MainWindow:public QMainWindow{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    QWidget *centralWidget;
    QHBoxLayout *hbox;

    QGroupBox *buttonGroup;
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QCheckBox *checkBox;
    QVBoxLayout *vboxButtonGroup;

    QGroupBox *textInputGroup;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QVBoxLayout *vboxTextInputGroup;

    QGroupBox *otherInputGroup;
    QComboBox *comboBox;
    QDial *dial;
    QSlider *slider;
    QVBoxLayout *vboxOtherInputGroup;
};

#endif