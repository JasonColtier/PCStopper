#include "PCS_Window.h"

#include <QPushButton>


#include "TOOLS/Print.h"

PCS_Window::PCS_Window()
{
    CreateWindow();
}

PCS_Window::PCS_Window(const int sizeX,const int sizeY)
{
    this->resize(sizeX, sizeY);

    LOG("test log");
    LOG_COLOR(LogType::INFO,"test log color");
    LOG_COLOR(LogType::SUCCESS,"test log color");
    LOG_COLOR(LogType::WARN,"test log color");
    LOG_COLOR(LogType::ERROR,"test log color");
    LOG_COLOR(LogType::LOG,"test log color");
    CreateWindow();
}

void PCS_Window::CreateWindow()
{
    QPushButton hello("Hello world!", this); //création d'un nouveau bouton
    // QObject::connect( &hello, SIGNAL(clicked()), &app, SLOT(quit()) );
    hello.move(60, 50);
    hello.resize(100, 100);
    hello.show();
}
