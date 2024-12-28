#include "generated/Variant.h"

#include "VariantInternal.h"
#include "PaintResourcesInternal.h"

#include <QVariant>

#include "ColorInternal.h"
#include "util/convert.h"

#define THIS ((QVariant*)_this)

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

    Size Handle_toSize(HandleRef _this) {
        return toSize(THIS->toSize());
    }

    CheckState Handle_toCheckState(HandleRef _this) {
        switch ((Qt::CheckState)THIS->toInt()) {
            case Qt::Unchecked:
                return CheckState::Unchecked;
            case Qt::PartiallyChecked:
                return CheckState::PartiallyChecked;
            case Qt::Checked:
                return CheckState::Checked;
            default:
                printf("Variant::Handle_toCheckState - unknown input value %d\n", THIS->toInt());
        }
        return CheckState::Unchecked;
    }

    Icon::OwnedRef Handle_toIcon(HandleRef _this) { // throws VariantConversionFailure
        if (THIS->canConvert<QIcon>()) {
            return ICON_HEAP_NEW(THIS->value<QIcon>());
        }
        // else
        throw VariantConversionFailure();
    }

    Color::OwnedRef Handle_toColor(HandleRef _this) {
        if (THIS->isValid() && THIS->canConvert<QColor>()) {
            auto value = THIS->value<QColor>();
            return new Color::__Owned { value };
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

    // deferred stuff ========================================
    class FromDeferredMatcher : public Deferred::Matcher {
    private:
        QVariant &variant;
    public:
        explicit FromDeferredMatcher(QVariant &variant) : variant(variant) {}
        void onEmpty(const Deferred::Empty *value) override {
            variant = QVariant();
        }
    };

    QVariant fromDeferred(const std::shared_ptr<Deferred::Base>& deferred) {
        QVariant ret;
        FromDeferredMatcher matcher(ret);
        deferred->match(&matcher);
        return ret;
    }
}
