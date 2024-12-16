#pragma once

#include "../generated/MainWindow.h"
#include "Widget.h"

#include "../util/SignalStuff.h"
#include "../util/convert.h"

#include <QDockWidget>

namespace MainWindow {
    class SignalRelay : public Widget::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // MainWindow:
            { IconSizeChanged, SIGNAL(iconSizeChanged(QSize)), SLOT(onIconSizeChanged(QSize)) },
            { TabifiedDockWidgetActivated, SIGNAL(tabifiedDockWidgetActivated(QDockWidget)), SLOT(onTabifiedDockWidgetActivated(QDockWidget)) },
            { ToolButtonStyleChanged, SIGNAL(toolButtonStyleChanged(Qt::ToolButtonStyle)), SLOT(onToolButtonStyleChanged(Qt::ToolButtonStyle)) },
            // MainWindow custom:
            { WindowClosed, SIGNAL(windowClosed()), SLOT(onWindowClosed()) }
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) :
            Widget::SignalRelay(relayFor, SignalHandler::as_Widget_SignalHandler(handler)),
            handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Widget::SignalRelay::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, relayFor, this);
                lastMask = newMask;
            }
        }
    public slots:
        // MainWindow ===============
        void onIconSizeChanged(const QSize& size) const {
            handler->iconSizeChanged(toSize(size));
        }
        void onTabifiedDockWidgetActivated(QDockWidget* dockWidget) const {
            handler->tabifiedDockWidgetActivated(reinterpret_cast<DockWidget::HandleRef>(dockWidget));
        }
        void onToolButtonStyleChanged(Qt::ToolButtonStyle style) const {
            handler->toolButtonStyleChanged(static_cast<ToolButtonStyle>(style));
        }
        // MainWindow (custom) ======
        void onWindowClosed() const {
            handler->windowClosed();
        }
    };
}
