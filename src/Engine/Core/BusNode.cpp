#include "Engine/Core/BusNode.hpp"

#include <iostream>

#include "Engine/Core/Message.hpp"

BusNode::BusNode(MessageBus *messageBus)
{
    this->messageBus = messageBus;
    this->messageBus->addReceiver(getNotifyFunc());
}

std::function<void(Message)> BusNode::getNotifyFunc()
{
    auto messageListener = [=](Message message) -> void {
        handleMessage(message);
    };
    return messageListener;
}

void BusNode::postMessage(std::string event, void *data)
{
    Message msg;
    msg.event = event;
    msg.sender = this;
    std::cout << "Posting message " << msg.event << std::endl;
    messageBus->postMessage(msg);
}