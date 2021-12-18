#include "includes/mainwindow.h"
#include <QApplication>

#include "JCO_Tools/JcoPrint.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    LOG("Start Main Application");
    
    return a.exec();
}
