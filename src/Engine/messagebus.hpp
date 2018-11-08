#ifndef MESSAGEBUS_H
#define MESSAGEBUS_H

#include <iostream>
#include <functional>
#include <vector>
#include <queue>

class Message
{
public:
    Message(const std::string event);
    std::string getEvent();

private:
    std::string messageEvent;
};

class MessageBus
{
public:
    MessageBus();
    ~MessageBus();

    void addReceiver(std::function<void(Message)> messageReceiver);
    void sendMessage(Message message);
    void notify();

private:
    std::vector<std::function<void(Message)>> receivers;
    std::queue<Message> messages;
};

#endif