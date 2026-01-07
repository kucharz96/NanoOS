#pragma once
#include "AppContext.h"
#include "KeyMapper.h"
#include "Router.h"
#include <M5Cardputer.h>

class App
{
  public:
    App(AppContext &ctx, Router &router) : _ctx(ctx), _router(router)
    {
    }

    void begin(RouteId initial)
    {
        M5Cardputer.begin();
        _router.start(initial);
    }

    void loop()
    {
        M5Cardputer.update();

        KeyEvent e;
        if (_ctx.input.poll(e) && e.down)
        {
            Action a = KeyMapper::map(e);

            // Centralny BACK jak w frameworku
            if (a == Action::Back)
            {
                _router.goBack();
            }
            else if (a == Action::GoHome)
            {
                _ctx.nav.navigateTo(RouteId::Home);
            }
            else if (a == Action::GoSettings)
            {
                _ctx.nav.navigateTo(RouteId::Settings);
            }
            else
            {
                _router.dispatchAction(a);
            }
        }

        _router.tick();
        _router.navigateIfNeeded();
    }

  private:
    AppContext &_ctx;
    Router &_router;
};
