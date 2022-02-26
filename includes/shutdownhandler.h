#ifndef SHUTDOWNHANDLER_H
#define SHUTDOWNHANDLER_H


class QTime;


class ShutdownHandler {
public :
    static void StopPCAtTime(QTime targetTime);
    static void AbortStop();

private:

    ShutdownHandler() = default;

};

#endif // SHUTDOWNHANDLER_H
