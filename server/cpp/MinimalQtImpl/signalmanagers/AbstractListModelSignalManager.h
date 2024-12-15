#pragma once

#include "../util/SignalStuff.h"
#include "../generated/AbstractListModel.h"
#include "AbstractItemModelSignalManager.h"

namespace AbstractListModel {
    class AbstractListModelSignalManager : public AbstractItemModelSignalManager {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // none extra
        };
    public:
        explicit AbstractListModelSignalManager(QObject *managerFor, const std::shared_ptr<SignalHandler> &handler)
            : AbstractItemModelSignalManager(managerFor, SignalHandler::as_AbstractItemModel_SignalHandler(handler)),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractItemModelSignalManager::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, sender, this);
                lastMask = newMask;
            }
        }
    public slots:
        // none defined
    };
}
