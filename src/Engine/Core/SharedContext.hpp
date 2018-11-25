#ifndef SHAREDCONTEXT_H
#define SHAREDCONTEXT_H

#include "Engine/Core/ResourceHolder.hpp"
#include "Engine/Core/ResourceIdentifiers.hpp"

class Window;

struct SharedContext
{
    // SharedContext(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, MessageBus& messageBus)
    SharedContext(Window& window, TextureHolder& textures, FontHolder& fonts)
    : window(&window)
    //, messagebus(&messageBus)
    , textures(&textures)
    , fonts(&fonts)
    {}

    Window* window;
    // MessageBus* messagebus;
    FontHolder* fonts;
    TextureHolder* textures;
};

#endif