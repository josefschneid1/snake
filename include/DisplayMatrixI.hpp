#pragma once
#include "Point.hpp"

namespace Display
{
struct Color
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

class DisplayMatrixI
{
public:
    virtual void set(Point point,  Color c) = 0;
    virtual void clear(Color c = Color{0,0,0}) = 0;
    virtual ~DisplayMatrixI() = default;
};
}
