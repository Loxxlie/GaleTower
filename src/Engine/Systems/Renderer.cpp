#include "Engine/Systems/Renderer.hpp"

#include <iostream>

#include "Engine/Core/Message.hpp"

Renderer::Renderer(MessageBus* messageBus)
: BusNode(messageBus)
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
{}

void Renderer::render()
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