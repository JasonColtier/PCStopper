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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int OnDialValueChanged(int value) const;
    void OnAMPMButtonClicked() const;

private:
    Ui::MainWindow* ui;
    QDial* dial;
    QLabel* labelDialValue;
    QPushButton* am_pm_button;

    void SetupDialWithTime();
    void SetupAMPMButton();
};
#endif // MAINWINDOW_H
