#include "Engine/Scene/SceneNode.hpp"

SceneNode::SceneNode()
{}

void SceneNode::attachChild(SceneNode* child)
{
    child->parent = this;
    this->children.push_back(child);
}

SceneNode* SceneNode::detachChild(const SceneNode& node)
{
    auto found = std::find_if(children.begin(), children.end(),
    [&] (SceneNode* p) -> bool { return p == &node; });

    if ( found == children.end() )
    {
        return nullptr;
    }

    SceneNode* result = (*found);
    result->parent = nullptr;
    children.erase(found);
    return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= this->getTransform();

    this->drawCurrent(target, states);

    for (auto iter = children.begin(); iter != children.end(); iter++)
    {
        (*iter)->draw(target, states);
    }
}