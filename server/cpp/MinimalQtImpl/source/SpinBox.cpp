#include "generated/SpinBox.h"
#include "SpinBoxInternal.h"

#include "ObjectInternal.h"
#include "WidgetInternal.h"

using namespace ::Object;
using namespace ::AbstractSpinBox;
using namespace ::Widget;

#define THIS (reinterpret_cast<QSpinBox*>(_this))

namespace SpinBox
{
    std::string Handle_cleanText(HandleRef _this) {
        return THIS->cleanText().toStdString();
    }

    int32_t Handle_displayIntegerBase(HandleRef _this) {
        return THIS->displayIntegerBase();
    }

    int32_t Handle_maximum(HandleRef _this) {
        return THIS->maximum();
    }

    int32_t Handle_minimum(HandleRef _this) {
        return THIS->minimum();
    }

    std::string Handle_prefix(HandleRef _this) {
        return THIS->prefix().toStdString();
    }

    void Handle_setDisplayIntegerBase(HandleRef _this, int32_t base_) {
        THIS->setDisplayIntegerBase(base_);
    }

    void Handle_setMaximum(HandleRef _this, int32_t max) {
        THIS->setMaximum(max);
    }

    void Handle_setMinimum(HandleRef _this, int32_t min) {
        THIS->setMinimum(min);
    }

    void Handle_setPrefix(HandleRef _this, const std::string& prefix) {
        THIS->setPrefix(QString::fromStdString(prefix));
    }

    void Handle_setRange(HandleRef _this, int32_t minimum, int32_t maximum) {
        THIS->setRange(minimum, maximum);
    }

    void Handle_setSingleStep(HandleRef _this, int32_t val) {
        THIS->setSingleStep(val);
    }

    void Handle_setStepType(HandleRef _this, StepType stepType) {
        THIS->setStepType(static_cast<QAbstractSpinBox::StepType>(stepType));
    }

    void Handle_setSuffix(HandleRef _this, const std::string& suffix) {
        THIS->setSuffix(QString::fromStdString(suffix));
    }

    int32_t Handle_singleStep(HandleRef _this) {
        return THIS->singleStep();
    }

    StepType Handle_stepType(HandleRef _this) {
        return static_cast<StepType>(THIS->stepType());
    }

    std::string Handle_suffix(HandleRef _this) {
        return THIS->suffix().toStdString();
    }

    int32_t Handle_value(HandleRef _this) {
        return THIS->value();
    }

    void Handle_setValue(HandleRef _this, int32_t val) {
        THIS->setValue(val);
    }

    SignalConnectionRef Handle_connect_TextChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSpinBox::textChanged, [handler](const QString &value) {
            handler->textChanged(value.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ValueChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSpinBox::valueChanged, [handler](int value) {
            handler->valueChanged(value);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QSpinBox(AS_QWIDGET_PTR(parent)));
    }
}
