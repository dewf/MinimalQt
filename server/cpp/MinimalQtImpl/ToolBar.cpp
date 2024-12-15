#include "generated/ToolBar.h"

#include <QToolBar>
#include <utility>
#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((ToolBarWithHandler*)_this)

namespace ToolBar
{
    class ToolBarWithHandler : public QToolBar {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // Widget:
            { CustomContextMenuRequested, SIGNAL(customContextMenuRequested(QPoint)), SLOT(onCustomContextMenuRequested(QPoint)) },
            { WindowIconChanged, SIGNAL(windowIconChanged(QIcon)), SLOT(onWindowIconChanged(QIcon)) },
            { WindowTitleChanged, SIGNAL(windowTitleChanged(QString)), SLOT(onWindowTitleChanged(QString)) },
            // ToolBar:
            { ActionTriggered, SIGNAL(actionTriggered(QAction)), SLOT(onActionTriggered(QAction)) },
            { AllowedAreasChanged, SIGNAL(allowedAreasChanged(Qt::ToolBarAreas)), SLOT(onAllowedAreasChanged(Qt::ToolBarAreas)) },
            { IconSizeChanged, SIGNAL(iconSizeChanged(QSize)), SLOT(onIconSizeChanged(QSize)) },
            { MovableChanged, SIGNAL(movableChanged(bool)), SLOT(onMovableChanged(bool)) },
            { OrientationChanged, SIGNAL(orientationChanged(Qt::Orientation)), SLOT(onOrientationChanged(Qt::Orientation)) },
            { ToolButtonStyleChanged, SIGNAL(toolButtonStyleChanged(Qt::ToolButtonStyle)), SLOT(onToolButtonStyleChanged(Qt::ToolButtonStyle)) },
            { TopLevelChanged, SIGNAL(topLevelChanged(bool)), SLOT(onTopLevelChanged(bool)) },
            { VisibilityChanged, SIGNAL(visibilityChanged(bool)), SLOT(onVisibilityChanged(bool)) },
        };
    public:
        explicit ToolBarWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            handler->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Widget ==================
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->
                inherited_Widget_SignalHandler()->
                    customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowIconChanged((Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowTitleChanged(title.toStdString());
        }
        // ToolBar =================
        void onActionTriggered(QAction *action) const {
            handler->actionTriggered(reinterpret_cast<Action::HandleRef>(action));
        };
        void onAllowedAreasChanged(Qt::ToolBarAreas allowed) const {
            handler->allowedAreasChanged(allowed);
        }
        void onIconSizeChanged(const QSize& size) const {
            handler->iconSizeChanged(toSize(size));
        }
        void onMovableChanged(bool movable) const {
            handler->movableChanged(movable);
        }
        void onOrientationChanged(Qt::Orientation value) const {
            handler->orientationChanged(static_cast<Enums::Orientation>(value));
        }
        void onToolButtonStyleChanged(Qt::ToolButtonStyle style) const {
            handler->toolButtonStyleChanged(static_cast<ToolButtonStyle>(style));
        }
        void onTopLevelChanged(bool topLevel) const {
            handler->topLevelChanged(topLevel);
        }
        void onVisibilityChanged(bool visible) const {
            handler->visibilityChanged(visible);
        }
    };

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

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new ToolBarWithHandler(handler));
    }
}

#include "ToolBar.moc"
