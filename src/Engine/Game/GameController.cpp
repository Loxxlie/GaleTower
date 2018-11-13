#include "Engine/Game/GameController.hpp"

#include "Engine/Core/Message.hpp"
#include "Engine/Game/Game.hpp"

GameController::GameController(MessageBus *messageBus, Game* game)
: BusNode(messageBus)
{
    _game = game;
}

void GameController::handleMessage(Message message)
{
    if (message.event == "CLOSE_GAME")
    {
        std::cout << "GameController: Received message CLOSE_GAME" << std::endl;
        _game->closeGame();
    }
}