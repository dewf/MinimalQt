module Variant;

import Icon;
import Size;
import Enums;
import Color;
import DateTime;
import Url;
import Transform;

enum KnownType {
    Bool,
    String,
    Int,
    DateTime,
    Size,
    Icon,
    Color,
    Alignment,
    Url,

    // convenience ones, not sure if appropriate
    CheckState,
    Transform
}

@nodispose
opaque Handle {
    bool isValid();

    bool toBool();
    string toString2(); // toString() is a C# thing
    int toInt();
    DateTime.Owned toDateTime();
    Size.Owned toSize();

    // convenience function, special values for toInt()
    CheckState toCheckState();

    // below can return null!
    Icon.Owned toIcon();
    Color.Owned toColor();
    Transform.Owned toTransform();

    bool canConvert(KnownType t);
}
opaque Owned extends Handle;

Owned create();
Owned create(Handle other);
Owned create(bool value);
Owned create(string value);
Owned create(int value);
Owned create(DateTime.Handle value);
Owned create(Size.Handle size);
Owned create(Icon.Handle icon);
Owned create(Color.Handle color);
Owned createAlign(Alignment align); // different name because just an int32_t typedef
Owned create(Url.Handle url);

// convenience constructors:
Owned create(CheckState value); // convenience for int 0/1/2
Owned create(Transform.Handle transform);
