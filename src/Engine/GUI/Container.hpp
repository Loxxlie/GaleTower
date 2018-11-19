#ifndef GUICONTAINER_H
#define GUICONTAINER_H

#include "Engine/GUI/Component.hpp"

namespace GUI
{
class Container : public Component
{
public:
    Container();

    void addComponent(Component* component);

    virtual bool isSelectable() const;
    virtual void handleEvent(const sf::Event& event);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool hasSelection();

    void select(std::size_t index);
    void selectPrevious();
    void selectNext();

    std::vector<Component*> children;
    int selected_child;
};
}
#endif