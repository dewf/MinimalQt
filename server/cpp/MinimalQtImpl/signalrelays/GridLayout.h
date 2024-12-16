#pragma once

#include "../generated/GridLayout.h"
#include "Layout.h"

namespace GridLayout {
    class SignalRelay : public Layout::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // none
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler)
            : Layout::SignalRelay(relayFor, SignalHandler::as_Layout_SignalHandler(handler)),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Layout::SignalRelay::setSignalMask(newMask);
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
