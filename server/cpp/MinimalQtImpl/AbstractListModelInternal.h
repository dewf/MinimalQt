#pragma once

#include "util/SignalStuff.h"
#include "generated/AbstractListModel.h"
#include "AbstractItemModelInternal.h"

namespace AbstractListModel {
    class SignalRelay : public AbstractItemModel::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // none extra
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler)
            : AbstractItemModel::SignalRelay(relayFor, SignalHandler::as_AbstractItemModel_SignalHandler(handler)),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractItemModel::SignalRelay::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, relayFor, this);
                lastMask = newMask;
            }
        }
    public slots:
        // none defined
    };
}
