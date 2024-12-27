#pragma once

#include "generated/MainWindow.h"
#include "WidgetInternal.h"

#include "util/SignalStuff.h"
#include "util/convert.h"

#include <QDockWidget>
#include <QMainWindow>

namespace MainWindow {
    class SignalWrapper : public Widget::SignalWrapper {
        Q_OBJECT
    private:
        QMainWindow *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // MainWindow:
            { IconSizeChanged, SIGNAL(iconSizeChanged(QSize)), SLOT(onIconSizeChanged(QSize)) },
            { TabifiedDockWidgetActivated, SIGNAL(tabifiedDockWidgetActivated(QDockWidget)), SLOT(onTabifiedDockWidgetActivated(QDockWidget)) },
            { ToolButtonStyleChanged, SIGNAL(toolButtonStyleChanged(Qt::ToolButtonStyle)), SLOT(onToolButtonStyleChanged(Qt::ToolButtonStyle)) },
        };
    public:
        QMainWindow *getActual() const {
            return actual;
        }
        SignalWrapper(QMainWindow *existing, const std::shared_ptr<SignalHandler>& handler)
            : Widget::SignalWrapper(existing, SignalHandler::as_Widget_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Widget::SignalWrapper::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        // MainWindow ===============
        void onIconSizeChanged(const QSize& size) const {
            handler->iconSizeChanged(toSize(size));
        }
        void onTabifiedDockWidgetActivated(QDockWidget* dockWidget) const {
            const auto wrapper = wrapperForQObject(dockWidget);
            handler->tabifiedDockWidgetActivated(reinterpret_cast<DockWidget::HandleRef>(wrapper));
        }
        void onToolButtonStyleChanged(Qt::ToolButtonStyle style) const {
            handler->toolButtonStyleChanged(static_cast<ToolButtonStyle>(style));
        }
    };
}
