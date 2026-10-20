module Pixmap;

import PaintDevice;
import Size;
import SizeF;
import Rect;
import Enums;
import Image;
import Color;
import Region;
import Transform;

@nodispose
opaque Handle {         // we don't directly inherit from PaintDevice, because that's conceptually more of an interface, and it's nice to get the QValueType<T> behavior on the C# side
    // interfaces:
    PaintDevice.Handle asPaintDevice();

    // properties + methods:

    int64 cacheKey();
    bool convertFromImage(Image.Handle image, ImageConversionFlags flags_ = AutoColor);
    Owned copy(Rect.Handle rect = null);
    Owned copy(int x, int y, int width, int height);

    // implemented as extension methods in Bitmap:
    // Bitmap.Owned createHeuristicMask(bool clipTight = true);
    // Bitmap.Owned createMaskFromColor(Color.Handle maskColor, MaskMode mode = MaskInColor);

    int depth();
    void detach();
    SizeF.Owned deviceIndependentSize();
    double devicePixelRatio();

    // below is actually: void fill(const QColor &color = Qt::white)
    // but we don't have a way of expressing that yet (Qt::white is a GlobalColor, which has an implicit constructor or whatever)
    void fill(Color.Handle color = null);

    bool hasAlpha();
    bool hasAlphaChannel();
    int height();
    bool isNull();
    bool isQBitmap();
    bool load(string fileName, Option<string> format = none, ImageConversionFlags flags_ = AutoColor);
    bool loadFromData(Buffer<byte> data, Option<string> format = none, ImageConversionFlags flags_ = AutoColor);
    bool loadFromData(Array<byte> data, Option<string> format = none, ImageConversionFlags flags_ = AutoColor);

    // implemented as extension method in Bitmap:
    // Bitmap.Owned mask();

    Rect.Owned rect();
    bool save(string fileName, Option<string> format = none, int quality = -1);

    // bool save(QIODevice *device, const char *format = nullptr, int quality = -1) const
    // TODO

    Owned scaled(Size.Handle size, AspectRatioMode aspectRatioMode = IgnoreAspectRatio, TransformationMode transformMode = FastTransformation);
    Owned scaled(int width, int height, AspectRatioMode aspectRatioMode = IgnoreAspectRatio, TransformationMode transformMode = FastTransformation);
    Owned scaledToHeight(int height, TransformationMode mode = FastTransformation);
    Owned scaledToWidth(int width, TransformationMode mode = FastTransformation);
    void scroll(int dx, int dy, Rect.Handle rect, Region.Handle outPtr_exposed = null); // OUTPUT parameter
    void scroll(int dx, int dy, int x, int y, int width, int height, Region.Handle outPtr_exposed = null); // same
    void setDevicePixelRatio(double scaleFactor);

    // implemented as extension method in Bitmap:
    // void setMask(Bitmap.Handle mask);

    Size.Owned size();
    void swap(Handle other);
    Image.Owned toImage();
    Owned transformed(Transform.Handle transform, TransformationMode mode = FastTransformation);
    int width();
}
@useparenttype
opaque Owned extends Handle;

Owned create(Array<byte> xpm);
Owned create(int width, int height);
Owned create(string filename, Option<string> format = none, ImageConversionFlags flags_ = AutoColor);
Owned create(Size.Handle size);
Owned create(Handle other);

// static methods:
int defaultDepth();
Owned fromImage(Image.Handle image, ImageConversionFlags flags_ = AutoColor);
Transform.Owned trueMatrix(Transform.Handle matrix, int width, int height);

// QPixmap	fromImageReader(QImageReader *imageReader, Qt::ImageConversionFlags flags = Qt::AutoColor)
// TODO
