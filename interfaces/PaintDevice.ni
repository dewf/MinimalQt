module PaintDevice;

@nodispose
opaque Handle {
    int colorCount();
    int depth();
    double devicePixelRatio();
    double devicePixelRatioF();
    int height();
    int heightMM();
    int logicalDpiX();
    int logicalDpiY();

    // virtual QPaintEngine * paintEngine() const = 0

    bool paintingActive();
    int physicalDpiX();
    int physicalDpiY();
    int width();
    int widthMM();
}

// no Owned or creation methods, other things inherit from this (but IMO it's more like an interface)
