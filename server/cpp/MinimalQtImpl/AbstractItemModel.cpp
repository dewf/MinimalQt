#include "generated/AbstractItemModel.h"
#include "AbstractItemModelInternal.h"

#include <QModelIndex>

#include "ModelIndexInternal.h"
#include "VariantInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define ABSITEMMODEL_THIS (WRAPPER->getActual())
#define SUBCLASSED_THIS (static_cast<Implementation*>(WRAPPER->getActual()))

namespace AbstractItemModel
{
    ModelIndex::OwnedRef Handle_index(HandleRef _this, int32_t row, int32_t column) {
        const auto value = ABSITEMMODEL_THIS->index(row, column);
        return new ModelIndex::__Owned(value);
    }

    ModelIndex::OwnedRef Handle_index(HandleRef _this, int32_t row, int32_t column, ModelIndex::HandleRef parent) {
        const auto value = ABSITEMMODEL_THIS->index(row, column, parent->value);
        return new ModelIndex::__Owned(value);
    }

    bool Handle_setData(HandleRef _this, ModelIndex::HandleRef index, Variant::HandleRef value) {
        return ABSITEMMODEL_THIS->setData(index->value, value->value);
    }

    bool Handle_setData(HandleRef _this, ModelIndex::HandleRef index, Variant::HandleRef value, ItemDataRole role) {
        const auto qrole = static_cast<Qt::ItemDataRole>(role);
        return ABSITEMMODEL_THIS->setData(index->value, value->value, qrole);
    }

    Variant::OwnedRef Handle_data(HandleRef _this, ModelIndex::HandleRef index) {
        const auto value = ABSITEMMODEL_THIS->data(index->value);
        return new Variant::__Owned(value);
    }

    Variant::OwnedRef Handle_data(HandleRef _this, ModelIndex::HandleRef index, ItemDataRole role) {
        const auto qrole = static_cast<Qt::ItemDataRole>(role);
        const auto value = ABSITEMMODEL_THIS->data(index->value, qrole);
        return new Variant::__Owned(value);
    }

    void Handle_sort(HandleRef _this, int32_t column) {
        ABSITEMMODEL_THIS->sort(column);
    }

    void Handle_sort(HandleRef _this, int32_t column, SortOrder order) {
        auto qorder = static_cast<Qt::SortOrder>(order);
        ABSITEMMODEL_THIS->sort(column, qorder);
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
        QModelIndex index(int row, int column, const QModelIndex &parent) const override {
            ModelIndex::__Handle parent2(parent);
            const auto result = methodDelegate->index(row, column, &parent2);
            return result->consume();
        }

        QModelIndex parent(const QModelIndex &child) const override {
            ModelIndex::__Handle child2(child);
            const auto result = methodDelegate->parent(&child2);
            return result->consume();
        }

        int rowCount(const QModelIndex &parent) const override {
            ModelIndex::__Handle parent2(parent);
            return methodDelegate->rowCount(&parent2);
        }

        int columnCount(const QModelIndex &parent) const override {
            ModelIndex::__Handle parent2(parent);
            return methodDelegate->columnCount(&parent2);
        }

        QVariant data(const QModelIndex &index, int role) const override {
            ModelIndex::__Handle index2(index);
            const auto result = methodDelegate->data(&index2, role);
            return result->consume();
        }

        // ===== optional methods ==================================================
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

        Qt::ItemFlags flags(const QModelIndex &index) const override {
            auto baseFlags = QAbstractItemModel::flags(index);
            if (methodMask & Flags) {
                ModelIndex::__Handle index2(index);
                return static_cast<Qt::ItemFlags>(methodDelegate->getFlags(&index2, baseFlags));
            } else {
                return baseFlags;
            }
        }

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
