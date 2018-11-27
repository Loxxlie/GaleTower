#include "Game/States/DevMenuState.hpp"

#include "Engine/GUI/Label.hpp"
#include "Engine/GUI/Button.hpp"
#include "Engine/Core/Message.hpp"

DevMenuState::DevMenuState(SharedContext context, MessageBus *messageBus)
: GameState(context, messageBus)
, m_gui_container()
{
    GUI::Label* title = new GUI::Label(std::string("Development Menu"), *(m_context.fonts));
    m_gui_container.addComponent(title);
    m_gui_container.setPosition(20, 20);

    GUI::Button* green_circle = new GUI::Button(*(m_context.fonts), m_context.textures);
    green_circle->setPosition(20, 20);
    green_circle->setText("Start SFML Test State");
    green_circle->setCallback([this] ()
    {
        std::cout << "button callback triggered" << std::endl;
        postMessage(std::string("START_GREENCIRCLE"));
    });
    green_circle->deactivate();
    m_gui_container.addComponent(green_circle);
}

void DevMenuState::init()
{}

void DevMenuState::cleanup()
{}

void DevMenuState::handleEvents(sf::Event event)
{
    if (event.type == sf::Event::Closed)
    {
        postMessage(std::string("CLOSE_GAME"));
    }

    m_gui_container.handleEvent(event);
}

void DevMenuState::update()
{

}

void DevMenuState::render(sf::RenderTarget& target) const
{
    target.draw(m_gui_container);
}

void DevMenuState::handleMessage(Message message)
{}