module Variant;

import Icon;
import Size;
import Enums;
import Color;
import DateTime;
import Url;
import Transform;

exception VariantConversionFailure; // no message for now, we need to figure out how to integrate with std::exception and C# Exception cleanly

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

    Icon.Owned toIcon() throws VariantConversionFailure;
    Color.Owned toColor() throws VariantConversionFailure;
    Transform.Owned toTransform() throws VariantConversionFailure;
}
opaque Owned extends Handle;

Owned create();
Owned create(Handle other);
Owned create(bool value);
Owned create(string value);
Owned create(int value);
Owned create(DateTime.Handle value);
Owned create(CheckState value); // convenience for int 0/1/2
Owned create(Size.Handle size);
Owned create(Icon.Handle icon);
Owned create(Color.Handle color);
Owned createAlign(Alignment align); // different name because just an int32_t typedef
Owned create(Url.Handle url);

// convenience constructors:
Owned create(Transform.Handle transform);
