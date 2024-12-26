#pragma once

#include "generated/ListView.h"
#include "AbstractItemViewInternal.h"

#include <QListView>

namespace ListView {
    class SignalWrapper : public AbstractItemView::SignalWrapper {
        Q_OBJECT
    private:
        QListView *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { IndexesMoved, SIGNAL(indexesMoved(QModelIndexList)), SLOT(onIndexesMoved(QModelIndexList)) },
        };
    public:
        QListView *getActual() const {
            return actual;
        }
        SignalWrapper(QListView *existing, const std::shared_ptr<SignalHandler> &handler)
            : AbstractItemView::SignalWrapper(existing, SignalHandler::as_AbstractItemView_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractItemView::SignalWrapper::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onIndexesMoved(const QModelIndexList &indexes) const {
            std::vector<ModelIndex::HandleRef> indexes2;
            for (auto &index : indexes) {
                // will this work? seems sketchy
                indexes2.push_back((ModelIndex::HandleRef)&index);
            }
            handler->indexesMoved(indexes2);
        }
    };
}
