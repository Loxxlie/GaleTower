#ifndef GUIBUTTON_H
#define GUIBUTTON_H

#include "Engine/GUI/Component.hpp"
#include "Engine/Core/ResourceHolder.hpp"
#include "Engine/Core/ResourceIdentifiers.hpp"

#include <functional>

namespace GUI
{
class Button : public Component
{
public:
    typedef std::function<void()> Callback;

    Button(const FontHolder& fonts, const TextureHolder& textures);

    void setCallback(Callback callback);
    void setText(const std::string& text);
    void setToggle(bool flag);

    virtual bool isSelectable() const;
    virtual void select();
    virtual void deselect();
    virtual void activate();
    virtual void deactivate();

    virtual void handleEvent(const sf::Event& event);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    Callback m_callback;
    sf::Sprite m_sprite;
    const sf::Texture& m_normalTexture;
    const sf::Texture& m_selectedTexture;
    sf::Text m_text;
    bool m_isToggleable;

};
}

#endif