enum class GameState
{
    RUNNING,STOPPED,PAUSED
};


class Game
{
    GameState state;
public:
    Game();
    GameState getGameState();
    void changeGameState(GameState state);
};