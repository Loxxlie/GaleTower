#include "system.hpp"
#include "messagebus.hpp"

#include <functional>

System::System(MessageBus *messageBus)
{
    messageBus = messageBus;
    messageBus->addReceiver(getNotifyFunc());
}

std::function<void(Message)> System::getNotifyFunc()
{
    auto messageListener = [=](Message message) -> void {
        handleMessage(message);
    };
    return messageListener;
}

void System::send(Message message)
{
    messageBus->sendMessage(message);
}