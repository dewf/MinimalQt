#include "generated/SortFilterProxyModel.h"
#include "SortFilterProxyModelInternal.h"

#include "ObjectInternal.h"
#include "RegularExpressionInternal.h"

#define THIS (reinterpret_cast<QSortFilterProxyModel*>(_this))

#define BROKEN_MODELINDEX(x) ((ModelIndex::HandleRef)&x) // BAD DON'T USE

namespace SortFilterProxyModel
{
    void Handle_setAutoAcceptChildRows(HandleRef _this, bool state) {
        THIS->setAutoAcceptChildRows(state);
    }

    void Handle_setDynamicSortFilter(HandleRef _this, bool state) {
        THIS->setDynamicSortFilter(state);
    }

    void Handle_setFilterCaseSensitivity(HandleRef _this, CaseSensitivity sensitivity) {
        THIS->setFilterCaseSensitivity(static_cast<Qt::CaseSensitivity>(sensitivity));
    }

    void Handle_setFilterKeyColumn(HandleRef _this, int32_t filterKeyColumn) {
        THIS->setFilterKeyColumn(filterKeyColumn);
    }

    void Handle_setFilterRegularExpression(HandleRef _this, RegularExpression::HandleRef regex) {
        THIS->setFilterRegularExpression(QREGEX_VALUE(regex));
    }

    void Handle_setFilterRole(HandleRef _this, ItemDataRole filterRole) {
        THIS->setFilterRole(static_cast<int>(filterRole));
    }

    void Handle_setSortLocaleAware(HandleRef _this, bool state) {
        THIS->setSortLocaleAware(state);
    }

    void Handle_setRecursiveFilteringEnabled(HandleRef _this, bool enabled) {
        THIS->setRecursiveFilteringEnabled(enabled);
    }

    void Handle_setSortCaseSensitivity(HandleRef _this, CaseSensitivity sensitivity) {
        THIS->setSortCaseSensitivity(static_cast<Qt::CaseSensitivity>(sensitivity));
    }

    void Handle_setSortRole(HandleRef _this, ItemDataRole sortRole) {
        THIS->setSortRole(static_cast<int>(sortRole));
    }

    SignalConnectionRef Handle_connect_AutoAcceptChildRowsChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSortFilterProxyModel::autoAcceptChildRowsChanged, [handler](bool autoAcceptChildRows) {
            handler->autoAcceptChildRowsChanged(autoAcceptChildRows);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FilterCaseSensitivityChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSortFilterProxyModel::filterCaseSensitivityChanged, [handler](Qt::CaseSensitivity filterCaseSensitivity) {
            handler->filterCaseSensitivityChanged(static_cast<CaseSensitivity>(filterCaseSensitivity));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FilterRoleChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSortFilterProxyModel::filterRoleChanged, [handler](int filterRole) {
            handler->filterRoleChanged(static_cast<ItemDataRole>(filterRole));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_RecursiveFilteringEnabledChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSortFilterProxyModel::recursiveFilteringEnabledChanged, [handler](bool recursiveFilteringEnabled) {
            handler->recursiveFilteringEnabledChanged(recursiveFilteringEnabled);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SortCaseSensitivityChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSortFilterProxyModel::sortCaseSensitivityChanged, [handler](Qt::CaseSensitivity sortCaseSensitivity) {
            handler->sortCaseSensitivityChanged(static_cast<CaseSensitivity>(sortCaseSensitivity));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SortLocaleAwareChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSortFilterProxyModel::sortLocaleAwareChanged, [handler](bool sortLocaleAware) {
            handler->sortLocaleAwareChanged(sortLocaleAware);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SortRoleChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSortFilterProxyModel::sortRoleChanged, [handler](int sortRole) {
            handler->sortRoleChanged(static_cast<ItemDataRole>(sortRole));
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QSortFilterProxyModel());
    }

    // subclass stuff ==================================================

#define DELEGATED_THIS (reinterpret_cast<Delegated*>(_this))

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
        delete DELEGATED_THIS;
    }

    DelegatedRef createDelegated() {
        return reinterpret_cast<DelegatedRef>(new Delegated());
    }
}
