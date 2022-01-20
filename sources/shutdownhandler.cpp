#include "../includes/shutdownhandler.h"
#include "../includes/TimeHelpers.h"
#include "JCO_Tools/JcoPrint.h"

void ShutdownHandler::StopPCAtTime(int targetHour)
{
    LOG("stopping pc at "<<targetHour);

    //https://www.ionos.fr/digitalguide/serveur/configuration/commandes-shutdown-par-cmd/
    //shutdown /f /t sec
//    system("shutdown /s /t 1000");


//todo : handle next day
    LOG("shutting down in "<<targetHour-TimeHelpers::getCurrentHour()<<" h");
}


