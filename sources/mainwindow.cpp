#include "includes/mainwindow.h"
#include "../views/ui_mainwindow.h"
#include <QDial>
#include <QLabel>
#include <QPushButton>

#include "includes/TimeHelpers.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Get UI elements
    dial = ui->dial;
    Q_ASSERT(dial);
    labelDialValue = ui->labelDialValue;
    Q_ASSERT(labelDialValue);
    am_pm_button = ui->am_pm_button;

    //Connect signals
    connect(dial, &QDial::valueChanged, this, &MainWindow::OnDialValueChanged);
    connect(am_pm_button, &QPushButton::clicked, this, &MainWindow::OnAMPMButtonClicked);

    SetupDialWithTime();
    SetupAMPMButton();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::OnDialValueChanged(int value) const
{
    if (value > 6)
        value = value % 6;
    else
        value += 6;

    if (value == 0)
        value = 6;

    QString text = QString::number(value);
    LOG_COLOR(LogType::LOG, "Dial value changed to "<<text.toStdString());
    labelDialValue->setText(text);
    return value;
}

void MainWindow::OnAMPMButtonClicked() const
{
    LOG("AM PM Button clicked ! ");

}

void MainWindow::SetupDialWithTime()
{
    LOG("dial value set to "<<TimeHelpers::getCurrentHour()); 

    //le dial prend la valeur de l'heure actuelle
    dial->setValue(TimeHelpers::getCurrentHour()+6);
}

void MainWindow::SetupAMPMButton()
{
    LOG("seting up AM / PM button");
    if(TimeHelpers::getCurrentTimeFrame() == AM)
        am_pm_button->setText("AM");
    else
        am_pm_button->setText("PM");
}
