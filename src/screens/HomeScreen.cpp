#include "../components/FooterHintsComponent.h"
#include "../components/HeaderComponent.h"
#include "../components/MenuListComponent.h"
#include "../core/Action.h"
#include "../core/AppContext.h"
#include "../core/BaseScreen.h"
#include "../core/ComponentList.h"
#include "../core/RouteId.h"

class HomeScreen : public BaseScreen
{
  public:
    RouteId routeId() const override
    {
        return RouteId::Home;
    }

    HomeScreen() : header("HOME"), menu(items, 2) // 2 elementy menu
    {
        components.add(header);
        components.add(menu);
        components.add(footer);
    }

    void onAction(AppContext &ctx, Action a) override
    {
        // najpierw dajemy komponentom szansę obsłużyć akcję
        if (components.onAction(ctx, a))
            _dirty = true;

        // logika screen-level: jeśli menu "kliknięte", to nawiguj
        if (menu.consumeClicked())
        {
            if (menu.selectedIndex() == 0)
                ctx.nav.navigateTo(RouteId::Settings);
            // else ... kolejne trasy
            _dirty = true;
        }
    }

    void tick(AppContext &ctx) override
    {
        if (components.tick(ctx))
            _dirty = true;
        if (_dirty)
            render(ctx);
    }

    void render(AppContext &ctx) override
    {
        _dirty = false;
        ctx.ui.clear();

        // Layout: header, menu, footer (ręcznie, prosto)
        header.render(ctx, Rect{0, 0, 0, 0});
        menu.render(ctx, Rect{10, 40, 220, 80});
        footer.render(ctx, Rect{10, 115, 220, 20});
    }

  private:
    bool _dirty = true;

    HeaderComponent header;
    FooterHintsComponent footer;

    const char *items[2] = {"Settings", "About"};
    MenuListComponent menu;

    ComponentList<8> components;
};
