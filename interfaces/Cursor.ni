module Cursor;

import Bitmap;
import Pixmap;
import Enums;
import Screen;
import Point;

@nodispose
opaque Handle {
    Bitmap.Owned bitmap();
    Point.Owned hotSpot();
    Bitmap.Owned mask();
    Pixmap.Owned pixmap();
    void setShape(CursorShape shape);
    CursorShape shape();
}
@useparenttype
opaque Owned extends Handle;

// ctors =======================

Owned create();
Owned create(CursorShape shape);
Owned create(Pixmap.Handle pixmap, int hotX = -1, int hotY = -1);
Owned create(Bitmap.Handle bitmap, Bitmap.Handle mask, int hotX = -1, int hotY = -1);
Owned create(Handle other);

// static methods ==============

Point.Owned pos();
Point.Owned pos(Screen.Handle screen);
void setPos(int x, int y);
void setPos(Screen.Handle screen, int x, int y);
void setPos(Point.Handle p);
void setPos(Screen.Handle screen, Point.Handle p);
