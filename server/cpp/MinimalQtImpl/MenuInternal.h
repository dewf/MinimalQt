#pragma once

#include "generated/Menu.h"
#include "WidgetInternal.h"

#include <QAction>

namespace Menu {
    class SignalRelay : public Widget::SignalWrapper {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { AboutToHide, SIGNAL(aboutToHide()), SLOT(onAboutToHide()) },
            { AboutToShow, SIGNAL(aboutToShow()), SLOT(onAboutToShow()) },
            { Hovered, SIGNAL(hovered(QAction*)), SLOT(onHovered(QAction*)) },
            { Triggered, SIGNAL(triggered(QAction*)), SLOT(onTriggered(QAction*)) }
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) :
            Widget::SignalWrapper(relayFor, SignalHandler::as_Widget_SignalHandler(handler)),
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
        void onAboutToHide() const {
            handler->aboutToHide();
        }
        void onAboutToShow() const {
            handler->aboutToShow();
        }
        void onHovered(QAction *action) const {
            handler->hovered(reinterpret_cast<Action::HandleRef>(action));
        }
        void onTriggered(QAction *action) const {
            handler->triggered(reinterpret_cast<Action::HandleRef>(action));
        }
    };
}
