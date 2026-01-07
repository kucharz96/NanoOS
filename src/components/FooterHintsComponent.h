// components/FooterHintsComponent.h
#pragma once
#include "../core/AppContext.h"
#include "../core/IComponent.h"

class FooterHintsComponent : public IComponent
{
  public:
    void render(AppContext &ctx, const Rect &r) override
    {
        ctx.ui.line(r.x, r.y, "UP/DOWN: move  ENTER: select  BACK: back");
    }
};
