#include "ConsoleMatrix.hpp"

ConsoleMatrix::ConsoleMatrix():
pairSnake{1}, pairEmpty{2}
{
    init_pair(1, COLOR_BLUE, COLOR_RED);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
}

void ConsoleMatrix::set(Display::Point point,  Display::Color c)
{ 
    int pair = c.red + c.green + c.blue == 0 ? pairEmpty : pairSnake;   
    attron(COLOR_PAIR(pair));
    mvaddch(point.second, point.first, ' ');
    attroff(COLOR_PAIR(pair));
    refresh();
}

void ConsoleMatrix::clear(Display::Color c)
{
    ::clear();
    refresh();
}