#pragma once

#include "generated/AbstractButton.h"
#include <QAbstractButton>

#include "util/SignalStuff.h"
#include "WidgetInternal.h"

namespace AbstractButton {
    class SignalWrapper : public Widget::SignalWrapper {
        Q_OBJECT
    private:
        QAbstractButton *actual = nullptr;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { Clicked, SIGNAL(clicked(bool)), SLOT(onClicked(bool)) },
            { Pressed, SIGNAL(pressed()), SLOT(onPressed()) },
            { Released, SIGNAL(released()), SLOT(onReleased()) },
            { Toggled, SIGNAL(toggled(bool)), SLOT(onToggled(bool)) }
        };
    public:
        QAbstractButton *getActual() const {
            return actual;
        }
        // wrap existing
        SignalWrapper(QAbstractButton *existing, const std::shared_ptr<SignalHandler> &handler)
            : Widget::SignalWrapper(existing, SignalHandler::as_Widget_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Widget::SignalWrapper::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onClicked(bool checkState) const {
            handler->clicked(checkState);
        }
        void onPressed() const {
            handler->pressed();
        }
        void onReleased() const {
            handler->released();
        }
        void onToggled(bool checkState) const {
            handler->toggled(checkState);
        }
    };
}
