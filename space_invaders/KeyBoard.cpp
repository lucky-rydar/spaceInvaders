#include "KeyBoard.h"

KeyBoard::KeyBoard()
{
}

bool KeyBoard::isPressed(int key)
{
    return (GetKeyState(key) & 0x8000);
}
