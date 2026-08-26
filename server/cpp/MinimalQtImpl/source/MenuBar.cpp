#include "generated/MenuBar.h"
#include "MenuBarInternal.h"

#include "ObjectInternal.h"
#include "WidgetInternal.h"
#include "ActionInternal.h"
#include "IconInternal.h"
#include "MenuInternal.h"
#include "PointInternal.h"
#include "RectInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Point;
using namespace ::Rect;
using namespace ::Enums;
using namespace ::Icon;
using namespace ::Widget;
using namespace ::Menu;
using namespace ::Action;

#define THIS (reinterpret_cast<QMenuBar*>(_this))

namespace MenuBar
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

    Action::HandleRef Handle_addMenu(HandleRef _this, Menu::HandleRef menu) {
        return reinterpret_cast<Action::HandleRef>(THIS->addMenu(AS_QMENU_PTR(menu)));
    }

    Menu::HandleRef Handle_addMenu(HandleRef _this, const std::string& title) {
        return reinterpret_cast<Menu::HandleRef>(THIS->addMenu(QString::fromStdString(title)));
    }

    Menu::HandleRef Handle_addMenu(HandleRef _this, Icon::HandleRef icon, const std::string& title) {
        return reinterpret_cast<Menu::HandleRef>(THIS->addMenu(QICON_VALUE(icon), QString::fromStdString(title)));
    }

    Action::HandleRef Handle_addSeparator(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(THIS->addSeparator());
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    Widget::HandleRef Handle_cornerWidget(HandleRef _this, Corner corner /* Corner::TopRightCorner */) {
        return reinterpret_cast<Widget::HandleRef>(THIS->cornerWidget(static_cast<Qt::Corner>(corner)));
    }

    Action::HandleRef Handle_insertMenu(HandleRef _this, Action::HandleRef before, Menu::HandleRef menu) {
        return reinterpret_cast<Action::HandleRef>(THIS->insertMenu(AS_QACTION_PTR(before), AS_QMENU_PTR(menu)));
    }

    Action::HandleRef Handle_insertSeparator(HandleRef _this, Action::HandleRef before) {
        return reinterpret_cast<Action::HandleRef>(THIS->insertSeparator(AS_QACTION_PTR(before)));
    }

    bool Handle_isDefaultUp(HandleRef _this) {
        return THIS->isDefaultUp();
    }

    bool Handle_isNativeMenuBar(HandleRef _this) {
        return THIS->isNativeMenuBar();
    }

    void Handle_setActiveAction(HandleRef _this, Action::HandleRef act) {
        THIS->setActiveAction(AS_QACTION_PTR(act));
    }

    void Handle_setCornerWidget(HandleRef _this, Widget::HandleRef widget, Corner corner /* Corner::TopRightCorner */) {
        THIS->setCornerWidget(AS_QWIDGET_PTR(widget), static_cast<Qt::Corner>(corner));
    }

    void Handle_setDefaultUp(HandleRef _this, bool value) {
        THIS->setDefaultUp(value);
    }

    void Handle_setNativeMenuBar(HandleRef _this, bool nativeMenuBar) {
        THIS->setNativeMenuBar(nativeMenuBar);
    }

    // seems like this is already implemented in Widget, and it's virtual, so why is it listed as a slot on QMenuBar in the docs?
    // void Handle_setVisible(HandleRef _this, bool visible) {
    //     THIS->setVisible(visible);
    // }

    SignalConnectionRef Handle_connect_Hovered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QMenuBar::hovered, [handler](QAction* action) {
            handler->sig_hovered(reinterpret_cast<Action::HandleRef>(action));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Triggered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QMenuBar::triggered, [handler](QAction* action) {
            handler->sig_triggered(reinterpret_cast<Action::HandleRef>(action));
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QMenuBar(AS_QWIDGET_PTR(parent)));
    }
}
