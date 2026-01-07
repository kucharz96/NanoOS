#pragma once
#include "AppContext.h"
#include "IScreen.h"
#include "RouteId.h"
#include <stddef.h>

struct RouteEntry
{
    RouteId id;
    IScreen *screen;
};

class Router
{
  public:
    Router(AppContext &ctx, RouteEntry *entries, size_t count) : _ctx(ctx), _entries(entries), _count(count)
    {
    }

    void start(RouteId initial)
    {
        _current = find(initial);
        _ctx.nav.navigateTo(initial);
        if (_current)
        {
            _current->onEnter(_ctx);
            _current->render(_ctx);
        }
    }

    void navigateIfNeeded()
    {
        if (!_current)
            return;

        RouteId req = _ctx.nav.requested();
        if (req == _current->routeId())
            return;

        IScreen *next = find(req);
        if (!next)
            return;

        // push current to history
        pushHistory(_current->routeId());

        // switch
        _current->onLeave(_ctx);
        _current = next;
        _current->onEnter(_ctx);
        _current->render(_ctx);
    }

    void goBack()
    {
        if (!_current)
            return;
        if (_histSize == 0)
            return;

        RouteId prev = popHistory();
        if (prev == _current->routeId())
            return;

        IScreen *next = find(prev);
        if (!next)
            return;

        // ustawiamy requested, żeby zachować jeden mechanizm
        _ctx.nav.navigateTo(prev);
        navigateIfNeeded();
    }

    void dispatchAction(Action a)
    {
        if (_current && a != Action::None)
            _current->onAction(_ctx, a);
    }

    void tick()
    {
        if (_current)
            _current->tick(_ctx);
    }

  private:
    IScreen *find(RouteId r)
    {
        for (size_t i = 0; i < _count; i++)
        {
            if (_entries[i].id == r)
                return _entries[i].screen;
        }
        return nullptr;
    }

    void pushHistory(RouteId r)
    {
        if (_histSize >= HIST_MAX)
            return; // prosto: ucinamy jak pełny
        _history[_histSize++] = r;
    }

    RouteId popHistory()
    {
        return _history[--_histSize];
    }

    static constexpr int HIST_MAX = 8;
    RouteId _history[HIST_MAX]{};
    int _histSize = 0;

    AppContext &_ctx;
    RouteEntry *_entries;
    size_t _count;
    IScreen *_current = nullptr;
};
