module StandardItem;

import Icon;
import Enums;
import Variant;
import ModelIndex;
import Brush;
import Font;
import Size;

enum ItemType { Type = 0, UserType = 1000 }

@nodispose
opaque ConstHandle {
    string accessibleDescription();
    string accessibleText();
    Brush.Owned background();
    CheckState checkState();
    Handle child(int row, int column = 0);
    Handle clone();
    int column();
    int columnCount();
    Variant.Owned data(int role = cast<int>(ItemDataRole.UserRole) + 1);
    ItemFlags getFlags();
    Font.Owned font();
    Brush.Owned foreground();
    bool hasChildren();
    Icon.Owned icon();
    ModelIndex.Owned index();
    bool isAutoTristate();
    bool isCheckable();
    bool isDragEnabled();
    bool isDropEnabled();
    bool isEditable();
    bool isEnabled();
    bool isSelectable();
    bool isUserTristate();

    // moved to StandardItemModel extension method
    // StandardItemModel_Handle model();

    // (since 6.0) virtual void multiData(QModelRoleDataSpan roleDataSpan) const

    Handle parent();
    int row();
    int rowCount();
    Size.Owned sizeHint();
    string statusTip();
    string text();
    Alignment textAlignment();
    string toolTip();
    int type();
    string whatsThis();
}

opaque Handle extends ConstHandle {
    void appendColumn(Array<Handle> items);
    void appendRow(Array<Handle> items);
    void appendRow(Handle item);
    void appendRows(Array<Handle> items);
    void clearData();
    void insertColumn(int column, Array<Handle> items);
    void insertColumns(int column, int count);
    void insertRow(int row, Array<Handle> items);
    void insertRow(int row, Handle item);
    void insertRows(int row, Array<Handle> items);
    void insertRows(int row, int count);

    // // virtual void	read(QDataStream &in)

    void removeColumn(int column);
    void removeColumns(int column, int count);
    void removeRow(int row);
    void removeRows(int row, int count);

    void setAccessibleDescription(string accessibleDescription);
    void setAccessibleText(string accessibleText);
    void setAutoTristate(bool tristate);
    void setBackground(Brush.Handle brush);
    void setCheckState(CheckState state);
    void setCheckable(bool checkable);
    void setChild(int row, int column, Handle item);
    void setChild(int row, Handle item);
    void setColumnCount(int columns);
    void setData(Variant.Handle value, int role = cast<int>(ItemDataRole.UserRole) + 1);
    void setDragEnabled(bool dragEnabled);
    void setDropEnabled(bool dropEnabled);
    void setEditable(bool editable);
    void setEnabled(bool enabled);
    void setFlags(ItemFlags flags_);
    void setFont(Font.Handle font);
    void setForeground(Brush.Handle brush);
    void setIcon(Icon.Handle icon);
    void setRowCount(int rows);
    void setSelectable(bool selectable);
    void setSizeHint(Size.Handle size);
    void setStatusTip(string statusTip);
    void setText(string text);
    void setTextAlignment(Alignment alignment);
    void setToolTip(string toolTip);
    void setUserTristate(bool tristate);
    void setWhatsThis(string whatsThis);

    void sortChildren(int column, SortOrder order = AscendingOrder);
    Handle takeChild(int row, int column = 0);
    Array<Handle> takeColumn(int column);
    Array<Handle> takeRow(int row);
}

Handle create();
Handle create(string text);
Handle create(Icon.Handle icon, string text);
Handle create(int rows, int columns = 1);
