#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <functional>
#include <vector>
#include <queue>

class BusNode;

struct Message
{
    BusNode *sender;
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