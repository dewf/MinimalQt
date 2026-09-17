module Bitmap;

import Pixmap;
import Size;
import Transform;
import Variant;
import Image;
import Enums;
import Color;

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

// Pixmap extension methods:
Owned ext_Pixmap_createHeuristicMask(Pixmap.Handle this_, bool clipTight = true);
Owned ext_Pixmap_createMaskFromColor(Pixmap.Handle this_, Color.Handle maskColor, MaskMode mode = MaskInColor);
Owned ext_Pixmap_mask(Pixmap.Handle this_);
void ext_Pixmap_setMask(Pixmap.Handle this_, Handle mask);
