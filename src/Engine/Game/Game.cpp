#include "Engine/Game/Game.hpp"

#include "Engine/Core/Message.hpp"
#include "Engine/Systems/GameStateManager.hpp"
#include "Engine/Game/GameController.hpp"
#include "Engine/Core/ResourceIdentifiers.hpp"

#include "Game/States/GreenCircle.hpp"

Game::Game()
{
    runningFlag = false;
    messageBus = new MessageBus();
    statemanager = new GameStateManager(messageBus);
    gamecontroller = new GameController(messageBus, this);
    fontholder = new FontHolder();

    window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!");
}

Game::~Game()
{
    delete messageBus;
    delete statemanager;
    delete gamecontroller;

    if(window->isOpen())
        window->close();
    delete window;
}

void Game::run()
{
    startup();
    
    while (runningFlag)
    {
        sf::Event event;
        while (window->pollEvent(event))
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
    window->clear();
    statemanager->render(*(window));
    window->display();
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
    window->close();
    runningFlag = false;
}