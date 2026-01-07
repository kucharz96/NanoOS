// core/ComponentList.h
#pragma once
#include "IComponent.h"

template <size_t N> class ComponentList
{
  public:
    void add(IComponent &c)
    {
        if (_count < N)
            _items[_count++] = &c;
    }

    void render(AppContext &ctx, const Rect &r)
    {
        for (size_t i = 0; i < _count; i++)
            _items[i]->render(ctx, r);
    }

    bool onAction(AppContext &ctx, Action a)
    {
        for (size_t i = 0; i < _count; i++)
            if (_items[i]->onAction(ctx, a))
                return true;
        return false;
    }

    bool tick(AppContext &ctx)
    {
        bool dirty = false;
        for (size_t i = 0; i < _count; i++)
            dirty |= _items[i]->tick(ctx);
        return dirty;
    }

  private:
    IComponent *_items[N]{};
    size_t _count = 0;
};
