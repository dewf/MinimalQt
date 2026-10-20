module TextOption;

import Enums;

enum WrapMode {
    NoWrap,
    WordWrap,
    ManualWrap,
    WrapAnywhere,
    WrapAtWordBoundaryOrAnywhere
}

@nodispose
opaque Handle {
    Alignment alignment();
    void setAlignment(Alignment alignment);
}
@useparenttype
opaque Owned extends Handle;

Owned create();
Owned create(Alignment alignment);
Owned create(Handle other);
