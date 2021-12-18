#include "includes/mainwindow.h"
#include "../views/ui_mainwindow.h"
#include <QDial>
#include <QLabel>

#include "includes/TimeHelpers.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Get UI elements
    dial = ui->centralwidget->findChild<QDial*>("dial");
    Q_ASSERT(dial);
    labelDialValue = ui->centralwidget->findChild<QLabel*>("labelDialValue");
    Q_ASSERT(labelDialValue);

    //Connect signals
    connect(dial, &QDial::valueChanged, this, &MainWindow::OnDialValueChanged);

    //Init values
    labelDialValue->setText(QString::number(OnDialValueChanged(dial->value())));

    std::cout<<"time value "<<TimeHelpers::getCurrentTime();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::OnDialValueChanged(int value) const
{

    if(value>6)
        value = value%6;
    else
        value +=6;

    if(value == 0)
        value = 6;
    
    QString text = QString::number(value);
    LOG_COLOR(LogType::LOG,"Dial value changed to "<<text.toStdString());
    labelDialValue->setText(text);
    return value;
}

