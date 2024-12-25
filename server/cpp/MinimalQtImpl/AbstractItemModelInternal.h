#pragma once

#include "generated/AbstractItemModel.h"
#include "ObjectInternal.h"

#include "util/SignalStuff.h"
#include "util/Macros.h"

#include <QAbstractItemModel>

namespace AbstractItemModel {
    class SignalWrapper : public Object::SignalWrapper {
        Q_OBJECT
    private:
        QAbstractItemModel *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { ColumnsAboutToBeInserted, SIGNAL(columnsAboutToBeInserted(QModelIndex,int,int)), SLOT(onColumnsAboutToBeInserted(QModelIndex,int,int)) },
            { ColumnsAboutToBeMoved, SIGNAL(columnsAboutToBeMoved(QModelIndex,int,int,QModelIndex,int)), SLOT(onColumnsAboutToBeMoved(QModelIndex,int,int,QModelIndex,int)) },
            { ColumnsAboutToBeRemoved, SIGNAL(columnsAboutToBeRemoved(QModelIndex,int,int)), SLOT(onColumnsAboutToBeRemoved(QModelIndex,int,int)) },
            { ColumnsInserted, SIGNAL(columnsInserted(QModelIndex,int,int)), SLOT(onColumnsInserted(QModelIndex,int,int)) },
            { ColumnsMoved, SIGNAL(columnsMoved(QModelIndex,int,int,QModelIndex,int)), SLOT(onColumnsMoved(QModelIndex,int,int,QModelIndex,int)) },
            { ColumnsRemoved, SIGNAL(columnsRemoved(QModelIndex,int,int)), SLOT(onColumnsRemoved(QModelIndex,int,int)) },
            { DataChanged, SIGNAL(dataChanged(QModelIndex,QModelIndex,QList<int>)), SLOT(onDataChanged(QModelIndex,QModelIndex,QList<int>)) },
            { HeaderDataChanged, SIGNAL(headerDataChanged(Qt::Orientation,int,int)), SLOT(onHeaderDataChanged(Qt::Orientation,int,int)) },
            { LayoutAboutToBeChanged, SIGNAL(layoutAboutToBeChanged(QList<QPersistentModelIndex>,QAbstractItemModel::LayoutChangeHint)), SLOT(onLayoutAboutToBeChanged(QList<QPersistentModelIndex>,QAbstractItemModel::LayoutChangeHint)) },
            { LayoutChanged, SIGNAL(layoutChanged(QList<QPersistentModelIndex>,QAbstractItemModel::LayoutChangeHint)), SLOT(onLayoutChanged(QList<QPersistentModelIndex>,QAbstractItemModel::LayoutChangeHint)) },
            { ModelAboutToBeReset, SIGNAL(modelAboutToBeReset()), SLOT(onModelAboutToBeReset()) },
            { ModelReset, SIGNAL(modelReset()), SLOT(onModelReset()) },
            { RowsAboutToBeInserted, SIGNAL(rowsAboutToBeInserted(QModelIndex,int,int)), SLOT(onRowsAboutToBeInserted(QModelIndex,int,int)) },
            { RowsAboutToBeMoved, SIGNAL(rowsAboutToBeMoved(QModelIndex,int,int,QModelIndex,int)), SLOT(onRowsAboutToBeMoved(QModelIndex,int,int,QModelIndex,int)) },
            { RowsAboutToBeRemoved, SIGNAL(rowsAboutToBeRemoved(QModelIndex,int,int)), SLOT(onRowsAboutToBeRemoved(QModelIndex,int,int)) },
            { RowsInserted, SIGNAL(rowsInserted(QModelIndex,int,int)), SLOT(onRowsInserted(QModelIndex,int,int)) },
            { RowsMoved, SIGNAL(rowsMoved(QModelIndex,int,int,QModelIndex,int)), SLOT(onRowsMoved(QModelIndex,int,int,QModelIndex,int)) },
            { RowsRemoved, SIGNAL(rowsRemoved(QModelIndex,int,int)), SLOT(onRowsRemoved(QModelIndex,int,int)) }
        };
    public:
        QAbstractItemModel *getActual() {
            return actual;
        }
        SignalWrapper(QAbstractItemModel *existing, const std::shared_ptr<SignalHandler> &handler)
            : Object::SignalWrapper(existing, SignalHandler::as_Object_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Object::SignalWrapper::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onColumnsAboutToBeInserted(const QModelIndex &parent, int first, int last) const {
            handler->columnsAboutToBeInserted(MODELINDEX(parent), first, last);
        }
        void onColumnsAboutToBeMoved(const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationColumn) const {
            handler->columnsAboutToBeMoved(MODELINDEX(sourceParent), sourceStart, sourceEnd, MODELINDEX(destinationParent), destinationColumn);
        }
        void onColumnsAboutToBeRemoved(const QModelIndex &parent, int first, int last) const {
            handler->columnsAboutToBeRemoved(MODELINDEX(parent), first, last);
        }
        void onColumnsInserted(const QModelIndex &parent, int first, int last) const {
            handler->columnsInserted(MODELINDEX(parent), first, last);
        }
        void onColumnsMoved(const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationColumn) const {
            handler->columnsMoved(MODELINDEX(sourceParent), sourceStart, sourceEnd, MODELINDEX(destinationParent), destinationColumn);
        }
        void onColumnsRemoved(const QModelIndex &parent, int first, int last) const {
            handler->columnsRemoved(MODELINDEX(parent), first, last);
        }
        void onDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QList<int> &roles = QList<int>()) const {
            std::vector<ItemDataRole> roles2;
            for (auto &role : roles) {
                roles2.push_back(static_cast<ItemDataRole>(role));
            }
            handler->dataChanged(MODELINDEX(topLeft), MODELINDEX(bottomRight), roles2);
        }
        void onHeaderDataChanged(Qt::Orientation orientation, int first, int last) const {
            handler->headerDataChanged(static_cast<Orientation>(orientation), first, last);
        }
        void onLayoutAboutToBeChanged(const QList<QPersistentModelIndex> &parents = QList<QPersistentModelIndex>(), QAbstractItemModel::LayoutChangeHint hint = QAbstractItemModel::NoLayoutChangeHint) const {
            std::vector<PersistentModelIndex::HandleRef> parents2;
            for (auto &parent : parents) {
                parents2.push_back(PMODELINDEX(parent));
            }
            handler->layoutAboutToBeChanged(parents2, static_cast<LayoutChangeHint>(hint));
        }
        void onLayoutChanged(const QList<QPersistentModelIndex> &parents = QList<QPersistentModelIndex>(), QAbstractItemModel::LayoutChangeHint hint = QAbstractItemModel::NoLayoutChangeHint) const {
            std::vector<PersistentModelIndex::HandleRef> parents2;
            for (auto &parent : parents) {
                parents2.push_back(PMODELINDEX(parent));
            }
            handler->layoutChanged(parents2, static_cast<LayoutChangeHint>(hint));
        }
        void onModelAboutToBeReset() const {
            handler->modelAboutToBeReset();
        }
        void onModelReset() const {
            handler->modelReset();
        }
        void onRowsAboutToBeInserted(const QModelIndex &parent, int start, int end) const {
            handler->rowsAboutToBeInserted(MODELINDEX(parent), start, end);
        }
        void onRowsAboutToBeMoved(const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationRow) const {
            handler->rowsAboutToBeMoved(MODELINDEX(sourceParent), sourceStart, sourceEnd, MODELINDEX(destinationParent), destinationRow);
        }
        void onRowsAboutToBeRemoved(const QModelIndex &parent, int first, int last) const {
            handler->rowsAboutToBeRemoved(MODELINDEX(parent), first, last);
        }
        void onRowsInserted(const QModelIndex &parent, int first, int last) const {
            handler->rowsInserted(MODELINDEX(parent), first, last);
        }
        void onRowsMoved(const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationRow) const {
            handler->rowsMoved(MODELINDEX(sourceParent), sourceStart, sourceEnd, MODELINDEX(destinationParent), destinationRow);
        }
        void onRowsRemoved(const QModelIndex &parent, int first, int last) const {
            handler->rowsRemoved(MODELINDEX(parent), first, last);
        }
    };
}
