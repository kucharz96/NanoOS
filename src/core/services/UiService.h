#pragma once
#include <M5Cardputer.h>

class UiService
{
  public:
    void clear()
    {
        M5Cardputer.Display.clear(BLACK);
        M5Cardputer.Display.setTextColor(WHITE);
    }

    void header(const char *title)
    {
        M5Cardputer.Display.setTextSize(2);
        M5Cardputer.Display.setCursor(10, 10);
        M5Cardputer.Display.print(title);
        M5Cardputer.Display.setTextSize(1);
    }

    void line(int x, int y, const char *text)
    {
        M5Cardputer.Display.setCursor(x, y);
        M5Cardputer.Display.print(text);
    }

    void valueLine(int x, int y, const char *label, int value, const char *suffix = "")
    {
        M5Cardputer.Display.setCursor(x, y);
        M5Cardputer.Display.print(label);
        M5Cardputer.Display.print(value);
        M5Cardputer.Display.print(suffix);
    }
};
