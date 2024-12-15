#include "generated/SortFilterProxyModel.h"

#include <QSortFilterProxyModel>
#include <utility>
#include "util/SignalStuff.h"
#include "util/Macros.h"

#include "RegularExpressionInternal.h"

#define THIS ((SortFilterProxyModelWithHandler*)_this)

namespace SortFilterProxyModel
{
    class SortFilterProxyModelWithHandler : public QSortFilterProxyModel {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // AbstractItemModel:
            { ColumnsAboutToBeInserted, SIGNAL(columnsAboutToBeInserted(QModelIndex,int,int)), SLOT(onColumnsAboutToBeInserted(QModelIndex,int,int)) },
            { ColumnsAboutToBeMoved, SIGNAL(columnsAboutToBeMoved(QModelIndex,int,QModelIndex,int)), SLOT(onColumnsAboutToBeMoved(QModelIndex,int,QModelIndex,int)) },
            { ColumnsAboutToBeRemoved, SIGNAL(columnsAboutToBeRemoved(QModelIndex,int,int)), SLOT(onColumnsAboutToBeRemoved(QModelIndex,int,int)) },
            { ColumnsInserted, SIGNAL(columnsInserted(QModelIndex,int,int)), SLOT(onColumnsInserted(QModelIndex,int,int)) },
            { ColumnsMoved, SIGNAL(columnsMoved(QModelIndex,int,int,QModelIndex,int)), SLOT(onColumnsMoved(QModelIndex,int,int,QModelIndex,int)) },
            { ColumnsRemoved, SIGNAL(columnsRemoved(QModelIndex,int,int)), SLOT(onColumnsRemoved(QModelIndex,int,int)) },
            { DataChanged, SIGNAL(dataChanged(QModelIndex,QModelIndex,QList<int>)), SLOT(onDataChanged(QModelIndex,QModelIndex,QList<int>)) },
            { HeaderDataChanged, SIGNAL(headerDataChanged(Orientation,int,int)), SLOT(onHeaderDataChanged(Orientation,int,int)) },
            { LayoutAboutToBeChanged, SIGNAL(layoutAboutToBeChanged(QList<QPersistentModelIndex>,LayoutChangeHint)), SLOT(onLayoutAboutToBeChanged(QList<QPersistentModelIndex>,LayoutChangeHint)) },
            { LayoutChanged, SIGNAL(layoutChanged(QList<QPersistentModelIndex>,LayoutChangeHint)), SLOT(onLayoutChanged(QList<QPersistentModelIndex>,LayoutChangeHint)) },
            { ModelAboutToBeReset, SIGNAL(modelAboutToBeReset()), SLOT(onModelAboutToBeReset()) },
            { ModelReset, SIGNAL(modelReset()), SLOT(onModelReset()) },
            { RowsAboutToBeInserted, SIGNAL(rowsAboutToBeInserted(QModelIndex,int,int)), SLOT(onRowsAboutToBeInserted(QModelIndex,int,int)) },
            { RowsAboutToBeMoved, SIGNAL(rowsAboutToBeMoved(ModelIndex,int,int,ModelIndex,int)), SLOT(onRowsAboutToBeMoved(ModelIndex,int,int,ModelIndex,int)) },
            { RowsAboutToBeRemoved, SIGNAL(rowsAboutToBeRemoved(QModelIndex,int,int)), SLOT(onRowsAboutToBeRemoved(QModelIndex,int,int)) },
            { RowsInserted, SIGNAL(rowsInserted(QModelIndex,int,int)), SLOT(onRowsInserted(QModelIndex,int,int)) },
            { RowsMoved, SIGNAL(rowsMoved(QModelIndex,int,int,QModelIndex,int)), SLOT(onRowsMoved(QModelIndex,int,int,QModelIndex,int)) },
            { RowsRemoved, SIGNAL(rowsRemoved(QModelIndex,int,int)), SLOT(onRowsRemoved(QModelIndex,int,int)) },
            // AbstractProxyModel:
            { SourceModelChanged, SIGNAL(sourceModelChanged()), SLOT(onSourceModelChanged()) },
            // SortFilterProxyModel:
            { AutoAcceptChildRowsChanged, SIGNAL(autoAcceptChildRowsChanged(bool)), SLOT(onAutoAcceptChildRowsChanged(bool)) },
            { FilterCaseSensitivityChanged, SIGNAL(filterCaseSensitivityChanged(CaseSensitivity)), SLOT(onFilterCaseSensitivityChanged(CaseSensitivity)) },
            { FilterRoleChanged, SIGNAL(filterRoleChanged(int)), SLOT(onFilterRoleChanged(int)) },
            { RecursiveFilteringEnabledChanged, SIGNAL(recursiveFilteringEnabledChanged(bool)), SLOT(onRecursiveFilteringEnabledChanged(bool)) },
            { SortCaseSensitivityChanged, SIGNAL(sortCaseSensitivityChanged(CaseSensitivity)), SLOT(onSortCaseSensitivityChanged(CaseSensitivity)) },
            { SortLocaleAwareChanged, SIGNAL(sortLocaleAwareChanged(bool)), SLOT(onSortLocaleAwareChanged(bool)) },
            { SortRoleChanged, SIGNAL(sortRoleChanged(int)), SLOT(onSortRoleChanged(int)) },
        };
    public:
        explicit SortFilterProxyModelWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // AbstractItemModel ======
        void onColumnsAboutToBeInserted(const QModelIndex& parent, int first, int last) const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    columnsAboutToBeInserted(MODELINDEX(parent), first, last);
        };
        void onColumnsAboutToBeMoved(const QModelIndex& sourceParent, int sourceStart, int sourceEnd, const QModelIndex& destinationParent, int destinationColumn) const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    columnsAboutToBeMoved(MODELINDEX(sourceParent), sourceStart, sourceEnd, MODELINDEX(destinationParent), destinationColumn);
        };
        void onColumnsAboutToBeRemoved(const QModelIndex& parent, int first, int last) const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    columnsAboutToBeRemoved(MODELINDEX(parent), first, last);
        };
        void onColumnsInserted(const QModelIndex& parent, int first, int last) const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    columnsInserted(MODELINDEX(parent), first, last);
        };
        void onColumnsMoved(const QModelIndex& sourceParent, int sourceStart, int sourceEnd, const QModelIndex& destinationParent, int destinationColumn) const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    columnsMoved(MODELINDEX(sourceParent), sourceStart, sourceEnd, MODELINDEX(destinationParent), destinationColumn);
        };
        void onColumnsRemoved(const QModelIndex& parent, int first, int last) const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    columnsRemoved(MODELINDEX(parent), first, last);
        };
        void onDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QList<int> &roles = QList<int>()) const {
            std::vector<ItemDataRole> roles2;
            for (auto &role : roles) {
                roles2.push_back(static_cast<ItemDataRole>(role));
            }
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    dataChanged(MODELINDEX(topLeft), MODELINDEX(bottomRight), roles2);
        }
        void onHeaderDataChanged(Qt::Orientation orientation, int first, int last) const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    headerDataChanged(static_cast<Orientation>(orientation), first, last);
        };
        void onLayoutAboutToBeChanged(const QList<QPersistentModelIndex>& parents, QAbstractItemModel::LayoutChangeHint hint) const {
            std::vector<PersistentModelIndex::HandleRef> parents2;
            for (auto &parent : parents) {
                parents2.push_back(PMODELINDEX(parent));
            }
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    layoutAboutToBeChanged(parents2, static_cast<AbstractItemModel::LayoutChangeHint>(hint));
        };
        void onLayoutChanged(const QList<QPersistentModelIndex>& parents, QAbstractItemModel::LayoutChangeHint hint) const {
            std::vector<PersistentModelIndex::HandleRef> parents2;
            for (auto &parent : parents) {
                parents2.push_back(PMODELINDEX(parent));
            }
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    layoutChanged(parents2, static_cast<AbstractItemModel::LayoutChangeHint>(hint));
        };
        void onModelAboutToBeReset() const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    modelAboutToBeReset();
        };
        void onModelReset() const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    modelReset();
        };
        void onRowsAboutToBeInserted(const QModelIndex& parent, int start, int end) const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    rowsAboutToBeInserted(MODELINDEX(parent), start, end);
        };
        void onRowsAboutToBeMoved(const QModelIndex& sourceParent, int sourceStart, int sourceEnd, const QModelIndex& destinationParent, int destinationRow) const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    rowsAboutToBeMoved(MODELINDEX(sourceParent), sourceStart, sourceEnd, MODELINDEX(destinationParent), destinationRow);
        };
        void onRowsAboutToBeRemoved(const QModelIndex& parent, int first, int last) const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    rowsAboutToBeRemoved(MODELINDEX(parent), first, last);
        };
        void onRowsInserted(const QModelIndex& parent, int first, int last) const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    rowsInserted(MODELINDEX(parent), first, last);
        };
        void onRowsMoved(const QModelIndex& sourceParent, int sourceStart, int sourceEnd, const QModelIndex& destinationParent, int destinationRow) const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    rowsMoved(MODELINDEX(sourceParent), sourceStart, sourceEnd, MODELINDEX(destinationParent), destinationRow);
        };
        void onRowsRemoved(const QModelIndex& parent, int first, int last) const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                inherited_AbstractItemModel_SignalHandler()->
                    rowsRemoved(MODELINDEX(parent), first, last);
        };
        // AbstractProxyModel =====
        void onSourceModelChanged() const {
            handler->
                inherited_AbstractProxyModel_SignalHandler()->
                    sourceModelChanged();
        };
        // SortFilterProxyModel ===
        void onAutoAcceptChildRowsChanged(bool autoAcceptChildRows) const {
            handler->autoAcceptChildRowsChanged(autoAcceptChildRows);
        };
        void onFilterCaseSensitivityChanged(Qt::CaseSensitivity filterCaseSensitivity) const {
            handler->filterCaseSensitivityChanged(static_cast<CaseSensitivity>(filterCaseSensitivity));
        };
        void onFilterRoleChanged(int filterRole) const {
            handler->filterRoleChanged(static_cast<ItemDataRole>(filterRole));
        };
        void onRecursiveFilteringEnabledChanged(bool recursiveFilteringEnabled) const {
            handler->recursiveFilteringEnabledChanged(recursiveFilteringEnabled);
        };
        void onSortCaseSensitivityChanged(Qt::CaseSensitivity sortCaseSensitivity) const {
            handler->sortCaseSensitivityChanged(static_cast<CaseSensitivity>(sortCaseSensitivity));
        };
        void onSortLocaleAwareChanged(bool sortLocaleAware) const {
            handler->sortLocaleAwareChanged(sortLocaleAware);
        };
        void onSortRoleChanged(int sortRole) const {
            handler->sortRoleChanged(static_cast<ItemDataRole>(sortRole));
        };
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
