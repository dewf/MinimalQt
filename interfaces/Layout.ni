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
    Tuple<int,int,int,int> getContentsMargins();
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
    void setMenuBar(Widget.Handle widget);
    void setSizeConstraint(SizeConstraint sizeConstraint);
    void setSpacing(int spacing);
    SizeConstraint getSizeConstraint();
    int spacing();
    LayoutItem.Handle takeAt(int index);
    void unsetContentsMargins();
    void update();
}

// no create because abstract

Size.Owned closestAcceptableSize(Widget.Handle widget, Size.Handle size);

// extension methods below,
// to break circular references between Widget, Layout, LayoutItem

extmethods Widget.Handle {
    Handle layout();
    void setLayout(Handle layout);
}

extmethods LayoutItem.Handle {
    Handle layout();
    // Widget.Handle widget(); // we could also have put this in Widget.ni, but it otherwise has no layout/layoutitem dependence. YOLO
}
