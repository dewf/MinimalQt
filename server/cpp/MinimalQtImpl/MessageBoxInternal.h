#pragma once

#include "generated/MessageBox.h"
#include "DialogInternal.h"

#include <QMessageBox>
#include <QAbstractButton>

namespace MessageBox {
    class SignalWrapper : public Dialog::SignalWrapper {
        Q_OBJECT
    private:
        QMessageBox *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { ButtonClicked, SIGNAL(buttonClicked(QAbstractButton)), SLOT(onButtonClicked(QAbstractButton)) }
        };
    public:
        QMessageBox *getActual() const {
            return actual;
        }
        SignalWrapper(QMessageBox *existing, const std::shared_ptr<SignalHandler>& handler)
            : Dialog::SignalWrapper(existing, SignalHandler::as_Dialog_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Dialog::SignalWrapper::setSignalMask(newMask);
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
