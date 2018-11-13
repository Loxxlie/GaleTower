#ifndef BUSNODE_H
#define BUSNODE_H

#include <functional>

class Message;
class MessageBus;

class BusNode
{
public:
    BusNode(MessageBus *messageBus);

protected:
    MessageBus *messageBus;

    std::function<void(Message)> getNotifyFunc();
    void postMessage(std::string event, void *data=NULL);

    virtual void handleMessage(Message message) = 0;
};

#endif