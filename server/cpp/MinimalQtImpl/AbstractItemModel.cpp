#include "generated/AbstractItemModel.h"
#include "AbstractItemModelInternal.h"

#include "ObjectInternal.h"
#include "MimeDataInternal.h"
#include "ModelIndexInternal.h"
#include "PersistentModelIndexInternal.h"
#include "VariantInternal.h"
#include "SafeReturnInternal.h"
#include "SizeInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Size;
using namespace ::Enums;
using namespace ::ModelIndex;
using namespace ::PersistentModelIndex;
using namespace ::Variant;
using namespace ::MimeData;
using namespace ::SafeReturn;

#define THIS (reinterpret_cast<QAbstractItemModel*>(_this))
#define SUBCLASSED_THIS (reinterpret_cast<Implementation*>(_this))

// TODO: replace with new macros
#define PMODELINDEX(x) ((PersistentModelIndex::HandleRef)&x)

namespace AbstractItemModel
{
    // ConstHandle methods ======================================================
    ModelIndex::OwnedRef ConstHandle_buddy(ConstHandleRef _this, ModelIndex::HandleRef index) {
        return MODELINDEX_HEAP_NEW(THIS->buddy(QMODELINDEX_VALUE(index)));
    }

    bool ConstHandle_canDropMimeData(ConstHandleRef _this, MimeData::HandleRef data, DropAction action, int32_t row, int32_t column, ModelIndex::HandleRef parent) {
        return THIS->canDropMimeData(AS_QMIMEDATA_PTR(data), static_cast<Qt::DropAction>(action), row, column, QMODELINDEX_VALUE(parent));
    }

    bool ConstHandle_canFetchMore(ConstHandleRef _this, ModelIndex::HandleRef parent) {
        return THIS->canFetchMore(QMODELINDEX_VALUE(parent));
    }

    bool ConstHandle_checkIndex(ConstHandleRef _this, ModelIndex::HandleRef index, Flags<CheckIndexOptions> options_ /* CheckIndexOptions::NoOption */) {
        return THIS->checkIndex(QMODELINDEX_VALUE(index), static_cast<QAbstractItemModel::CheckIndexOptions>(options_.value()));
    }

    int32_t ConstHandle_columnCount(ConstHandleRef _this, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->columnCount(fromOptionalIndex(parent));
    }

    Variant::OwnedRef ConstHandle_data(ConstHandleRef _this, ModelIndex::HandleRef index, const std::optional<int32_t>& role) {
        return VARIANT_HEAP_NEW(THIS->data(QMODELINDEX_VALUE(index), role.value_or(Qt::DisplayRole)));
    }

    Flags<ItemFlags> ConstHandle_flags_(ConstHandleRef _this, ModelIndex::HandleRef index) {
        return static_cast<Flags<ItemFlags>>(THIS->flags(QMODELINDEX_VALUE(index)));
    }

    bool ConstHandle_hasChildren(ConstHandleRef _this, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->hasChildren(fromOptionalIndex(parent));
    }

    bool ConstHandle_hasIndex(ConstHandleRef _this, int32_t row, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->hasIndex(row, column, fromOptionalIndex(parent));
    }

    Variant::OwnedRef ConstHandle_headerData(ConstHandleRef _this, int32_t section, Orientation orientation, const std::optional<int32_t>& role) {
        return VARIANT_HEAP_NEW(THIS->headerData(section, static_cast<Qt::Orientation>(orientation), role.value_or(Qt::DisplayRole)));
    }

    ModelIndex::OwnedRef ConstHandle_index(ConstHandleRef _this, int32_t row, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return MODELINDEX_HEAP_NEW(THIS->index(row, column, fromOptionalIndex(parent)));
    }

    std::map<int32_t,Variant::OwnedRef> ConstHandle_itemData(ConstHandleRef _this, ModelIndex::HandleRef index) {
        const auto result = THIS->itemData(QMODELINDEX_VALUE(index));
        std::map<int32_t, Variant::OwnedRef> retMap;
        for (auto i = result.cbegin(), end = result.cend(); i != end; ++i) {
            retMap[i.key()] = VARIANT_HEAP_NEW(i.value());
        }
        return retMap;
    }

    std::vector<ModelIndex::OwnedRef> ConstHandle_match(ConstHandleRef _this, ModelIndex::HandleRef start, int32_t role, Variant::HandleRef value, int32_t hits /* 1 */, Flags<MatchFlags> flags_ /* MatchFlags::MatchStartsWith | MatchFlags::MatchWrap */) {
        std::vector<ModelIndex::OwnedRef> ret;
        const auto result = THIS->match(QMODELINDEX_VALUE(start), role, QVARIANT_VALUE(value), hits, static_cast<Qt::MatchFlags>(flags_.value()));
        return fromQList<QModelIndex,ModelIndex::OwnedRef>(result, [](const QModelIndex &index) { return MODELINDEX_HEAP_NEW(index); });
    }

    MimeData::HandleRef ConstHandle_getMimeData(ConstHandleRef _this, const std::vector<ModelIndex::HandleRef>& indexes) {
        const auto qIndexes = toQList<ModelIndex::HandleRef,QModelIndex>(indexes, [](const ModelIndex::HandleRef& ref) { return QMODELINDEX_VALUE(ref); });
        return reinterpret_cast<MimeData::HandleRef>(THIS->mimeData(qIndexes));
    }

    std::vector<std::string> ConstHandle_mimeTypes(ConstHandleRef _this) {
        return toVectorStrings(THIS->mimeTypes());
    }

    ModelIndex::OwnedRef ConstHandle_parent(ConstHandleRef _this, ModelIndex::HandleRef index) {
        return MODELINDEX_HEAP_NEW(THIS->parent(QMODELINDEX_VALUE(index)));
    }

    int32_t ConstHandle_rowCount(ConstHandleRef _this, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->rowCount(fromOptionalIndex(parent));
    }

    ModelIndex::OwnedRef ConstHandle_sibling(ConstHandleRef _this, int32_t row, int32_t column, ModelIndex::HandleRef index) {
        return MODELINDEX_HEAP_NEW(THIS->sibling(row, column, QMODELINDEX_VALUE(index)));
    }

    Size::OwnedRef ConstHandle_span(ConstHandleRef _this, ModelIndex::HandleRef index) {
        return SIZE_HEAP_NEW(THIS->span(QMODELINDEX_VALUE(index)));
    }

    Flags<DropActions> ConstHandle_supportedDragActions(ConstHandleRef _this) {
        return static_cast<Flags<DropActions>>(THIS->supportedDragActions());
    }

    Flags<DropActions> ConstHandle_supportedDropActions(ConstHandleRef _this) {
        return static_cast<Flags<DropActions>>(THIS->supportedDropActions());
    }

    SignalConnectionRef ConstHandle_connect_ColumnsAboutToBeInserted(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::columnsAboutToBeInserted, [handler](const QModelIndex &parent, int first, int last) {
            // here and below in other signals, just copy to prevent any modifications to the const QModelIndexes
            QModelIndex parent2(parent);
            handler->columnsAboutToBeInserted(reinterpret_cast<ModelIndex::HandleRef>(&parent2), first, last);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_ColumnsAboutToBeMoved(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::columnsAboutToBeMoved, [handler](const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationColumn) {
            QModelIndex src2(sourceParent);
            QModelIndex dest2(destinationParent);
            handler->columnsAboutToBeMoved(reinterpret_cast<ModelIndex::HandleRef>(&src2), sourceStart, sourceEnd, reinterpret_cast<ModelIndex::HandleRef>(&dest2), destinationColumn);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_ColumnsAboutToBeRemoved(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::columnsAboutToBeRemoved, [handler](const QModelIndex &parent, int first, int last) {
            QModelIndex parent2(parent);
            handler->columnsAboutToBeRemoved(reinterpret_cast<ModelIndex::HandleRef>(&parent2), first, last);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_ColumnsInserted(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::columnsInserted, [handler](const QModelIndex &parent, int first, int last) {
            QModelIndex parent2(parent);
            handler->columnsInserted(reinterpret_cast<ModelIndex::HandleRef>(&parent2), first, last);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_ColumnsMoved(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::columnsMoved, [handler](const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationColumn) {
            QModelIndex src2(sourceParent);
            QModelIndex dest2(destinationParent);
            handler->columnsMoved(reinterpret_cast<ModelIndex::HandleRef>(&src2), sourceStart, sourceEnd, reinterpret_cast<ModelIndex::HandleRef>(&dest2), destinationColumn);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_ColumnsRemoved(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::columnsRemoved, [handler](const QModelIndex &parent, int first, int last) {
            QModelIndex parent2(parent);
            handler->columnsRemoved(reinterpret_cast<ModelIndex::HandleRef>(&parent2), first, last);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_DataChanged(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::dataChanged, [handler](const QModelIndex &topLeft, const QModelIndex &bottomRight, const QList<int> &roles = QList<int>()) {
            const auto roles2 = fromQList<int,ItemDataRole>(roles, [](auto i) {
                return static_cast<ItemDataRole>(i);
            });
            QModelIndex topLeft2(topLeft);
            QModelIndex bottomRight2(bottomRight);
            handler->dataChanged(reinterpret_cast<ModelIndex::HandleRef>(&topLeft2), reinterpret_cast<ModelIndex::HandleRef>(&bottomRight2), roles2);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_HeaderDataChanged(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::headerDataChanged, [handler](Qt::Orientation orientation, int first, int last) {
            handler->headerDataChanged(static_cast<Orientation>(orientation), first, last);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_LayoutAboutToBeChanged(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::layoutAboutToBeChanged, [handler](const QList<QPersistentModelIndex> &parents, QAbstractItemModel::LayoutChangeHint hint) {
            // as of now, our PMI List wrapper is immutable, so just forcibly cast:
            const auto parents2 = (PersistentModelIndex::ListRef)&parents;
            handler->layoutAboutToBeChanged(parents2, static_cast<LayoutChangeHint>(hint));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_LayoutChanged(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::layoutChanged, [handler](const QList<QPersistentModelIndex> &parents, QAbstractItemModel::LayoutChangeHint hint) {
            // as of now, our PMI List wrapper is immutable, so just forcibly cast:
            const auto parents2 = (PersistentModelIndex::ListRef)&parents;
            handler->layoutChanged(parents2, static_cast<LayoutChangeHint>(hint));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_ModelAboutToBeReset(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::modelAboutToBeReset, [handler] {
            handler->modelAboutToBeReset();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_ModelReset(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::modelReset, [handler] {
            handler->modelReset();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_RowsAboutToBeInserted(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::rowsAboutToBeInserted, [handler](const QModelIndex &parent, int start, int end) {
            QModelIndex parent2(parent);
            handler->rowsAboutToBeInserted(reinterpret_cast<ModelIndex::HandleRef>(&parent2), start, end);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_RowsAboutToBeMoved(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::rowsAboutToBeMoved, [handler](const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationRow) {
            QModelIndex src2(sourceParent);
            QModelIndex dest2(destinationParent);
            handler->rowsAboutToBeMoved(reinterpret_cast<ModelIndex::HandleRef>(&src2), sourceStart, sourceEnd, reinterpret_cast<ModelIndex::HandleRef>(&dest2), destinationRow);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_RowsAboutToBeRemoved(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::rowsAboutToBeRemoved, [handler](const QModelIndex &parent, int first, int last) {
            QModelIndex parent2(parent);
            handler->rowsAboutToBeRemoved(reinterpret_cast<ModelIndex::HandleRef>(&parent2), first, last);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_RowsInserted(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::rowsInserted, [handler](const QModelIndex &parent, int first, int last) {
            QModelIndex parent2(parent);
            handler->rowsInserted(reinterpret_cast<ModelIndex::HandleRef>(&parent2), first, last);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_RowsMoved(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::rowsMoved, [handler](const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationRow) {
            QModelIndex src2(sourceParent);
            QModelIndex dest2(destinationParent);
            handler->rowsMoved(reinterpret_cast<ModelIndex::HandleRef>(&src2), sourceStart, sourceEnd, reinterpret_cast<ModelIndex::HandleRef>(&dest2), destinationRow);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef ConstHandle_connect_RowsRemoved(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemModel::rowsRemoved, [handler](const QModelIndex &parent, int first, int last) {
            QModelIndex parent2(parent);
            handler->rowsRemoved(reinterpret_cast<ModelIndex::HandleRef>(&parent2), first, last);
        });
        return new __SignalConnection { connection };
    }

    // normal Handle methods ====================================================
    bool Handle_clearItemData(HandleRef _this, ModelIndex::HandleRef index) {
        return THIS->clearItemData(QMODELINDEX_VALUE(index));
    }

    bool Handle_dropMimeData(HandleRef _this, MimeData::HandleRef data, DropAction action, int32_t row, int32_t column, ModelIndex::HandleRef parent) {
        return THIS->dropMimeData(AS_QMIMEDATA_PTR(data), static_cast<Qt::DropAction>(action), row, column, QMODELINDEX_VALUE(parent));
    }

    void Handle_fetchMore(HandleRef _this, ModelIndex::HandleRef parent) {
        THIS->fetchMore(QMODELINDEX_VALUE(parent));
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

    bool Handle_moveColumn(HandleRef _this, ModelIndex::HandleRef sourceParent, int32_t sourceColumn, ModelIndex::HandleRef destinationParent, int32_t destinationChild) {
        return THIS->moveColumn(QMODELINDEX_VALUE(sourceParent), sourceColumn, QMODELINDEX_VALUE(destinationParent), destinationChild);
    }

    bool Handle_moveColumns(HandleRef _this, ModelIndex::HandleRef sourceParent, int32_t sourceColumn, int32_t count, ModelIndex::HandleRef destinationParent, int32_t destinationChild) {
        return THIS->moveColumns(QMODELINDEX_VALUE(sourceParent), sourceColumn, count, QMODELINDEX_VALUE(destinationParent), destinationChild);
    }

    bool Handle_moveRow(HandleRef _this, ModelIndex::HandleRef sourceParent, int32_t sourceRow, ModelIndex::HandleRef destinationParent, int32_t destinationChild) {
        return THIS->moveRow(QMODELINDEX_VALUE(sourceParent), sourceRow, QMODELINDEX_VALUE(destinationParent), destinationChild);
    }

    bool Handle_moveRows(HandleRef _this, ModelIndex::HandleRef sourceParent, int32_t sourceRow, int32_t count, ModelIndex::HandleRef destinationParent, int32_t destinationChild) {
        return THIS->moveRows(QMODELINDEX_VALUE(sourceParent), sourceRow, count, QMODELINDEX_VALUE(destinationParent), destinationChild);
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

    bool Handle_setData(HandleRef _this, ModelIndex::HandleRef index, Variant::HandleRef value, const std::optional<int32_t>& role) {
        return THIS->setData(QMODELINDEX_VALUE(index), QVARIANT_VALUE(value), role.value_or(Qt::EditRole));
    }

    bool Handle_setHeaderData(HandleRef _this, int32_t section, Orientation orientation, Variant::HandleRef value, const std::optional<int32_t>& role) {
        return THIS->setHeaderData(section, static_cast<Qt::Orientation>(orientation), QVARIANT_VALUE(value), role.value_or(Qt::EditRole));
    }

    bool Handle_setItemData(HandleRef _this, ModelIndex::HandleRef index, const std::map<int32_t,Variant::HandleRef>& roles) {
        const QMap<int, QVariant> qRoles;
        for (auto i = roles.begin(); i != roles.end(); ++i) {
            qRoles[i->first] = QVARIANT_VALUE(i->second);
        }
        return THIS->setItemData(QMODELINDEX_VALUE(index), qRoles);
    }

    void Handle_sort(HandleRef _this, int32_t column, const std::optional<SortOrder>& order) {
        const auto order2 = order.value_or(SortOrder::AscendingOrder);
        THIS->sort(column, static_cast<Qt::SortOrder>(order2));
    }

    void Handle_revert(HandleRef _this) {
        THIS->revert();
    }

    void Handle_submit(HandleRef _this) {
        THIS->submit();
    }

    // subclassing stuff ===============================================================
    class Implementation : public QAbstractItemModel {
    private:
        std::shared_ptr<ImplementationMethods> methodDelegate;
        Flags<ImplementationMask> methodMask;
    public:
        Implementation(const std::shared_ptr<ImplementationMethods> &methods, Flags<ImplementationMask> methodMask)
            : methodDelegate(methods), methodMask(methodMask) {}

        // ===== must-implement abstract methods ================================
        [[nodiscard]]
        QModelIndex index(int row, int column, const QModelIndex &parent) const override {
            QModelIndex parent2(parent);
            __ModelIndexReturn safeRet;
            methodDelegate->index(row, column, reinterpret_cast<ModelIndex::HandleRef>(&parent2), &safeRet);
            return safeRet.result;
        }

        [[nodiscard]]
        QModelIndex parent(const QModelIndex &child) const override {
            QModelIndex child2(child);
            __ModelIndexReturn safeRet;
            methodDelegate->parent(reinterpret_cast<ModelIndex::HandleRef>(&child2), &safeRet);
            return safeRet.result;
        }

        [[nodiscard]]
        int rowCount(const QModelIndex &parent) const override {
            QModelIndex parent2(parent);
            return methodDelegate->rowCount(reinterpret_cast<ModelIndex::HandleRef>(&parent2));
        }

        [[nodiscard]]
        int columnCount(const QModelIndex &parent) const override {
            QModelIndex parent2(parent);
            return methodDelegate->columnCount(reinterpret_cast<ModelIndex::HandleRef>(&parent2));
        }

        [[nodiscard]]
        QVariant data(const QModelIndex &index, int role) const override {
            QModelIndex index2(index);
            __VariantReturn safeRet;
            methodDelegate->data(reinterpret_cast<ModelIndex::HandleRef>(&index2), role, &safeRet);
            return safeRet.result;
        }

        // ===== optional methods ==================================================
        [[nodiscard]]
        bool hasChildren(const QModelIndex &parent) const override {
            if (methodMask & ImplementationMask::HasChildren) {
                QModelIndex parent2(parent);
                return methodDelegate->hasChildren(reinterpret_cast<ModelIndex::HandleRef>(&parent2));
            } else {
                return QAbstractItemModel::hasChildren(parent);
            }
        }

        bool setData(const QModelIndex &index, const QVariant &value, int role) override {
            if (methodMask & ImplementationMask::SetData) {
                QModelIndex index2(index);
                QVariant value2(value); // non-const, until we figure out "proxies" or whatever
                return methodDelegate->setData(reinterpret_cast<ModelIndex::HandleRef>(&index2), reinterpret_cast<Variant::HandleRef>(&value2), role);
            } else {
                return QAbstractItemModel::setData(index, value, role);
            }
        }

        [[nodiscard]]
        Qt::ItemFlags flags(const QModelIndex &index) const override {
            auto baseFlags = QAbstractItemModel::flags(index);
            if (methodMask & ImplementationMask::Flags) {
                QModelIndex index2(index);
                const auto result = methodDelegate->getFlags(reinterpret_cast<ModelIndex::HandleRef>(&index2), static_cast<Flags<ItemFlags>>(baseFlags)); // ItemFlags(baseFlags)
                return static_cast<Qt::ItemFlags>(result.value());
            } else {
                return baseFlags;
            }
        }

        [[nodiscard]]
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override {
            if (methodMask & ImplementationMask::HeaderData) {
                __VariantReturn safeRet;
                methodDelegate->headerData(section, static_cast<Orientation>(orientation), role, &safeRet);
                return safeRet.result;
            } else {
                return QAbstractItemModel::headerData(section, orientation, role);
            }
        }

        bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role) override {
            if (methodMask & ImplementationMask::HeaderData) {
                QVariant value2(value); // non-const, until we figure out "proxies" or whatever
                return methodDelegate->setHeaderData(section, static_cast<Orientation>(orientation), reinterpret_cast<Variant::HandleRef>(&value2), role);
            } else {
                return QAbstractItemModel::setHeaderData(section, orientation, value, role);
            }
        }

        void sort(int column, Qt::SortOrder order) override {
            if (methodMask & ImplementationMask::Sort) {
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
        SUBCLASSED_THIS->emitDataChanged(QMODELINDEX_VALUE(topLeft), QMODELINDEX_VALUE(bottomRight), qRoles);
    }

    void Interior_emitHeaderDataChanged(InteriorRef _this, Orientation orientation, int32_t first, int32_t last) {
        SUBCLASSED_THIS->emitHeaderDataChanged(static_cast<Qt::Orientation>(orientation), first, last);
    }

    void Interior_beginInsertRows(InteriorRef _this, ModelIndex::HandleRef parent, int32_t first, int32_t last) {
        SUBCLASSED_THIS->beginInsertRows(QMODELINDEX_VALUE(parent), first, last);
    }

    void Interior_endInsertRows(InteriorRef _this) {
        SUBCLASSED_THIS->endInsertRows();
    }

    void Interior_beginRemoveRows(InteriorRef _this, ModelIndex::HandleRef parent, int32_t first, int32_t last) {
        SUBCLASSED_THIS->beginRemoveRows(QMODELINDEX_VALUE(parent), first, last);
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
        return MODELINDEX_HEAP_NEW(SUBCLASSED_THIS->createIndex(row, column, ptr));
    }

    void Interior_dispose(InteriorRef _this) {
        delete SUBCLASSED_THIS;
    }

    InteriorRef createImplementation(const std::shared_ptr<ImplementationMethods>& methods, Flags<ImplementationMask> mask) {
        return reinterpret_cast<InteriorRef>(new Implementation(methods, mask));
    }

    // ext methods block for: ModelIndex::HandleRef ====
    ConstHandleRef ext__ModelIndex_Handle_model(ModelIndex::HandleRef _this) {
        const auto result = const_cast<QAbstractItemModel*>(AS_QMODELINDEX_PTR(_this)->model());
        return reinterpret_cast<ConstHandleRef>(result);
    }
    // ==============================

    // ext methods block for: PersistentModelIndex::HandleRef ====
    ConstHandleRef ext__PersistentModelIndex_Handle_model(PersistentModelIndex::HandleRef _this) {
        const auto result = const_cast<QAbstractItemModel*>(AS_QPERSISTENTMODELINDEX_PTR(_this)->model());
        return reinterpret_cast<ConstHandleRef>(result);
    }
    // ==============================
}
