#include "generated/ToolBar.h"
#include "ToolBarInternal.h"

#include "ObjectInternal.h"
#include "util/convert.h"

#define THIS (reinterpret_cast<QToolBar*>(_this))

namespace ToolBar
{
    void Handle_setAllowedAreas(HandleRef _this, Enums::ToolBarAreas allowed) {
        THIS->setAllowedAreas(static_cast<Qt::ToolBarAreas>(allowed));
    }

    void Handle_setFloatable(HandleRef _this, bool floatable) {
        THIS->setFloatable(floatable);
    }

    bool Handle_isFloating(HandleRef _this) {
        return THIS->isFloating();
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        THIS->setIconSize(toQSize(size));
    }

    void Handle_setMovable(HandleRef _this, bool value) {
        THIS->setMovable(value);
    }

    void Handle_setOrientation(HandleRef _this, Orientation value) {
        THIS->setOrientation(static_cast<Qt::Orientation>(value));
    }

    void Handle_setToolButtonStyle(HandleRef _this, ToolButtonStyle style) {
        THIS->setToolButtonStyle(static_cast<Qt::ToolButtonStyle>(style));
    }

    Action::HandleRef Handle_addSeparator(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(THIS->addSeparator());
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->addWidget(reinterpret_cast<QWidget *>(widget));
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    SignalConnectionRef Handle_connect_ActionTriggered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QToolBar::actionTriggered, [handler](QAction *action) {
            handler->actionTriggered(reinterpret_cast<Action::HandleRef>(action));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_AllowedAreasChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QToolBar::allowedAreasChanged, [handler](Qt::ToolBarAreas allowed) {
            handler->allowedAreasChanged(allowed);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_IconSizeChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QToolBar::iconSizeChanged, [handler](const QSize& size) {
            handler->iconSizeChanged(toSize(size));
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

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QToolBar());
    }
}
