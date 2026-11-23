#include "MainWindow.h"

/**
QMainWindow
└── centralWidget (QWidget)
    └── hbox (QHBoxLayout)
        ├── buttonGroup (QGroupBox)
        │   └── vboxButtonGroup (QVBoxLayout)
        │       ├── pushButton
        │       ├── radioButton
        │       └── checkBox
        ├── textInputGroup (QGroupBox)
        │   └── vboxTextInputGroup (QVBoxLayout)
        │       ├── lineEdit
        │       └── textEdit
        └── otherInputGroup (QGroupBox)
            └── vboxOtherInputGroup (QVBoxLayout)
                ├── comboBox
                ├── dial
                └── slider
*/

MainWindow::MainWindow(QWidget *parent): QMainWindow{parent}{
    this->setWindowTitle("QT Widgets");
    resize(640, 480);

    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    hbox = new QHBoxLayout;
    centralWidget->setLayout(hbox);

    buttonGroup = new QGroupBox("Button Group");
    pushButton = new QPushButton("Push Button");
    radioButton = new QRadioButton("Radio Button");
    checkBox = new QCheckBox("Check Box");
    vboxButtonGroup = new QVBoxLayout;
    vboxButtonGroup->addWidget(pushButton);
    vboxButtonGroup->addWidget(radioButton);
    vboxButtonGroup->addWidget(checkBox);
    buttonGroup->setLayout(vboxButtonGroup);
    hbox->addWidget(buttonGroup);

    textInputGroup = new QGroupBox("Text Inputs");
    lineEdit = new QLineEdit;
    textEdit = new QTextEdit;
    vboxTextInputGroup = new QVBoxLayout;
    vboxTextInputGroup->addWidget(lineEdit);
    vboxTextInputGroup->addWidget(textEdit);
    textInputGroup->setLayout(vboxTextInputGroup);
    hbox->addWidget(textInputGroup);

    otherInputGroup = new QGroupBox("Other Inputs");
    comboBox = new QComboBox;
    comboBox->addItems({"Item 1", "Item 2", "Item 3"});
    dial = new QDial;
    slider = new QSlider;
    slider->setOrientation(Qt::Horizontal);
    vboxOtherInputGroup = new QVBoxLayout;
    vboxOtherInputGroup->addWidget(comboBox);
    vboxOtherInputGroup->addWidget(dial);
    vboxOtherInputGroup->addWidget(slider);
    otherInputGroup->setLayout(vboxOtherInputGroup);
    hbox->addWidget(otherInputGroup);

}

MainWindow::~MainWindow(){

}