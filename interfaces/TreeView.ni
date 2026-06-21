module TreeView;

import Object;
import Widget;
import Icon;
import Enums;
import AbstractItemView;
import ModelIndex;
import HeaderView;

interface SignalHandler extends AbstractItemView.SignalHandler {
    void collapsed(ModelIndex.Handle index);
    void expanded(ModelIndex.Handle index);
}

opaque Handle extends AbstractItemView.Handle {
    bool allColumnsShowFocus();
    int autoExpandDelay();
    int columnAt(int x);
    int columnViewportPosition(int column);
    int columnWidth(int column);
    bool expandsOnDoubleClick();
    HeaderView.Handle header();
    int indentation();
    ModelIndex.Owned indexAbove(ModelIndex.Handle index);
    ModelIndex.Owned indexBelow(ModelIndex.Handle index);
    bool isAnimated();
    bool isColumnHidden(int column);
    bool isExpanded(ModelIndex.Handle index);
    bool isFirstColumnSpanned(int row, ModelIndex.Handle parent);
    bool isHeaderHidden();
    bool isRowHidden(int row, ModelIndex.Handle parent);
    bool isSortingEnabled();
    bool itemsExpandable();
    void resetIndentation();
    bool rootIsDecorated();
    void setAllColumnsShowFocus(bool enable);
    void setAnimated(bool enable);
    void setAutoExpandDelay(int delay);
    void setColumnHidden(int column, bool hide);
    void setColumnWidth(int column, int width);
    void setExpanded(ModelIndex.Handle index, bool expanded);
    void setExpandsOnDoubleClick(bool enable);
    void setFirstColumnSpanned(int row, ModelIndex.Handle parent, bool span);
    void setHeader(HeaderView.Handle header);
    void setHeaderHidden(bool hide);
    void setIndentation(int i);
    void setItemsExpandable(bool enable);
    void setRootIsDecorated(bool show);
    void setRowHidden(int row, ModelIndex.Handle parent, bool hide);
    void setSortingEnabled(bool enable);
    void setTreePosition(int index);
    void setUniformRowHeights(bool uniform);
    void setWordWrap(bool on);
    int treePosition();
    bool uniformRowHeights();
    bool wordWrap();

    void collapse(ModelIndex.Handle index);
    void collapseAll();
    void expand(ModelIndex.Handle index);
    void expandAll();
    void expandRecursively(ModelIndex.Handle index, int depth = -1);
    void expandToDepth(int depth);
    void hideColumn(int column);
    void resizeColumnToContents(int column);
    void showColumn(int column);
    void sortByColumn(int column, SortOrder order);

    // signals ============================
    SignalConnection connect_Collapsed(SignalHandler handler);
    SignalConnection connect_Expanded(SignalHandler handler);
}

Handle create(Widget.Handle parent = null);
