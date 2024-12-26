#pragma once

#include "generated/TreeView.h"
#include "AbstractItemViewInternal.h"

#include <QTreeView>

namespace TreeView {
    class SignalWrapper : public AbstractItemView::SignalWrapper {
        Q_OBJECT
    private:
        QTreeView *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { Collapsed, SIGNAL(collapsed(QModelIndex)), SLOT(onCollapsed(QModelIndex)) },
            { Expanded, SIGNAL(expanded(QModelIndex)), SLOT(onExpanded(QModelIndex)) },
        };
    public:
        QTreeView *getActual() const {
            return actual;
        }
        SignalWrapper(QTreeView *existing, const std::shared_ptr<SignalHandler> &handler)
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
        void onCollapsed(const QModelIndex& index) const {
            handler->collapsed((ModelIndex::HandleRef)&index);
        }
        void onExpanded(const QModelIndex& index) const {
            handler->expanded((ModelIndex::HandleRef)&index);
        }
    };
}
