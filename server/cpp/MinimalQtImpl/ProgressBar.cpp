#include "generated/ProgressBar.h"
#include "ProgressBarInternal.h"

#include "ObjectInternal.h"
#include "util/convert.h"

#define THIS (reinterpret_cast<QProgressBar*>(_this))

namespace ProgressBar
{
    void Handle_setAlignment(HandleRef _this, Alignment align) {
        THIS->setAlignment(static_cast<Qt::Alignment>(align));
    }

    void Handle_setFormat(HandleRef _this, const std::string& format) {
        THIS->setFormat(QString::fromStdString(format));
    }

    void Handle_setInvertedAppearance(HandleRef _this, bool invert) {
        THIS->setInvertedAppearance(invert);
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

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    void Handle_setTextDirection(HandleRef _this, Direction direction) {
        THIS->setTextDirection(static_cast<QProgressBar::Direction>(direction));
    }

    void Handle_setTextVisible(HandleRef _this, bool visible) {
        THIS->setTextVisible(visible);
    }

    void Handle_setValue(HandleRef _this, int32_t value) {
        THIS->setValue(value);
    }

    void Handle_setRange(HandleRef _this, int32_t min, int32_t max) {
        THIS->setRange(min, max);
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

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QProgressBar());
    }
}
