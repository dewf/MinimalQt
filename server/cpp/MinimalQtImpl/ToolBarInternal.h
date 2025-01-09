#pragma once

#include "generated/ToolBar.h"
#include "WidgetInternal.h"

#include <QToolBar>

#define AS_QTOOLBAR_PTR(x) (reinterpret_cast<QToolBar*>(x))

namespace ToolBar {
    // class SignalWrapper : public Widget::SignalWrapper {
    //     Q_OBJECT
    // private:
    //     QToolBar *actual;
    //     std::shared_ptr<SignalHandler> handler;
    //     SignalMask lastMask = 0;
    //     std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
    //         { ActionTriggered, SIGNAL(actionTriggered(QAction)), SLOT(onActionTriggered(QAction)) },
    //         { AllowedAreasChanged, SIGNAL(allowedAreasChanged(Qt::ToolBarAreas)), SLOT(onAllowedAreasChanged(Qt::ToolBarAreas)) },
    //         { IconSizeChanged, SIGNAL(iconSizeChanged(QSize)), SLOT(onIconSizeChanged(QSize)) },
    //         { MovableChanged, SIGNAL(movableChanged(bool)), SLOT(onMovableChanged(bool)) },
    //         { OrientationChanged, SIGNAL(orientationChanged(Qt::Orientation)), SLOT(onOrientationChanged(Qt::Orientation)) },
    //         { ToolButtonStyleChanged, SIGNAL(toolButtonStyleChanged(Qt::ToolButtonStyle)), SLOT(onToolButtonStyleChanged(Qt::ToolButtonStyle)) },
    //         { TopLevelChanged, SIGNAL(topLevelChanged(bool)), SLOT(onTopLevelChanged(bool)) },
    //         { VisibilityChanged, SIGNAL(visibilityChanged(bool)), SLOT(onVisibilityChanged(bool)) },
    //     };
    // public:
    //     QToolBar *getActual() const {
    //         return actual;
    //     }
    //     SignalWrapper(QToolBar *existing, const std::shared_ptr<SignalHandler> &handler)
    //         : Widget::SignalWrapper(existing, SignalHandler::as_Widget_SignalHandler(handler)),
    //           actual(existing),
    //           handler(handler) {}
    //     void setSignalMask(SignalMask newMask) {
    //         // update inherited signals
    //         Widget::SignalWrapper::setSignalMask(newMask);
    //         // ours:
    //         if (newMask != lastMask) {
    //             processChanges(lastMask, newMask, signalMap, actual, this);
    //             lastMask = newMask;
    //         }
    //     }
    // public slots:
    //     void onActionTriggered(QAction *action) const {
    //         handler->actionTriggered(reinterpret_cast<Action::HandleRef>(action));
    //     };
    //     void onAllowedAreasChanged(Qt::ToolBarAreas allowed) const {
    //         handler->allowedAreasChanged(allowed);
    //     }
    //     void onIconSizeChanged(const QSize& size) const {
    //         handler->iconSizeChanged(toSize(size));
    //     }
    //     void onMovableChanged(bool movable) const {
    //         handler->movableChanged(movable);
    //     }
    //     void onOrientationChanged(Qt::Orientation value) const {
    //         handler->orientationChanged(static_cast<Enums::Orientation>(value));
    //     }
    //     void onToolButtonStyleChanged(Qt::ToolButtonStyle style) const {
    //         handler->toolButtonStyleChanged(static_cast<ToolButtonStyle>(style));
    //     }
    //     void onTopLevelChanged(bool topLevel) const {
    //         handler->topLevelChanged(topLevel);
    //     }
    //     void onVisibilityChanged(bool visible) const {
    //         handler->visibilityChanged(visible);
    //     }
    // };
}
