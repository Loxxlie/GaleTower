#include "Engine/Core/gamecontroller.hpp"
#include "Engine/Systems/messagebus.hpp"
#include "Engine/Core/game.hpp"

GameController::GameController(MessageBus *messageBus, Game* game)
: System(messageBus)
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