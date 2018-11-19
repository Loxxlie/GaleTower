#ifndef GUILABEL_H
#define GUILABEL_H

#include "Engine/GUI/Component.hpp"
#include "Engine/Core/ResourceIdentities.hpp"

namespace GUI
{
class Label : public Component
{
public:
    Label(const std::string& text, const FontHolder& fonts, Fonts::ID font);

    void setText(const std::string& text);

    bool isSelectable() const;
    void handleEvent(const sf::Event& event);
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::Text text;
};
}

#endif