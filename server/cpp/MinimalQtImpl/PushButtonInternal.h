#pragma once

#include "generated/PushButton.h"
#include "AbstractButtonInternal.h"

#include "util/SignalStuff.h"
#include <QPushButton>

namespace PushButton {
    class SignalWrapper : public AbstractButton::SignalWrapper {
        Q_OBJECT
    private:
        QPushButton *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // PushButton:
            // .... (none)
        };
    public:
        QPushButton *getActual() const {
            return actual;
        }
        SignalWrapper(QPushButton *existing, const std::shared_ptr<SignalHandler> &handler)
            : AbstractButton::SignalWrapper(existing, SignalHandler::as_AbstractButton_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractButton::SignalWrapper::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        // none
    };
}
