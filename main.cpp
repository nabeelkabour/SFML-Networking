#include "olcPixelGameEngine.h"
#include "Game.h"
#include "Command.h"
#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
    if (game.Construct(SCREENWIDTH, SCREENHEIGHT, 2, 2))
        game.Start();

    return 0;
}
