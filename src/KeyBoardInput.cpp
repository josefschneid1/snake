#include "KeyBoardInput.hpp"

ControlInput::Key KeyBoardInput::getInput()
{
    switch (getch())
    {
        case ERR:
            return ControlInput::Key::NO_INPUT;
            break;
        case KEY_UP:
            return ControlInput::Key::UP;
            break;
        case KEY_DOWN:
            return ControlInput::Key::DOWN;
            break;
        case KEY_LEFT:
            return ControlInput::Key::LEFT;
            break;
        case KEY_RIGHT:
            return ControlInput::Key::RIGHT;
            break;   
         case 'q':
            return ControlInput::Key::EXIT;
            break;
         case 's':
            return ControlInput::Key::STEP;
            break;
        default:
            return ControlInput::Key::NO_INPUT;
            break;
    }
}

void KeyBoardInput::toggleSingleStep()
{
    nodelay(stdscr, isSingleStep = !isSingleStep); 
}