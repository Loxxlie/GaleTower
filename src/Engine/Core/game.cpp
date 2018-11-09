
#include "Engine/Core/game.hpp"

Game::Game()
{
    runningFlag = false;
    messageBus = new MessageBus();
    renderer = new Renderer(messageBus);
}

Game::~Game()
{
    delete renderer;
    delete messageBus;
}

void Game::run()
{
    startup();
    
    while (runningFlag)
    {
        sf::Event event;
        while (renderer->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                renderer->getWindow()->close();
                runningFlag = false;
            }
        }

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
    renderer->update();
}

void Game::startup()
{
    messageBus->sendMessage(std::string("SPAWN_GREEN_CIRCLE"));

    runningFlag = true;
}

void Game::shutdown()
{}