#include "messagebus.hpp"

#include <iostream>
#include <functional>
#include <vector>
#include <queue>

MessageBus::MessageBus() {}

void MessageBus::addReceiver(std::function<void(Message)> messageReceiver)
{
    receivers.push_back(messageReceiver);
}

void MessageBus::postMessage(Message message)
{
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
