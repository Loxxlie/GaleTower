#include "Engine/Systems/system.hpp"
#include "Engine/Systems/messagebus.hpp"

#include <functional>

System::System(MessageBus *messageBus)
{
    this->messageBus = messageBus;
    this->messageBus->addReceiver(getNotifyFunc());
}

std::function<void(Message)> System::getNotifyFunc()
{
    auto messageListener = [=](Message message) -> void {
        handleMessage(message);
    };
    return messageListener;
}

void System::postMessage(std::string event, void *data)
{
    Message msg;
    msg.event = event;
    msg.sender = this;
    std::cout << "Posting message " << msg.event << std::endl;
    messageBus->postMessage(msg);
}