#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Engine/Systems/system.hpp"
#include "Engine/Systems/messagebus.hpp"

class Renderer : public System
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