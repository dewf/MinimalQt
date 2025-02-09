module Layout;

import Object;
import Margins;
import Size;
import Rect;
import Enums;
import LayoutItem;

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

fwdopaque WidgetHandle = Widget.Handle;

@nodispose
opaque Handle extends Object.Handle {
    // interfaces =============================
    LayoutItem.Handle asLayoutItem();

    // methods and properties =================
    bool activate();
    void addItem(LayoutItem.Handle item);
    void addWidget(WidgetHandle w);
    Margins.Owned contentsMargins();
    Rect.Owned contentsRect();
    int count();
    Tuple<int,int,int,int> getContentsMargins();
    int indexOf(LayoutItem.Handle layoutItem);
    int indexOf(WidgetHandle widget);
    bool isEnabled();
    LayoutItem.Handle itemAt(int index);
    WidgetHandle menuBar();
    WidgetHandle parentWidget();
    void removeItem(LayoutItem.Handle item);
    void removeWidget(WidgetHandle widget);
    LayoutItem.Handle replaceWidget(WidgetHandle from, WidgetHandle to, FindChildOptions options_ = FindChildrenRecursively);
    bool setAlignment(WidgetHandle w, Alignment alignment);
    bool setAlignment(Handle l, Alignment alignment);
    void setContentsMargins(Margins.Handle margins);
    void setContentsMargins(int left, int top, int right, int bottom);
    void setEnabled(bool enable);
    void setMenuBar(WidgetHandle widget);
    void setSizeConstraint(SizeConstraint sizeConstraint);
    void setSpacing(int spacing);
    SizeConstraint getSizeConstraint();
    int spacing();
    LayoutItem.Handle takeAt(int index);
    void unsetContentsMargins();
    void update();
}

// no create because abstract

Size.Owned closestAcceptableSize(WidgetHandle widget, Size.Handle size);
