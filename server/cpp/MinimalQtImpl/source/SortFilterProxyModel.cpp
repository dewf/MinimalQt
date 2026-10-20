#include "generated/SortFilterProxyModel.h"
#include "SortFilterProxyModelInternal.h"

#include "ObjectInternal.h"
#include "RegularExpressionInternal.h"
#include "ModelIndexInternal.h"

using namespace ::Object;
using namespace ::Enums;
using namespace ::AbstractItemModel;
using namespace ::AbstractProxyModel;
using namespace ::RegularExpression;
using namespace ::ModelIndex;
using namespace ::PersistentModelIndex;

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
            handler->sig_autoAcceptChildRowsChanged(autoAcceptChildRows);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FilterCaseSensitivityChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSortFilterProxyModel::filterCaseSensitivityChanged, [handler](Qt::CaseSensitivity filterCaseSensitivity) {
            handler->sig_filterCaseSensitivityChanged(static_cast<CaseSensitivity>(filterCaseSensitivity));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FilterRoleChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSortFilterProxyModel::filterRoleChanged, [handler](int filterRole) {
            handler->sig_filterRoleChanged(filterRole);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_RecursiveFilteringEnabledChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSortFilterProxyModel::recursiveFilteringEnabledChanged, [handler](bool recursiveFilteringEnabled) {
            handler->sig_recursiveFilteringEnabledChanged(recursiveFilteringEnabled);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SortCaseSensitivityChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSortFilterProxyModel::sortCaseSensitivityChanged, [handler](Qt::CaseSensitivity sortCaseSensitivity) {
            handler->sig_sortCaseSensitivityChanged(static_cast<CaseSensitivity>(sortCaseSensitivity));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SortLocaleAwareChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSortFilterProxyModel::sortLocaleAwareChanged, [handler](bool sortLocaleAware) {
            handler->sig_sortLocaleAwareChanged(sortLocaleAware);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SortRoleChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSortFilterProxyModel::sortRoleChanged, [handler](int sortRole) {
            handler->sig_sortRoleChanged(sortRole);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto model = AS_QSORTFILTERPROXYMODEL_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(model);
        case Handle_CastTarget::AbstractItemModel_ConstHandle:
        case Handle_CastTarget::AbstractItemModel_Handle:
            return static_cast<QAbstractItemModel*>(model);
        case Handle_CastTarget::AbstractProxyModel_Handle:
            return static_cast<QAbstractProxyModel*>(model);
        }
        std::unreachable();
    }

    HandleRef create(Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QSortFilterProxyModel(AS_QOBJECT_PTR(parent)));
    }

    // subclass stuff ==================================================

#define DELEGATED_THIS (reinterpret_cast<Delegated*>(_this))

    class Delegated : public QSortFilterProxyModel {
        std::shared_ptr<DelegatedMethods> methods;
        Flags<DelegatedMethodMask> mask;
    public:
        Delegated(QObject* parent, const std::shared_ptr<DelegatedMethods> &methodDelegate, Flags<DelegatedMethodMask> methodMask)
            : QSortFilterProxyModel(parent),
                methods(methodDelegate),
                mask(methodMask) {}
    protected:
        [[nodiscard]]
        bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override {
            if (mask & DelegatedMethodMask::FilterAcceptsRow) {
                QModelIndex source2(source_parent);
                return methods->dm_filterAcceptsRow(source_row, reinterpret_cast<ModelIndex::HandleRef>(&source2));
            } else {
                return QSortFilterProxyModel::filterAcceptsRow(source_row, source_parent);
            }
        }
        [[nodiscard]]
        bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const override {
            if (mask & DelegatedMethodMask::FilterAcceptsColumn) {
                QModelIndex source2(source_parent);
                return methods->dm_filterAcceptsColumn(source_column, reinterpret_cast<ModelIndex::HandleRef>(&source2));
            } else {
                return QSortFilterProxyModel::filterAcceptsColumn(source_column, source_parent);
            }
        }
        [[nodiscard]]
        bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override {
            if (mask & DelegatedMethodMask::LessThan) {
                QModelIndex left2(source_left), right2(source_right);
                return methods->dm_lessThan(reinterpret_cast<ModelIndex::HandleRef>(&left2), reinterpret_cast<ModelIndex::HandleRef>(&right2));
            } else {
                return QSortFilterProxyModel::lessThan(source_left, source_right);
            }
        }
    public:
        friend void Delegated_beginFilterChange(DelegatedRef _this);
        friend void Delegated_endFilterChange(DelegatedRef _this, Flags<SortFilterProxyModel::Directions> directions);
    };

    void Delegated_beginFilterChange(DelegatedRef _this) {
        DELEGATED_THIS->beginFilterChange();
    }

    void Delegated_endFilterChange(DelegatedRef _this, Flags<Directions> directions /* Directions::Both */) {
        DELEGATED_THIS->endFilterChange(QSortFilterProxyModel::Directions::fromInt(directions.value()));
    }

    void Delegated_dispose(DelegatedRef _this) {
        delete DELEGATED_THIS;
    }

    void* Delegated_staticCast(DelegatedRef obj, Delegated_CastTarget target) {
        auto delegated = reinterpret_cast<Delegated*>(obj);
        switch (target)
        {
        case Delegated_CastTarget::Object_Handle:
            return static_cast<QObject*>(delegated);
        case Delegated_CastTarget::AbstractItemModel_ConstHandle:
        case Delegated_CastTarget::AbstractItemModel_Handle:
            return static_cast<QAbstractItemModel*>(delegated);
        case Delegated_CastTarget::AbstractProxyModel_Handle:
            return static_cast<QAbstractProxyModel*>(delegated);
        case Delegated_CastTarget::Handle:
            return static_cast<QSortFilterProxyModel*>(delegated);
        }
        std::unreachable();
    }

    DelegatedRef createDelegated(const std::shared_ptr<DelegatedMethods>& methods, Flags<DelegatedMethodMask> mask, Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<DelegatedRef>(new Delegated(AS_QOBJECT_PTR(parent), methods, mask));
    }
}
