/*
    A basic example of a 3D spinning cube, using
    javidx9's console game engine.

    The header file olcConsoleGameEngine.h is provided
    under the One Lone Coder license and can be found at
    the top.
*/

#include "examples/cube.h"

int main()
{
    Engine engine;

    if (engine.ConstructConsole(256, 240, 4, 4))
        engine.Start();

    return 0;
}