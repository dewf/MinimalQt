#pragma once

#include "../util/SignalStuff.h"
#include "../generated/Layout.h"
#include "Object.h"

namespace Layout {
    class SignalRelay : public Object::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // none
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler)
            : Object::SignalRelay(relayFor, SignalHandler::as_Object_SignalHandler(handler)),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Object::SignalRelay::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, relayFor, this);
                lastMask = newMask;
            }
        }
    public slots:
        // none
    };
}
