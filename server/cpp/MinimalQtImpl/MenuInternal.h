#pragma once

#include "generated/Menu.h"
#include "WidgetInternal.h"

#include <QAction>
#include <QMenu>

namespace Menu {
    class SignalWrapper : public Widget::SignalWrapper {
        Q_OBJECT
    private:
        QMenu *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { AboutToHide, SIGNAL(aboutToHide()), SLOT(onAboutToHide()) },
            { AboutToShow, SIGNAL(aboutToShow()), SLOT(onAboutToShow()) },
            { Hovered, SIGNAL(hovered(QAction*)), SLOT(onHovered(QAction*)) },
            { Triggered, SIGNAL(triggered(QAction*)), SLOT(onTriggered(QAction*)) }
        };
    public:
        QMenu *getActual() const {
            return actual;
        }
        SignalWrapper(QMenu *existing, const std::shared_ptr<SignalHandler> &handler)
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
        void onAboutToHide() const {
            handler->aboutToHide();
        }
        void onAboutToShow() const {
            handler->aboutToShow();
        }
        void onHovered(QAction *action) const {
            const auto wrapper = wrapperForQObject(action);
            handler->hovered(reinterpret_cast<Action::HandleRef>(wrapper));
        }
        void onTriggered(QAction *action) const {
            const auto wrapper = wrapperForQObject(action);
            handler->triggered(reinterpret_cast<Action::HandleRef>(wrapper));
        }
    };
}
