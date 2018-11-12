#ifndef SYSTEM_H
#define SYSTEM_H

#include <functional>

class Message;
class MessageBus;

class System
{
public:
    System(MessageBus *messageBus);

protected:
    MessageBus *messageBus;

    std::function<void(Message)> getNotifyFunc();
    void postMessage(std::string event, void *data=NULL);

    virtual void handleMessage(Message message) = 0;
};

#endif