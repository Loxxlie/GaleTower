#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Engine/Core/BusNode.hpp"

class Message;
class MessageBus;
class GameState;

class GameStateManager : public BusNode
{
public:
    GameStateManager(MessageBus *messageBus) : BusNode(messageBus) {}

    void init();
    void cleanup();

    void pushState(GameState *state, bool pause_prev=true);
    void popState();

    void handleEvents(sf::Event event);
    void update();
    void render(sf::RenderTarget& target) const;

private:
    std::vector<GameState*> stateStack;

    void handleMessage(Message message);
};

#endif