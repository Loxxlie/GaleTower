#ifndef SCENENODE_H
#define SCENENODE_H

#include <SFML/Graphics.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable,
                  private sf::NonCopyable
{
public:
    SceneNode();

    void        attachChild(SceneNode* child);
    SceneNode*  detachChild(const SceneNode& node);
private:
    std::vector<SceneNode*> children;
    SceneNode*              parent;

    virtual void draw(sf::RenderTarget& target,
                    sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target,
                    sf::RenderStates states) const { }
};

#endif