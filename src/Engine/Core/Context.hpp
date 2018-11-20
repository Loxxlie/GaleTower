#ifndef CONTEXT_H
#define CONTEXT_H

#include "Engine/Core/ResourceHolder.hpp"
#include "Engine/Core/ResourceIdentifiers.hpp"

struct Context
{
    // Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, MessageBus& messageBus)
    Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts)
    : window(&window)
    //, messagebus(&messageBus)
    , textures(&textures)
    , fonts(&fonts)
    {}

    sf::RenderWindow* window;
    // MessageBus* messagebus;
    FontHolder* fonts;
    TextureHolder* textures;
};

#endif