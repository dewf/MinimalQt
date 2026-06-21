module SortFilterProxyModel;

import Object;
import Enums;
import AbstractItemModel;
import AbstractProxyModel;
import RegularExpression;
import ModelIndex;
import PersistentModelIndex;

interface SignalHandler extends AbstractProxyModel.SignalHandler {
    void autoAcceptChildRowsChanged(bool autoAcceptChildRows);
    void filterCaseSensitivityChanged(CaseSensitivity filterCaseSensitivity);
    void filterRoleChanged(int filterRole);
    void recursiveFilteringEnabledChanged(bool recursiveFilteringEnabled);
    void sortCaseSensitivityChanged(CaseSensitivity sortCaseSensitivity);
    void sortLocaleAwareChanged(bool sortLocaleAware);
    void sortRoleChanged(int sortRole);
}

opaque Handle extends AbstractProxyModel.Handle {

    // QBindable<bool> bindableAutoAcceptChildRows()
    // QBindable<bool> bindableDynamicSortFilter()
    // QBindable<Qt::CaseSensitivity> bindableFilterCaseSensitivity()
    // QBindable<int> bindableFilterKeyColumn()
    // QBindable<QRegularExpression> bindableFilterRegularExpression()
    // QBindable<int> bindableFilterRole()
    // QBindable<bool> bindableIsSortLocaleAware()
    // QBindable<bool> bindableRecursiveFilteringEnabled()
    // QBindable<Qt::CaseSensitivity> bindableSortCaseSensitivity()
    // QBindable<int> bindableSortRole()

    bool autoAcceptChildRows();
    bool dynamicSortFilter();
    CaseSensitivity filterCaseSensitivity();
    int filterKeyColumn();
    RegularExpression.Owned filterRegularExpression();
    int filterRole();
    bool isRecursiveFilteringEnabled();
    bool isSortLocaleAware();
    void setAutoAcceptChildRows(bool accept);
    void setDynamicSortFilter(bool enable);
    void setFilterCaseSensitivity(CaseSensitivity cs);
    void setFilterKeyColumn(int column);
    void setFilterRole(int role);
    void setRecursiveFilteringEnabled(bool recursive);
    void setSortCaseSensitivity(CaseSensitivity cs);
    void setSortLocaleAware(bool on);
    void setSortRole(int role);
    CaseSensitivity sortCaseSensitivity();
    int sortColumn();
    SortOrder sortOrder();
    int sortRole();

    void invalidate();
    void setFilterFixedString(string pattern);
    void setFilterRegularExpression(string pattern);
    void setFilterRegularExpression(RegularExpression.Handle regularExpression);
    void setFilterWildcard(string pattern);

    // signals ============================
    SignalConnection connect_AutoAcceptChildRowsChanged(SignalHandler handler);
    SignalConnection connect_FilterCaseSensitivityChanged(SignalHandler handler);
    SignalConnection connect_FilterRoleChanged(SignalHandler handler);
    SignalConnection connect_RecursiveFilteringEnabledChanged(SignalHandler handler);
    SignalConnection connect_SortCaseSensitivityChanged(SignalHandler handler);
    SignalConnection connect_SortLocaleAwareChanged(SignalHandler handler);
    SignalConnection connect_SortRoleChanged(SignalHandler handler);
}

Handle create(Object.Handle parent = null);

// subclassing ==============================================

namedbits MethodMask {
    FilterAcceptsColumn,
    FilterAcceptsRow,
    LessThan
}

interface MethodDelegate {
    bool filterAcceptsColumn(int sourceColumn, ModelIndex.Handle sourceParent);
    bool filterAcceptsRow(int sourceRow, ModelIndex.Handle sourceParent);
    bool lessThan(ModelIndex.Handle sourceLeft, ModelIndex.Handle sourceRight);
}

opaque Delegated extends Handle {
    void invalidateColumnsFilter();
    void invalidateRowsFilter();
    void invalidateFilter();

    void setDelegate(MethodDelegate methodDelegate, MethodMask methodMask);
}

Delegated createDelegated();
