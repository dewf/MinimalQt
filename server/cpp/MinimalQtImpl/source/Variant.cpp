#include "generated/Variant.h"
#include "VariantInternal.h"

#include "DateTimeInternal.h"
#include "ColorInternal.h"
#include "IconInternal.h"
#include "UrlInternal.h"
#include "SizeInternal.h"
#include "TransformInternal.h"

#include "LoggingInternal.h"
using namespace ::Logging;

using namespace ::Icon;
using namespace ::Size;
using namespace ::Enums;
using namespace ::Color;
using namespace ::DateTime;
using namespace ::Url;
using namespace ::Transform;

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

    Size::OwnedRef Handle_toSize(HandleRef _this) {
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

    Icon::OwnedRef Handle_toIcon(HandleRef _this) {
        if (THIS->isValid() && THIS->canConvert<QIcon>())
        {
            const auto icon = THIS->value<QIcon>();
            return ICON_HEAP_NEW(icon);
        }
        return nullptr;
    }

    Color::OwnedRef Handle_toColor(HandleRef _this) {
        if (THIS->isValid() && THIS->canConvert<QColor>())
        {
            const auto color = THIS->value<QColor>();
            return COLOR_HEAP_NEW(color);
        }
        return nullptr;
    }

    Transform::OwnedRef Handle_toTransform(HandleRef _this) {
        if (THIS->isValid() && THIS->canConvert<QTransform>())
        {
            const auto transform = THIS->value<QTransform>();
            return TRANSFORM_HEAP_NEW(transform);
        }
        return nullptr;
    }

    bool Handle_canConvert(HandleRef _this, KnownType t) {
        switch (t)
        {
        case KnownType::Bool:
            return THIS->canConvert<bool>();
        case KnownType::String:
            return THIS->canConvert<QString>();
        case KnownType::Int:
            return THIS->canConvert<int>();
        case KnownType::DateTime:
            return THIS->canConvert<QDateTime>();
        case KnownType::Size:
            return THIS->canConvert<QSize>();
        case KnownType::Icon:
            return THIS->canConvert<QIcon>();
        case KnownType::Color:
            return THIS->canConvert<QColor>();
        case KnownType::Alignment:
            return THIS->canConvert<Qt::Alignment>();
        case KnownType::Url:
            return THIS->canConvert<QUrl>();
        // convenience types =================================
        case KnownType::CheckState:
            {
                bool ok;
                const auto value = THIS->toInt(&ok);
                return ok && value >= Qt::Unchecked && value <= Qt::PartiallyChecked;
            }
        case KnownType::Transform:
            return THIS->canConvert<QTransform>();
        }
        return false;
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

    OwnedRef create(Size::HandleRef size) {
        return VARIANT_HEAP_NEW(QSIZE_VALUE(size));
    }

    OwnedRef create(Icon::HandleRef icon) {
        return VARIANT_HEAP_NEW(QICON_VALUE(icon));
    }

    OwnedRef create(Color::HandleRef color) {
        return VARIANT_HEAP_NEW(QCOLOR_VALUE(color));
    }

    OwnedRef createAlign(Flags<Alignment> align) {
        const auto qAlign = static_cast<Qt::Alignment>(align.value());
        return VARIANT_HEAP_NEW(qAlign);
    }

    OwnedRef create(Url::HandleRef url) {
        return VARIANT_HEAP_NEW(QURL_VALUE(url));
    }

    // convenience constructors ============================
    OwnedRef create(CheckState value) {
        return VARIANT_HEAP_NEW(static_cast<int>(value));
    }
    OwnedRef create(Transform::HandleRef transform) {
        const QVariant value = QTRANSFORM_VALUE(transform);
        return VARIANT_HEAP_NEW(value);
    }
}
