module Drag;

import Object;
import Enums;
import Pixmap;
import Point;
import MimeData;

interface SignalHandler extends Object.SignalHandler {
    void actionChanged(DropAction action);
    void targetChanged(Object.Handle newTarget);
}

opaque Handle extends Object.Handle {

    DropAction defaultAction();
    Pixmap.Owned dragCursor(DropAction action);
    DropAction exec(DropActions supportedActions = MoveAction);
    DropAction exec(DropActions supportedActions, DropAction defaultDropAction);
    Point.Owned hotSpot();
    MimeData.Handle mimeData();
    Pixmap.Owned pixmap();
    void setDragCursor(Pixmap.Handle cursor, DropAction action);
    void setHotSpot(Point.Handle hotspot);
    void setMimeData(MimeData.Handle data);
    void setPixmap(Pixmap.Handle pixmap);
    Object.Handle source();
    DropActions supportedActions();
    Object.Handle target();

    // signals ====================
    SignalConnection connect_ActionChanged(SignalHandler handler);
    SignalConnection connect_TargetChanged(SignalHandler handler);
}

Handle create(Object.Handle dragSource);

void cancel();
