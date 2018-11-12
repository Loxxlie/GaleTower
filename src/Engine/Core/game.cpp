
#include "Engine/Core/game.hpp"
#include "Game/States/greencircle.hpp"

Game::Game()
{
    runningFlag = false;
    messageBus = new MessageBus();
    renderer = new Renderer(messageBus);
    statemanager = new GameStateManager(messageBus);
    gamecontroller = new GameController(messageBus, this);
}

Game::~Game()
{
    delete renderer;
    delete messageBus;
    delete statemanager;
    delete gamecontroller;
}

void Game::run()
{
    startup();
    
    while (runningFlag)
    {
        sf::Event event;
        while (renderer->getWindow()->pollEvent(event))
            statemanager->handleEvents(event);

        update();
        render();
    }

    shutdown();
}

void Game::update()
{
    messageBus->notify();
}

void Game::render()
{
    renderer->render();
}

void Game::startup()
{
    GameState* green_circle = new GreenCircle(messageBus);
    statemanager->pushState(green_circle);

    runningFlag = true;
}

void Game::shutdown()
{}

void Game::closeGame()
{
    renderer->getWindow()->close();
    runningFlag = false;
}