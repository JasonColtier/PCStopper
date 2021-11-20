#ifndef PCS_Window_H
#define PCS_Window_H
#include <qwidget.h>

class PCS_Window : public QWidget
{
public:
    PCS_Window();
    PCS_Window(int sizeX,int sizeY);

private:
    void CreateWindow();
    
};

#endif

