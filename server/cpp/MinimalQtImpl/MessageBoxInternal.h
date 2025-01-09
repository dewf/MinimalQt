#pragma once

#include "generated/MessageBox.h"
#include "DialogInternal.h"

#include <QMessageBox>
#include <QAbstractButton>

#include "AbstractButtonInternal.h"

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
            // uhhhh, it coudl conceivably be a button we haven't wrapped yet, SIGH
            std::shared_ptr<AbstractButtonResult::Base> result;
            if (const auto existing = wrapperForQObject(button); existing != nullptr) {
                result = std::make_shared<AbstractButtonResult::Existing>(reinterpret_cast<AbstractButton::HandleRef>(existing));
            } else {
                // we haven't seen it before, needs a wrapper
                const auto createFunc = [button](const std::shared_ptr<AbstractButton::SignalHandler>& handler) {
                    const auto wrapper = new AbstractButton::SignalWrapper(button, handler);
                    return reinterpret_cast<AbstractButton::HandleRef>(wrapper);
                };
                result = std::make_shared<AbstractButtonResult::NeedsWrapper>(createFunc);
            }
            handler->buttonClicked(result);
        }
    };
}
