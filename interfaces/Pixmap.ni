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

    // QBitmap createHeuristicMask(bool clipTight = true) const
    // QBitmap createMaskFromColor(const QColor &maskColor, Qt::MaskMode mode = Qt::MaskInColor) const
    // TODO

    int depth();
    void detach();
    SizeF.Owned deviceIndependentSize();
    double devicePixelRatio();
    void fill(Option<Color.Handle> color); // not sure about this yet - not that Option<> helps - but we don't have a way of specifying constructor defaults (eg Qt::white) [... that will actually build]
    bool hasAlpha();
    bool hasAlphaChannel();
    int height();
    bool isNull();
    bool isQBitmap();
    bool load(string fileName, Option<string> format, ImageConversionFlags flags_ = AutoColor);
    bool loadFromData(Buffer<byte> data, Option<string> format, ImageConversionFlags flags_ = AutoColor);
    bool loadFromData(Array<byte> data, Option<string> format, ImageConversionFlags flags_ = AutoColor);

    // QBitmap mask() const
    // TODO

    Rect.Owned rect();
    bool save(string fileName, Option<string> format, int quality = -1);

    // bool save(QIODevice *device, const char *format = nullptr, int quality = -1) const
    // TODO

    Owned scaled(Size.Handle size, AspectRatioMode aspectRatioMode = IgnoreAspectRatio, TransformationMode transformMode = FastTransformation);
    Owned scaled(int width, int height, AspectRatioMode aspectRatioMode = IgnoreAspectRatio, TransformationMode transformMode = FastTransformation);
    Owned scaledToHeight(int height, TransformationMode mode = FastTransformation);
    Owned scaledToWidth(int width, TransformationMode mode = FastTransformation);
    void scroll(int dx, int dy, Rect.Handle rect, Region.Handle outPtr_exposed = null); // OUTPUT parameter
    void scroll(int dx, int dy, int x, int y, int width, int height, Region.Handle outPtr_exposed = null); // same
    void setDevicePixelRatio(double scaleFactor);

    // void setMask(const QBitmap &mask)
    // TODO

    Size.Owned size();
    void swap(Handle other);
    Image.Owned toImage();
    Owned transformed(Transform.Handle transform, TransformationMode mode = FastTransformation);
    int width();
}

opaque Owned extends Handle;

Owned create(Array<byte> xpm);
Owned create(int width, int height);
Owned create(string filename, Option<string> format, ImageConversionFlags flags_ = AutoColor);
Owned create(Size.Handle size);
Owned create(Handle other);

// static methods:
int defaultDepth();
Owned fromImage(Image.Handle image, ImageConversionFlags flags_ = AutoColor);
Transform.Owned trueMatrix(Transform.Handle matrix, int width, int height);

// QPixmap	fromImageReader(QImageReader *imageReader, Qt::ImageConversionFlags flags = Qt::AutoColor)
// TODO
