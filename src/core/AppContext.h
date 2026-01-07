#pragma once
#include "services/InputService.h"
#include "services/NavigationService.h"
#include "services/SettingsService.h"
#include "services/UiService.h"

struct AppContext
{
    NavigationService nav;
    InputService input;
    SettingsService settings;
    UiService ui;
};
