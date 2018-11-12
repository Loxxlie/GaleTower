#ifndef GAME_H
#define GAME_H

#include "Engine/Systems/renderer.hpp"
#include "Engine/Systems/messagebus.hpp"
#include "Engine/Core/gamestatemanager.hpp"
#include "Engine/Core/gamecontroller.hpp"

class Game
{
public:
    Game();
    ~Game();

    void run();
    void update();
    void render();
    void startup();
    void shutdown();

    void closeGame();

private:
    bool runningFlag;

    Renderer *renderer;
    MessageBus *messageBus;
    GameStateManager *statemanager;
    GameController *gamecontroller;
};

#endif