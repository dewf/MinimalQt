#pragma once

#include "generated/Timer.h"
#include "ObjectInternal.h"

#include <QTimer>

namespace Timer {
    class SignalWrapper : public Object::SignalWrapper {
        Q_OBJECT
    private:
        QTimer *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { Timeout, SIGNAL(timeout()), SLOT(onTimeout()) },
        };
    public:
        QTimer *getActual() const {
            return actual;
        }
        SignalWrapper(QTimer *existing, const std::shared_ptr<SignalHandler> &handler)
            : Object::SignalWrapper(existing, SignalHandler::as_Object_SignalHandler(handler)),
              actual(existing),
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
