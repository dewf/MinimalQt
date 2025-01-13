#include "generated/SortFilterProxyModel.h"
#include "SortFilterProxyModelInternal.h"

#include "ObjectInternal.h"
#include "RegularExpressionInternal.h"
#include "ModelIndexInternal.h"

#define THIS (reinterpret_cast<QSortFilterProxyModel*>(_this))

namespace SortFilterProxyModel
{
    bool Handle_autoAcceptChildRows(HandleRef _this) {
        return THIS->autoAcceptChildRows();
    }

    bool Handle_dynamicSortFilter(HandleRef _this) {
        return THIS->dynamicSortFilter();
    }

    CaseSensitivity Handle_filterCaseSensitivity(HandleRef _this) {
        return static_cast<CaseSensitivity>(THIS->filterCaseSensitivity());
    }

    int32_t Handle_filterKeyColumn(HandleRef _this) {
        return THIS->filterKeyColumn();
    }

    RegularExpression::OwnedRef Handle_filterRegularExpression(HandleRef _this) {
        return REGEX_HEAP_NEW(THIS->filterRegularExpression());
    }

    int32_t Handle_filterRole(HandleRef _this) {
        return THIS->filterRole();
    }

    bool Handle_isRecursiveFilteringEnabled(HandleRef _this) {
        return THIS->isRecursiveFilteringEnabled();
    }

    bool Handle_isSortLocaleAware(HandleRef _this) {
        return THIS->isSortLocaleAware();
    }

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

    void Handle_setFilterRole(HandleRef _this, int32_t role) {
        THIS->setFilterRole(role);
    }

    void Handle_setRecursiveFilteringEnabled(HandleRef _this, bool enabled) {
        THIS->setRecursiveFilteringEnabled(enabled);
    }

    void Handle_setSortCaseSensitivity(HandleRef _this, CaseSensitivity sensitivity) {
        THIS->setSortCaseSensitivity(static_cast<Qt::CaseSensitivity>(sensitivity));
    }

    void Handle_setSortLocaleAware(HandleRef _this, bool state) {
        THIS->setSortLocaleAware(state);
    }

    void Handle_setSortRole(HandleRef _this, int sortRole) {
        THIS->setSortRole(sortRole);
    }

    CaseSensitivity Handle_sortCaseSensitivity(HandleRef _this) {
        return static_cast<CaseSensitivity>(THIS->sortCaseSensitivity());
    }

    int32_t Handle_sortColumn(HandleRef _this) {
        return THIS->sortColumn();
    }

    SortOrder Handle_sortOrder(HandleRef _this) {
        return static_cast<SortOrder>(THIS->sortOrder());
    }

    int32_t Handle_sortRole(HandleRef _this) {
        return THIS->sortRole();
    }

    void Handle_invalidate(HandleRef _this) {
        THIS->invalidate();
    }

    void Handle_setFilterFixedString(HandleRef _this, const std::string& pattern) {
        THIS->setFilterFixedString(QString::fromStdString(pattern));
    }

    void Handle_setFilterRegularExpression(HandleRef _this, const std::string& pattern) {
        THIS->setFilterRegularExpression(QString::fromStdString(pattern));
    }

    void Handle_setFilterRegularExpression(HandleRef _this, RegularExpression::HandleRef regex) {
        THIS->setFilterRegularExpression(QREGEX_VALUE(regex));
    }

    void Handle_setFilterWildcard(HandleRef _this, const std::string& pattern) {
        THIS->setFilterWildcard(QString::fromStdString(pattern));
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
            handler->filterRoleChanged(filterRole);
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
            handler->sortRoleChanged(sortRole);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QSortFilterProxyModel(AS_QOBJECT_PTR(parent)));
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
                ModelIndex::__Owned source2(source_parent);
                return methodDelegate->filterAcceptsRow(source_row, &source2);
            } else {
                return QSortFilterProxyModel::filterAcceptsRow(source_row, source_parent);
            }
        }
        [[nodiscard]]
        bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const override {
            if (methodMask & FilterAcceptsColumn) {
                ModelIndex::__Owned source2(source_parent);
                return methodDelegate->filterAcceptsColumn(source_column, &source2);
            } else {
                return QSortFilterProxyModel::filterAcceptsColumn(source_column, source_parent);
            }
        }
        [[nodiscard]]
        bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override {
            if (methodMask & LessThan) {
                ModelIndex::__Owned left2(source_left), right2(source_right);
                return methodDelegate->lessThan(&left2, &right2);
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
