// core/IComponent.h
#pragma once
#include "Action.h"

struct AppContext;

struct Rect
{
    int x, y, w, h;
};

class IComponent
{
  public:
    virtual ~IComponent() = default;

    // render w obrębie rect (jak template w danym miejscu)
    virtual void render(AppContext &ctx, const Rect &r) = 0;

    // komponent może zareagować na akcję; zwraca true jeśli "obsłużył"
    virtual bool onAction(AppContext &ctx, Action a)
    {
        (void)ctx;
        (void)a;
        return false;
    }

    // tick na animacje/timery; zwraca true jeśli wymaga redraw
    virtual bool tick(AppContext &ctx)
    {
        (void)ctx;
        return false;
    }
};
