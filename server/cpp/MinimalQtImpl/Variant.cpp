#include "generated/Variant.h"

#include "VariantInternal.h"
#include "PaintResourcesInternal.h"

#include <QVariant>

#include "ColorInternal.h"
#include "IconInternal.h"
#include "util/convert.h"

#define WRAPPER (_this) // RefCountedWrapper<QVariant>*
#define VALUE (WRAPPER->value)

namespace Variant
{
    bool Handle_isValid(HandleRef _this) {
        return VALUE.isValid();
    }

    bool Handle_toBool(HandleRef _this) {
        return VALUE.toBool();
    }

    std::string Handle_toString2(HandleRef _this) {
        return VALUE.toString().toStdString();
    }

    int32_t Handle_toInt(HandleRef _this) {
        return VALUE.toInt();
    }

    Size Handle_toSize(HandleRef _this) {
        return toSize(VALUE.toSize());
    }

    CheckState Handle_toCheckState(HandleRef _this) {
        switch (static_cast<Qt::CheckState>(VALUE.toInt())) {
            case Qt::Unchecked:
                return CheckState::Unchecked;
            case Qt::PartiallyChecked:
                return CheckState::PartiallyChecked;
            case Qt::Checked:
                return CheckState::Checked;
            default:
                printf("Variant::Handle_toCheckState - unknown input value %d\n", VALUE.toInt());
        }
        return CheckState::Unchecked;
    }

    Icon::OwnedRef Handle_toIcon(HandleRef _this) { // throws VariantConversionFailure
        if (VALUE.isValid() && VALUE.canConvert<QIcon>()) {
            const auto icon = VALUE.value<QIcon>();
            return ICON_HEAP_NEW(icon);
        }
        // else
        throw VariantConversionFailure();
    }

    Color::OwnedRef Handle_toColor(HandleRef _this) {
        if (VALUE.isValid() && VALUE.canConvert<QColor>()) {
            const auto color = VALUE.value<QColor>();
            return new Color::__Owned { color };
        }
        // else
        throw VariantConversionFailure();
    }

    SafeReturnRef Owned_getSafeReturn(OwnedRef _this) {
        WRAPPER->addRef();
        // return "as" a different type, but not really - this is just to enforce API safety requiring us to call this method to safely return the opaques from a client interface (which is normally unsafe)
        return reinterpret_cast<SafeReturnRef>(_this);
    }

    void Owned_dispose(OwnedRef _this) {
        WRAPPER->release();
    }

    void SafeReturn_dispose(SafeReturnRef _this) {
        WRAPPER->release();
    }

    // ctors =================================================
    OwnedRef create() {
        return new __Owned(QVariant());
    }

    OwnedRef create(bool value) {
        return new __Owned(value);
    }

    OwnedRef create(const std::string& value) {
        return new __Owned(QString::fromStdString(value));
    }

    OwnedRef create(int32_t value) {
        return new __Owned(value);
    }

    OwnedRef create(CheckState value) {
        return new __Owned(static_cast<int>(value));
    }

    OwnedRef create(Size size) {
        return new __Owned(toQSize(size));
    }

    OwnedRef create(Icon::HandleRef icon) {
        return new __Owned(QICON_VALUE(icon));
    }

    OwnedRef create(Color::HandleRef color) {
        return new __Owned(color->qColor);
    }

    OwnedRef createAlign(Alignment align) {
        const auto qAlign = static_cast<Qt::Alignment>(align);
        return new __Owned(QVariant(qAlign));
    }
}
