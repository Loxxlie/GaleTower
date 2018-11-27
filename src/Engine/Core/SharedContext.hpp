#ifndef SHAREDCONTEXT_H
#define SHAREDCONTEXT_H

class Window;
class TextureManager;
class FontManager;

struct SharedContext
{
    SharedContext(Window& window, TextureManager& textures, FontManager& fonts)
    : window(&window)
    , textures(&textures)
    , fonts(&fonts)
    {}

    Window* window;
    FontManager* fonts;
    TextureManager* textures;
};

#endif