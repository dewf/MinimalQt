#pragma once

#include "../generated/RadioButton.h"
#include "AbstractButton.h"

namespace RadioButton {
    class SignalRelay : public AbstractButton::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // none
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) :
            AbstractButton::SignalRelay(relayFor, SignalHandler::as_AbstractButton_SignalHandler(handler)),
            handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractButton::SignalRelay::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, relayFor, this);
                lastMask = newMask;
            }
        }
        public slots:
            // none
        };
}
