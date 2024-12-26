#include "generated/ProgressBar.h"
#include "ProgressBarInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define PROGRESS_THIS (WRAPPER->getActual())

namespace ProgressBar
{
    void Handle_setAlignment(HandleRef _this, Alignment align) {
        PROGRESS_THIS->setAlignment(static_cast<Qt::Alignment>(align));
    }

    void Handle_setFormat(HandleRef _this, const std::string& format) {
        PROGRESS_THIS->setFormat(QString::fromStdString(format));
    }

    void Handle_setInvertedAppearance(HandleRef _this, bool invert) {
        PROGRESS_THIS->setInvertedAppearance(invert);
    }

    void Handle_setMaximum(HandleRef _this, int32_t value) {
        PROGRESS_THIS->setMaximum(value);
    }

    void Handle_setMinimum(HandleRef _this, int32_t value) {
        PROGRESS_THIS->setMinimum(value);
    }

    void Handle_setOrientation(HandleRef _this, Orientation orient) {
        PROGRESS_THIS->setOrientation(static_cast<Qt::Orientation>(orient));
    }

    std::string Handle_text(HandleRef _this) {
        return PROGRESS_THIS->text().toStdString();
    }

    void Handle_setTextDirection(HandleRef _this, Direction direction) {
        PROGRESS_THIS->setTextDirection(static_cast<QProgressBar::Direction>(direction));
    }

    void Handle_setTextVisible(HandleRef _this, bool visible) {
        PROGRESS_THIS->setTextVisible(visible);
    }

    void Handle_setValue(HandleRef _this, int32_t value) {
        PROGRESS_THIS->setValue(value);
    }

    void Handle_setRange(HandleRef _this, int32_t min, int32_t max) {
        PROGRESS_THIS->setRange(min, max);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QProgressBar(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
