#include "generated/Menu.h"
#include "MenuInternal.h"

// #include <QObject>

#include "util/convert.h"
#include "IconInternal.h"

#include "ActionInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define MENU_THIS (WRAPPER->getActual())

namespace Menu
{
    Icon::OwnedRef Handle_getIcon(HandleRef _this) {
        return ICON_HEAP_NEW(MENU_THIS->icon());
    }

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        MENU_THIS->setIcon(QICON_VALUE(icon));
    }

    bool Handle_separatorsCollasible(HandleRef _this) {
        return MENU_THIS->separatorsCollapsible();
    }

    void Handle_setSeparatorsCollapsible(HandleRef _this, bool state) {
        MENU_THIS->setSeparatorsCollapsible(state);
    }

    bool Handle_isTearOffEnabled(HandleRef _this) {
        return MENU_THIS->isTearOffEnabled();
    }

    void Handle_setTearOffEnabled(HandleRef _this, bool state) {
        MENU_THIS->setTearOffEnabled(state);
    }

    std::string Handle_title(HandleRef _this) {
        return MENU_THIS->title().toStdString();
    }

    void Handle_setTitle(HandleRef _this, const std::string& title) {
        MENU_THIS->setTitle(QString::fromStdString(title));
    }

    bool Handle_toolTipsVisible(HandleRef _this) {
        return MENU_THIS->toolTipsVisible();
    }

    void Handle_setToolTipsVisible(HandleRef _this, bool visible) {
        MENU_THIS->setToolTipsVisible(visible);
    }

    Action::HandleRef Handle_actionAt(HandleRef _this, Point pos) {
        if (const auto action = MENU_THIS->actionAt(toQPoint(pos)); action != nullptr) {
            const auto wrapper = wrapperForQObject(action);
            return reinterpret_cast<Action::HandleRef>(wrapper);
        }
        return nullptr;
    }

    Rect Handle_actionGeometry(HandleRef _this, Action::HandleRef act) {
        const auto wrapper = reinterpret_cast<Action::SignalWrapper*>(act);
        return toRect(MENU_THIS->actionGeometry(wrapper->getActual()));
    }

    Action::HandleRef Handle_activeAction(HandleRef _this) {
        if (const auto action = MENU_THIS->activeAction(); action != nullptr) {
            const auto wrapper = wrapperForQObject(action);
            return reinterpret_cast<Action::HandleRef>(wrapper);
        }
        return nullptr;
    }

    Action::HandleRef Handle_addMenu(HandleRef _this, HandleRef menu, const std::shared_ptr<Action::SignalHandler>& actionHandler) {
        // what would happen if this menu already existed for us? would an existing Action be returned? hmmm
        const auto menuWrapper = reinterpret_cast<SignalWrapper*>(menu);
        const auto action = MENU_THIS->addMenu(menuWrapper->getActual());
        // we must not already have seen this action!
        assert(wrapperForQObject(action) == nullptr);
        //
        const auto actionWrapper = new Action::SignalWrapper(action, actionHandler);
        return reinterpret_cast<Action::HandleRef>(actionWrapper);
    }

    HandleRef Handle_addMenu(HandleRef _this, const std::string& title, const std::shared_ptr<SignalHandler>& handler) {
        const auto menu = MENU_THIS->addMenu(QString::fromStdString(title));
        const auto wrapper = new SignalWrapper(menu, handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    HandleRef Handle_addMenu(HandleRef _this, Icon::HandleRef icon, const std::string& title, const std::shared_ptr<SignalHandler>& handler) {
        const auto menu = MENU_THIS->addMenu(QICON_VALUE(icon), QString::fromStdString(title));
        const auto wrapper = new SignalWrapper(menu, handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    Action::HandleRef Handle_addSection(HandleRef _this, const std::string& text, const std::optional<Icon::HandleRef>& icon, const std::shared_ptr<Action::SignalHandler>& actionHandler) {
        QAction *action;
        if (icon.has_value()) {
            action = MENU_THIS->addSection(QICON_VALUE(icon.value()), QString::fromStdString(text));
        } else {
            action = MENU_THIS->addSection(QString::fromStdString(text));
        }
        const auto wrapper = new Action::SignalWrapper(action, actionHandler);
        return reinterpret_cast<Action::HandleRef>(wrapper);
    }

    Action::HandleRef Handle_addSeparator(HandleRef _this, const std::shared_ptr<Action::SignalHandler>& handler) {
        const auto wrapper = new Action::SignalWrapper(MENU_THIS->addSeparator(), handler);
        return reinterpret_cast<Action::HandleRef>(wrapper);
    }

    void Handle_clear(HandleRef _this) {
        MENU_THIS->clear();
    }

    Action::HandleRef Handle_defaultAction(HandleRef _this) {
        if (const auto action = MENU_THIS->defaultAction(); action != nullptr) {
            const auto wrapper = wrapperForQObject(action);
            assert(wrapper != nullptr); // should be something we know about already
            return reinterpret_cast<Action::HandleRef>(wrapper);
        }
        return nullptr;
    }

    Action::HandleRef Handle_exec(HandleRef _this) {
        if (const auto action = MENU_THIS->exec(); action != nullptr) {
            const auto wrapper = wrapperForQObject(action);
            assert(wrapper != nullptr);
            return reinterpret_cast<Action::HandleRef>(wrapper);
        }
        return nullptr;
    }

    Action::HandleRef Handle_exec(HandleRef _this, Point p, const std::optional<Action::HandleRef>& action) {
        QAction *qAction = nullptr;
        if (action.has_value()) {
            const auto actionWrapper = reinterpret_cast<Action::SignalWrapper*>(action.value());
            qAction = actionWrapper->getActual();
        }
        if (const auto retAction = MENU_THIS->exec(toQPoint(p), qAction); retAction != nullptr) {
            const auto retActionWrapper = wrapperForQObject(retAction);
            // should be something we know about ...
            assert(retActionWrapper != nullptr);
            return reinterpret_cast<Action::HandleRef>(retActionWrapper);
        }
        return nullptr;
    }

    void Handle_hideTearOffMenu(HandleRef _this) {
        MENU_THIS->hideTearOffMenu();
    }

    Action::HandleRef Handle_insertMenu(HandleRef _this, Action::HandleRef before, HandleRef menu, const std::shared_ptr<Action::SignalHandler>& actionHandler) {
        const auto beforeWrapper = reinterpret_cast<Action::SignalWrapper*>(before);
        const auto menuWrapper = reinterpret_cast<SignalWrapper*>(menu);
        const auto retAction = MENU_THIS->insertMenu(beforeWrapper->getActual(), menuWrapper->getActual());
        assert(wrapperForQObject(retAction) == nullptr); // should be new to us
        const auto retWrapper = new Action::SignalWrapper(retAction, actionHandler);
        return reinterpret_cast<Action::HandleRef>(retWrapper);
    }

    Action::HandleRef Handle_insertSection(HandleRef _this, Action::HandleRef before, const std::string& text, const std::optional<Icon::HandleRef>& icon, const std::shared_ptr<Action::SignalHandler>& actionHandler) {
        const auto beforeWrapper = reinterpret_cast<Action::SignalWrapper*>(before);
        QAction *retAction = nullptr;
        if (icon.has_value()) {
            retAction = MENU_THIS->insertSection(beforeWrapper->getActual(), QICON_VALUE(icon.value()), QString::fromStdString(text));
        } else {
            retAction = MENU_THIS->insertSection(beforeWrapper->getActual(), QString::fromStdString(text));
        }
        assert(wrapperForQObject(retAction) == nullptr); // should be new to us
        const auto retWrapper = new Action::SignalWrapper(retAction, actionHandler);
        return reinterpret_cast<Action::HandleRef>(retWrapper);
    }

    Action::HandleRef Handle_insertSeparator(HandleRef _this, Action::HandleRef before, const std::shared_ptr<Action::SignalHandler>& actionHandler) {
        const auto beforeWrapper = reinterpret_cast<Action::SignalWrapper*>(before);
        const auto retAction = MENU_THIS->insertSeparator(beforeWrapper->getActual());
        assert(wrapperForQObject(retAction) == nullptr); // should be new to us
        const auto retWrapper = new Action::SignalWrapper(retAction, actionHandler);
        return reinterpret_cast<Action::HandleRef>(retWrapper);
    }

    bool Handle_isEmpty(HandleRef _this) {
        return MENU_THIS->isEmpty();
    }

    bool Handle_isTearOffMenuVisible(HandleRef _this) {
        return MENU_THIS->isTearOffMenuVisible();
    }

    Action::HandleRef Handle_menuAction(HandleRef _this) {
        if (const auto action = MENU_THIS->menuAction(); action != nullptr) {
            const auto wrapper = wrapperForQObject(action);
            assert(wrapper != nullptr); // should already exist, from a prior call, no?
            return reinterpret_cast<Action::HandleRef>(wrapper);
        }
        return nullptr;
    }

    void Handle_popup(HandleRef _this, Point p, const std::optional<Action::HandleRef>& atAction) {
        QAction *qAtAction = nullptr;
        if (atAction.has_value()) {
            const auto atActionWrapper = reinterpret_cast<Action::SignalWrapper*>(atAction.value());
            qAtAction = atActionWrapper->getActual();
        }
        MENU_THIS->popup(toQPoint(p), qAtAction);
    }

    void Handle_setActiveAction(HandleRef _this, Action::HandleRef act) {
        const auto wrapper = reinterpret_cast<Action::SignalWrapper*>(act);
        MENU_THIS->setActiveAction(wrapper->getActual());
    }

    void Handle_setAsDockMenu(HandleRef _this) {
        // TODO, macOS only!
    }

    void Handle_setDefaultAction(HandleRef _this, Action::HandleRef act) {
        const auto wrapper = reinterpret_cast<Action::SignalWrapper*>(act);
        MENU_THIS->setDefaultAction(wrapper->getActual());
    }

    void Handle_showTearOffMenu(HandleRef _this, const std::optional<Point>& pos) {
        if (pos.has_value()) {
            MENU_THIS->showTearOffMenu(toQPoint(pos.value()));
        } else {
            MENU_THIS->showTearOffMenu();
        }
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler, const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        const auto wrapper = new SignalWrapper(new QMenu(qParent), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler, const std::string& title, const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        const auto menu = new QMenu(QString::fromStdString(title), qParent);
        const auto wrapper = new SignalWrapper(menu, handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    Action::HandleRef exec(const std::vector<Action::HandleRef>& actions, Point pos, const std::optional<Action::HandleRef>& at, const std::optional<Widget::HandleRef>& parent) {
        const auto qActionList = toQList<Action::HandleRef,QAction*>(actions, [](auto a) {
            const auto wrapper = reinterpret_cast<Action::SignalWrapper*>(a);
            return wrapper->getActual();
        });
        QAction *atAction = nullptr;
        if (at.has_value()) {
            const auto atWrapper = reinterpret_cast<Action::SignalWrapper*>(at.value());
            atAction = atWrapper->getActual();
        }
        if (const auto retAction = QMenu::exec(qActionList, toQPoint(pos), atAction, Widget::fromOptionalHandle(parent)); retAction != nullptr) {
            const auto wrapper = wrapperForQObject(retAction);
            assert(wrapper != nullptr);
            return reinterpret_cast<Action::HandleRef>(wrapper);
        }
        return nullptr;
    }

    HandleRef menuInAction(Action::HandleRef action) {
        const auto actionWrapper = reinterpret_cast<Action::SignalWrapper*>(action);
        if (const auto menu = QMenu::menuInAction(actionWrapper->getActual()); menu != nullptr) {
            const auto wrapper = wrapperForQObject(menu);
            assert(wrapper != nullptr);
            return reinterpret_cast<HandleRef>(wrapper);
        }
        return nullptr;
    }
}
