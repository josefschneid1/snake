#pragma once
#include <vector>
#include <cstdlib>
#include "DisplayMatrixI.hpp"
#include "Point.hpp"

enum class Direction
{
    UP,DOWN,LEFT,RIGHT,
};

class Snake
{
    std::vector<Display::Point> snakeParts;
    Display::DisplayMatrixI* dMatrix;
    Direction direction;
    size_t headPos;
    Display::Color color;
public:
    Snake(Display::DisplayMatrixI* dMatrix, Display::Color color, size_t defaultLength = 3);
    void move();
    void changeDirection(Direction dir);
};

Display::Point directionToPointOffset(Direction dir);