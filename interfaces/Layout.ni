module Layout;

import Object;
import Margins;
import Size;
import Rect;
import Enums;
import LayoutItem;
import Widget;

@methodprefix("sig_")
interface SignalHandler extends Object.SignalHandler;
// none of our own

enum SizeConstraint {
    SetDefaultConstraint,
    SetNoConstraint,
    SetMinimumSize,
    SetFixedSize,
    SetMaximumSize,
    SetMinAndMaxSize
}

@nodispose
opaque Handle extends Object.Handle {
    // interfaces =============================
    LayoutItem.Handle asLayoutItem();

    // methods and properties =================
    bool activate();
    void addItem(LayoutItem.Handle item);
    void addWidget(Widget.Handle w);
    Margins.Owned contentsMargins();
    Rect.Owned contentsRect();
    int count();
    Tuple<int,int,int,int> getContentsMargins(); // getter for 4-argument setter below
    SizeConstraint horizontalSizeConstraint();
    int indexOf(LayoutItem.Handle layoutItem);
    int indexOf(Widget.Handle widget);
    bool isEnabled();
    LayoutItem.Handle itemAt(int index);
    Widget.Handle menuBar();
    Widget.Handle parentWidget();
    void removeItem(LayoutItem.Handle item);
    void removeWidget(Widget.Handle widget);
    LayoutItem.Handle replaceWidget(Widget.Handle from, Widget.Handle to, FindChildOptions options_ = FindChildrenRecursively);
    bool setAlignment(Widget.Handle w, Alignment alignment);
    bool setAlignment(Handle l, Alignment alignment);
    void setContentsMargins(Margins.Handle margins);
    void setContentsMargins(int left, int top, int right, int bottom);
    void setEnabled(bool enable);
    void setHorizontalSizeConstraint(SizeConstraint constraint);
    void setMenuBar(Widget.Handle widget);
    void setSizeConstraint(SizeConstraint sizeConstraint);
    void setSpacing(int spacing);
    void setVerticalSizeConstraint(SizeConstraint constraint);
    SizeConstraint getSizeConstraint();
    int spacing();
    LayoutItem.Handle takeAt(int index);
    void unsetContentsMargins();
    void update();
    SizeConstraint verticalSizeConstraint();
}

// no create because abstract

Size.Owned closestAcceptableSize(Widget.Handle widget, Size.Handle size);

// extension methods below,
// to break circular references between Widget, Layout, LayoutItem

// Widget methods:
Handle ext_Widget_layout(Widget.Handle this_);
void ext_Widget_setLayout(Widget.Handle this_, Handle layout);

// LayoutItem methods:
Handle ext_LayoutItem_layout(LayoutItem.Handle this_);
