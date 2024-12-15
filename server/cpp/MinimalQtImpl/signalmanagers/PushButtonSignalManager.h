#pragma once

#include "../generated/PushButton.h"
#include "AbstractButtonSignalManager.h"
#include "../util/SignalStuff.h"

namespace PushButton {
    class PushButtonSignalManager : public AbstractButtonSignalManager {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // PushButton:
            // .... (none)
        };
    public:
        explicit PushButtonSignalManager(QObject *managerFor, const std::shared_ptr<SignalHandler> &handler) :
            AbstractButtonSignalManager(managerFor, SignalHandler::as_AbstractButton_SignalHandler(handler)),
            handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractButtonSignalManager::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, sender, this);
                lastMask = newMask;
            }
        }
    public slots:
        // none
    };
}
