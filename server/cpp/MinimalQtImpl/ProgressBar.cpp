#include "generated/ProgressBar.h"
#include "ProgressBarInternal.h"

#include "ObjectInternal.h"
#include "WidgetInternal.h"
#include "util/convert.h"

#define THIS (reinterpret_cast<QProgressBar*>(_this))

namespace ProgressBar
{
    Alignment Handle_getAlignment(HandleRef _this) {
        return Alignment(THIS->alignment());
    }

    std::string Handle_format(HandleRef _this) {
        return THIS->format().toStdString();
    }

    bool Handle_invertedAppearance(HandleRef _this) {
        return THIS->invertedAppearance();
    }

    bool Handle_isTextVisible(HandleRef _this) {
        return THIS->isTextVisible();
    }

    int32_t Handle_maximum(HandleRef _this) {
        return THIS->maximum();
    }

    int32_t Handle_minimum(HandleRef _this) {
        return THIS->minimum();
    }

    Orientation Handle_getOrientation(HandleRef _this) {
        return static_cast<Orientation>(THIS->orientation());
    }

    void Handle_resetFormat(HandleRef _this) {
        return THIS->resetFormat();
    }

    void Handle_setAlignment(HandleRef _this, Alignment align) {
        THIS->setAlignment(static_cast<Qt::Alignment>(align.value));
    }

    void Handle_setFormat(HandleRef _this, const std::string& format) {
        THIS->setFormat(QString::fromStdString(format));
    }

    void Handle_setInvertedAppearance(HandleRef _this, bool invert) {
        THIS->setInvertedAppearance(invert);
    }

    void Handle_setTextDirection(HandleRef _this, Direction direction) {
        THIS->setTextDirection(static_cast<QProgressBar::Direction>(direction));
    }

    void Handle_setTextVisible(HandleRef _this, bool visible) {
        THIS->setTextVisible(visible);
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    Direction Handle_textDirection(HandleRef _this) {
        return static_cast<Direction>(THIS->textDirection());
    }

    int32_t Handle_value(HandleRef _this) {
        return THIS->value();
    }

    void Handle_reset(HandleRef _this) {
        THIS->reset();
    }

    void Handle_setMaximum(HandleRef _this, int32_t value) {
        THIS->setMaximum(value);
    }

    void Handle_setMinimum(HandleRef _this, int32_t value) {
        THIS->setMinimum(value);
    }

    void Handle_setOrientation(HandleRef _this, Orientation orient) {
        THIS->setOrientation(static_cast<Qt::Orientation>(orient));
    }

    void Handle_setRange(HandleRef _this, int32_t min, int32_t max) {
        THIS->setRange(min, max);
    }

    void Handle_setValue(HandleRef _this, int32_t value) {
        THIS->setValue(value);
    }

    SignalConnectionRef Handle_connect_ValueChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QProgressBar::valueChanged, [handler](int value) {
            handler->valueChanged(value);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QProgressBar(AS_QWIDGET_PTR(parent)));
    }
}
