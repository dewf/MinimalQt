module LayoutItem;

import Enums;
import Size;
import Rect;
import SizePolicy;
import Widget;

// note, treating this like an interface, nobody will inherit from it directly
// doing a similar thing with PaintDevice

@nodispose          // we can't create these directly, and they're not value types, so I don't think any .dispose() method makes sense
opaque Handle {
    Alignment alignment();
    SizePolicy.ControlTypes controlTypes();
    Orientations expandingDirections();
    Rect.Owned geometry();
    bool hasHeightForWidth();
    int heightForWidth(int width);
    void invalidate();
    bool isEmpty();

    // moved to extension method in Layout.ni
    // LayoutHandle layout();

    Size.Owned maximumSize();
    int minimumHeightForWidth(int width);
    Size.Owned minimumSize();
    void setAlignment(Alignment alignment);
    void setGeometry(Rect.Handle r);
    Size.Owned sizeHint();

    // virtual QSpacerItem * spacerItem()
    // TODO

    Widget.Handle widget();
}

// pretty sure these are abstract, so no ctors here
