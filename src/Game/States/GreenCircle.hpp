#ifndef GREENCIRCLE_H
#define GREENCIRCLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Engine/Systems/GameState.hpp"
#include "Game/Objects/ObjGreenCircle.hpp"

class Message;
class MessageBus;

class GreenCircle : public GameState
{
public:
    GreenCircle(MessageBus *messageBus) : GameState(messageBus) {}

    void init()
    {
        circle = new ObjGreenCircle();
    }

    void cleanup() 
    {
        delete circle;
    }

    void handleEvents(sf::Event event)
    {
        if (event.type == sf::Event::Closed)
        {
            postMessage(std::string("CLOSE_GAME"));
        }
    }

    void update() {}
    void render(sf::RenderTarget& target) const
    {
        target.draw(*circle);
    }

private:
    void handleMessage(Message message) {}

    ObjGreenCircle* circle;
};

#endif