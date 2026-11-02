module ListWidget;

import Object;
import Widget;
import ListView;
import ListWidgetItem;
import Enums;
import ModelIndex;
import MimeData;
import ItemSelectionModel;
import AbstractItemView;
import Point;
import Rect;
import Icon;

@methodprefix("sig_")
interface SignalHandler extends ListView.SignalHandler {
    void currentItemChanged(ListWidgetItem.Handle current, ListWidgetItem.Handle previous);
    void currentRowChanged(int currentRow);
    void currentTextChanged(string currentText);
    void itemActivated(ListWidgetItem.Handle item);
    void itemChanged(ListWidgetItem.Handle item);
    void itemClicked(ListWidgetItem.Handle item);
    void itemDoubleClicked(ListWidgetItem.Handle item);
    void itemEntered(ListWidgetItem.Handle item);
    void itemPressed(ListWidgetItem.Handle item);
    void itemSelectionChanged();
}

opaque Handle extends ListView.Handle {
    void addItem(ListWidgetItem.Handle item);
    void addItem(string label);
    void addItems(Array<string> labels);
    void closePersistentEditor(ListWidgetItem.Handle item);
    int count();
    ListWidgetItem.Handle currentItem();
    int currentRow();
    void editItem(ListWidgetItem.Handle item);
    Array<ListWidgetItem.Handle> findItems(string text, MatchFlags flags_);
    ModelIndex.Owned indexFromItem(ListWidgetItem.Handle item);
    void insertItem(int row, ListWidgetItem.Handle item);
    void insertItem(int row, string label);
    void insertItems(int row, Array<string> labels);
    bool isPersistentEditorOpen(ListWidgetItem.Handle item);
    bool isSortingEnabled();
    ListWidgetItem.Handle item(int row);
    ListWidgetItem.Handle itemAt(Point.Handle p);
    ListWidgetItem.Handle itemAt(int x, int y);
    ListWidgetItem.Handle itemFromIndex(ModelIndex.Handle index);
    Widget.Handle itemWidget(ListWidgetItem.Handle item);
    Array<ListWidgetItem.Handle> items(MimeData.Handle data);
    void openPersistentEditor(ListWidgetItem.Handle item);
    void removeItemWidget(ListWidgetItem.Handle item);
    int row(ListWidgetItem.Handle item);
    Array<ListWidgetItem.Handle> selectedItems();
    void setCurrentItem(ListWidgetItem.Handle item);
    void setCurrentItem(ListWidgetItem.Handle item, ItemSelectionModel.SelectionFlags command);
    void setCurrentRow(int row);
    void setCurrentRow(int row, ItemSelectionModel.SelectionFlags command);
    void setItemWidget(ListWidgetItem.Handle item, Widget.Handle widget);
    void setSortingEnabled(bool enable);
    void setSupportedDragActions(DropActions actions);
    void sortItems(SortOrder order = AscendingOrder);
    DropActions supportedDragActions();
    ListWidgetItem.Handle takeItem(int row);
    Rect.Owned visualItemRect(ListWidgetItem.Handle item);

    @shadows
    void setSelectionModel(ItemSelectionModel.Handle selectionModel);

    void clear();
    void scrollToItem(ListWidgetItem.Handle item, AbstractItemView.ScrollHint hint = EnsureVisible);

    // signals ================================
    SignalConnection connect_CurrentItemChanged(SignalHandler handler);
    SignalConnection connect_CurrentRowChanged(SignalHandler handler);
    SignalConnection connect_CurrentTextChanged(SignalHandler handler);
    SignalConnection connect_ItemActivated(SignalHandler handler);
    SignalConnection connect_ItemChanged(SignalHandler handler);
    SignalConnection connect_ItemClicked(SignalHandler handler);
    SignalConnection connect_ItemDoubleClicked(SignalHandler handler);
    SignalConnection connect_ItemEntered(SignalHandler handler);
    SignalConnection connect_ItemPressed(SignalHandler handler);
    SignalConnection connect_ItemSelectionChanged(SignalHandler handler);
}

Handle create(Widget.Handle parent = null);

// ListWidgetItem ctors (to avoid circular dependency)
ListWidgetItem.Handle ctor_ListWidgetItem(Handle parent = null, int type = cast<int>(ItemType.Type));
ListWidgetItem.Handle ctor_ListWidgetItem(string text, ListWidget.Handle parent = null, int type = cast<int>(ItemType.Type));
ListWidgetItem.Handle ctor_ListWidgetItem(Icon.Handle icon, string text, Handle parent = null, int type = cast<int>(ItemType.Type));

// ListWidgetItem extension method
Handle ext_ListWidgetItem_listWidget(ListWidgetItem.Handle this_);
