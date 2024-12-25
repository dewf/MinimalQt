#pragma once

#include "generated/Dialog.h"
#include "WidgetInternal.h"

#include <QDialog>

namespace Dialog {
    class SignalWrapper : public Widget::SignalWrapper {
        Q_OBJECT
    private:
        QDialog *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { Accepted, SIGNAL(accepted()), SLOT(onAccepted()) },
            { Finished, SIGNAL(finished(int)), SLOT(onFinished(int)) },
            { Rejected, SIGNAL(rejected()), SLOT(onRejected()) },
        };
    public:
        QDialog *getActual() const {
            return actual;
        }
        SignalWrapper(QDialog *existing, const std::shared_ptr<SignalHandler>& handler)
            : Widget::SignalWrapper(existing, SignalHandler::as_Widget_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Widget::SignalWrapper::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onAccepted() const {
            handler->accepted();
        }
        void onFinished(int result) const {
            handler->finished(result);
        }
        void onRejected() const {
            handler->rejected();
        }
    };
}
