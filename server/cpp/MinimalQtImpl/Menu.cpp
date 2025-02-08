#include "generated/Menu.h"
#include "MenuInternal.h"

#include "ObjectInternal.h"
#include "WidgetInternal.h"
#include "ActionInternal.h"
#include "IconInternal.h"
#include "PointInternal.h"
#include "RectInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Common;
using namespace ::Point;
using namespace ::Rect;
using namespace ::Widget;
using namespace ::Action;
using namespace ::Icon;

#define THIS (reinterpret_cast<QMenu*>(_this))

namespace Menu
{
    Action::HandleRef Handle_actionAt(HandleRef _this, Point::HandleRef pt) {
        return reinterpret_cast<Action::HandleRef>(THIS->actionAt(QPOINT_VALUE(pt)));
    }

    Rect::OwnedRef Handle_actionGeometry(HandleRef _this, Action::HandleRef act) {
        return RECT_HEAP_NEW(THIS->actionGeometry(AS_QACTION_PTR(act)));
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

    Action::HandleRef Handle_addSection(HandleRef _this, const std::string& text) {
        return reinterpret_cast<Action::HandleRef>(THIS->addSection(QString::fromStdString(text)));
    }

    Action::HandleRef Handle_addSection(HandleRef _this, Icon::HandleRef icon, const std::string& text) {
        return reinterpret_cast<Action::HandleRef>(THIS->addSection(QICON_VALUE(icon), QString::fromStdString(text)));
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

    Action::HandleRef Handle_exec(HandleRef _this, Point::HandleRef p, Action::HandleRef action /* nullptr */) {
        return reinterpret_cast<Action::HandleRef>(THIS->exec(QPOINT_VALUE(p), reinterpret_cast<QAction*>(action)));
    }

    void Handle_hideTearOffMenu(HandleRef _this) {
        THIS->hideTearOffMenu();
    }

    Icon::OwnedRef Handle_icon(HandleRef _this) {
        return ICON_HEAP_NEW(THIS->icon());
    }

    Action::HandleRef Handle_insertMenu(HandleRef _this, Action::HandleRef before, HandleRef menu) {
        return reinterpret_cast<Action::HandleRef>(THIS->insertMenu(AS_QACTION_PTR(before), AS_QMENU_PTR(menu)));
    }

    Action::HandleRef Handle_insertSection(HandleRef _this, Action::HandleRef before, const std::string& text) {
        return reinterpret_cast<Action::HandleRef>(THIS->insertSection(AS_QACTION_PTR(before), QString::fromStdString(text)));
    }

    Action::HandleRef Handle_insertSection(HandleRef _this, Action::HandleRef before, Icon::HandleRef icon, const std::string& text) {
        return reinterpret_cast<Action::HandleRef>(THIS->insertSection(AS_QACTION_PTR(before), QICON_VALUE(icon), QString::fromStdString(text)));
    }

    Action::HandleRef Handle_insertSeparator(HandleRef _this, Action::HandleRef before) {
        return reinterpret_cast<Action::HandleRef>(THIS->insertSeparator(AS_QACTION_PTR(before)));
    }

    bool Handle_isEmpty(HandleRef _this) {
        return THIS->isEmpty();
    }

    bool Handle_isTearOffEnabled(HandleRef _this) {
        return THIS->isTearOffEnabled();
    }

    bool Handle_isTearOffMenuVisible(HandleRef _this) {
        return THIS->isTearOffMenuVisible();
    }

    Action::HandleRef Handle_menuAction(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(THIS->menuAction());
    }

    void Handle_popup(HandleRef _this, Point::HandleRef p, Action::HandleRef atAction /* nullptr */) {
        THIS->popup(QPOINT_VALUE(p), reinterpret_cast<QAction*>(atAction));
    }

    bool Handle_separatorsCollapsible(HandleRef _this) {
        return THIS->separatorsCollapsible();
    }

    void Handle_setActiveAction(HandleRef _this, Action::HandleRef act) {
        THIS->setActiveAction(AS_QACTION_PTR(act));
    }

    void Handle_setAsDockMenu(HandleRef _this) {
        // MACOS-ONLY
    }

    void Handle_setDefaultAction(HandleRef _this, Action::HandleRef act) {
        THIS->setDefaultAction(AS_QACTION_PTR(act));
    }

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        THIS->setIcon(QICON_VALUE(icon));
    }

    void Handle_setSeparatorsCollapsible(HandleRef _this, bool collapse) {
        THIS->setSeparatorsCollapsible(collapse);
    }

    void Handle_setTearOffEnabled(HandleRef _this, bool enabled) {
        THIS->setTearOffEnabled(enabled);
    }

    void Handle_setTitle(HandleRef _this, const std::string& title) {
        THIS->setTitle(QString::fromStdString(title));
    }

    void Handle_setToolTipsVisible(HandleRef _this, bool visible) {
        THIS->setToolTipsVisible(visible);
    }

    void Handle_showTearOffMenu(HandleRef _this, Point::HandleRef pos) {
        THIS->showTearOffMenu(QPOINT_VALUE(pos));
    }

    void Handle_showTearOffMenu(HandleRef _this) {
        THIS->showTearOffMenu();
    }

    std::string Handle_title(HandleRef _this) {
        return THIS->title().toStdString();
    }

    bool Handle_toolTipsVisible(HandleRef _this) {
        return THIS->toolTipsVisible();
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

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QMenu(AS_QWIDGET_PTR(parent)));
    }

    HandleRef create(const std::string& title, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QMenu(QString::fromStdString(title), AS_QWIDGET_PTR(parent)));
    }

    Action::HandleRef exec(const std::vector<Action::HandleRef>& actions, Point::HandleRef pos, Action::HandleRef at /* nullptr */, Widget::HandleRef parent /* nullptr */) {
        const auto qActionList = toQList<Action::HandleRef,QAction*>(actions, [](auto a) {
            return AS_QACTION_PTR(a);
        });
        const auto result = QMenu::exec(qActionList, QPOINT_VALUE(pos), AS_QACTION_PTR(at), AS_QWIDGET_PTR(parent));
        return reinterpret_cast<Action::HandleRef>(result);
    }

    HandleRef menuInAction(Action::HandleRef action) {
        return reinterpret_cast<HandleRef>(QMenu::menuInAction(AS_QACTION_PTR(action)));
    }
}
