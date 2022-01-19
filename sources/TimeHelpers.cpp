#include "includes/TimeHelpers.h"

#include "JCO_Tools/JcoPrint.h"


string TimeHelpers::getCurrentTime()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    string s = "Time : ";
    s += std::to_string((now->tm_year + 1900)).append("-").append(std::to_string((now->tm_mon + 1))).append("-").append(std::to_string(now->tm_mday)).append("\n");
    return s;
}

int TimeHelpers::getCurrentHour()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    return now->tm_hour;
}

AM_PM TimeHelpers::getCurrentTimeFrame()
{
    if(getCurrentHour()>12)
    {
        return PM;
    }
    return AM;
}
