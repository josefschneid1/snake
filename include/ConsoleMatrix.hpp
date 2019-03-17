#include "DisplayMatrixI.hpp"
#include "Point.hpp"
#include "ncurses.h"

class ConsoleMatrix : public Display::DisplayMatrixI
{
    int pairSnake;
    int pairEmpty;
public:
    ConsoleMatrix();
    virtual void set(Display::Point point,  Display::Color c) override;
    virtual void clear(Display::Color c = Display::Color{0,0,0}) override;
};