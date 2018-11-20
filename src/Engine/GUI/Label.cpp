#include "Engine/GUI/Label.hpp"
#include "SFML/Graphics.hpp"

namespace GUI
{

Label::Label(const std::string& text, const FontHolder& fonts)
: m_text(text, fonts.get(Font::Development), 16)
{}

void Label::setFont(const sf::Font& font)
{
    m_text.setFont(font);
}

void Label::setText(const std::string& text)
{
    m_text.setString(text);
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
    target.draw(m_text, states);
}

}