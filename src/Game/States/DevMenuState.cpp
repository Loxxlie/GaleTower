#include "Game/States/DevMenuState.hpp"

#include "Engine/GUI/Label.hpp"

DevMenuState::DevMenuState(MessageBus *messageBus, const FontHolder& fonts)
: GameState(messageBus)
, gui_container()
{
    GUI::Label title = new GUI::Label("Development Menu");
    

}