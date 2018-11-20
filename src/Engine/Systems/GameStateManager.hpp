#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Engine/Core/BusNode.hpp"
#include "Engine/Core/Context.hpp"

class Message;
class MessageBus;
class GameState;
struct Context;

class GameStateManager : public BusNode
{
public:
    GameStateManager(Context context, MessageBus *messageBus) : BusNode(messageBus), context(context) {}

    void init();
    void cleanup();

    void pushState(GameState *state, bool pause_prev=true);
    void popState();

    void handleEvents(sf::Event event);
    void update();
    void render(sf::RenderTarget& target) const;

private:
    std::vector<GameState*> stateStack;
    Context context;

    void handleMessage(Message message);
};

#endif