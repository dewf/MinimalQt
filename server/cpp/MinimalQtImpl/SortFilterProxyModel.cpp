#include "generated/SortFilterProxyModel.h"

#include <QSortFilterProxyModel>
#include <utility>
#include "util/SignalStuff.h"
#include "util/Macros.h"

#include "RegularExpressionInternal.h"

#define THIS ((SortFilterProxyModelWithHandler*)_this)

#include "signalrelays/SortFilterProxyModel.h"

namespace SortFilterProxyModel
{
    class SortFilterProxyModelWithHandler : public QSortFilterProxyModel {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit SortFilterProxyModelWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

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

    void Handle_setFilterRegularExpression(HandleRef _this, const std::shared_ptr<RegularExpression::Deferred::Base>& regex) {
        THIS->setFilterRegularExpression(RegularExpression::fromDeferred(regex));
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

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new SortFilterProxyModelWithHandler(handler));
    }

    // subclass stuff ==================================================

#define SUBTHIS ((Subclassed*)_this)

    class Subclassed : public SortFilterProxyModelWithHandler {
    private:
        MethodMask methodMask;
        std::shared_ptr<MethodDelegate> methodDelegate;
    public:
        Subclassed(const std::shared_ptr<SignalHandler> &handler, const std::shared_ptr<MethodDelegate> &methodDelegate, MethodMask methodMask)
            : SortFilterProxyModelWithHandler(handler), methodMask(methodMask), methodDelegate(methodDelegate) {}
    protected:
        [[nodiscard]] bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override {
            if (methodMask & FilterAcceptsRow) {
                return methodDelegate->filterAcceptsRow(source_row, MODELINDEX(source_parent));
            } else {
                return QSortFilterProxyModel::filterAcceptsRow(source_row, source_parent);
            }
        }
        [[nodiscard]] bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const override {
            if (methodMask & FilterAcceptsColumn) {
                return methodDelegate->filterAcceptsColumn(source_column,MODELINDEX(source_parent));
            } else {
                return QSortFilterProxyModel::filterAcceptsColumn(source_column, source_parent);
            }
        }
        [[nodiscard]] bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override {
            if (methodMask & LessThan) {
                return methodDelegate->lessThan(MODELINDEX(source_left), MODELINDEX(source_right));
            } else {
                return QSortFilterProxyModel::lessThan(source_left, source_right);
            }
        }
    public:
        friend void Interior_invalidateColumnsFilter(InteriorRef _this);
        friend void Interior_invalidateRowsFilter(InteriorRef _this);
        friend void Interior_invalidateFilter(InteriorRef _this);
    };

    void Interior_invalidateColumnsFilter(InteriorRef _this) {
        SUBTHIS->invalidateColumnsFilter();
    }

    void Interior_invalidateRowsFilter(InteriorRef _this) {
        SUBTHIS->invalidateRowsFilter();
    }

    void Interior_invalidateFilter(InteriorRef _this) {
        SUBTHIS->invalidateFilter();
    }

    void Interior_dispose(InteriorRef _this) {
        delete THIS;
    }

    InteriorRef createSubclassed(const std::shared_ptr<SignalHandler>& handler, const std::shared_ptr<MethodDelegate>& methodDelegate, MethodMask methodMask) {
        return reinterpret_cast<InteriorRef>(new Subclassed(handler, methodDelegate, methodMask));
    }

}

#include "SortFilterProxyModel.moc"
