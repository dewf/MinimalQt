#include "generated/Menu.h"
#include "MenuInternal.h"

#include "util/convert.h"

#include "ObjectInternal.h"
#include "WidgetInternal.h"
#include "ActionInternal.h"
#include "IconInternal.h"

#define THIS (reinterpret_cast<QMenu*>(_this))

namespace Menu
{
    Icon::OwnedRef Handle_getIcon(HandleRef _this) {
        return ICON_HEAP_NEW(THIS->icon());
    }

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        THIS->setIcon(QICON_VALUE(icon));
    }

    bool Handle_separatorsCollasible(HandleRef _this) {
        return THIS->separatorsCollapsible();
    }

    void Handle_setSeparatorsCollapsible(HandleRef _this, bool state) {
        THIS->setSeparatorsCollapsible(state);
    }

    bool Handle_isTearOffEnabled(HandleRef _this) {
        return THIS->isTearOffEnabled();
    }

    void Handle_setTearOffEnabled(HandleRef _this, bool state) {
        THIS->setTearOffEnabled(state);
    }

    std::string Handle_title(HandleRef _this) {
        return THIS->title().toStdString();
    }

    void Handle_setTitle(HandleRef _this, const std::string& title) {
        THIS->setTitle(QString::fromStdString(title));
    }

    bool Handle_toolTipsVisible(HandleRef _this) {
        return THIS->toolTipsVisible();
    }

    void Handle_setToolTipsVisible(HandleRef _this, bool visible) {
        THIS->setToolTipsVisible(visible);
    }

    Action::HandleRef Handle_actionAt(HandleRef _this, Point pos) {
        return reinterpret_cast<Action::HandleRef>(THIS->actionAt(toQPoint(pos)));
    }

    Rect Handle_actionGeometry(HandleRef _this, Action::HandleRef act) {
        return toRect(THIS->actionGeometry(AS_QACTION_PTR(act)));
    }

    Action::HandleRef Handle_activeAction(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(THIS->activeAction());
    }

    Action::HandleRef Handle_addMenu(HandleRef _this, HandleRef menu) {
        return reinterpret_cast<Action::HandleRef>(THIS->addMenu(AS_QMENU_PTR(menu)));
    }

    HandleRef Handle_addMenu(HandleRef _this, const std::string& title) {
        return reinterpret_cast<HandleRef>(THIS->addMenu(QString::fromStdString(title)));
    }

    HandleRef Handle_addMenu(HandleRef _this, Icon::HandleRef icon, const std::string& title) {
        return reinterpret_cast<HandleRef>(THIS->addMenu(QICON_VALUE(icon), QString::fromStdString(title)));
    }

    Action::HandleRef Handle_addSection(HandleRef _this, const std::string& text, const std::optional<Icon::HandleRef>& icon) {
        if (icon.has_value()) {
            return reinterpret_cast<Action::HandleRef>(THIS->addSection(QICON_VALUE(icon.value()), QString::fromStdString(text)));
        } else {
            return reinterpret_cast<Action::HandleRef>(THIS->addSection(QString::fromStdString(text)));
        }
    }

    Action::HandleRef Handle_addSeparator(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(THIS->addSeparator());
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    Action::HandleRef Handle_defaultAction(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(THIS->defaultAction());
    }

    Action::HandleRef Handle_exec(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(THIS->exec());
    }

    Action::HandleRef Handle_exec(HandleRef _this, Point p, const std::optional<Action::HandleRef>& action) {
        QAction *qAction = Action::fromOptionalHandle(action);
        return reinterpret_cast<Action::HandleRef>(THIS->exec(toQPoint(p), qAction));
    }

    void Handle_hideTearOffMenu(HandleRef _this) {
        THIS->hideTearOffMenu();
    }

    Action::HandleRef Handle_insertMenu(HandleRef _this, Action::HandleRef before, HandleRef menu) {
        return reinterpret_cast<Action::HandleRef>(THIS->insertMenu(AS_QACTION_PTR(before), AS_QMENU_PTR(menu)));
    }

    Action::HandleRef Handle_insertSection(HandleRef _this, Action::HandleRef before, const std::string& text, const std::optional<Icon::HandleRef>& icon) {
        if (icon.has_value()) {
            return reinterpret_cast<Action::HandleRef>(THIS->insertSection(AS_QACTION_PTR(before), QICON_VALUE(icon.value()), QString::fromStdString(text)));
        } else {
            return reinterpret_cast<Action::HandleRef>(THIS->insertSection(AS_QACTION_PTR(before),QString::fromStdString(text)));
        }
    }

    Action::HandleRef Handle_insertSeparator(HandleRef _this, Action::HandleRef before) {
        return reinterpret_cast<Action::HandleRef>(THIS->insertSeparator(AS_QACTION_PTR(before)));
    }

    bool Handle_isEmpty(HandleRef _this) {
        return THIS->isEmpty();
    }

    bool Handle_isTearOffMenuVisible(HandleRef _this) {
        return THIS->isTearOffMenuVisible();
    }

    Action::HandleRef Handle_menuAction(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(THIS->menuAction());
    }

    void Handle_popup(HandleRef _this, Point p, const std::optional<Action::HandleRef>& atAction) {
        THIS->popup(toQPoint(p), Action::fromOptionalHandle(atAction));
    }

    void Handle_setActiveAction(HandleRef _this, Action::HandleRef act) {
        THIS->setActiveAction(AS_QACTION_PTR(act));
    }

    void Handle_setAsDockMenu(HandleRef _this) {
        // TODO, macOS only!
    }

    void Handle_setDefaultAction(HandleRef _this, Action::HandleRef act) {
        THIS->setDefaultAction(AS_QACTION_PTR(act));
    }

    void Handle_showTearOffMenu(HandleRef _this, const std::optional<Point>& pos) {
        if (pos.has_value()) {
            THIS->showTearOffMenu(toQPoint(pos.value()));
        } else {
            THIS->showTearOffMenu();
        }
    }

    SignalConnectionRef Handle_connect_AboutToHide(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QMenu::aboutToHide, [handler] {
            handler->aboutToHide();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_AboutToShow(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QMenu::aboutToShow, [handler] {
            handler->aboutToShow();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Hovered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QMenu::hovered, [handler](QAction *action) {
            handler->hovered(reinterpret_cast<Action::HandleRef>(action));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Triggered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QMenu::triggered, [handler](QAction *action) {
            handler->triggered(reinterpret_cast<Action::HandleRef>(action));
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        return reinterpret_cast<HandleRef>(new QMenu(qParent));
    }

    HandleRef create(const std::string& title, const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        return reinterpret_cast<HandleRef>(new QMenu(QString::fromStdString(title), qParent));
    }

    Action::HandleRef exec(const std::vector<Action::HandleRef>& actions, Point pos, const std::optional<Action::HandleRef>& at, const std::optional<Widget::HandleRef>& parent) {
        const auto qActionList = toQList<Action::HandleRef,QAction*>(actions, [](auto a) {
            return AS_QACTION_PTR(a);
        });
        return reinterpret_cast<Action::HandleRef>(QMenu::exec(qActionList, toQPoint(pos), Action::fromOptionalHandle(at), Widget::fromOptionalHandle(parent)));
    }

    HandleRef menuInAction(Action::HandleRef action) {
        return reinterpret_cast<HandleRef>(QMenu::menuInAction(AS_QACTION_PTR(action)));
    }
}
