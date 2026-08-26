module ListView;

import Object;
import Size;
import Enums;
import Icon;
import AbstractListModel;
import ModelIndex;
import AbstractItemView;
import Widget;

@methodprefix("sig_")
interface SignalHandler extends AbstractItemView.SignalHandler {
    void indexesMoved(ModelIndex.List indexes);
}

enum Movement {
    Static,
    Free,
    Snap
}

enum Flow {
    LeftToRight,
    TopToBottom
}

enum ResizeMode {
    Fixed,
    Adjust
}

enum LayoutMode {
    SinglePass,
    Batched
}

enum ViewMode {
    ListMode,
    IconMode
}

opaque Handle extends AbstractItemView.Handle {

    int batchSize();
    void clearPropertyFlags();
    Flow getFlow();
    Size.Owned gridSize();
    bool isRowHidden(int row);
    bool isSelectionRectVisible();
    bool isWrapping();
    Alignment itemAlignment();
    LayoutMode getLayoutMode();
    int modelColumn();
    Movement getMovement();
    ResizeMode getResizeMode();
    void setBatchSize(int batchSize);
    void setFlow(Flow flow);
    void setGridSize(Size.Handle size);
    void setItemAlignment(Alignment alignment);
    void setLayoutMode(LayoutMode mode);
    void setModelColumn(int column);
    void setMovement(Movement movement);
    void setResizeMode(ResizeMode mode);
    void setRowHidden(int row, bool hide);
    void setSelectionRectVisible(bool show);
    void setSpacing(int space);
    void setUniformItemSizes(bool enable);
    void setViewMode(ViewMode mode);
    void setWordWrap(bool on);
    void setWrapping(bool enable);
    int spacing();
    bool uniformItemSizes();
    ViewMode getViewMode();
    bool wordWrap();

    // signals ================
    SignalConnection connect_IndexesMoved(SignalHandler handler);
}

Handle create(Widget.Handle parent = null);
