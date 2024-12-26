#include "generated/MenuBar.h"
#include "MenuBarInternal.h"

#include <QMenuBar>

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define MENUBAR_THIS (WRAPPER->getActual())

namespace MenuBar
{
    bool Handle_isDefaultUp(HandleRef _this) {
        return MENUBAR_THIS->isDefaultUp();
    }

    void Handle_setDefaultUp(HandleRef _this, bool state) {
        MENUBAR_THIS->setDefaultUp(state);
    }

    bool Handle_isNativeMenuBar(HandleRef _this) {
        return MENUBAR_THIS->isNativeMenuBar();
    }

    void Handle_setNativeMenuBar(HandleRef _this, bool state) {
        MENUBAR_THIS->setNativeMenuBar(state);
    }

    void Handle_clear(HandleRef _this) {
        MENUBAR_THIS->clear();
    }

    Action::HandleRef Handle_addMenu(HandleRef _this, Menu::HandleRef menu) {
        const auto ret = MENUBAR_THIS->addMenu(reinterpret_cast<QMenu*>(menu));
        return reinterpret_cast<Action::HandleRef>(ret);
    }

    Action::HandleRef Handle_addSeparator(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(MENUBAR_THIS->addSeparator());
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QMenuBar(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
