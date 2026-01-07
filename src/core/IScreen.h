#pragma once
#include "Action.h"
#include "RouteId.h"

struct AppContext;

class IScreen
{
  public:
    virtual ~IScreen() = default;
    virtual RouteId routeId() const = 0;

    virtual void onEnter(AppContext &ctx) = 0;
    virtual void onLeave(AppContext &ctx) = 0;

    virtual void onAction(AppContext &ctx, Action a) = 0;
    virtual void tick(AppContext &ctx) = 0;
    virtual void render(AppContext &ctx) = 0;
};
