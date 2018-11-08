#ifndef RENDERER_H
#define RENDERER_H

#include "Engine/system.hpp"
#include "Engine/messagebus.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Renderer : public System
{
public:
    Renderer(MessageBus* messageBus);
    ~Renderer();

    void update();
    sf::RenderWindow* getWindow();

private:
    sf::RenderWindow *window;
    std::vector<sf::CircleShape> objects;

    void handleMessage(Message message);
};

#endif