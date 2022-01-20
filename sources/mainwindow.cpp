#include "includes/mainwindow.h"
#include "../views/ui_mainwindow.h"
#include "includes/shutdownhandler.h"
#include <QDial>
#include <QPushButton>


#include "includes/TimeHelpers.h"


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);


    //Get UI elements
    dial = ui->dial;
    Q_ASSERT(dial);
    labelDialValue = ui->labelDialValue;
    Q_ASSERT(labelDialValue);
    amPmButton = ui->am_pm_button;
    Q_ASSERT(amPmButton);
    startTimerButton = ui->startTimerButton;
    Q_ASSERT(startTimerButton);

    //Connect signals
    connect(dial, &QDial::valueChanged, this, &MainWindow::OnDialValueChanged);
    connect(amPmButton, &QPushButton::clicked, this, &MainWindow::OnAMPMButtonClicked);
    connect(startTimerButton, &QPushButton::clicked, this, &MainWindow::OnStartTimerButtonClicked);

    SetupDialWithTime();
    SetupAMPMButton();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::OnDialValueChanged(int value) {
    if (value > 6)
        value = value % 6;
    else
        value += 6;

    if (value == 0)
        value = 6;

    QString text = QString::number(value);
    LOG_COLOR(LogType::LOG, "Dial value changed to " << text.toStdString());
    labelDialValue->setText(text);
    targetHour = value;
}

void MainWindow::OnAMPMButtonClicked() {
    if (selectedTimeFrame == AM) {
        amPmButton->setText("PM");
        selectedTimeFrame = PM;
        LOG("AM PM BUtton Blicked ! selected time is : PM");

    } else {
        amPmButton->setText("AM");
        selectedTimeFrame = AM;
        LOG("AM PM BUtton Blicked ! selected time is : AM");
    }


}

void MainWindow::OnStartTimerButtonClicked() const {
    LOG("Button clicked !");

    ShutdownHandler::StopPCAtTime(targetHour+(12*selectedTimeFrame));
}

void MainWindow::SetupDialWithTime() {
    LOG("dial value set to " << TimeHelpers::getCurrentHour());

    //le dial prend la valeur de l'heure actuelle
    dial->setValue(TimeHelpers::getCurrentHour() + 6);
}

void MainWindow::SetupAMPMButton() {
    LOG("seting up AM / PM button");
    if (TimeHelpers::getCurrentTimeFrame() == AM) {
        amPmButton->setText("AM");
        selectedTimeFrame = AM;
    } else{
        amPmButton->setText("PM");
        selectedTimeFrame = PM;
    }
}
