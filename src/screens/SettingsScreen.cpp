#include "../components/HeaderComponent.h"
#include "../core/Action.h"
#include "../core/AppContext.h"
#include "../core/BaseScreen.h"
#include "../core/RouteId.h"

class SettingsScreen : public BaseScreen
{
  public:
    SettingsScreen() : header("SETTINGS")
    {
    }

    RouteId routeId() const override
    {
        return RouteId::Settings;
    }

    void onAction(AppContext &ctx, Action a) override
    {
        if (a == Action::Up)
        {
            ctx.settings.inc(10);
            render(ctx);
        }
        if (a == Action::Down)
        {
            ctx.settings.dec(10);
            render(ctx);
        }
        // Back działa centralnie w App (router.goBack())
    }

    void render(AppContext &ctx) override
    {
        ctx.ui.clear();
        header.render(ctx, Rect{0, 0, 0, 0});
        ctx.ui.valueLine(10, 40, "Brightness: ", (int)ctx.settings.brightness(), "%");
        ctx.ui.line(10, 60, "UP/DOWN: change");
        ctx.ui.line(10, 75, "BACK: go back");
    }

  private:
    HeaderComponent header;
};
