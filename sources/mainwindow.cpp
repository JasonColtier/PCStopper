#include "includes/mainwindow.h"
#include "../views/ui_mainwindow.h"
#include "includes/shutdownhandler.h"
#include <QDial>
#include <QPushButton>
#include <QDateTimeEdit>
#include <QRadioButton>
#include <QTimer>

#include "includes/TimeHelpers.h"


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    labelDialValue = ui->labelDialValue;
    startTimerButton = ui->startTimerButton;
    dateTimeEdit = ui->dateTimeEdit;
    stopAtTimeRadio = ui->stopAtTimeRadio;
    stopInTimeRadio = ui->stopInTimeRadio;
    countDownLabel = ui->countDown;

    Q_ASSERT(startTimerButton);
    Q_ASSERT(labelDialValue);
    Q_ASSERT(dateTimeEdit);
    Q_ASSERT(stopAtTimeRadio);
    Q_ASSERT(stopInTimeRadio);

    dateTimeEdit->setTime(QTime::currentTime().addSecs(60));

    //Connect signals
    connect(startTimerButton, &QPushButton::clicked, this, &MainWindow::OnStartTimerButtonClicked);
//    connect(dateTimeEdit,&QDateTimeEdit::dateTimeChanged,this, &MainWindow::OnDateTimeChanged);
//    connect(stopAtTimeRadio,&QRadioButton::clicked,this,&MainWindow::OnStopAtTimeRadioButtonClicked);
//    connect(stopInTimeRadio,&QRadioButton::clicked,this,&MainWindow::OnStopInTimeRadioButtonClicked);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::TimerCountdown);

}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::OnStartTimerButtonClicked() {
    LOG("Button clicked !");

    if(!timerActive){
        QTime targetTime;

        if (stopAtTimeRadio->isChecked()) {
            targetTime = dateTimeEdit->time();
        } else if (stopInTimeRadio->isChecked()) {
            targetTime = QTime::currentTime().addMSecs(dateTimeEdit->time().msecsSinceStartOfDay());
        }

        timer->start();
        shutdownTargetTime = targetTime;
        ShutdownHandler::StopPCAtTime(targetTime);

        startTimerButton->setText("Stop timer");
    }else{
        timer->stop();
        ShutdownHandler::AbortStop();
        countDownLabel->setText("00:00:00");
    }

    timerActive = !timerActive;

}

void MainWindow::TimerCountdown() {
    LOG("timercountdown");

    QTime zeroTime = QTime::fromMSecsSinceStartOfDay(0);

    int secondsLeft = QTime::currentTime().secsTo(shutdownTargetTime);

    auto res = zeroTime.addSecs(secondsLeft);

    LOG("shutting down in "<<res.toString().toUtf8().constData()<<" seconds !");


    countDownLabel->setText(res.toString());

}




