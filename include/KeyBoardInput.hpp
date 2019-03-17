#pragma once
#include <thread>
#include "InputI.hpp"
#include <mutex>
#include <ncurses.h>

class KeyBoardInput : public ControlInput::InputI
{
        bool isSingleStep = false;
public:
        virtual ControlInput::Key getInput() override;
        virtual void toggleSingleStep() override;
};