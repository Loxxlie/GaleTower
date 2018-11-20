#include "Engine/GUI/Button.hpp"
#include <SFML/Graphics.hpp>

namespace GUI
{

Button::Button(const FontHolder& fonts, const TextureHolder& textures)
: m_callback()
, m_normalTexture(textures.get(Texture::None))
, m_selectedTexture(textures.get(Texture::NoneSelected))
, m_text("", fonts.get(Font::Development), 14)
, m_isToggleable(false)
, m_sprite()
{
    m_sprite.setTexture(m_normalTexture);
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

    m_sprite.setTexture(m_selectedTexture);
}

void Button::deselect()
{
    Component::deselect();

    m_sprite.setTexture(m_normalTexture);
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