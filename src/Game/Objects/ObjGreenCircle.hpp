#ifndef OBJ_GREENCIRCLE_H
#define OBJ_GREENCIRCLE_H

#include "Engine/Scene/SceneNode.hpp"

#include <iostream>

class ObjGreenCircle : public SceneNode
{
public:
    ObjGreenCircle() : shape(sf::CircleShape(100.f)) {
        shape.setFillColor(sf::Color::Green);
    }

    void drawCurrent(sf::RenderTarget& target,
                    sf::RenderStates states) const
    {
        target.draw(shape, states);
    }
private:
    sf::CircleShape shape;
};

#endif
