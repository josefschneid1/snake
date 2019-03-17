#include "Snake.hpp"

Display::Point directionToPointOffset(Direction dir)
{
    size_t dx,dy;
    switch(dir)
    {
        case Direction::UP:
        dx = 0; dy = -1;
        break;
        case Direction::DOWN:
        dx = 0; dy = 1;
        break;
        case Direction::LEFT:
        dx = -1; dy = 0;
        break;
        case Direction::RIGHT:
        dx = 1; dy = 0;
        break;
        default:
        break;
    }
    return {dx,dy};
}

Snake::Snake(Display::DisplayMatrixI* dMatrix,Display::Color color,  size_t defaultLength):
snakeParts(defaultLength),dMatrix{dMatrix}, direction{Direction::RIGHT},
headPos{defaultLength-1}, color{color}
{
    for(size_t i = 0; i < defaultLength; ++i)
    {
        snakeParts.at(i).first = i;
        dMatrix->set(snakeParts[i],color);
    }
}

void Snake::move()
{
    const auto calcTailPos = [this]()->size_t
    {
        return ( headPos + 1 ) % snakeParts.size();
    };
    dMatrix->set(snakeParts[calcTailPos()], Display::Color{0,0,0});
    size_t newHeadPos = calcTailPos();
    snakeParts[newHeadPos] = snakeParts[headPos] + directionToPointOffset(direction);
    headPos = newHeadPos;
    dMatrix->set(snakeParts[headPos], color);
}

void Snake::changeDirection(Direction direction)
{
    this->direction = direction;
}