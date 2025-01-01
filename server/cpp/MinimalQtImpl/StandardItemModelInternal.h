#pragma once

#include "generated/StandardItemModel.h"
#include "AbstractItemModelInternal.h"

#include <QStandardItemModel>

namespace StandardItemModel {
    class SignalWrapper : public AbstractItemModel::SignalWrapper {
        Q_OBJECT
    private:
        QStandardItemModel *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { ItemChanged, SIGNAL(itemChanged(QStandardItem*)), SLOT(onItemChanged(QStandardItem*)) }
        };
    public:
        QStandardItemModel *getActual() const {
            return actual;
        }
        SignalWrapper(QStandardItemModel *existing, const std::shared_ptr<SignalHandler>& handler)
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
        void onItemChanged(QStandardItem *item) const {
            // direct cast because these don't have signal wrappers
            handler->ItemChanged(reinterpret_cast<StandardItem::HandleRef>(item));
        }
    };
}
