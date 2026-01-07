#pragma once
#include "IScreen.h"

class BaseScreen : public IScreen
{
  public:
    void onEnter(AppContext &ctx) override
    {
        render(ctx);
    }
    void onLeave(AppContext &) override
    {
    }

    void onAction(AppContext &, Action) override
    {
    }
    void tick(AppContext &) override
    {
    }
};
