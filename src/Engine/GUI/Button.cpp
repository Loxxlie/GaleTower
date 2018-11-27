#include "Engine/GUI/Button.hpp"
#include <SFML/Graphics.hpp>

#include "Engine/Core/TextureManager.hpp"

namespace GUI
{

Button::Button(const FontHolder& fonts, TextureManager* textures)
: m_callback()
, m_textureManager(textures)
, m_text("", fonts.get(Font::Development), 14)
, m_isToggleable(false)
, m_sprite()
{
    std::cout << "Requiring None and NoneSelected Resources..." << std::endl;
    if (!textures->requireResource("None")) 
    {
        std::cout << "! Could not set up the texture: " << "None" << std::endl;
    }
    if (!textures->requireResource("NoneSelected")) 
    {
        std::cout << "! Could not set up the texture: " << "NoneSelected" << std::endl;
    }
    m_normalTexture = "None";
    m_selectedTexture = "NoneSelected";

    m_sprite.setTexture(*textures->getResource(m_normalTexture));
}

Button::~Button()
{
    std::cout << "Releasing None and NoneSelected Resources..." << std::endl;
    m_textureManager->releaseResource("None");
    m_textureManager->releaseResource("NoneSelected");
}

void Button::setCallback(Callback callback)
{
    m_callback = std::move(callback);
}

void Button::setText(const std::string& text)
{
    m_text.setString(text);
}

void Button::setToggle(bool flag)
{
    m_isToggleable = flag;
}

bool Button::isSelectable() const
{
    return true;
}

void Button::select()
{
    Component::select();

    m_sprite.setTexture(*m_textureManager->getResource(m_selectedTexture));
}

void Button::deselect()
{
    Component::deselect();

    m_sprite.setTexture(*m_textureManager->getResource(m_normalTexture));
}

void Button::activate()
{
    Component::activate();

    if (m_callback)
        m_callback();

    if (!m_isToggleable)
        deactivate();
}

void Button::deactivate()
{
    Component::deactivate();
}

void Button::handleEvent(const sf::Event& event)
{}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_sprite, states);
    target.draw(m_text, states);
}

}