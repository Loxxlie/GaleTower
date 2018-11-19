#ifndef RESOURCEIDENTIFIERS_H
#define RESOURCEIDENTIFIERS_H

namespace sf
{
    class Font;
}

namespace Fonts
{
    enum ID
    {
        Development
    };
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;

#endif