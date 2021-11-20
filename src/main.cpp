//This line includes the QApplication class definition. There has to be exactly one QApplication object in every application that uses Qt.
//QApplication manages various application-wide resources, such as the default font and cursor.
#include <qapplication.h>


#include <qpushbutton.h>

#include "PCS_Window.h"

int main(int argc, char** argv)
{
    //argc is the number of command-line arguments and argv is the array of command-line arguments.
    //This is a C/C++ feature. It is not specific to Qt; however, Qt needs to process these arguments (see following).
    QApplication app(argc, argv);

    PCS_Window mainWindow(300,300);
    mainWindow.show();

    return app.exec();
}
