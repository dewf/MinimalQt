#pragma once

#include "generated/ItemSelectionModel.h"
#include "ObjectInternal.h"
#include "AbstractItemModelInternal.h"

#include <QItemSelectionModel>

namespace ItemSelectionModel {
    class SignalWrapper : public Object::SignalWrapper {
        Q_OBJECT
    private:
        QItemSelectionModel *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { CurrentChanged, SIGNAL(currentChanged(QModelIndex,QModelIndex)), SLOT(onCurrentChanged(QModelIndex,QModelIndex)) },
            { CurrentColumnChanged, SIGNAL(currentColumnChanged(QModelIndex,QModelIndex)), SLOT(onCurrentColumnChanged(QModelIndex,QModelIndex)) },
            { CurrentRowChanged, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), SLOT(onCurrentRowChanged(QModelIndex,QModelIndex)) },
            { ModelChanged, SIGNAL(modelChanged(QAbstractItemModel*)), SLOT(onModelChanged(QAbstractItemModel*)) },
            { SelectionChanged, SIGNAL(selectionChanged(QItemSelection,QItemSelection)), SLOT(onSelectionChanged(QItemSelection,QItemSelection)) }
        };
    public:
        QItemSelectionModel *getActual() const {
            return actual;
        }
        SignalWrapper(QItemSelectionModel *existing, const std::shared_ptr<SignalHandler>& handler)
            : Object::SignalWrapper(existing, SignalHandler::as_Object_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Object::SignalWrapper::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onCurrentChanged(const QModelIndex &current, const QModelIndex &previous) const {
            handler->currentChanged((ModelIndex::HandleRef)&current, (ModelIndex::HandleRef)&previous);
        }
        void onCurrentColumnChanged(const QModelIndex &current, const QModelIndex &previous) const {
            handler->currentColumnChanged((ModelIndex::HandleRef)&current, (ModelIndex::HandleRef)&previous);
        }
        void onCurrentRowChanged(const QModelIndex &current, const QModelIndex &previous) const {
            handler->currentRowChanged((ModelIndex::HandleRef)&current, (ModelIndex::HandleRef)&previous);
        }
        void onModelChanged(QAbstractItemModel *model) const {
            const auto modelWrapper = wrapperForQObject(model);
            handler->modelChanged(reinterpret_cast<AbstractItemModel::HandleRef>(modelWrapper));
        }
        void onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected) const {
            handler->selectionChanged((ItemSelection::HandleRef)&selected, (ItemSelection::HandleRef)&deselected);
        }
    };
}
