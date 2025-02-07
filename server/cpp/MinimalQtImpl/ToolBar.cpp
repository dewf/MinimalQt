#include "generated/ToolBar.h"
#include "ToolBarInternal.h"

#include "ActionInternal.h"
#include "ObjectInternal.h"
#include "PointInternal.h"
#include "WidgetInternal.h"
#include "SizeInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Common;
using namespace ::Size;
using namespace ::Point;
using namespace ::Enums;
using namespace ::Widget;
using namespace ::Action;

#define THIS (reinterpret_cast<QToolBar*>(_this))

namespace ToolBar
{
    Action::HandleRef Handle_actionAt(HandleRef _this, Point::HandleRef p) {
        return reinterpret_cast<Action::HandleRef>(THIS->actionAt(QPOINT_VALUE(p)));
    }

    Action::HandleRef Handle_actionAt(HandleRef _this, int32_t x, int32_t y) {
        return reinterpret_cast<Action::HandleRef>(THIS->actionAt(x, y));
    }

    Action::HandleRef Handle_addSeparator(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(THIS->addSeparator());
    }

    Action::HandleRef Handle_addWidget(HandleRef _this, Widget::HandleRef widget) {
        return reinterpret_cast<Action::HandleRef>(THIS->addWidget(AS_QWIDGET_PTR(widget)));
    }

    ToolBarAreas Handle_allowedAreas(HandleRef _this) {
        return ToolBarAreas(THIS->allowedAreas());
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    Size::OwnedRef Handle_iconSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->iconSize());
    }

    Action::HandleRef Handle_insertSeparator(HandleRef _this, Action::HandleRef before) {
        return reinterpret_cast<Action::HandleRef>(THIS->insertSeparator(AS_QACTION_PTR(before)));
    }

    Action::HandleRef Handle_insertWidget(HandleRef _this, Action::HandleRef before, Widget::HandleRef widget) {
        return reinterpret_cast<Action::HandleRef>(THIS->insertWidget(AS_QACTION_PTR(before), AS_QWIDGET_PTR(widget)));
    }

    bool Handle_isAreaAllowed(HandleRef _this, ToolBarArea area) {
        return THIS->isAreaAllowed(static_cast<Qt::ToolBarArea>(area));
    }

    bool Handle_isFloatable(HandleRef _this) {
        return THIS->isFloatable();
    }

    bool Handle_isFloating(HandleRef _this) {
        return THIS->isFloating();
    }

    bool Handle_isMovable(HandleRef _this) {
        return THIS->isMovable();
    }

    Orientation Handle_orientation(HandleRef _this) {
        return static_cast<Orientation>(THIS->orientation());
    }

    void Handle_setAllowedAreas(HandleRef _this, ToolBarAreas areas) {
        return THIS->setAllowedAreas(static_cast<Qt::ToolBarAreas>(areas.value));
    }

    void Handle_setFloatable(HandleRef _this, bool floatable) {
        THIS->setFloatable(floatable);
    }

    void Handle_setMovable(HandleRef _this, bool movable) {
        THIS->setMovable(movable);
    }

    void Handle_setOrientation(HandleRef _this, Orientation orientation) {
        THIS->setOrientation(static_cast<Qt::Orientation>(orientation));
    }

    Action::HandleRef Handle_toggleViewAction(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(THIS->toggleViewAction());
    }

    ToolButtonStyle Handle_getToolButtonStyle(HandleRef _this) {
        return static_cast<ToolButtonStyle>(THIS->toolButtonStyle());
    }

    Widget::HandleRef Handle_widgetForAction(HandleRef _this, Action::HandleRef action) {
        return reinterpret_cast<Widget::HandleRef>(THIS->widgetForAction(AS_QACTION_PTR(action)));
    }

    void Handle_setIconSize(HandleRef _this, Size::HandleRef iconSize) {
        THIS->setIconSize(QSIZE_VALUE(iconSize));
    }

    void Handle_setToolButtonStyle(HandleRef _this, ToolButtonStyle toolButtonStyle) {
        THIS->setToolButtonStyle(static_cast<Qt::ToolButtonStyle>(toolButtonStyle));
    }

    SignalConnectionRef Handle_connect_ActionTriggered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QToolBar::actionTriggered, [handler](QAction *action) {
            handler->actionTriggered(reinterpret_cast<Action::HandleRef>(action));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_AllowedAreasChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QToolBar::allowedAreasChanged, [handler](Qt::ToolBarAreas allowed) {
            handler->allowedAreasChanged(ToolBarAreas(allowed));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_IconSizeChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QToolBar::iconSizeChanged, [handler](const QSize& size) {
            // TODO: ConstHandle
            handler->iconSizeChanged((Size::HandleRef)&size);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_MovableChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QToolBar::movableChanged, [handler](bool movable) {
            handler->movableChanged(movable);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_OrientationChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QToolBar::orientationChanged, [handler](Qt::Orientation value) {
            handler->orientationChanged(static_cast<Enums::Orientation>(value));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ToolButtonStyleChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QToolBar::toolButtonStyleChanged, [handler](Qt::ToolButtonStyle style) {
            handler->toolButtonStyleChanged(static_cast<ToolButtonStyle>(style));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TopLevelChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QToolBar::topLevelChanged, [handler](bool topLevel) {
            handler->topLevelChanged(topLevel);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_VisibilityChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QToolBar::visibilityChanged, [handler](bool visible) {
            handler->visibilityChanged(visible);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QToolBar(AS_QWIDGET_PTR(parent)));
    }

    HandleRef create(const std::string& title, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QToolBar(QString::fromStdString(title), AS_QWIDGET_PTR(parent)));
    }
}
