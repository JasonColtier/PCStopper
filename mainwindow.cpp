#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDial>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    dial = ui->centralwidget->findChild<QDial*>("dial");
    Q_ASSERT(dial);

    labelDialValue = ui->centralwidget->findChild<QLabel*>("labelDialValue");
    Q_ASSERT(labelDialValue);

    connect(dial, &QDial::valueChanged, this, &MainWindow::OnDialValueChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnDialValueChanged(int value)
{

    if(value>6)
        value = value%6;
    else
        value +=6;

    if(value == 0)
        value = 6;
    
    QString text = QString::number(value);
    labelDialValue->setText(text);
}

