#pragma once

namespace ControlInput
{

enum class Key
{
    UP, DOWN, LEFT, RIGHT, NO_INPUT, EXIT, STEP
};

class InputI
{

public:
    virtual Key getInput() = 0;
    virtual ~InputI() = default;
    virtual void toggleSingleStep() = 0;
};

}