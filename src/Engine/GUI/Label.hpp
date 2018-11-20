#ifndef GUILABEL_H
#define GUILABEL_H

#include "Engine/GUI/Component.hpp"
#include "Engine/Core/ResourceHolder.hpp"
#include "Engine/Core/ResourceIdentifiers.hpp"

namespace GUI
{
class Label : public Component
{
public:
    Label(const std::string& text, const FontHolder& fonts);

    void setText(const std::string& text);
    void setFont(const sf::Font& font);

    bool isSelectable() const;
    void handleEvent(const sf::Event& event);
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::Text m_text;
};
}

#endif