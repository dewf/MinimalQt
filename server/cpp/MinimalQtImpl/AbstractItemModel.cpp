#include "generated/AbstractItemModel.h"
#include "AbstractItemModelInternal.h"

#include <QModelIndex>

#include "MimeDataInternal.h"
#include "ModelIndexInternal.h"
#include "VariantInternal.h"
#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define ABSITEMMODEL_THIS (WRAPPER->getActual())
#define SUBCLASSED_THIS (dynamic_cast<Implementation*>(WRAPPER->getActual()))

namespace AbstractItemModel
{
    ModelIndex::OwnedRef Handle_buddy(HandleRef _this, ModelIndex::HandleRef index) {
        return new ModelIndex::__Owned { ABSITEMMODEL_THIS->buddy(index->value) };
    }

    bool Handle_canDropMimeData(HandleRef _this, MimeData::HandleRef data, DropAction action, int32_t row, int32_t column, ModelIndex::HandleRef parent) {
        return ABSITEMMODEL_THIS->canDropMimeData(AS_QMIMEDATA_PTR(data), static_cast<Qt::DropAction>(action), row, column, parent->value);
    }

    bool Handle_canFetchMore(HandleRef _this, ModelIndex::HandleRef parent) {
        return ABSITEMMODEL_THIS->canFetchMore(parent->value);
    }

    bool Handle_checkIndex(HandleRef _this, ModelIndex::HandleRef index, const std::optional<CheckIndexOptions>& options_) {
        CheckIndexOptions optionsArg = options_.value_or(NoOption);
        return ABSITEMMODEL_THIS->checkIndex(index->value, static_cast<QAbstractItemModel::CheckIndexOption>(optionsArg));
    }

    bool Handle_clearItemData(HandleRef _this, ModelIndex::HandleRef index) {
        return ABSITEMMODEL_THIS->clearItemData(index->value);
    }

    int32_t Handle_columnCount(HandleRef _this, const std::optional<ModelIndex::HandleRef>& parent) {
        return ABSITEMMODEL_THIS->columnCount(fromOptionalIndex(parent));
    }

    Variant::OwnedRef Handle_data(HandleRef _this, ModelIndex::HandleRef index, const std::optional<int32_t>& role) {
        return new Variant::__Owned { ABSITEMMODEL_THIS->data(index->value, role.value_or(Qt::DisplayRole))};
    }

    bool Handle_dropMimeData(HandleRef _this, MimeData::HandleRef data, DropAction action, int32_t row, int32_t column, ModelIndex::HandleRef parent) {
        return ABSITEMMODEL_THIS->dropMimeData(AS_QMIMEDATA_PTR(data), static_cast<Qt::DropAction>(action), row, column, parent->value);
    }

    void Handle_fetchMore(HandleRef _this, ModelIndex::HandleRef parent) {
        ABSITEMMODEL_THIS->fetchMore(parent->value);
    }

    ItemFlags Handle_flags_(HandleRef _this, ModelIndex::HandleRef index) {
        return ABSITEMMODEL_THIS->flags(index->value);
    }

    bool Handle_hasChildren(HandleRef _this, const std::optional<ModelIndex::HandleRef>& parent) {
        return ABSITEMMODEL_THIS->hasChildren(fromOptionalIndex(parent));
    }

    bool Handle_hasIndex(HandleRef _this, int32_t row, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return ABSITEMMODEL_THIS->hasIndex(row, column, fromOptionalIndex(parent));
    }

    Variant::OwnedRef Handle_headerData(HandleRef _this, int32_t section, Orientation orientation, const std::optional<int32_t>& role) {
        return new Variant::__Owned { ABSITEMMODEL_THIS->headerData(section, static_cast<Qt::Orientation>(orientation), role.value_or(Qt::DisplayRole)) };
    }

    ModelIndex::OwnedRef Handle_index(HandleRef _this, int32_t row, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return new ModelIndex::__Owned { ABSITEMMODEL_THIS->index(row, column, fromOptionalIndex(parent)) };
    }

    bool Handle_insertColumn(HandleRef _this, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return ABSITEMMODEL_THIS->insertColumn(column, fromOptionalIndex(parent));
    }

    bool Handle_insertColumns(HandleRef _this, int32_t column, int32_t count, const std::optional<ModelIndex::HandleRef>& parent) {
        return ABSITEMMODEL_THIS->insertColumns(column, count, fromOptionalIndex(parent));
    }

    bool Handle_insertRow(HandleRef _this, int32_t row, const std::optional<ModelIndex::HandleRef>& parent) {
        return ABSITEMMODEL_THIS->insertRow(row, fromOptionalIndex(parent));
    }

    bool Handle_insertRows(HandleRef _this, int32_t row, int32_t count, const std::optional<ModelIndex::HandleRef>& parent) {
        return ABSITEMMODEL_THIS->insertRows(row, count, fromOptionalIndex(parent));
    }

    std::map<int32_t,Variant::OwnedRef> Handle_itemData(HandleRef _this, ModelIndex::HandleRef index) {
        const auto result = ABSITEMMODEL_THIS->itemData(index->value);
        std::map<int32_t, Variant::OwnedRef> retMap;
        for (auto i = result.cbegin(), end = result.cend(); i != end; ++i) {
            retMap[i.key()] = new Variant::__Owned { i.value() };
        }
        return retMap;
    }

    std::vector<ModelIndex::OwnedRef> Handle_match(HandleRef _this, ModelIndex::HandleRef start, int32_t role, Variant::HandleRef value, const Handle::MatchArgs& args) {
        std::vector<ModelIndex::OwnedRef> ret;
        const auto hits = args.getOrDefaultHits(1);
        const auto flags_ = args.getOrDefaultFlags_(MatchStartsWith | MatchWrap);
        const auto result = ABSITEMMODEL_THIS->match(start->value, role, value->value, hits, static_cast<Qt::MatchFlags>(flags_));
        return fromQList<QModelIndex,ModelIndex::OwnedRef>(result, [](const QModelIndex &index) { return new ModelIndex::__Owned(index); });
    }

    MimeData::HandleRef Handle_getMimeData(HandleRef _this, const std::vector<ModelIndex::HandleRef>& indexes) {
        const auto qIndexes = toQList<ModelIndex::HandleRef,QModelIndex>(indexes, [](const ModelIndex::HandleRef& ref) { return ref->value; });
        return reinterpret_cast<MimeData::HandleRef>(ABSITEMMODEL_THIS->mimeData(qIndexes));
    }

    std::vector<std::string> Handle_mimeTypes(HandleRef _this) {
        return toVectorStrings(ABSITEMMODEL_THIS->mimeTypes());
    }

    bool Handle_moveColumn(HandleRef _this, ModelIndex::HandleRef sourceParent, int32_t sourceColumn, ModelIndex::HandleRef destinationParent, int32_t destinationChild) {
        return ABSITEMMODEL_THIS->moveColumn(sourceParent->value, sourceColumn, destinationParent->value, destinationChild);
    }

    bool Handle_moveColumns(HandleRef _this, ModelIndex::HandleRef sourceParent, int32_t sourceColumn, int32_t count, ModelIndex::HandleRef destinationParent, int32_t destinationChild) {
        return ABSITEMMODEL_THIS->moveColumns(sourceParent->value, sourceColumn, count, destinationParent->value, destinationChild);
    }

    bool Handle_moveRow(HandleRef _this, ModelIndex::HandleRef sourceParent, int32_t sourceRow, ModelIndex::HandleRef destinationParent, int32_t destinationChild) {
        return ABSITEMMODEL_THIS->moveRow(sourceParent->value, sourceRow, destinationParent->value, destinationChild);
    }

    bool Handle_moveRows(HandleRef _this, ModelIndex::HandleRef sourceParent, int32_t sourceRow, int32_t count, ModelIndex::HandleRef destinationParent, int32_t destinationChild) {
        return ABSITEMMODEL_THIS->moveRows(sourceParent->value, sourceRow, count, destinationParent->value, destinationChild);
    }

    ModelIndex::OwnedRef Handle_parent(HandleRef _this, ModelIndex::HandleRef index) {
        return new ModelIndex::__Owned { ABSITEMMODEL_THIS->parent(index->value) };
    }

    bool Handle_removeColumn(HandleRef _this, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return ABSITEMMODEL_THIS->removeColumn(column, fromOptionalIndex(parent));
    }

    bool Handle_removeColumns(HandleRef _this, int32_t column, int32_t count, const std::optional<ModelIndex::HandleRef>& parent) {
        return ABSITEMMODEL_THIS->removeColumns(column, count, fromOptionalIndex(parent));
    }

    bool Handle_removeRow(HandleRef _this, int32_t row, const std::optional<ModelIndex::HandleRef>& parent) {
        return ABSITEMMODEL_THIS->removeRow(row, fromOptionalIndex(parent));
    }

    bool Handle_removeRows(HandleRef _this, int32_t row, int32_t count, const std::optional<ModelIndex::HandleRef>& parent) {
        return ABSITEMMODEL_THIS->removeRows(row, count, fromOptionalIndex(parent));
    }

    int32_t Handle_rowCount(HandleRef _this, const std::optional<ModelIndex::HandleRef>& parent) {
        return ABSITEMMODEL_THIS->rowCount(fromOptionalIndex(parent));
    }

    bool Handle_setData(HandleRef _this, ModelIndex::HandleRef index, Variant::HandleRef value, const std::optional<int32_t>& role) {
        return ABSITEMMODEL_THIS->setData(index->value, value->value, role.value_or(Qt::EditRole));
    }

    bool Handle_setHeaderData(HandleRef _this, int32_t section, Orientation orientation, Variant::HandleRef value, const std::optional<int32_t>& role) {
        return ABSITEMMODEL_THIS->setHeaderData(section, static_cast<Qt::Orientation>(orientation), value->value, role.value_or(Qt::EditRole));
    }

    bool Handle_setItemData(HandleRef _this, ModelIndex::HandleRef index, std::map<int32_t,Variant::HandleRef> roles) {
        const QMap<int, QVariant> qRoles;
        for (auto i = roles.begin(); i != roles.end(); ++i) {
            qRoles[i->first] = i->second->value;
        }
        return ABSITEMMODEL_THIS->setItemData(index->value, qRoles);
    }

    ModelIndex::OwnedRef Handle_sibling(HandleRef _this, int32_t row, int32_t column, ModelIndex::HandleRef index) {
        return new ModelIndex::__Owned { ABSITEMMODEL_THIS->sibling(row, column, index->value) };
    }

    void Handle_sort(HandleRef _this, int32_t column, const std::optional<SortOrder>& order) {
        const auto order2 = order.value_or(SortOrder::AscendingOrder);
        ABSITEMMODEL_THIS->sort(column, static_cast<Qt::SortOrder>(order2));
    }

    Size Handle_span(HandleRef _this, ModelIndex::HandleRef index) {
        return toSize(ABSITEMMODEL_THIS->span(index->value));
    }

    DropActionSet Handle_supportedDragActions(HandleRef _this) {
        return ABSITEMMODEL_THIS->supportedDragActions();
    }

    DropActionSet Handle_supportedDropActions(HandleRef _this) {
        return ABSITEMMODEL_THIS->supportedDropActions();
    }

    void Handle_revert(HandleRef _this) {
        ABSITEMMODEL_THIS->revert();
    }

    void Handle_submit(HandleRef _this) {
        ABSITEMMODEL_THIS->submit();
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
                return static_cast<Qt::ItemFlags>(methodDelegate->getFlags(&index2, baseFlags));
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

    void Interior_setSignalMask(InteriorRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Interior_dispose(InteriorRef _this) {
        delete WRAPPER;
    }

    InteriorRef createImplementation(const std::shared_ptr<SignalHandler>& handler, const std::shared_ptr<ImplementationMethods>& methods, ImplementationMask mask) {
        const auto model = new Implementation(methods, mask);
        const auto wrapper = new SignalWrapper(model, handler);
        return reinterpret_cast<InteriorRef>(wrapper);
    }
}
