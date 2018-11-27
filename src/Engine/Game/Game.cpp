#include "Engine/Game/Game.hpp"

#include "Engine/Core/Message.hpp"
#include "Engine/Systems/GameStateManager.hpp"
#include "Engine/Game/GameController.hpp"
#include "Engine/Core/ResourceIdentifiers.hpp"

#include "Game/States/DevMenuState.hpp"
#include "Engine/Core/SharedContext.hpp"

Game::Game()
: m_isRunning(false)
, messageBus(new MessageBus())
, gamecontroller(new GameController(messageBus, this))
, fontholder(FontHolder())
, m_textureManager(TextureManager())
, m_window("SFML works!", sf::Vector2u(800, 600))
, statemanager(new GameStateManager(SharedContext(m_window, m_textureManager, fontholder), messageBus))
{
    restartClock();
}

Game::~Game()
{
    delete messageBus;
    delete statemanager;
    delete gamecontroller;
}

sf::Time Game::getElapsed(){ return m_elapsed; }
void Game::restartClock(){ m_elapsed = m_clock.restart(); }

void Game::run()
{
    startup();
    
    while (m_isRunning)
    {
        sf::Event event;
        while (m_window.pollEvents(event))
        {
            m_window.handleEvents(event);
            statemanager->handleEvents(event);
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
    m_window.beginDraw();
    statemanager->render(*(m_window.getWindow()));
    m_window.endDraw();
}

void Game::startup()
{
	fontholder.load(Font::Development, "resources/Fonts/dev-text.otf");
    // textureholder.load(Texture::None, "resources/Textures/transparent.png");
    // textureholder.load(Texture::NoneSelected, "resources/Textures/transparentselected.png");

    GameState* dev_menu = new DevMenuState(SharedContext(m_window, m_textureManager, fontholder), messageBus);
    statemanager->pushState(dev_menu);

    m_isRunning = true;
}

void Game::shutdown()
{}

void Game::closeGame()
{
    m_isRunning = false;
}