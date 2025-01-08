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

    Action::HandleRef Handle_actionAt(HandleRef _this, Point pt) {
        if (const auto action = MENUBAR_THIS->actionAt(toQPoint(pt)); action != nullptr) {
            const auto wrapper = wrapperForQObject(action);
            assert(wrapper != nullptr);
            return reinterpret_cast<Action::HandleRef>(wrapper);
        }
        return nullptr;
    }

    Rect Handle_actionGeometry(HandleRef _this, Action::HandleRef act) {
        const auto actionWrapper = reinterpret_cast<Action::SignalWrapper*>(act);
        return toRect(MENUBAR_THIS->actionGeometry(actionWrapper->getActual()));
    }

    Action::HandleRef Handle_activeAction(HandleRef _this) {
        if (const auto action = MENUBAR_THIS->activeAction(); action != nullptr) {
            const auto wrapper = wrapperForQObject(action);
            assert(wrapper != nullptr);
            return reinterpret_cast<Action::HandleRef>(wrapper);
        }
        return nullptr;
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

    void Handle_clear(HandleRef _this) {
        MENUBAR_THIS->clear();
    }

    Widget::HandleRef Handle_cornerWidget(HandleRef _this, const std::optional<Corner>& corner) {
        const auto qCorner = optionOrDefaultStaticCast(corner, Qt::TopRightCorner);
        if (const auto widget = MENUBAR_THIS->cornerWidget(qCorner); widget != nullptr) {
            const auto wrapper = wrapperForQObject(widget);
            assert(wrapper != nullptr);
            return reinterpret_cast<Widget::HandleRef>(wrapper);
        }
        return nullptr;
    }

    Action::HandleRef Handle_insertMenu(HandleRef _this, Action::HandleRef before, Menu::HandleRef menu, const std::shared_ptr<Action::SignalHandler>& actionHandler) {
        const auto beforeWrapper = reinterpret_cast<Action::SignalWrapper*>(before);
        const auto menuWrapper = reinterpret_cast<Menu::SignalWrapper*>(menu);
        const auto action = MENUBAR_THIS->insertMenu(beforeWrapper->getActual(), menuWrapper->getActual());
        const auto actionWrapper = new Action::SignalWrapper(action, actionHandler);
        return reinterpret_cast<Action::HandleRef>(actionWrapper);
    }

    Action::HandleRef Handle_insertSeparator(HandleRef _this, Action::HandleRef before, const std::shared_ptr<Action::SignalHandler>& actionHandler) {
        const auto beforeWrapper = reinterpret_cast<Action::SignalWrapper*>(before);
        const auto action = MENUBAR_THIS->insertSeparator(beforeWrapper->getActual());
        const auto actionWrapper = new Action::SignalWrapper(action, actionHandler);
        return reinterpret_cast<Action::HandleRef>(actionWrapper);
    }

    void Handle_setActiveAction(HandleRef _this, Action::HandleRef act) {
        const auto actionWrapper = reinterpret_cast<Action::SignalWrapper*>(act);
        MENUBAR_THIS->setActiveAction(actionWrapper->getActual());
    }

    void Handle_setCornerWidget(HandleRef _this, Widget::HandleRef widget, const std::optional<Corner>& corner) {
        const auto widgetWrapper = reinterpret_cast<Widget::SignalWrapper*>(widget);
        const auto qCorner = optionOrDefaultStaticCast(corner, Qt::TopRightCorner);
        MENUBAR_THIS->setCornerWidget(widgetWrapper->getActual(), qCorner);
    }

    // seems like this is already implemented in Widget, and it's virtual, so why is it listed as a slot on QMenuBar in the docs?
    // void Handle_setVisible(HandleRef _this, bool visible) {
    //     MENUBAR_THIS->setVisible(visible);
    // }

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

    HandleRef create(const std::shared_ptr<SignalHandler>& handler, const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        const auto wrapper = new SignalWrapper(new QMenuBar(qParent), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

}
