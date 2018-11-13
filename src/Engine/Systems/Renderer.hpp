#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Engine/Core/BusNode.hpp"

class Message;
class MessageBus;

class Renderer : public BusNode
{
public:
    Renderer(MessageBus* messageBus);
    ~Renderer();

    void render();
    sf::RenderWindow* getWindow();

private:
    sf::RenderWindow *window;
    std::vector<sf::CircleShape> objects;

    void handleMessage(Message message);
};

#endif