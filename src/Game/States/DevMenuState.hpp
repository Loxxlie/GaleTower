#ifndef DEVMENUSTATE_H
#define DEVMENUSTATE_H

#include "Engine/Systems/GameState.hpp"
#include "Engine/GUI/Container.hpp"
#include "Engine/Core/SharedContext.hpp"

class DevMenuState : public GameState
{
public:
    DevMenuState(SharedContext context, MessageBus *messageBus);

    void init();
    void cleanup();

    void handleEvents(sf::Event event);
    void update();
    void render(sf::RenderTarget& target) const;

private:
    void handleMessage(Message message);

    GUI::Container m_gui_container;
};

#endif