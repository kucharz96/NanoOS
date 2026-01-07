#pragma once
#include "../KeyEvent.h"
#include <M5Cardputer.h>

// Input oparty o oficjalny pattern keysState() (M5 docs)
// - zbiera wpisane znaki do małej kolejki
// - zwraca po 1 zdarzeniu na poll()
class InputService
{
  public:
    bool poll(KeyEvent &out)
    {
        // 1) Jeśli mamy coś w kolejce, oddajemy od razu
        if (_qLen > 0)
        {
            out.down = true;
            out.ascii = _queue[0];
            out.keyCode = 0;
            shiftLeft();
            return true;
        }

        // 2) Wczytujemy nowe zdarzenia z klawiatury
        if (!M5Cardputer.Keyboard.isChange())
            return false;
        if (!M5Cardputer.Keyboard.isPressed())
            return false;

        auto status = M5Cardputer.Keyboard.keysState(); // <- zgodne z dokumentacją

        // znaki „normalne”
        for (auto c : status.word)
        {
            pushChar((char)c);
        }

        // backspace
        if (status.del)
        {
            pushChar('\b');
        }

        // enter
        if (status.enter)
        {
            pushChar('\n');
        }

        // 3) jeśli coś wpadło do kolejki, zwracamy 1 znak
        if (_qLen > 0)
        {
            out.down = true;
            out.ascii = _queue[0];
            out.keyCode = 0;
            shiftLeft();
            return true;
        }

        return false;
    }

  private:
    // prosta mała kolejka (ring buffer niepotrzebny na start)
    static constexpr int QSIZE = 16;
    char _queue[QSIZE]{};
    int _qLen = 0;

    void pushChar(char c)
    {
        if (_qLen >= QSIZE)
            return; // jak przepełni, ucinamy (prosto i stabilnie)
        _queue[_qLen++] = c;
    }

    void shiftLeft()
    {
        for (int i = 1; i < _qLen; i++)
            _queue[i - 1] = _queue[i];
        _qLen--;
    }
};
