#include "Engine/renderer.hpp"

Renderer::Renderer(MessageBus* messageBus)
: System(messageBus)
{
    window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
}

Renderer::~Renderer()
{
    if(window->isOpen())
        window->close();
    delete window;
}

void Renderer::handleMessage(Message message)
{
    if(message.getEvent() == "SPAWN_GREEN_CIRCLE")
    {
        std::cout << "Renderer: Received message SPAWN_GREEN_CIRCLE" << std::endl;
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);
        objects.push_back(shape);
    }
}

void Renderer::update()
{
    window->clear();
    for(auto iter = objects.begin(); iter != objects.end(); iter++)
        window->draw((*iter));
    window->display();
}

sf::RenderWindow* Renderer::getWindow()
{
    return window;
}