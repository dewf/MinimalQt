#include "generated/AbstractSpinBox.h"
#include "AbstractSpinBoxInternal.h"

#include "ObjectInternal.h"

using namespace ::Widget;
using namespace ::Object;
using namespace ::Enums;
using namespace ::Validator;

#define THIS (reinterpret_cast<QAbstractSpinBox*>(_this))

namespace AbstractSpinBox
{
    Flags<Alignment> Handle_getAlignment(HandleRef _this) {
        return static_cast<Flags<Alignment>>(THIS->alignment());
    }

    ButtonSymbols Handle_getButtonSymbols(HandleRef _this) {
        return static_cast<ButtonSymbols>(THIS->buttonSymbols());
    }

    CorrectionMode Handle_getCorrectionMode(HandleRef _this) {
        return static_cast<CorrectionMode>(THIS->correctionMode());
    }

    std::string Handle_fixup(HandleRef _this, const std::string& input) {
        // 'input' is actually a ref QString, we need to retun the (potentially) modified version to emulate similar behavior on the frontend
        auto qInput = QString::fromStdString(input);
        THIS->fixup(qInput);
        return qInput.toStdString();
    }

    bool Handle_hasAcceptableInput(HandleRef _this) {
        return THIS->hasAcceptableInput();
    }

    bool Handle_hasFrame(HandleRef _this) {
        return THIS->hasFrame();
    }

    void Handle_interpretText(HandleRef _this) {
        THIS->interpretText();
    }

    bool Handle_isAccelerated(HandleRef _this) {
        return THIS->isAccelerated();
    }

    bool Handle_isGroupSeparatorShown(HandleRef _this) {
        return THIS->isGroupSeparatorShown();
    }

    bool Handle_isReadOnly(HandleRef _this) {
        return THIS->isReadOnly();
    }

    bool Handle_keyboardTracking(HandleRef _this) {
        return THIS->keyboardTracking();
    }

    void Handle_setAccelerated(HandleRef _this, bool on) {
        THIS->setAccelerated(on);
    }

    void Handle_setAlignment(HandleRef _this, Flags<Alignment> flag) {
        THIS->setAlignment(static_cast<Qt::Alignment>(flag.value()));
    }

    void Handle_setButtonSymbols(HandleRef _this, ButtonSymbols bs) {
        THIS->setButtonSymbols(static_cast<QAbstractSpinBox::ButtonSymbols>(bs));
    }

    void Handle_setCorrectionMode(HandleRef _this, CorrectionMode cm) {
        THIS->setCorrectionMode(static_cast<QAbstractSpinBox::CorrectionMode>(cm));
    }

    void Handle_setFrame(HandleRef _this, bool hasFrame) {
        THIS->setFrame(hasFrame);
    }

    void Handle_setGroupSeparatorShown(HandleRef _this, bool shown) {
        THIS->setGroupSeparatorShown(shown);
    }

    void Handle_setKeyboardTracking(HandleRef _this, bool kt) {
        THIS->setKeyboardTracking(kt);
    }

    void Handle_setReadOnly(HandleRef _this, bool r) {
        THIS->setReadOnly(r);
    }

    void Handle_setSpecialValueText(HandleRef _this, const std::string& text) {
        THIS->setSpecialValueText(QString::fromStdString(text));
    }

    void Handle_setWrapping(HandleRef _this, bool w) {
        THIS->setWrapping(w);
    }

    std::string Handle_specialValueText(HandleRef _this) {
        return THIS->specialValueText().toStdString();
    }

    void Handle_stepBy(HandleRef _this, int32_t steps) {
        THIS->stepBy(steps);
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    ValidateResult Handle_validate(HandleRef _this, const std::string& input, int32_t pos) {
        auto qInput = QString::fromStdString(input);
        const auto qState = THIS->validate(qInput, pos);
        return ValidateResult { static_cast<State>(qState), qInput.toStdString(), pos };
    }

    bool Handle_wrapping(HandleRef _this) {
        return THIS->wrapping();
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_selectAll(HandleRef _this) {
        THIS->selectAll();
    }

    void Handle_stepDown(HandleRef _this) {
        THIS->stepDown();
    }

    void Handle_stepUp(HandleRef _this) {
        THIS->stepUp();
    }

    SignalConnectionRef Handle_connect_EditingFinished(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractSpinBox::editingFinished, [handler] {
            handler->sig_editingFinished();
        });
        return new __SignalConnection { connection };
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto absSpinBox = AS_QABSTRACTSPINBOX_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(absSpinBox);
        case Handle_CastTarget::Widget_Handle:
            return static_cast<QWidget*>(absSpinBox);
        }
        std::unreachable();
    }
}
