#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "Engine/Core/ResourceHolder.hpp"
#include "Engine/Core/ResourceIdentifiers.hpp"

class Renderer;
class MessageBus;
class GameStateManager;
class GameController;

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

    MessageBus *messageBus;
    GameStateManager *statemanager;
    GameController *gamecontroller;

    FontHolder fontholder;
    TextureHolder textureholder;
    sf::RenderWindow* window;
};

#endif