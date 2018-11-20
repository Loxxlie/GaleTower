#include "Engine/Game/Game.hpp"

#include "Engine/Core/Message.hpp"
#include "Engine/Systems/GameStateManager.hpp"
#include "Engine/Game/GameController.hpp"
#include "Engine/Core/ResourceIdentifiers.hpp"

#include "Game/States/DevMenuState.hpp"
#include "Engine/Core/Context.hpp"

Game::Game()
: runningFlag(false)
, messageBus(new MessageBus())
, gamecontroller(new GameController(messageBus, this))
, fontholder(FontHolder())
, textureholder(TextureHolder())
, window(new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!"))
, statemanager(new GameStateManager(Context(*window, textureholder, fontholder), messageBus))
{}

Game::~Game()
{
    delete messageBus;
    delete statemanager;
    delete gamecontroller;

    if(window->isOpen())
        window->close();
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
    statemanager->render(*window);
    window->display();
}

void Game::startup()
{
	fontholder.load(Font::Development, "resources/Fonts/dev-text.otf");
    textureholder.load(Texture::None, "resources/Textures/transparent.png");
    textureholder.load(Texture::NoneSelected, "resources/Textures/transparentselected.png");

    GameState* dev_menu = new DevMenuState(Context(*window, textureholder, fontholder), messageBus);
    statemanager->pushState(dev_menu);

    runningFlag = true;
}

void Game::shutdown()
{}

void Game::closeGame()
{
    window->close();
    runningFlag = false;
}