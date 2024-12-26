#include "generated/MenuBar.h"
#include "MenuBarInternal.h"

#include <QMenuBar>

#include "ActionInternal.h"
#include "IconInternal.h"
#include "MenuInternal.h"

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

    Action::HandleRef Handle_addMenu(HandleRef _this, Menu::HandleRef menu, const std::shared_ptr<Action::SignalHandler>& handler) {
        const auto menuWrapper = reinterpret_cast<Menu::SignalWrapper*>(menu);
        const auto action = MENUBAR_THIS->addMenu(menuWrapper->getActual());
        const auto actionWrapper = new Action::SignalWrapper(action, handler);
        return reinterpret_cast<Action::HandleRef>(actionWrapper);
    }

    Menu::HandleRef Handle_addMenu(HandleRef _this, const std::string& title, const std::shared_ptr<Menu::SignalHandler>& handler) {
        const auto menu = MENUBAR_THIS->addMenu(QString::fromStdString(title));
        const auto menuWrapper = new Menu::SignalWrapper(menu, handler);
        return reinterpret_cast<Menu::HandleRef>(menuWrapper);
    }

    Menu::HandleRef Handle_addMenu(HandleRef _this, Icon::HandleRef icon, const std::string& title, const std::shared_ptr<Menu::SignalHandler>& handler) {
        const auto menu = MENUBAR_THIS->addMenu(QICON_VALUE(icon), QString::fromStdString(title));
        const auto menuWrapper = new Menu::SignalWrapper(menu, handler);
        return reinterpret_cast<Menu::HandleRef>(menuWrapper);
    }

    Action::HandleRef Handle_addSeparator(HandleRef _this, const std::shared_ptr<Action::SignalHandler>& handler) {
        const auto action = MENUBAR_THIS->addSeparator();
        const auto actionWrapper = new Action::SignalWrapper(action, handler);
        return reinterpret_cast<Action::HandleRef>(actionWrapper);
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
