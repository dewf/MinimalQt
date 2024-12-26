#pragma once

#include "generated/MenuBar.h"
#include "WidgetInternal.h"

#include <QAction>
#include <QMenuBar>

namespace MenuBar {
    class SignalWrapper : public Widget::SignalWrapper {
        Q_OBJECT
    private:
        QMenuBar *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { Hovered, SIGNAL(hovered(QAction*)), SLOT(onHovered(QAction*)) },
            { Triggered, SIGNAL(triggered(QAction*)), SLOT(onTriggered(QAction*))}
        };
    public:
        QMenuBar *getActual() const {
            return actual;
        }
        SignalWrapper(QMenuBar *existing, const std::shared_ptr<SignalHandler>& handler)
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
        void onHovered(QAction* action) const {
            handler->hovered(reinterpret_cast<Action::HandleRef>(action));
        }
        void onTriggered(QAction* action) const {
            handler->triggered(reinterpret_cast<Action::HandleRef>(action));
        }
    };
}
