#include "core/App.h"
#include "core/AppContext.h"
#include "core/Router.h"
#include "screens/HomeScreen.cpp"
#include "screens/SettingsScreen.cpp"

AppContext appCtx;

HomeScreen home;
SettingsScreen settings;

RouteEntry routes[] = {
    {RouteId::Home, &home},
    {RouteId::Settings, &settings},
};

Router router(appCtx, routes, sizeof(routes) / sizeof(routes[0]));
App app(appCtx, router);

void setup()
{
    app.begin(RouteId::Home);
}
void loop()
{
    app.loop();
}
