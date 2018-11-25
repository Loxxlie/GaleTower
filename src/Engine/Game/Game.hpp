#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "Engine/Core/ResourceHolder.hpp"
#include "Engine/Core/ResourceIdentifiers.hpp"
#include "Engine/Core/Window.hpp"

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

    sf::Time getElapsed();
	void restartClock();

private:
    bool m_isRunning;

    sf::Clock m_clock;
	sf::Time m_elapsed;

    MessageBus *messageBus;
    GameStateManager *statemanager;
    GameController *gamecontroller;

    FontHolder fontholder;
    TextureHolder textureholder;
    Window m_window;
};

#endif