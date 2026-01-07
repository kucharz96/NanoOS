// components/HeaderComponent.h
#pragma once
#include "../core/AppContext.h"
#include "../core/IComponent.h"

class HeaderComponent : public IComponent
{
  public:
    HeaderComponent(const char *title) : _title(title)
    {
    }

    void render(AppContext &ctx, const Rect &r) override
    {
        (void)r;
        ctx.ui.header(_title);
    }

  private:
    const char *_title;
};
