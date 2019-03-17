#pragma once
#include "DisplayMatrixI.hpp"

class LedMatrix : public Display::DisplayMatrixI
{
    
public:
    virtual void set(Display::Point point,  Display::Color c) override;
    virtual void clear(Display::Color c = Display::Color{0,0,0}) override;
};