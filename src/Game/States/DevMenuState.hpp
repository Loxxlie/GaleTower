#ifndef DEVMENUSTATE_H
#define DEVMENUSTATE_H

#include "Engine/Systems/GameState.hpp"
#include "Engine/GUI/Container.hpp"
#include "Engine/Core/ResourceHolder.hpp"
#include "Engine/Core/ResourceIdentifiers.hpp"
#include "Engine/Core/Context.hpp"

class DevMenuState : public GameState
{
public:
    DevMenuState(Context context, MessageBus *messageBus);

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