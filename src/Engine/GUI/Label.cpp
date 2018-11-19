#include "Engine/GUI/Label.hpp"

namespace GUI
{

Label::Label(const std::string& text, const FontHolder& fonts)
: text(text, fonts.get(Fonts::Development), 16)
{}

void Label::setFont(Fonts::ID fontId)
{
    
}

void Label::setText(const std::string& text)
{
    text.setString(text);
}

bool Label::isSelectable() const
{
    return false;
}

void Label::handleEvent(const sf::Event& event)
{}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(text, states);
}

}