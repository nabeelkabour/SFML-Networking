#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "SFML/Graphics.hpp"
#include "olcPixelGameEngine.h"
#include "Command.h"

class InputHandler
{
public:
    Command* _buttonX = nullptr;
    Command* _buttonY = nullptr;
    Command* _buttonA = nullptr;
    Command* _buttonB = nullptr;

public:
    Command* handleInput(olc::PixelGameEngine* _game)
    {
        if (_game->GetKey(olc::Key::D).bPressed) return _buttonX;

        return NULL;
    }
};

#endif