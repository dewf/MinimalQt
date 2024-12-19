#pragma once

#include "generated/AbstractButton.h"

#include "util/SignalStuff.h"
#include "WidgetInternal.h"

namespace AbstractButton {
    class SignalRelay : public Widget::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { Clicked, SIGNAL(clicked(bool)), SLOT(onClicked(bool)) },
            { Pressed, SIGNAL(pressed()), SLOT(onPressed()) },
            { Released, SIGNAL(released()), SLOT(onReleased()) },
            { Toggled, SIGNAL(toggled(bool)), SLOT(onToggled(bool)) }
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) :
            Widget::SignalRelay(relayFor, SignalHandler::as_Widget_SignalHandler(handler)),
            handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Widget::SignalRelay::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, relayFor, this);
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
