#include "generated/MessageBox.h"
#include "MessageBoxInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define MESSAGEBOX_THIS (WRAPPER->getActual())

namespace MessageBox
{
    void Handle_setDetailedText(HandleRef _this, const std::string& text) {
        MESSAGEBOX_THIS->setDetailedText(QString::fromStdString(text));
    }

    void Handle_setIcon(HandleRef _this, MessageBoxIcon icon) {
        MESSAGEBOX_THIS->setIcon(static_cast<QMessageBox::Icon>(icon));
    }

    void Handle_setInformativeText(HandleRef _this, const std::string& text) {
        MESSAGEBOX_THIS->setInformativeText(QString::fromStdString(text));
    }

    void Handle_setOptions(HandleRef _this, Options opts) {
        MESSAGEBOX_THIS->setOptions(static_cast<QMessageBox::Options>(opts));
    }

    void Handle_setStandardButtons(HandleRef _this, StandardButtonSet buttons) {
        MESSAGEBOX_THIS->setStandardButtons(static_cast<QMessageBox::StandardButtons>(buttons));
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        MESSAGEBOX_THIS->setText(QString::fromStdString(text));
    }

    void Handle_setTextFormat(HandleRef _this, TextFormat format) {
        MESSAGEBOX_THIS->setTextFormat(static_cast<Qt::TextFormat>(format));
    }

    void Handle_setTextInteractionFlags(HandleRef _this, TextInteractionFlags tiFlags) {
        MESSAGEBOX_THIS->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(tiFlags));
    }

    void Handle_setDefaultButton(HandleRef _this, StandardButton button) {
        MESSAGEBOX_THIS->setDefaultButton(static_cast<QMessageBox::StandardButton>(button));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(Widget::HandleRef parent, const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QMessageBox(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
