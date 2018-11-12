#ifndef GREENCIRCLE_H
#define GREENCIRCLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Engine/Systems/messagebus.hpp"

class GameState;

class GreenCircle : public GameState
{
public:
    GreenCircle(MessageBus *messageBus) : GameState(messageBus) {}

    void init()
    {
        postMessage(std::string("SPAWN_GREEN_CIRCLE"));
    }

    void cleanup() {}

    void handleEvents(sf::Event event)
    {
        if (event.type == sf::Event::Closed)
        {
            postMessage(std::string("CLOSE_GAME"));
        }
    }

    void update() {}
    void render() {}

private:
    void handleMessage(Message message) {}
};

#endif