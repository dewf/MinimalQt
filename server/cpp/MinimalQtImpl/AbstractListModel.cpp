#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nodiscard"

#include "generated/AbstractListModel.h"
#include "VariantInternal.h"
#include "ModelIndexInternal.h"

#include <QAbstractListModel>
#include "util/SignalStuff.h"
#include "util/Macros.h"

#define THIS ((AbstractListModelWithHandler*)_this)

namespace AbstractListModel
{
    class AbstractListModelWithHandler : public QAbstractListModel {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // AbstractItemModel:
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
            // AbstractListModel:
            // (none)
        };
    public:
        explicit AbstractListModelWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanged_OLD(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString &name) const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // AbstractItemModel ======
        void onColumnsAboutToBeInserted(const QModelIndex &parent, int first, int last) const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    columnsAboutToBeInserted(MODELINDEX(parent), first, last);
        }
        void onColumnsAboutToBeMoved(const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationColumn) const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    columnsAboutToBeMoved(MODELINDEX(sourceParent), sourceStart, sourceEnd, MODELINDEX(destinationParent), destinationColumn);
        }
        void onColumnsAboutToBeRemoved(const QModelIndex &parent, int first, int last) const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    columnsAboutToBeRemoved(MODELINDEX(parent), first, last);
        }
        void onColumnsInserted(const QModelIndex &parent, int first, int last) const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    columnsInserted(MODELINDEX(parent), first, last);
        }
        void onColumnsMoved(const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationColumn) const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    columnsMoved(MODELINDEX(sourceParent), sourceStart, sourceEnd, MODELINDEX(destinationParent), destinationColumn);
        }
        void onColumnsRemoved(const QModelIndex &parent, int first, int last) const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    columnsRemoved(MODELINDEX(parent), first, last);
        }
        void onDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QList<int> &roles = QList<int>()) const {
            std::vector<ItemDataRole> roles2;
            for (auto &role : roles) {
                roles2.push_back((ItemDataRole)role);
            }
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    dataChanged(MODELINDEX(topLeft), MODELINDEX(bottomRight), roles2);
        }
        void onHeaderDataChanged(Qt::Orientation orientation, int first, int last) const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    headerDataChanged((Enums::Orientation)orientation, first, last);
        }
        void onLayoutAboutToBeChanged(const QList<QPersistentModelIndex> &parents = QList<QPersistentModelIndex>(), QAbstractItemModel::LayoutChangeHint hint = QAbstractItemModel::NoLayoutChangeHint) const {
            std::vector<PersistentModelIndex::HandleRef> parents2;
            for (auto &parent : parents) {
                parents2.push_back(PMODELINDEX(parent));
            }
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    layoutAboutToBeChanged(parents2, (AbstractItemModel::LayoutChangeHint)hint);
        }
        void onLayoutChanged(const QList<QPersistentModelIndex> &parents = QList<QPersistentModelIndex>(), QAbstractItemModel::LayoutChangeHint hint = QAbstractItemModel::NoLayoutChangeHint) const {
            std::vector<PersistentModelIndex::HandleRef> parents2;
            for (auto &parent : parents) {
                parents2.push_back(PMODELINDEX(parent));
            }
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    layoutChanged(parents2, (AbstractItemModel::LayoutChangeHint)hint);
        }
        void onModelAboutToBeReset() const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    modelAboutToBeReset();
        }
        void onModelReset() const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    modelReset();
        }
        void onRowsAboutToBeInserted(const QModelIndex &parent, int start, int end) const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    rowsAboutToBeInserted(MODELINDEX(parent), start, end);
        }
        void onRowsAboutToBeMoved(const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationRow) const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    rowsAboutToBeMoved(MODELINDEX(sourceParent), sourceStart, sourceEnd, MODELINDEX(destinationParent), destinationRow);
        }
        void onRowsAboutToBeRemoved(const QModelIndex &parent, int first, int last) const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    rowsAboutToBeRemoved(MODELINDEX(parent), first, last);
        }
        void onRowsInserted(const QModelIndex &parent, int first, int last) const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    rowsInserted(MODELINDEX(parent), first, last);
        }
        void onRowsMoved(const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationRow) const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    rowsMoved(MODELINDEX(sourceParent), sourceStart, sourceEnd, MODELINDEX(destinationParent), destinationRow);
        }
        void onRowsRemoved(const QModelIndex &parent, int first, int last) const {
            handler->
                inherited_AbstractItemModel_SignalHandler()->
                    rowsRemoved(MODELINDEX(parent), first, last);
        }
    };

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        printf("AbstractListModel::Handle_dispose() called (vs. subclass dispose) ... honoring for now, but this might be a bug\n");
        delete THIS;
    }

    // subclass stuff =========================================================

#define SUBTHIS ((Subclassed*)_this)

    class Subclassed : public AbstractListModelWithHandler {
    private:
        std::shared_ptr<MethodDelegate> methodDelegate;
        MethodMask methodMask;
    public:
        Subclassed(const std::shared_ptr<SignalHandler> &handler, const std::shared_ptr<MethodDelegate> &methodDelegate, MethodMask methodMask)
                : AbstractListModelWithHandler(handler), methodDelegate(methodDelegate), methodMask(methodMask)
        {
        }

        // ==== must-implement abstract methods ===========================
        int rowCount(const QModelIndex &parent) const override {
            return methodDelegate->rowCount((ModelIndex::HandleRef)&parent);
        }

        QVariant data(const QModelIndex &index, int role) const override {
            auto deferred = methodDelegate->data((ModelIndex::HandleRef)&index, (ItemDataRole)role);
            return Variant::fromDeferred(deferred);
        }

        // ==== optional methods ==========================================
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override {
            if (methodMask & MethodMaskFlags::HeaderData) {
                auto deferred = methodDelegate->headerData(section, (Enums::Orientation)orientation, (ItemDataRole)role);
                return Variant::fromDeferred(deferred);
            } else {
                return QAbstractListModel::headerData(section, orientation, role);
            }
        }

        Qt::ItemFlags flags(const QModelIndex &index) const override {
            auto baseFlags = QAbstractListModel::flags(index);
            if (methodMask & MethodMaskFlags::Flags) {
                auto raw = (int)methodDelegate->getFlags((ModelIndex::HandleRef)&index, baseFlags);
                return (Qt::ItemFlags) raw;
            } else {
                return baseFlags;
            }
        }

        bool setData(const QModelIndex &index, const QVariant &value, int role) override {
            if (methodMask & MethodMaskFlags::SetData) {
                return methodDelegate->setData((ModelIndex::HandleRef)&index, (Variant::HandleRef)&value, (ItemDataRole)role);
            } else {
                return QAbstractListModel::setData(index, value, role);
            }
        }

        int columnCount(const QModelIndex &parent) const override {
            if (methodMask & MethodMaskFlags::ColumnCount) {
                return methodDelegate->columnCount((ModelIndex::HandleRef)&parent);
            } else {
                // QAbstractListModel::columnCount() is private, we're technically not supposed to be doing this in AbstractListModel
                return 1;
            }
        }

        // signal emission wrappers
        void emitDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QList<int>& roles) {
            emit dataChanged(topLeft, bottomRight, roles);
        }

        void emitHeaderDataChanged(Qt::Orientation orientation, int first, int last) {
            emit headerDataChanged(orientation, first, last);
        }

        // 'interior' (friend handle) functions
        friend void Interior_beginInsertRows(InteriorRef _this, ModelIndex::HandleRef parent, int32_t first, int32_t last);
        friend void Interior_endInsertRows(InteriorRef _this);
        friend void Interior_beginRemoveRows(InteriorRef _this, ModelIndex::HandleRef parent, int32_t first, int32_t last);
        friend void Interior_endRemoveRows(InteriorRef _this);
        friend void Interior_beginResetModel(InteriorRef _this);
        friend void Interior_endResetModel(InteriorRef _this);
    };

    void Interior_emitDataChanged(InteriorRef _this, ModelIndex::HandleRef topLeft, ModelIndex::HandleRef bottomRight, const std::vector<ItemDataRole>& roles) {
        QList<int> qRoles;
        for (auto role : roles) {
            qRoles.push_back((int)role);
        }
        SUBTHIS->emitDataChanged(MODELINDEX_VALUE(topLeft), MODELINDEX_VALUE(bottomRight), qRoles);
    }

    void Interior_emitHeaderDataChanged(InteriorRef _this, Orientation orientation, int32_t first, int32_t last) {
        SUBTHIS->emitHeaderDataChanged(static_cast<Qt::Orientation>(orientation), first, last);
    }

    void Interior_beginInsertRows(InteriorRef _this, ModelIndex::HandleRef parent, int32_t first, int32_t last) {
        SUBTHIS->beginInsertRows(MODELINDEX_VALUE(parent), first, last);
    }

    void Interior_endInsertRows(InteriorRef _this) {
        SUBTHIS->endInsertRows();
    }

    void Interior_beginRemoveRows(InteriorRef _this, ModelIndex::HandleRef parent, int32_t first, int32_t last) {
        SUBTHIS->beginRemoveRows(MODELINDEX_VALUE(parent), first, last);
    }

    void Interior_endRemoveRows(InteriorRef _this) {
        SUBTHIS->endRemoveRows();
    }

    void Interior_beginResetModel(InteriorRef _this) {
        SUBTHIS->beginResetModel();
    }

    void Interior_endResetModel(InteriorRef _this) {
        SUBTHIS->endResetModel();
    }

    void Interior_dispose(InteriorRef _this) {
        delete SUBTHIS;
    }

    InteriorRef createSubclassed(const std::shared_ptr<SignalHandler>& handler, const std::shared_ptr<MethodDelegate>& methodDelegate, MethodMask methodMask) {
        return reinterpret_cast<InteriorRef>(new Subclassed(handler, methodDelegate, methodMask));
    }
}
#pragma clang diagnostic pop

#include "AbstractListModel.moc"
