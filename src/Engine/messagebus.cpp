#include "messagebus.hpp"

#include <iostream>
#include <functional>
#include <vector>
#include <queue>

Message::Message(const std::string event)
{
    messageEvent = event;
}

std::string Message::getEvent()
{
    return messageEvent;
}

MessageBus::MessageBus() {}
MessageBus::~MessageBus() {}

void MessageBus::addReceiver(std::function<void(Message)> messageReceiver)
{
    receivers.push_back(messageReceiver);
}

void MessageBus::sendMessage(Message message)
{
    std::cout << "MessageBus: Pushing message " << message.getEvent() << std::endl;
    messages.push(message);
}

void MessageBus::notify()
{
    while(!messages.empty())
    {
        for(auto iter = receivers.begin(); iter != receivers.end(); iter++)
        {
            (*iter)(messages.front());
        }

        messages.pop();
    }
}
