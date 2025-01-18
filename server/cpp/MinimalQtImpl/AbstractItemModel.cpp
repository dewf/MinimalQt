#include "generated/AbstractItemModel.h"
#include "AbstractItemModelInternal.h"

#include <QAbstractItemModel>

#include "ObjectInternal.h"
#include "MimeDataInternal.h"
#include "ModelIndexInternal.h"
#include "VariantInternal.h"
#include "util/convert.h"

#define THIS (reinterpret_cast<QAbstractItemModel*>(_this))
#define SUBCLASSED_THIS (reinterpret_cast<Implementation*>(_this))

#define PMODELINDEX(x) ((PersistentModelIndex::HandleRef)&x)

namespace AbstractItemModel
{
    ModelIndex::OwnedRef Handle_buddy(HandleRef _this, ModelIndex::HandleRef index) {
        return new ModelIndex::__Owned { THIS->buddy(index->value) };
    }

    bool Handle_canDropMimeData(HandleRef _this, MimeData::HandleRef data, DropAction action, int32_t row, int32_t column, ModelIndex::HandleRef parent) {
        return THIS->canDropMimeData(AS_QMIMEDATA_PTR(data), static_cast<Qt::DropAction>(action), row, column, parent->value);
    }

    bool Handle_canFetchMore(HandleRef _this, ModelIndex::HandleRef parent) {
        return THIS->canFetchMore(parent->value);
    }

    bool Handle_checkIndex(HandleRef _this, ModelIndex::HandleRef index, const std::optional<CheckIndexOptions>& options_) {
        CheckIndexOptions optionsArg = options_.value_or(CheckIndexOptions::NoOption);
        return THIS->checkIndex(index->value, static_cast<QAbstractItemModel::CheckIndexOption>(optionsArg.value));
    }

    bool Handle_clearItemData(HandleRef _this, ModelIndex::HandleRef index) {
        return THIS->clearItemData(index->value);
    }

    int32_t Handle_columnCount(HandleRef _this, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->columnCount(fromOptionalIndex(parent));
    }

    Variant::OwnedRef Handle_data(HandleRef _this, ModelIndex::HandleRef index, const std::optional<int32_t>& role) {
        return new Variant::__Owned { THIS->data(index->value, role.value_or(Qt::DisplayRole))};
    }

    bool Handle_dropMimeData(HandleRef _this, MimeData::HandleRef data, DropAction action, int32_t row, int32_t column, ModelIndex::HandleRef parent) {
        return THIS->dropMimeData(AS_QMIMEDATA_PTR(data), static_cast<Qt::DropAction>(action), row, column, parent->value);
    }

    void Handle_fetchMore(HandleRef _this, ModelIndex::HandleRef parent) {
        THIS->fetchMore(parent->value);
    }

    ItemFlags Handle_flags_(HandleRef _this, ModelIndex::HandleRef index) {
        return ItemFlags(THIS->flags(index->value));
    }

    bool Handle_hasChildren(HandleRef _this, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->hasChildren(fromOptionalIndex(parent));
    }

    bool Handle_hasIndex(HandleRef _this, int32_t row, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->hasIndex(row, column, fromOptionalIndex(parent));
    }

    Variant::OwnedRef Handle_headerData(HandleRef _this, int32_t section, Orientation orientation, const std::optional<int32_t>& role) {
        return new Variant::__Owned { THIS->headerData(section, static_cast<Qt::Orientation>(orientation), role.value_or(Qt::DisplayRole)) };
    }

    ModelIndex::OwnedRef Handle_index(HandleRef _this, int32_t row, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return new ModelIndex::__Owned { THIS->index(row, column, fromOptionalIndex(parent)) };
    }

    bool Handle_insertColumn(HandleRef _this, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->insertColumn(column, fromOptionalIndex(parent));
    }

    bool Handle_insertColumns(HandleRef _this, int32_t column, int32_t count, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->insertColumns(column, count, fromOptionalIndex(parent));
    }

    bool Handle_insertRow(HandleRef _this, int32_t row, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->insertRow(row, fromOptionalIndex(parent));
    }

    bool Handle_insertRows(HandleRef _this, int32_t row, int32_t count, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->insertRows(row, count, fromOptionalIndex(parent));
    }

    std::map<int32_t,Variant::OwnedRef> Handle_itemData(HandleRef _this, ModelIndex::HandleRef index) {
        const auto result = THIS->itemData(index->value);
        std::map<int32_t, Variant::OwnedRef> retMap;
        for (auto i = result.cbegin(), end = result.cend(); i != end; ++i) {
            retMap[i.key()] = new Variant::__Owned { i.value() };
        }
        return retMap;
    }

    std::vector<ModelIndex::OwnedRef> Handle_match(HandleRef _this, ModelIndex::HandleRef start, int32_t role, Variant::HandleRef value, int32_t hits /* 1 */, MatchFlags flags_ /* MatchFlags::MatchStartsWith | MatchFlags::MatchWrap */) {
        std::vector<ModelIndex::OwnedRef> ret;
        const auto result = THIS->match(start->value, role, value->value, hits, static_cast<Qt::MatchFlags>(flags_.value));
        return fromQList<QModelIndex,ModelIndex::OwnedRef>(result, [](const QModelIndex &index) { return new ModelIndex::__Owned(index); });
    }

    MimeData::HandleRef Handle_getMimeData(HandleRef _this, const std::vector<ModelIndex::HandleRef>& indexes) {
        const auto qIndexes = toQList<ModelIndex::HandleRef,QModelIndex>(indexes, [](const ModelIndex::HandleRef& ref) { return ref->value; });
        return reinterpret_cast<MimeData::HandleRef>(THIS->mimeData(qIndexes));
    }

    std::vector<std::string> Handle_mimeTypes(HandleRef _this) {
        return toVectorStrings(THIS->mimeTypes());
    }

    bool Handle_moveColumn(HandleRef _this, ModelIndex::HandleRef sourceParent, int32_t sourceColumn, ModelIndex::HandleRef destinationParent, int32_t destinationChild) {
        return THIS->moveColumn(sourceParent->value, sourceColumn, destinationParent->value, destinationChild);
    }

    bool Handle_moveColumns(HandleRef _this, ModelIndex::HandleRef sourceParent, int32_t sourceColumn, int32_t count, ModelIndex::HandleRef destinationParent, int32_t destinationChild) {
        return THIS->moveColumns(sourceParent->value, sourceColumn, count, destinationParent->value, destinationChild);
    }

    bool Handle_moveRow(HandleRef _this, ModelIndex::HandleRef sourceParent, int32_t sourceRow, ModelIndex::HandleRef destinationParent, int32_t destinationChild) {
        return THIS->moveRow(sourceParent->value, sourceRow, destinationParent->value, destinationChild);
    }

    bool Handle_moveRows(HandleRef _this, ModelIndex::HandleRef sourceParent, int32_t sourceRow, int32_t count, ModelIndex::HandleRef destinationParent, int32_t destinationChild) {
        return THIS->moveRows(sourceParent->value, sourceRow, count, destinationParent->value, destinationChild);
    }

    ModelIndex::OwnedRef Handle_parent(HandleRef _this, ModelIndex::HandleRef index) {
        return new ModelIndex::__Owned { THIS->parent(index->value) };
    }

    bool Handle_removeColumn(HandleRef _this, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->removeColumn(column, fromOptionalIndex(parent));
    }

    bool Handle_removeColumns(HandleRef _this, int32_t column, int32_t count, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->removeColumns(column, count, fromOptionalIndex(parent));
    }

    bool Handle_removeRow(HandleRef _this, int32_t row, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->removeRow(row, fromOptionalIndex(parent));
    }

    bool Handle_removeRows(HandleRef _this, int32_t row, int32_t count, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->removeRows(row, count, fromOptionalIndex(parent));
    }

    int32_t Handle_rowCount(HandleRef _this, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->rowCount(fromOptionalIndex(parent));
    }

    bool Handle_setData(HandleRef _this, ModelIndex::HandleRef index, Variant::HandleRef value, const std::optional<int32_t>& role) {
        return THIS->setData(index->value, value->value, role.value_or(Qt::EditRole));
    }

    bool Handle_setHeaderData(HandleRef _this, int32_t section, Orientation orientation, Variant::HandleRef value, const std::optional<int32_t>& role) {
        return THIS->setHeaderData(section, static_cast<Qt::Orientation>(orientation), value->value, role.value_or(Qt::EditRole));
    }

    bool Handle_setItemData(HandleRef _this, ModelIndex::HandleRef index, std::map<int32_t,Variant::HandleRef> roles) {
        const QMap<int, QVariant> qRoles;
        for (auto i = roles.begin(); i != roles.end(); ++i) {
            qRoles[i->first] = i->second->value;
        }
        return THIS->setItemData(index->value, qRoles);
    }

    ModelIndex::OwnedRef Handle_sibling(HandleRef _this, int32_t row, int32_t column, ModelIndex::HandleRef index) {
        return new ModelIndex::__Owned { THIS->sibling(row, column, index->value) };
    }

    void Handle_sort(HandleRef _this, int32_t column, const std::optional<SortOrder>& order) {
        const auto order2 = order.value_or(SortOrder::AscendingOrder);
        THIS->sort(column, static_cast<Qt::SortOrder>(order2));
    }

    Size Handle_span(HandleRef _this, ModelIndex::HandleRef index) {
        return toSize(THIS->span(index->value));
    }

    DropActions Handle_supportedDragActions(HandleRef _this) {
        return DropActions(THIS->supportedDragActions());
    }

    DropActions Handle_supportedDropActions(HandleRef _this) {
        return DropActions(THIS->supportedDropActions());
    }

    void Handle_revert(HandleRef _this) {
        THIS->revert();
    }

    void Handle_submit(HandleRef _this) {
        THIS->submit();
    }

    SignalConnectionRef Handle_connect_ColumnsAboutToBeInserted(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::columnsAboutToBeInserted, [handler](const QModelIndex &parent, int first, int last) {
            ModelIndex::__Handle parent2(parent);
            handler->columnsAboutToBeInserted(&parent2, first, last);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ColumnsAboutToBeMoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::columnsAboutToBeMoved, [handler](const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationColumn) {
            ModelIndex::__Handle src2(sourceParent);
            ModelIndex::__Handle dest2(destinationParent);
            handler->columnsAboutToBeMoved(&src2, sourceStart, sourceEnd, &dest2, destinationColumn);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ColumnsAboutToBeRemoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::columnsAboutToBeRemoved, [handler](const QModelIndex &parent, int first, int last) {
            ModelIndex::__Handle parent2(parent);
            handler->columnsAboutToBeRemoved(&parent2, first, last);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ColumnsInserted(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::columnsInserted, [handler](const QModelIndex &parent, int first, int last) {
            ModelIndex::__Handle parent2(parent);
            handler->columnsInserted(&parent2, first, last);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ColumnsMoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::columnsMoved, [handler](const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationColumn) {
            ModelIndex::__Handle src2(sourceParent);
            ModelIndex::__Handle dest2(destinationParent);
            handler->columnsMoved(&src2, sourceStart, sourceEnd, &dest2, destinationColumn);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ColumnsRemoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::columnsRemoved, [handler](const QModelIndex &parent, int first, int last) {
            ModelIndex::__Handle parent2(parent);
            handler->columnsRemoved(&parent2, first, last);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_DataChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::dataChanged, [handler](const QModelIndex &topLeft, const QModelIndex &bottomRight, const QList<int> &roles = QList<int>()) {
            const auto roles2 = fromQList<int,ItemDataRole>(roles, [](auto i) {
                return static_cast<ItemDataRole>(i);
            });
            ModelIndex::__Handle topLeft2(topLeft);
            ModelIndex::__Handle bottomRight2(bottomRight);
            handler->dataChanged(&topLeft2, &bottomRight2, roles2);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_HeaderDataChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::headerDataChanged, [handler](Qt::Orientation orientation, int first, int last) {
            handler->headerDataChanged(static_cast<Orientation>(orientation), first, last);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_LayoutAboutToBeChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::layoutAboutToBeChanged, [handler](const QList<QPersistentModelIndex> &parents, QAbstractItemModel::LayoutChangeHint hint) {
            const auto parents2 = fromQList<QPersistentModelIndex,PersistentModelIndex::HandleRef>(parents, [](auto pmi) {
                return PMODELINDEX(pmi);
            });
            handler->layoutAboutToBeChanged(parents2, static_cast<LayoutChangeHint>(hint));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_LayoutChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::layoutChanged, [handler](const QList<QPersistentModelIndex> &parents, QAbstractItemModel::LayoutChangeHint hint) {
            const auto parents2 = fromQList<QPersistentModelIndex,PersistentModelIndex::HandleRef>(parents, [](auto pmi) {
                return PMODELINDEX(pmi);
            });
            handler->layoutChanged(parents2, static_cast<LayoutChangeHint>(hint));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ModelAboutToBeReset(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::modelAboutToBeReset, [handler] {
            handler->modelAboutToBeReset();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ModelReset(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::modelReset, [handler] {
            handler->modelReset();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_RowsAboutToBeInserted(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::rowsAboutToBeInserted, [handler](const QModelIndex &parent, int start, int end) {
            ModelIndex::__Handle parent2(parent);
            handler->rowsAboutToBeInserted(&parent2, start, end);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_RowsAboutToBeMoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::rowsAboutToBeMoved, [handler](const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationRow) {
            ModelIndex::__Handle src2(sourceParent);
            ModelIndex::__Handle dest2(destinationParent);
            handler->rowsAboutToBeMoved(&src2, sourceStart, sourceEnd, &dest2, destinationRow);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_RowsAboutToBeRemoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::rowsAboutToBeRemoved, [handler](const QModelIndex &parent, int first, int last) {
            ModelIndex::__Handle parent2(parent);
            handler->rowsAboutToBeRemoved(&parent2, first, last);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_RowsInserted(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::rowsInserted, [handler](const QModelIndex &parent, int first, int last) {
            ModelIndex::__Handle parent2(parent);
            handler->rowsInserted(&parent2, first, last);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_RowsMoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::rowsMoved, [handler](const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationRow) {
            ModelIndex::__Handle src2(sourceParent);
            ModelIndex::__Handle dest2(destinationParent);
            handler->rowsMoved(&src2, sourceStart, sourceEnd, &dest2, destinationRow);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_RowsRemoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::rowsRemoved, [handler](const QModelIndex &parent, int first, int last) {
            ModelIndex::__Handle parent2(parent);
            handler->rowsRemoved(&parent2, first, last);
        });
        return new __SignalConnection { connection };
    }

    // subclassing stuff ===============================================================
    class Implementation : public QAbstractItemModel {
    private:
        std::shared_ptr<ImplementationMethods> methodDelegate;
        ImplementationMask methodMask;
    public:
        Implementation(const std::shared_ptr<ImplementationMethods> &methods, ImplementationMask method_mask)
            : methodDelegate(methods), methodMask(method_mask) {}

        // ===== must-implement abstract methods ================================
        [[nodiscard]]
        QModelIndex index(int row, int column, const QModelIndex &parent) const override {
            ModelIndex::__Handle parent2(parent);
            const auto result = methodDelegate->index(row, column, &parent2);
            return result->consume();
        }

        [[nodiscard]]
        QModelIndex parent(const QModelIndex &child) const override {
            ModelIndex::__Handle child2(child);
            const auto result = methodDelegate->parent(&child2);
            return result->consume();
        }

        [[nodiscard]]
        int rowCount(const QModelIndex &parent) const override {
            ModelIndex::__Handle parent2(parent);
            return methodDelegate->rowCount(&parent2);
        }

        [[nodiscard]]
        int columnCount(const QModelIndex &parent) const override {
            ModelIndex::__Handle parent2(parent);
            return methodDelegate->columnCount(&parent2);
        }

        [[nodiscard]]
        QVariant data(const QModelIndex &index, int role) const override {
            ModelIndex::__Handle index2(index);
            const auto result = methodDelegate->data(&index2, role);
            return result->consume();
        }

        // ===== optional methods ==================================================
        [[nodiscard]]
        bool hasChildren(const QModelIndex &parent) const override {
            if (methodMask & HasChildren) {
                ModelIndex::__Handle parent2(parent);
                return methodDelegate->hasChildren(&parent2);
            } else {
                return QAbstractItemModel::hasChildren(parent);
            }
        }

        bool setData(const QModelIndex &index, const QVariant &value, int role) override {
            if (methodMask & SetData) {
                ModelIndex::__Handle index2(index);
                Variant::__Handle value2(value);
                return methodDelegate->setData(&index2, &value2, role);
            } else {
                return QAbstractItemModel::setData(index, value, role);
            }
        }

        [[nodiscard]]
        Qt::ItemFlags flags(const QModelIndex &index) const override {
            auto baseFlags = QAbstractItemModel::flags(index);
            if (methodMask & Flags) {
                ModelIndex::__Handle index2(index);
                const auto result = methodDelegate->getFlags(&index2, ItemFlags(baseFlags));
                return static_cast<Qt::ItemFlags>(result.value);
            } else {
                return baseFlags;
            }
        }

        [[nodiscard]]
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override {
            if (methodMask & HeaderData) {
                const auto variant = methodDelegate->headerData(section, static_cast<Orientation>(orientation), role);
                return variant->consume();
            } else {
                return QAbstractItemModel::headerData(section, orientation, role);
            }
        }

        bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role) override {
            if (methodMask & HeaderData) {
                Variant::__Handle value2(value);
                return methodDelegate->setHeaderData(section, static_cast<Orientation>(orientation), &value2, role);
            } else {
                return QAbstractItemModel::setHeaderData(section, orientation, value, role);
            }
        }

        void sort(int column, Qt::SortOrder order) override {
            if (methodMask & Sort) {
                return methodDelegate->sort(column, static_cast<SortOrder>(order));
            } else {
                return QAbstractItemModel::sort(column, order);
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
        friend void Interior_emitHeaderDataChanged(InteriorRef _this, Orientation orientation, int32_t first, int32_t last);
        friend void Interior_beginInsertRows(InteriorRef _this, ModelIndex::HandleRef parent, int32_t first, int32_t last);
        friend void Interior_endInsertRows(InteriorRef _this);
        friend void Interior_beginRemoveRows(InteriorRef _this, ModelIndex::HandleRef parent, int32_t first, int32_t last);
        friend void Interior_endRemoveRows(InteriorRef _this);
        friend void Interior_beginResetModel(InteriorRef _this);
        friend void Interior_endResetModel(InteriorRef _this);
        friend ModelIndex::OwnedRef Interior_createIndex(InteriorRef _this, int32_t row, int32_t column, size_t ptr);
    };

    void Interior_emitDataChanged(InteriorRef _this, ModelIndex::HandleRef topLeft, ModelIndex::HandleRef bottomRight, const std::vector<ItemDataRole>& roles) {
        QList<int> qRoles;
        for (auto role : roles) {
            qRoles.push_back(static_cast<int>(role));
        }
        SUBCLASSED_THIS->emitDataChanged(topLeft->value, bottomRight->value, qRoles);
    }

    void Interior_emitHeaderDataChanged(InteriorRef _this, Orientation orientation, int32_t first, int32_t last) {
        SUBCLASSED_THIS->emitHeaderDataChanged(static_cast<Qt::Orientation>(orientation), first, last);
    }

    void Interior_beginInsertRows(InteriorRef _this, ModelIndex::HandleRef parent, int32_t first, int32_t last) {
        SUBCLASSED_THIS->beginInsertRows(parent->value, first, last);
    }

    void Interior_endInsertRows(InteriorRef _this) {
        SUBCLASSED_THIS->endInsertRows();
    }

    void Interior_beginRemoveRows(InteriorRef _this, ModelIndex::HandleRef parent, int32_t first, int32_t last) {
        SUBCLASSED_THIS->beginRemoveRows(parent->value, first, last);
    }

    void Interior_endRemoveRows(InteriorRef _this) {
        SUBCLASSED_THIS->endRemoveRows();
    }

    void Interior_beginResetModel(InteriorRef _this) {
        SUBCLASSED_THIS->beginResetModel();
    }

    void Interior_endResetModel(InteriorRef _this) {
        SUBCLASSED_THIS->endResetModel();
    }

    ModelIndex::OwnedRef Interior_createIndex(InteriorRef _this, int32_t row, int32_t column, size_t ptr) {
        const auto raw = SUBCLASSED_THIS->createIndex(row, column, ptr);
        return new ModelIndex::__Owned(raw);
    }

    void Interior_dispose(InteriorRef _this) {
        delete SUBCLASSED_THIS;
    }

    InteriorRef createImplementation(const std::shared_ptr<ImplementationMethods>& methods, ImplementationMask mask) {
        return reinterpret_cast<InteriorRef>(new Implementation(methods, mask));
    }
}
