#include "Engine/Systems/GameStateManager.hpp"

#include <iostream>

#include "Engine/Core/Message.hpp"
#include "Engine/Systems/GameState.hpp"
#include "Game/States/GreenCircle.hpp"

void GameStateManager::init()
{}

void GameStateManager::cleanup()
{}

void GameStateManager::pushState(GameState *state, bool pause_prev)
{
    std::cout << "NEW STATE TO STACK" << std::endl;
    if (pause_prev && !stateStack.empty())
    {
        std::cout << "pausing old state..." << std::endl;
        stateStack.back()->pause();
    }
    stateStack.push_back(state);
    stateStack.back()->init();
}

void GameStateManager::popState()
{
    std::cout << "REMOVING STATE FROM STACK" << std::endl;
    stateStack.back()->cleanup();
    delete stateStack.back();
    stateStack.pop_back();
}

void GameStateManager::handleEvents(sf::Event event)
{
    if (!stateStack.empty())
        stateStack.back()->handleEvents(event);
}

void GameStateManager::update()
{
    for (auto iter = stateStack.begin(); iter != stateStack.end(); iter++)
    {
        if (!(*iter)->isPaused())
            (*iter)->update();
    }
}

void GameStateManager::render(sf::RenderTarget& target) const
{
    for (auto iter = stateStack.begin(); iter != stateStack.end(); iter++)
    {
        if (!(*iter)->isHidden())
            (*iter)->render(target);
    }
}

void GameStateManager::handleMessage(Message message)
{
    if (message.event == "START_GREENCIRCLE")
    {
        GameState* green_circle = new GreenCircle(context, messageBus);
        pushState(green_circle);
    }
}