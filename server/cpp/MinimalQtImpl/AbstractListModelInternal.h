#pragma once

#include "util/SignalStuff.h"
#include "generated/AbstractListModel.h"
#include "AbstractItemModelInternal.h"

#include <QAbstractListModel>

namespace AbstractListModel {
    class SignalWrapper : public AbstractItemModel::SignalWrapper {
        Q_OBJECT
    private:
        QAbstractListModel *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // none extra
        };
    public:
        QAbstractListModel *getActual() const {
            return actual;
        }
        SignalWrapper(QAbstractListModel *existing, const std::shared_ptr<SignalHandler>& handler)
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
        // none defined
    };
}
