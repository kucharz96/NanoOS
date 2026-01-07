#pragma once
#include "Action.h"
#include "KeyEvent.h"
#include <M5Cardputer.h>

class KeyMapper
{
  public:
    static Action map(const KeyEvent &e)
    {
        // Specjalne klawisze (najstabilniej po stanie klawiatury)
        if (M5Cardputer.Keyboard.isKeyPressed(';'))
            return Action::Up;
        if (M5Cardputer.Keyboard.isKeyPressed('.'))
            return Action::Down;
        if (M5Cardputer.Keyboard.isKeyPressed(','))
            return Action::Left;
        if (M5Cardputer.Keyboard.isKeyPressed('/'))
            return Action::Right;
        if (M5Cardputer.Keyboard.isKeyPressed(KEY_ENTER))
            return Action::Enter;
        if (M5Cardputer.Keyboard.isKeyPressed(KEY_BACKSPACE))
            return Action::Back;

        // ASCII routing
        if (e.ascii == 'h' || e.ascii == 'H')
            return Action::GoHome;
        if (e.ascii == 's' || e.ascii == 'S')
            return Action::GoSettings;

        return Action::None;
    }
};
