#include "generated/Variant.h"

#include "VariantInternal.h"
#include "PaintResourcesInternal.h"

#include <QVariant>

#include "ColorInternal.h"
#include "util/convert.h"

#define WRAPPER (AS_QVARIANT_PTR(_this)) // RefCountedWrapper<QVariant>*
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

    void Owned_markForReturn(OwnedRef _this) {
        WRAPPER->addRef();
    }

    void Owned_dispose(OwnedRef _this) {
        WRAPPER->release();
    }

    // ctors =================================================
    OwnedRef create() {
        return VARIANT_HEAP_NEW();
    }

    OwnedRef create(bool value) {
        return VARIANT_HEAP_NEW(value);
    }

    OwnedRef create(const std::string& value) {
        return VARIANT_HEAP_NEW(QString::fromStdString(value));
    }

    OwnedRef create(int32_t value) {
        return VARIANT_HEAP_NEW(value);
    }

    OwnedRef create(CheckState value) {
        return VARIANT_HEAP_NEW(static_cast<int>(value));
    }

    OwnedRef create(Size size) {
        return VARIANT_HEAP_NEW(toQSize(size));
    }

    OwnedRef create(Icon::HandleRef icon) {
        return VARIANT_HEAP_NEW(QICON_VALUE(icon));
    }

    OwnedRef create(Color::HandleRef color) {
        return VARIANT_HEAP_NEW(color->qColor);
    }

    OwnedRef createAlign(Alignment align) {
        return VARIANT_HEAP_NEW(static_cast<Qt::Alignment>(align));
    }
}
