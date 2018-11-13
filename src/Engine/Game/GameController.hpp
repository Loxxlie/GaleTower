#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Engine/Core/BusNode.hpp"

class Game;
class Message;
class MessageBus;

class GameController : public BusNode
{
public:
    GameController(MessageBus *messageBus, Game *game);

private:
    Game *_game;

    void handleMessage(Message message);
};

#endif
