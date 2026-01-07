#pragma once
#include <stdint.h>

enum class Action : uint8_t
{
    None,
    Up,
    Down,
    Left,
    Right,
    Enter,
    Back,
    GoHome,
    GoSettings
};
