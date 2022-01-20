#include "includes/mainwindow.h"
#include <QApplication>

#include "JCO_Tools/JcoPrint.h"

int main(int argc, char *argv[])
{
    LOG_COLOR(LogType::SUCCESS,"Start Main Application");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
