#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;
class QLabel;
class QDateTimeEdit;
class QRadioButton;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include "JCO_Tools/JcoPrint.h"
#include "TimeHelpers.h"
#include <QTime>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void OnStartTimerButtonClicked();
//    void OnDateTimeChanged(const QDateTime& dateTime);
//    void OnStopAtTimeRadioButtonClicked(bool clicked);
//    void OnStopInTimeRadioButtonClicked(bool clicked);

    void TimerCountdown();

private:
    Ui::MainWindow* ui;
    QLabel* labelDialValue;
    QLabel* countDownLabel;
    QLabel* versionLabel;
    QPushButton* startTimerButton;
    QDateTimeEdit* dateTimeEdit;
    QRadioButton* stopAtTimeRadio;
    QRadioButton* stopInTimeRadio;

    QTimer* timer;
    QTime shutdownTargetTime;
    bool timerActive = false;

    const QString VERSION = "1.0.0";
};
#endif // MAINWINDOW_H
