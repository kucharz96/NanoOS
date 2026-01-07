#pragma once
#include "../RouteId.h"

class NavigationService
{
  public:
    RouteId requested() const
    {
        return _requested;
    }
    void navigateTo(RouteId r)
    {
        _requested = r;
    }

  private:
    RouteId _requested = RouteId::Home;
};
