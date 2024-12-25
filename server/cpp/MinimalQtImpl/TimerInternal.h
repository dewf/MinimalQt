#pragma once

#include "generated/Timer.h"
#include "ObjectInternal.h"

namespace Timer {
    class SignalRelay : public Object::SignalWrapper {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { Timeout, SIGNAL(timeout()), SLOT(onTimeout()) },
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) :
            Object::SignalWrapper(relayFor, SignalHandler::as_Object_SignalHandler(handler)),
            handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Object::SignalWrapper::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onTimeout() const {
            handler->timeout();
        };
    };
}
