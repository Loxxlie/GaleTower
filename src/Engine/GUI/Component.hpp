#ifndef GUICOMPONENT_H
#define GUICOMPONENT_H

#include <SFML/Graphics.hpp>

namespace GUI
{
class Component : public sf::Transformable, public sf::Drawable,
                  private sf::NonCopyable
{
public:
    Component();

    virtual bool isSelectable() const = 0;
    bool isSelected() const;
    virtual void select();
    virtual void deselect();
    virtual bool isActive() const;
    virtual void activate();
    virtual void deactivate();
    virtual void handleEvent(const sf::Event& event) = 0;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    bool selected;
    bool active;
};
}

#endif
