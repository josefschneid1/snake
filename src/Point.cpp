#include "Point.hpp"

Display::Point operator+(const Display::Point& p1, const Display::Point& p2)
{
    return Display::Point{p1.first + p2.first, p1.second + p2.second};
}

Display::Point operator-(const Display::Point& p1, const Display::Point& p2)
{
    return Display::Point{p1.first - p2.first, p1.second + p2.second};
}

Display::Point& operator+=(Display::Point& p1, const Display::Point& p2)
{
    p1.first += p2.first;
    p1.second += p2.second;
    return p1;
}

Display::Point& operator-=(Display::Point& p1, const Display::Point& p2)
{
    p1.first -= p2.first;
    p1.second -= p2.second;
    return p1;
}