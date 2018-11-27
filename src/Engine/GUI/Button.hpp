#ifndef GUIBUTTON_H
#define GUIBUTTON_H

#include "Engine/GUI/Component.hpp"

#include <functional>

class TextureManager;
class FontManager;

namespace GUI
{
class Button : public Component
{
public:
    typedef std::function<void()> Callback;

    Button(FontManager* fonts, TextureManager* textures);
    ~Button();

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

    TextureManager* m_textureManager;
    FontManager* m_fontManager;
    Callback m_callback;
    sf::Sprite m_sprite;
    std::string m_normalTexture;
    std::string m_selectedTexture;
    std::string m_font;
    sf::Text m_text;
    bool m_isToggleable;

};
}

#endif