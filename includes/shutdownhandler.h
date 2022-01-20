#ifndef SHUTDOWNHANDLER_H
#define SHUTDOWNHANDLER_H


class ShutdownHandler
{
public :
    static void StopPCAtTime(int targetHour);

private:

    ShutdownHandler() = default;
};

#endif // SHUTDOWNHANDLER_H
