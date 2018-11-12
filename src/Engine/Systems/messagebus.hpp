#ifndef MESSAGEBUS_H
#define MESSAGEBUS_H

#include <iostream>
#include <functional>
#include <vector>
#include <queue>

class System;

struct Message
{
    System *sender;
    std::string event;
};

class MessageBus
{
public:
    MessageBus();

    void addReceiver(std::function<void(Message)> messageReceiver);
    void postMessage(Message message);
    void notify();

private:
    std::vector<std::function<void(Message)>> receivers;
    std::queue<Message> messages;
};

#endif