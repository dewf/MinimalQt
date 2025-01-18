module FormLayout;

import Enums;
import Layout;
import Widget;
import LayoutItem;

enum FieldGrowthPolicy {
    FieldsStayAtSizeHint,
    ExpandingFieldsGrow,
    AllNonFixedFieldsGrow
}

enum RowWrapPolicy {
    DontWrapRows,
    WrapLongRows,
    WrapAllRows
}

enum ItemRole {
    LabelRole = 0,
    FieldRole = 1,
    SpanningRole = 2
}

struct TakeRowResult {
    LayoutItem.Handle labelItem;
    LayoutItem.Handle fieldItem;
}

struct PositionResult {
    int row;
    ItemRole role;
}

interface SignalHandler extends Layout.SignalHandler;
// no signals

opaque Handle extends Layout.Handle {
    void addRow(Widget.Handle label, Widget.Handle field);
    void addRow(Layout.Handle layout);
    void addRow(Widget.Handle widget);
    void addRow(Widget.Handle label, Layout.Handle field);
    void addRow(string labelText, Layout.Handle field);
    void addRow(string labelText, Widget.Handle field);
    FieldGrowthPolicy getFieldGrowthPolicy();
    Alignment formAlignment();
    PositionResult getItemPosition(int index);
    PositionResult getLayoutPosition(Layout.Handle layout);
    PositionResult getWidgetPosition(Widget.Handle widget);
    int horizontalSpacing();
    void insertRow(int row, Widget.Handle label, Widget.Handle field);
    void insertRow(int row, Layout.Handle layout);
    void insertRow(int row, Widget.Handle widget);
    void insertRow(int row, Widget.Handle label, Layout.Handle field);
    void insertRow(int row, string labelText, Layout.Handle field);
    void insertRow(int row, string labelText, Widget.Handle field);
    bool isRowVisible(int row);
    bool isRowVisible(Layout.Handle layout);
    bool isRowVisible(Widget.Handle widget);
    LayoutItem.Handle itemAt(int row, ItemRole role);
    Alignment labelAlignment();
    Widget.Handle labelForField(Widget.Handle field);
    Widget.Handle labelForField(Layout.Handle field);
    void removeRow(int row);
    void removeRow(Layout.Handle layout);
    void removeRow(Widget.Handle widget);
    int rowCount();
    RowWrapPolicy rowWrapPolicy();
    void setFieldGrowthPolicy(FieldGrowthPolicy policy);
    void setFormAlignment(Alignment alignment);
    void setHorizontalSpacing(int spacing);
    void setItem(int row, ItemRole role, LayoutItem.Handle item);
    void setLabelAlignment(Alignment alignment);
    void setLayout(int row, ItemRole role, Layout.Handle layout);
    void setRowVisible(int row, bool on);
    void setRowVisible(Layout.Handle layout, bool on);
    void setRowVisible(Widget.Handle widget, bool on);
    void setRowWrapPolicy(RowWrapPolicy policy);
    void setVerticalSpacing(int spacing);
    void setWidget(int row, ItemRole role, Widget.Handle widget);
    TakeRowResult takeRow(int row);
    TakeRowResult takeRow(Layout.Handle layout);
    TakeRowResult takeRow(Widget.Handle widget);
    int verticalSpacing();
}

Handle create(Widget.Handle parent = null);
