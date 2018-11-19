#include "Engine/GUI/Component.hpp"

using namespace GUI;

Component::Component()
: selected(false)
, active(true)
{}

bool Component::isSelected() const
{
    return selected;
}

void Component::select()
{
    selected = true;
}

void Component::deselect()
{
    selected = false;
}

bool Component::isActive() const
{
    return active;
}

void Component::activate()
{
    active = true;
}

void Component::deactivate()
{
    active = false;
}

void Component::draw(sf::RenderTarget& target, sf::RenderStates states) const
{}
