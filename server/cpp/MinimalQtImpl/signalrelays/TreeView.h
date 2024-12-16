#pragma once

#include "../generated/TreeView.h"
#include "AbstractItemView.h"

namespace TreeView {
    class SignalRelay : public AbstractItemView::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { Collapsed, SIGNAL(collapsed(QModelIndex)), SLOT(onCollapsed(QModelIndex)) },
            { Expanded, SIGNAL(expanded(QModelIndex)), SLOT(onExpanded(QModelIndex)) },
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler)
            : AbstractItemView::SignalRelay(relayFor, SignalHandler::as_AbstractItemView_SignalHandler(handler)),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractItemView::SignalRelay::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, relayFor, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onCollapsed(const QModelIndex& index) const {
            handler->collapsed((ModelIndex::HandleRef)&index);
        }
        void onExpanded(const QModelIndex& index) const {
            handler->expanded((ModelIndex::HandleRef)&index);
        }
    };
}
