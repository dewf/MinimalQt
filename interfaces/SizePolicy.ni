module SizePolicy;

import Enums;

@withflags(ControlTypes)
enum ControlType {
    DefaultType      = 0x00000001,
    ButtonBox        = 0x00000002,
    CheckBox         = 0x00000004,
    ComboBox         = 0x00000008,
    Frame            = 0x00000010,
    GroupBox         = 0x00000020,
    Label            = 0x00000040,
    Line             = 0x00000080,
    LineEdit         = 0x00000100,
    PushButton       = 0x00000200,
    RadioButton      = 0x00000400,
    Slider           = 0x00000800,
    SpinBox          = 0x00001000,
    TabWidget        = 0x00002000,
    ToolButton       = 0x00004000
}

flags Policy {
    // in Qt these are defined separately as "PolicyFlag"
    // but our flags handling is still primitive so we just put them here
    GrowFlag = 1,
    ExpandFlag = 2,
    ShrinkFlag = 4,
    IgnoreFlag = 8,

    // actual Policy flags:
    Fixed = 0,
    Minimum = GrowFlag,
    Maximum = ShrinkFlag,
    Preferred = GrowFlag | ShrinkFlag,
    MinimumExpanding = GrowFlag | ExpandFlag,
    Expanding = GrowFlag | ShrinkFlag | ExpandFlag,
    Ignored = ShrinkFlag | GrowFlag | IgnoreFlag
}

@nodispose
opaque Handle {
    ControlType getControlType();
    Orientations expandingDirections();
    bool hasHeightForWidth();
    bool hasWidthForHeight();
    Policy horizontalPolicy();
    int horizontalStretch();
    bool retainSizeWhenHidden();
    void setControlType(ControlType type_);
    void setHeightForWidth(bool dependent);
    void setHorizontalPolicy(Policy policy);
    void setHorizontalStretch(int stretchFactor);
    void setRetainSizeWhenHidden(bool retainSize);
    void setVerticalPolicy(Policy policy);
    void setVerticalStretch(int stretchFactor);
    void setWidthForHeight(bool dependent);
    void transpose();
    Owned transposed();
    Policy verticalPolicy();
    int verticalStretch();
}
@useparenttype
opaque Owned extends Handle;

Owned create();
Owned create(Policy horizontal, Policy vertical, ControlType type_ = DefaultType);
