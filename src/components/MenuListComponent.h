// components/MenuListComponent.h
#pragma once
#include "../core/AppContext.h"
#include "../core/IComponent.h"

class MenuListComponent : public IComponent
{
  public:
    MenuListComponent(const char *const *items, int count) : _items(items), _count(count)
    {
    }

    int selectedIndex() const
    {
        return _sel;
    }

    void render(AppContext &ctx, const Rect &r) override
    {
        int y = r.y;
        for (int i = 0; i < _count; i++)
        {
            ctx.ui.line(r.x, y, (i == _sel) ? "> " : "  ");
            // prosto: wypisujemy item zaraz po znaczniku
            M5Cardputer.Display.print(_items[i]);
            y += 12;
        }
    }

    bool onAction(AppContext &ctx, Action a) override
    {
        (void)ctx;
        if (a == Action::Up)
        {
            if (_sel > 0)
                _sel--;
            _dirty = true;
            return true;
        }
        if (a == Action::Down)
        {
            if (_sel < _count - 1)
                _sel++;
            _dirty = true;
            return true;
        }
        if (a == Action::Enter)
        {
            _clicked = true;
            return true;
        }
        return false;
    }

    // Screen może zapytać czy klik był
    bool consumeClicked()
    {
        if (_clicked)
        {
            _clicked = false;
            return true;
        }
        return false;
    }

    bool tick(AppContext &) override
    {
        if (_dirty)
        {
            _dirty = false;
            return true;
        }
        return false;
    }

  private:
    const char *const *_items;
    int _count = 0;
    int _sel = 0;
    bool _clicked = false;
    bool _dirty = true;
};
