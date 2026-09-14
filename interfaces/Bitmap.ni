module Bitmap;

import Pixmap;
import Size;
import Transform;
import Variant;
import Image;
import Enums;

@nodispose
@dlang_withoverloads(Pixmap.Handle, swap)
@dlang_withoverloads(Pixmap.Handle, transformed)
opaque Handle extends Pixmap.Handle {
    void clear();
    void swap(Handle other);
    Owned transformed(Transform.Handle matrix);

    Variant.Owned operator_QVariant(); // lolwut
}

opaque Owned extends Handle;

Owned create();
Owned create(Size.Handle size);
Owned create(string fileName, Option<string> format = none);
Owned create(int width, int height);

Owned fromData(Size.Handle size, Array<byte> bits, Image.Format monoFormat = MonoLSB);
Owned fromImage(Image.Handle image, ImageConversionFlags flags_ = AutoColor);
Owned fromPixmap(Pixmap.Handle pixmap);
