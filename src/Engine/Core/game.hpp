#ifndef GAME_H
#define GAME_H

#include "Engine/Systems/renderer.hpp"
#include "Engine/Systems/messagebus.hpp"

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

private:
    bool runningFlag;

    Renderer *renderer;
    MessageBus *messageBus;
};

#endif