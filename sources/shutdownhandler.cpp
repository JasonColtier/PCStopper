#include "../includes/shutdownhandler.h"
#include "../includes/TimeHelpers.h"
#include <QTime>
#include "JCO_Tools/JcoPrint.h"


void ShutdownHandler::StopPCAtTime(const QTime targetTime) {
    LOG("shutting down to stop at "<<targetTime.toString().toUtf8().constData());

    int secondsLeft = QTime::currentTime().secsTo(targetTime);

    LOG("shutting down in "<<secondsLeft<<" seconds !");

    //https://www.ionos.fr/digitalguide/serveur/configuration/commandes-shutdown-par-cmd/

    string shutdownString = "shutdown /s /t "+std::to_string(secondsLeft);
    system(shutdownString.c_str());

}

void ShutdownHandler::AbortStop() {
    system("shutdown /a");
}
