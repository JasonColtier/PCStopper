#include "includes/TimeHelpers.h"


string TimeHelpers::getCurrentTime()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    string s = "Time : ";
    s += std::to_string((now->tm_year + 1900)).append("-").append(std::to_string((now->tm_mon + 1))).append("-").append(std::to_string(now->tm_mday)).append("\n");
    return s;
}
