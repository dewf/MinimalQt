#pragma once

#include "generated/AbstractProxyModel.h"
#include "AbstractItemModelInternal.h"

#include <QAbstractProxyModel>

namespace AbstractProxyModel {
    class SignalWrapper : public AbstractItemModel::SignalWrapper {
        Q_OBJECT
    private:
        QAbstractProxyModel *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { SourceModelChanged, SIGNAL(sourceModelChanged()), SLOT(onSourceModelChanged()) },
        };
    public:
        QAbstractProxyModel *getActual() const {
            return actual;
        }
        SignalWrapper(QAbstractProxyModel *existing, const std::shared_ptr<SignalHandler>& handler)
            : AbstractItemModel::SignalWrapper(existing, SignalHandler::as_AbstractItemModel_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractItemModel::SignalWrapper::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onSourceModelChanged() const {
            handler->sourceModelChanged();
        };
    };
}
