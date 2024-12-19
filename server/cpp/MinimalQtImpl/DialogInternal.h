#pragma once

#include "generated/Dialog.h"
#include "WidgetInternal.h"

namespace Dialog {
    class SignalRelay : public Widget::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { Accepted, SIGNAL(accepted()), SLOT(onAccepted()) },
            { Finished, SIGNAL(finished(int)), SLOT(onFinished(int)) },
            { Rejected, SIGNAL(rejected()), SLOT(onRejected()) },
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) :
            Widget::SignalRelay(relayFor, SignalHandler::as_Widget_SignalHandler(handler)),
            handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Widget::SignalRelay::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, relayFor, this);
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
