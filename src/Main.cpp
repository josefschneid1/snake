#include <iostream>
#include <chrono>
#include "LedMatrix.hpp"
#include "Snake.hpp"
#include "KeyBoardInput.hpp"
#include "Game.hpp"
#include "DisplayMatrixI.hpp"
#include "InputI.hpp"
#include "ConsoleMatrix.hpp"
#include <string>

using namespace std::literals::chrono_literals;

void startGameLoop(Game &game, Display::DisplayMatrixI &matrix, ControlInput::InputI &input)
{
    Snake snake{&matrix, Display::Color{255, 255, 255}};
    game.changeGameState(GameState::RUNNING);

    while (game.getGameState() == GameState::RUNNING)
    {
        if (ControlInput::Key key = input.getInput(); key != ControlInput::Key::NO_INPUT)
        {
            switch (key)
            {
            case ControlInput::Key::UP:
                snake.changeDirection(Direction::UP);
                break;
            case ControlInput::Key::DOWN:
                snake.changeDirection(Direction::DOWN);
                break;
            case ControlInput::Key::LEFT:
                snake.changeDirection(Direction::LEFT);
                break;
            case ControlInput::Key::RIGHT:
                snake.changeDirection(Direction::RIGHT);
                break;
            case ControlInput::Key::EXIT:
                game.changeGameState(GameState::STOPPED);
                break;
            case ControlInput::Key::STEP:
                input.toggleSingleStep();
                break;
            default:
                break;
            }
        }
        snake.move();
        std::this_thread::sleep_for(100ms);
    }
}

void initNCurses()
{
    initscr();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    noecho();
    curs_set(0);
    start_color();
}

void cleanUpNCurses()
{
    endwin();
}

int main()
{
    initNCurses();
    Game game;
    //LedMatrix matrix{};
    ConsoleMatrix matrix{};
    KeyBoardInput input;
    startGameLoop(game, matrix, input);
    cleanUpNCurses();
    return 0;
}