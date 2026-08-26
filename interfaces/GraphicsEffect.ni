module GraphicsEffect;

import Object;
import RectF;

@methodprefix("sig_")
interface SignalHandler {
    void enabledChanged(bool enabled);
}

@withflags(ChangeFlags)
enum ChangeFlag {
    SourceAttached = 0x1,
    SourceDetached = 0x2,
    SourceBoundingRectChanged = 0x4,
    SourceInvalidated = 0x8
}

enum PixmapPadMode {
    NoPad,
    PadToTransparentBorder,
    PadToEffectiveBoundingRect
}

@nodispose
opaque Handle extends Object.Handle {
    RectF.Owned boundingRect();
    RectF.Owned boundingRectFor(RectF.Handle rect);
    bool isEnabled();

    void setEnabled(bool enable);
    void update();

    // signals ========================
    SignalConnection connect_EnabledChanged(SignalHandler handler);
}
