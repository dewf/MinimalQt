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
            ModelIndex::__Handle parent2(parent);
            return methodDelegate->rowCount(&parent2);
        }

        QVariant data(const QModelIndex &index, int role) const override {
            ModelIndex::__Handle index2(index);
            const auto variant = methodDelegate->data(&index2, static_cast<ItemDataRole>(role));
            return variant->consume();
        }

        // ==== optional methods ==========================================
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override {
            if (methodMask & HeaderData) {
                const auto variant = methodDelegate->headerData(section, static_cast<Orientation>(orientation), static_cast<ItemDataRole>(role));
                return variant->consume();
            } else {
                return QAbstractListModel::headerData(section, orientation, role);
            }
        }

        Qt::ItemFlags flags(const QModelIndex &index) const override {
            auto baseFlags = QAbstractListModel::flags(index);
            if (methodMask & Flags) {
                ModelIndex::__Handle index2(index);
                return static_cast<Qt::ItemFlags>(methodDelegate->getFlags(&index2, baseFlags));
            } else {
                return baseFlags;
            }
        }

        bool setData(const QModelIndex &index, const QVariant &value, int role) override {
            if (methodMask & SetData) {
                ModelIndex::__Handle index2(index);
                Variant::__Handle value2(value);
                return methodDelegate->setData(&index2, &value2, static_cast<ItemDataRole>(role));
            } else {
                return QAbstractListModel::setData(index, value, role);
            }
        }

        int columnCount(const QModelIndex &parent) const override {
            if (methodMask & ColumnCount) {
                ModelIndex::__Handle parent2(parent);
                return methodDelegate->columnCount(&parent2);
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
