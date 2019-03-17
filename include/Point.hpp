#pragma once
#include <cstdlib>
#include <utility>

namespace Display
{
/* 
Point(x,y)
*/
using Point = std::pair<size_t,size_t>;

}

Display::Point operator+(const Display::Point& p1, const Display::Point& p2);

Display::Point operator-(const Display::Point& p1, const Display::Point& p2);

Display::Point& operator+=(Display::Point& p1, const Display::Point& p2);

Display::Point& operator-=(Display::Point& p1, const Display::Point& p2);
