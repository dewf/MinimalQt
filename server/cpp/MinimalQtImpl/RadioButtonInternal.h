#pragma once

#include "generated/RadioButton.h"
#include "AbstractButtonInternal.h"

#include <QRadioButton>

namespace RadioButton {
    class SignalWrapper : public AbstractButton::SignalWrapper {
        Q_OBJECT
    private:
        QRadioButton *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // none
        };
    public:
        QRadioButton *getActual() const {
            return actual;
        }
        SignalWrapper(QRadioButton *existing, const std::shared_ptr<SignalHandler> &handler)
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
