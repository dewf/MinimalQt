#pragma once

#include "generated/MessageBox.h"
#include "DialogInternal.h"

#include <QAbstractButton>

namespace MessageBox {
    class SignalRelay : public Dialog::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { ButtonClicked, SIGNAL(buttonClicked(QAbstractButton)), SLOT(onButtonClicked(QAbstractButton)) }
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) :
            Dialog::SignalRelay(relayFor, SignalHandler::as_Dialog_SignalHandler(handler)),
            handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Dialog::SignalRelay::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onButtonClicked(QAbstractButton *button) const {
            handler->buttonClicked(reinterpret_cast<AbstractButton::HandleRef>(button));
        }
    };
}
