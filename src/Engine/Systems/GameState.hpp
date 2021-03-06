#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

#include "Engine/Core/BusNode.hpp"
#include "Engine/Core/SharedContext.hpp"

class Message;
class MessageBus;

class GameState : public BusNode {
public:
    GameState(SharedContext context, MessageBus *messageBus) : BusNode(messageBus), m_context(context) {}

    virtual void init() = 0;
    virtual void cleanup() = 0;

    virtual void pause() {  m_isPaused = true; }
    virtual void resume() { m_isPaused = false; }
    virtual void hide() { m_isHidden = true; }
    virtual void show() { m_isHidden = false; }

    bool isPaused() { return m_isPaused; }
    bool isHidden() { return m_isHidden; }

    virtual void handleEvents(sf::Event event) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderTarget& target) const = 0;

protected:
    SharedContext m_context;

private:
    bool m_isPaused = false;
    bool m_isHidden = false;
};

#endif