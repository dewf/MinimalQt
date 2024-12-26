#include "generated/PlainTextEdit.h"
#include "PlainTextEditInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define TEXTEDIT_THIS (WRAPPER->getActual())

namespace PlainTextEdit
{
    void Handle_setBackgroundVisible(HandleRef _this, bool visible) {
        TEXTEDIT_THIS->setBackgroundVisible(visible);
    }

    int32_t Handle_blockCount(HandleRef _this) {
        return TEXTEDIT_THIS->blockCount();
    }

    void Handle_setCenterOnScroll(HandleRef _this, bool state) {
        TEXTEDIT_THIS->setCenterOnScroll(state);
    }

    void Handle_setCursorWidth(HandleRef _this, int32_t width) {
        TEXTEDIT_THIS->setCursorWidth(width);
    }

    void Handle_setDocumentTitle(HandleRef _this, const std::string& title) {
        TEXTEDIT_THIS->setDocumentTitle(QString::fromStdString(title));
    }

    void Handle_setLineWrapMode(HandleRef _this, LineWrapMode mode) {
        TEXTEDIT_THIS->setLineWrapMode(static_cast<QPlainTextEdit::LineWrapMode>(mode));
    }

    void Handle_setMaximumBlockCount(HandleRef _this, int32_t count) {
        TEXTEDIT_THIS->setMaximumBlockCount(count);
    }

    void Handle_setOverwriteMode(HandleRef _this, bool overwrite) {
        TEXTEDIT_THIS->setOverwriteMode(overwrite);
    }

    void Handle_setPlaceholderText(HandleRef _this, const std::string& text) {
        TEXTEDIT_THIS->setPlaceholderText(QString::fromStdString(text));
    }

    void Handle_setPlainText(HandleRef _this, const std::string& text) {
        TEXTEDIT_THIS->setPlainText(QString::fromStdString(text));
    }

    void Handle_setReadOnly(HandleRef _this, bool state) {
        TEXTEDIT_THIS->setReadOnly(state);
    }

    void Handle_setTabChangesFocus(HandleRef _this, bool state) {
        TEXTEDIT_THIS->setTabChangesFocus(state);
    }

    void Handle_setTabStopDistance(HandleRef _this, double distance) {
        TEXTEDIT_THIS->setTabStopDistance(distance);
    }

    void Handle_setTextInteractionFlags(HandleRef _this, TextInteractionFlags tiFlags) {
        TEXTEDIT_THIS->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(tiFlags));
    }

    void Handle_setUndoRedoEnabled(HandleRef _this, bool enabled) {
        TEXTEDIT_THIS->setUndoRedoEnabled(enabled);
    }

    void Handle_setWordWrapMode(HandleRef _this, WrapMode mode) {
        TEXTEDIT_THIS->setWordWrapMode(static_cast<QTextOption::WrapMode>(mode));
    }

    std::string Handle_toPlainText(HandleRef _this) {
        return TEXTEDIT_THIS->toPlainText().toStdString();
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QPlainTextEdit(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
