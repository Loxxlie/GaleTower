#ifndef SYSTEM_H
#define SYSTEM_H

#include <functional>
#include "Engine/Systems/messagebus.hpp"

class System
{
public:
    System(MessageBus *messageBus);

    virtual void update() = 0;

protected:
    MessageBus *messageBus;

    std::function<void(Message)> getNotifyFunc();
    void send(Message message);

    virtual void handleMessage(Message message) = 0;
};

#endif