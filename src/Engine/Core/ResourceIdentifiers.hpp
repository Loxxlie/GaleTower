#ifndef RESOURCEIDENTIFIERS_H
#define RESOURCEIDENTIFIERS_H

namespace sf
{
    class Font;
}

namespace Font
{
    enum ID
    {
        Development
    };
}

namespace Texture
{
    enum ID
    {
        None,
        NoneSelected
    };
}

typedef ResourceHolder<sf::Font, Font::ID> FontHolder;
typedef ResourceHolder<sf::Texture, Texture::ID> TextureHolder;

#endif