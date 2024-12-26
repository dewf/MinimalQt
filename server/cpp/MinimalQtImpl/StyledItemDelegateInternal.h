#pragma once

#include "generated/StyledItemDelegate.h"
#include "AbstractItemDelegateInternal.h"

#include <QStyledItemDelegate>

namespace StyledItemDelegate {
    class SignalWrapper : public AbstractItemDelegate::SignalWrapper {
        Q_OBJECT
    private:
        QStyledItemDelegate *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // none
        };
    public:
        QStyledItemDelegate *getActual() const {
            return actual;
        }
        SignalWrapper(QStyledItemDelegate *existing, const std::shared_ptr<SignalHandler> &handler)
            : AbstractItemDelegate::SignalWrapper(existing, SignalHandler::as_AbstractItemDelegate_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractItemDelegate::SignalWrapper::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        // none
    };
}
