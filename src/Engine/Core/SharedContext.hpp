#ifndef SHAREDCONTEXT_H
#define SHAREDCONTEXT_H

#include "Engine/Core/ResourceHolder.hpp"
#include "Engine/Core/ResourceIdentifiers.hpp"

class Window;
class TextureManager;

struct SharedContext
{
    SharedContext(Window& window, TextureManager& textures, FontHolder& fonts)
    : window(&window)
    , textures(&textures)
    , fonts(&fonts)
    {}

    Window* window;
    FontHolder* fonts;
    TextureManager* textures;
};

#endif