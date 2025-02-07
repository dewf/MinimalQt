#include "generated/Variant.h"
#include "VariantInternal.h"

#include "DateTimeInternal.h"
#include "ColorInternal.h"
#include "IconInternal.h"
#include "UrlInternal.h"
#include "Size2Internal.h"

#include "LoggingInternal.h"
using namespace ::Logging;

#include "util/convert.h"

using namespace ::Icon;
using namespace ::Common;
using namespace ::Size2;
using namespace ::Enums;
using namespace ::Color;
using namespace ::DateTime;
using namespace ::Url;

#define THIS (AS_QVARIANT_PTR(_this))

namespace Variant
{
    bool Handle_isValid(HandleRef _this) {
        return THIS->isValid();
    }

    bool Handle_toBool(HandleRef _this) {
        return THIS->toBool();
    }

    std::string Handle_toString2(HandleRef _this) {
        return THIS->toString().toStdString();
    }

    int32_t Handle_toInt(HandleRef _this) {
        return THIS->toInt();
    }

    DateTime::OwnedRef Handle_toDateTime(HandleRef _this) {
        return DATETIME_HEAP_NEW(THIS->toDateTime());
    }

    Size2::OwnedRef Handle_toSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->toSize());
    }

    CheckState Handle_toCheckState(HandleRef _this) {
        const auto intValue = THIS->toInt();
        switch (static_cast<Qt::CheckState>(intValue)) {
            case Qt::Unchecked:
                return CheckState::Unchecked;
            case Qt::PartiallyChecked:
                return CheckState::PartiallyChecked;
            case Qt::Checked:
                return CheckState::Checked;
            default:
                clientLog(LogLevel::Warning, "Variant::Handle_toCheckState - unknown input value %d", intValue);
        }
        return CheckState::Unchecked;
    }

    Icon::OwnedRef Handle_toIcon(HandleRef _this) { // throws VariantConversionFailure
        if (THIS->isValid() && THIS->canConvert<QIcon>()) {
            const auto icon = THIS->value<QIcon>();
            return ICON_HEAP_NEW(icon);
        }
        // else
        throw VariantConversionFailure();
    }

    Color::OwnedRef Handle_toColor(HandleRef _this) {
        if (THIS->isValid() && THIS->canConvert<QColor>()) {
            const auto color = THIS->value<QColor>();
            return COLOR_HEAP_NEW(color);
        }
        // else
        throw VariantConversionFailure();
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    // ctors =================================================
    OwnedRef create() {
        return VARIANT_HEAP_NEW();
    }

    OwnedRef create(HandleRef other) {
        return VARIANT_HEAP_NEW(QVARIANT_VALUE(other));
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

    OwnedRef create(DateTime::HandleRef value) {
        return VARIANT_HEAP_NEW(QDATETIME_VALUE(value));
    }

    OwnedRef create(CheckState value) {
        return VARIANT_HEAP_NEW(static_cast<int>(value));
    }

    OwnedRef create(Size2::HandleRef size) {
        return VARIANT_HEAP_NEW(QSIZE_VALUE(size));
    }

    OwnedRef create(Icon::HandleRef icon) {
        return VARIANT_HEAP_NEW(QICON_VALUE(icon));
    }

    OwnedRef create(Color::HandleRef color) {
        return VARIANT_HEAP_NEW(QCOLOR_VALUE(color));
    }

    OwnedRef createAlign(Alignment align) {
        const auto qAlign = static_cast<Qt::Alignment>(align.value);
        return VARIANT_HEAP_NEW(qAlign);
    }

    OwnedRef create(Url::HandleRef url) {
        return VARIANT_HEAP_NEW(QURL_VALUE(url));
    }
}
