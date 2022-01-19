#ifndef TimeHelpers_H
#define TimeHelpers_H
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

enum AM_PM
{
    AM,
    PM
};

class TimeHelpers
{
public:
    static string getCurrentTime();
    static int getCurrentHour();
    
    /**
     * \brief Retourne AM ou PM selon le moment de la journée
     */
    static AM_PM getCurrentTimeFrame();
};

#endif

