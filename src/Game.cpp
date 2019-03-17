#include "Game.hpp"

Game::Game():state{GameState::STOPPED}
{}

GameState Game::getGameState()
{
    return state;
}

void Game::changeGameState(GameState state)
{
    this->state = state;
}