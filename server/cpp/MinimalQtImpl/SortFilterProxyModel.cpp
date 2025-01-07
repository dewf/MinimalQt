#include "generated/SortFilterProxyModel.h"
#include "SortFilterProxyModelInternal.h"

#include <utility>

#include "RegularExpressionInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define PROXYMODEL_THIS (WRAPPER->getActual())

#define BROKEN_MODELINDEX(x) ((ModelIndex::HandleRef)&x) // BAD DON'T USE

namespace SortFilterProxyModel
{
    void Handle_setAutoAcceptChildRows(HandleRef _this, bool state) {
        PROXYMODEL_THIS->setAutoAcceptChildRows(state);
    }

    void Handle_setDynamicSortFilter(HandleRef _this, bool state) {
        PROXYMODEL_THIS->setDynamicSortFilter(state);
    }

    void Handle_setFilterCaseSensitivity(HandleRef _this, CaseSensitivity sensitivity) {
        PROXYMODEL_THIS->setFilterCaseSensitivity(static_cast<Qt::CaseSensitivity>(sensitivity));
    }

    void Handle_setFilterKeyColumn(HandleRef _this, int32_t filterKeyColumn) {
        PROXYMODEL_THIS->setFilterKeyColumn(filterKeyColumn);
    }

    void Handle_setFilterRegularExpression(HandleRef _this, const std::shared_ptr<RegularExpression::Deferred::Base>& regex) {
        PROXYMODEL_THIS->setFilterRegularExpression(RegularExpression::fromDeferred(regex));
    }

    void Handle_setFilterRole(HandleRef _this, ItemDataRole filterRole) {
        PROXYMODEL_THIS->setFilterRole(static_cast<int>(filterRole));
    }

    void Handle_setSortLocaleAware(HandleRef _this, bool state) {
        PROXYMODEL_THIS->setSortLocaleAware(state);
    }

    void Handle_setRecursiveFilteringEnabled(HandleRef _this, bool enabled) {
        PROXYMODEL_THIS->setRecursiveFilteringEnabled(enabled);
    }

    void Handle_setSortCaseSensitivity(HandleRef _this, CaseSensitivity sensitivity) {
        PROXYMODEL_THIS->setSortCaseSensitivity(static_cast<Qt::CaseSensitivity>(sensitivity));
    }

    void Handle_setSortRole(HandleRef _this, ItemDataRole sortRole) {
        PROXYMODEL_THIS->setSortRole(static_cast<int>(sortRole));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QSortFilterProxyModel(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    // subclass stuff ==================================================

    class Delegated : public QSortFilterProxyModel {
    private:
        MethodMask methodMask = 0;
        std::shared_ptr<MethodDelegate> methodDelegate;
    public:
        void setDelegate(const std::shared_ptr<MethodDelegate> &methodDelegate, MethodMask methodMask) {
            this->methodDelegate = methodDelegate;
            this->methodMask = methodMask;
        }
    protected:
        [[nodiscard]]
        bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override {
            if (methodMask & FilterAcceptsRow) {
                return methodDelegate->filterAcceptsRow(source_row, BROKEN_MODELINDEX(source_parent));
            } else {
                return QSortFilterProxyModel::filterAcceptsRow(source_row, source_parent);
            }
        }
        [[nodiscard]]
        bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const override {
            if (methodMask & FilterAcceptsColumn) {
                return methodDelegate->filterAcceptsColumn(source_column,BROKEN_MODELINDEX(source_parent));
            } else {
                return QSortFilterProxyModel::filterAcceptsColumn(source_column, source_parent);
            }
        }
        [[nodiscard]]
        bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override {
            if (methodMask & LessThan) {
                return methodDelegate->lessThan(BROKEN_MODELINDEX(source_left), BROKEN_MODELINDEX(source_right));
            } else {
                return QSortFilterProxyModel::lessThan(source_left, source_right);
            }
        }
    public:
        friend void Delegated_invalidateColumnsFilter(DelegatedRef _this);
        friend void Delegated_invalidateRowsFilter(DelegatedRef _this);
        friend void Delegated_invalidateFilter(DelegatedRef _this);
    };

#define DELEGATED_THIS (reinterpret_cast<Delegated*>(PROXYMODEL_THIS)) // or would we have to do a dynamic cast? we're downcasting a QSortFilterProxyModel to a Delegated ptr

    void Delegated_invalidateColumnsFilter(DelegatedRef _this) {
        DELEGATED_THIS->invalidateColumnsFilter();
    }

    void Delegated_invalidateRowsFilter(DelegatedRef _this) {
        DELEGATED_THIS->invalidateRowsFilter();
    }

    void Delegated_invalidateFilter(DelegatedRef _this) {
        DELEGATED_THIS->invalidateFilter();
    }

    void Delegated_setDelegate(DelegatedRef _this, const std::shared_ptr<MethodDelegate>& methodDelegate, MethodMask methodMask) {
        DELEGATED_THIS->setDelegate(methodDelegate, methodMask);
    }

    void Delegated_dispose(DelegatedRef _this) {
        delete WRAPPER;
    }

    DelegatedRef createDelegated(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new Delegated(), handler);
        return reinterpret_cast<DelegatedRef>(wrapper);
    }
}
