module Brush;

import Enums;
import Image;
import Pixmap;
import Color;
import Gradient;
import Transform;

@nodispose
opaque Handle {
    Color.Owned color();

    // const QGradient * gradient() const
    // this returns a pointer to a gradient, which we can't do anything with
    // (they apparently can't be cloned)
    // [months later...] so why wouldn't a Gradient.Handle work? keep it Scoped<Gradient> for safety?
    // or because we didn't bother with a gradient ConstHandle?

    bool isOpaque();
    void setColor(Color.Handle color);
    void setColor(GlobalColor color);
    void setStyle(BrushStyle style);
    void setTexture(Pixmap.Handle pixmap);
    void setTextureImage(Image.Handle image);
    void setTransform(Transform.Handle transform);

    BrushStyle style();
    Pixmap.Owned texture();
    Image.Owned textureImage();
    Transform.Owned transform();
}

@useparenttype
opaque Owned extends Handle;

Owned create();
Owned create(BrushStyle style);
Owned create(Gradient.Handle gradient);
Owned create(Image.Handle image);
Owned create(Pixmap.Handle pixmap);
Owned create(GlobalColor color, BrushStyle style = SolidPattern);
Owned create(GlobalColor color, Pixmap.Handle pixmap);
Owned create(Color.Handle color, BrushStyle style = SolidPattern);
Owned create(Color.Handle color, Pixmap.Handle pixmap);
Owned create(Handle other);
