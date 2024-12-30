#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nodiscard"

#include "generated/AbstractListModel.h"
#include "VariantInternal.h"
#include "ModelIndexInternal.h"

#include <QAbstractListModel>
#include "util/SignalStuff.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define ABSLISTMODEL_THIS (WRAPPER->getActual())
#define SUBCLASSED_THIS (static_cast<Implementation*>(WRAPPER->getActual()))

#include "AbstractListModelInternal.h"

namespace AbstractListModel
{
    // subclass stuff =========================================================

    class Implementation : public QAbstractListModel {
    private:
        std::shared_ptr<ImplementationMethods> methodDelegate;
        ImplementedMethodMask methodMask;
    public:
        Implementation(const std::shared_ptr<ImplementationMethods> &methodDelegate, ImplementedMethodMask methodMask)
            : methodDelegate(methodDelegate), methodMask(methodMask) {}

        // ==== must-implement abstract methods ===========================
        int rowCount(const QModelIndex &parent) const override {
            return methodDelegate->rowCount((ModelIndex::HandleRef)&parent);
        }

        QVariant data(const QModelIndex &index, int role) const override {
            const auto variant = methodDelegate->data((ModelIndex::HandleRef)&index, (ItemDataRole)role);
            return AS_QVARIANT_PTR(variant)->consume();
        }

        // ==== optional methods ==========================================
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override {
            if (methodMask & HeaderData) {
                const auto variant = methodDelegate->headerData(section, static_cast<Enums::Orientation>(orientation), static_cast<ItemDataRole>(role));
                return AS_QVARIANT_PTR(variant)->consume();
            } else {
                return QAbstractListModel::headerData(section, orientation, role);
            }
        }

        Qt::ItemFlags flags(const QModelIndex &index) const override {
            auto baseFlags = QAbstractListModel::flags(index);
            if (methodMask & Flags) {
                auto raw = (int)methodDelegate->getFlags((ModelIndex::HandleRef)&index, baseFlags);
                return (Qt::ItemFlags) raw;
            } else {
                return baseFlags;
            }
        }

        bool setData(const QModelIndex &index, const QVariant &value, int role) override {
            if (methodMask & SetData) {
                return methodDelegate->setData((ModelIndex::HandleRef)&index, (Variant::HandleRef)&value, (ItemDataRole)role);
            } else {
                return QAbstractListModel::setData(index, value, role);
            }
        }

        int columnCount(const QModelIndex &parent) const override {
            if (methodMask & ColumnCount) {
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
        SUBCLASSED_THIS->emitDataChanged(QMODELINDEX_VALUE(topLeft), QMODELINDEX_VALUE(bottomRight), qRoles);
        // if (const auto delegated = dynamic_cast<Delegated*>(ABSLISTMODEL_THIS); delegated != nullptr) {
        // }
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

    void Interior_setSignalMask(InteriorRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Interior_dispose(InteriorRef _this) {
        delete WRAPPER;
    }

    InteriorRef createImplementation(const std::shared_ptr<SignalHandler>& handler, const std::shared_ptr<ImplementationMethods>& methods, ImplementedMethodMask mask) {
        const auto model = new Implementation(methods, mask);
        const auto wrapper = new SignalWrapper(model, handler);
        return reinterpret_cast<InteriorRef>(wrapper);
    }
}
#pragma clang diagnostic pop
