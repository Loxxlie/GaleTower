#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Engine/Core/gamestate.hpp"
#include "Engine/Systems/messagebus.hpp"

class GameStateManager : public System
{
public:
    GameStateManager(MessageBus *messageBus) : System(messageBus) {}

    void init();
    void cleanup();

    void pushState(GameState *state, bool pause_prev=true);
    void popState();

    void handleEvents(sf::Event event);
    void update();
    void render();

private:
    std::vector<GameState*> stateStack;

    void handleMessage(Message message) {}
};

#endif