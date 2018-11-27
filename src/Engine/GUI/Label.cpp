#include "Engine/GUI/Label.hpp"
#include "SFML/Graphics.hpp"
#include "Engine/Core/FontManager.hpp"

#include <iostream>

namespace GUI
{

Label::Label(const std::string& text, FontManager* fonts)
: m_fontManager(fonts)
{
    if (!m_fontManager->requireResource("Development")) 
    {
        std::cout << "! Could not set up the font: " << "Development" << std::endl;
    }

    m_font = "Development";

    m_text = sf::Text(text, *m_fontManager->getResource(m_font), 16);
}

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