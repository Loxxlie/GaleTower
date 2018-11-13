#ifndef GAME_H
#define GAME_H

class Renderer;
class MessageBus;
class GameStateManager;
class GameController;

class Game
{
public:
    Game();
    ~Game();

    void run();
    void update();
    void render();
    void startup();
    void shutdown();

    void closeGame();

private:
    bool runningFlag;

    Renderer *renderer;
    MessageBus *messageBus;
    GameStateManager *statemanager;
    GameController *gamecontroller;
};

#endif