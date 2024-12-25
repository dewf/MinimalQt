#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nodiscard"

#include "generated/AbstractListModel.h"
#include "VariantInternal.h"
#include "ModelIndexInternal.h"

#include <QAbstractListModel>
#include "util/SignalStuff.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define ABSLISTMODEL_THIS (WRAPPER->getActual())

#include "AbstractListModelInternal.h"

namespace AbstractListModel
{
    // class AbstractListModelWithHandler : public QAbstractListModel {
    //     Q_OBJECT
    // private:
    //     SignalRelay signalManager;
    // public:
    //     explicit AbstractListModelWithHandler(const std::shared_ptr<SignalHandler>& handler) : signalManager(this, handler) {}
    //     void setSignalMask(SignalMask newMask) {
    //         signalManager.setSignalMask(newMask);
    //     }
    // };
    //
    // void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
    //     THIS->setSignalMask(mask);
    // }
    //
    // void Handle_dispose(HandleRef _this) {
    //     printf("AbstractListModel::Handle_dispose() called (vs. subclass dispose) ... honoring for now, but this might be a bug\n");
    //     delete THIS;
    // }

    // subclass stuff =========================================================

    class Delegated : public QAbstractListModel {
    private:
        std::shared_ptr<MethodDelegate> methodDelegate;
        MethodMask methodMask;
    public:
        Delegated(const std::shared_ptr<MethodDelegate> &methodDelegate, MethodMask methodMask)
            : methodDelegate(methodDelegate), methodMask(methodMask) {}

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
        if (const auto delegated = dynamic_cast<Delegated*>(ABSLISTMODEL_THIS); delegated != nullptr) {
            delegated->emitDataChanged(MODELINDEX_VALUE(topLeft), MODELINDEX_VALUE(bottomRight), qRoles);
        }
    }

    void Interior_emitHeaderDataChanged(InteriorRef _this, Orientation orientation, int32_t first, int32_t last) {
        if (const auto delegated = dynamic_cast<Delegated*>(ABSLISTMODEL_THIS); delegated != nullptr) {
            delegated->emitHeaderDataChanged(static_cast<Qt::Orientation>(orientation), first, last);
        }
    }

    void Interior_beginInsertRows(InteriorRef _this, ModelIndex::HandleRef parent, int32_t first, int32_t last) {
        if (const auto delegated = dynamic_cast<Delegated*>(ABSLISTMODEL_THIS); delegated != nullptr) {
            delegated->beginInsertRows(MODELINDEX_VALUE(parent), first, last);
        }
    }

    void Interior_endInsertRows(InteriorRef _this) {
        if (const auto delegated = dynamic_cast<Delegated*>(ABSLISTMODEL_THIS); delegated != nullptr) {
            delegated->endInsertRows();
        }
    }

    void Interior_beginRemoveRows(InteriorRef _this, ModelIndex::HandleRef parent, int32_t first, int32_t last) {
        if (const auto delegated = dynamic_cast<Delegated*>(ABSLISTMODEL_THIS); delegated != nullptr) {
            delegated->beginRemoveRows(MODELINDEX_VALUE(parent), first, last);
        }
    }

    void Interior_endRemoveRows(InteriorRef _this) {
        if (const auto delegated = dynamic_cast<Delegated*>(ABSLISTMODEL_THIS); delegated != nullptr) {
            delegated->endRemoveRows();
        }
    }

    void Interior_beginResetModel(InteriorRef _this) {
        if (const auto delegated = dynamic_cast<Delegated*>(ABSLISTMODEL_THIS); delegated != nullptr) {
            delegated->beginResetModel();
        }
    }

    void Interior_endResetModel(InteriorRef _this) {
        if (const auto delegated = dynamic_cast<Delegated*>(ABSLISTMODEL_THIS); delegated != nullptr) {
            delegated->endResetModel();
        }
    }

    void Interior_dispose(InteriorRef _this) {
        delete WRAPPER;
    }

    InteriorRef createSubclassed(const std::shared_ptr<SignalHandler>& handler, const std::shared_ptr<MethodDelegate>& methodDelegate, MethodMask methodMask) {
        const auto wrapper = new Delegated(methodDelegate, methodMask);
        return reinterpret_cast<InteriorRef>(new SignalWrapper(wrapper, handler));
    }
}
#pragma clang diagnostic pop

#include "AbstractListModel.moc"
