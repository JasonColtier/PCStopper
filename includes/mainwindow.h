#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;
class QDial;
class QLabel;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include "JCO_Tools/JcoPrint.h"
#include "TimeHelpers.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void OnDialValueChanged(int value);
    void OnAMPMButtonClicked();
    void OnStartTimerButtonClicked() const;

private:
    Ui::MainWindow* ui;
    QDial* dial;
    QLabel* labelDialValue;
    QPushButton* amPmButton;
    QPushButton* startTimerButton;
    AM_PM selectedTimeFrame;
    int targetHour;

    void SetupDialWithTime();
    void SetupAMPMButton();
};
#endif // MAINWINDOW_H
