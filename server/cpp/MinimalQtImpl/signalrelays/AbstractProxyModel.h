#pragma once

#include "../generated/AbstractProxyModel.h"
#include "AbstractItemModel.h"

namespace AbstractProxyModel {
    class SignalRelay : public AbstractItemModel::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { SourceModelChanged, SIGNAL(sourceModelChanged()), SLOT(onSourceModelChanged()) },
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
        void onSourceModelChanged() const {
            handler->sourceModelChanged();
        };
    };
}
