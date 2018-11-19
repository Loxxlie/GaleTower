#ifndef DEVMENUSTATE_H
#define DEVMENUSTATE_H

#include "Engine/Systems/GameState.hpp"
#include "Engine/GUI/Container.hpp"

class DevMenuState : public GameState
{
public:
    DevMenuState(MessageBus *messageBus, const FoldHolder& fonts);

    void init();
    void cleanup();

    void handleEvents(sf::Event event);
    void update();
    void render();

private:
    void handleMessage(Message message);

    GUI::Container gui_container;
};

#endif