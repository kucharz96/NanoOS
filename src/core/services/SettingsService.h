#pragma once
#include <stdint.h>

class SettingsService
{
  public:
    uint8_t brightness() const
    {
        return _brightness;
    }
    void setBrightness(uint8_t v)
    {
        _brightness = (v > 100) ? 100 : v;
    }

    void inc(uint8_t step = 10)
    {
        setBrightness((_brightness + step) > 100 ? 100 : (_brightness + step));
    }
    void dec(uint8_t step = 10)
    {
        setBrightness((_brightness < step) ? 0 : (_brightness - step));
    }

  private:
    uint8_t _brightness = 50;
};
