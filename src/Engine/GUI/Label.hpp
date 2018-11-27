#ifndef GUILABEL_H
#define GUILABEL_H

#include "Engine/GUI/Component.hpp"
#include <string>

class FontManager;

namespace GUI
{
class Label : public Component
{
public:
    Label(const std::string& text, FontManager* fonts);

    void setText(const std::string& text);
    void setFont(const sf::Font& font);

    bool isSelectable() const;
    void handleEvent(const sf::Event& event);
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    FontManager* m_fontManager;

    sf::Text m_text;
    std::string m_font;
};
}

#endif