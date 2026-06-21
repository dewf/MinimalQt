module SafeReturn;

import ModelIndex;
import Variant;
import Size;

@nodispose
opaque ModelIndexReturn {
    void setResult(ModelIndex.Handle value);
}

@nodispose
opaque VariantReturn {
    void setResult(Variant.Handle value);
}

@nodispose
opaque SizeReturn {
    void setResult(Size.Handle value);
}
