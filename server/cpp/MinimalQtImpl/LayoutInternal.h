#pragma once

#include "generated/Layout.h"
#include "ObjectInternal.h"

#include <QLayout>

namespace Layout {
    class SignalWrapper : public Object::SignalWrapper {
        Q_OBJECT
    private:
        QLayout *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // none extra
        };
    public:
        QLayout *getActual() const {
            return actual;
        }
        SignalWrapper(QLayout *existing, const std::shared_ptr<SignalHandler>& handler)
            : Object::SignalWrapper(existing, SignalHandler::as_Object_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Object::SignalWrapper::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        // none
    };
}
