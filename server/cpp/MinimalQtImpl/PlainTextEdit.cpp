#include "generated/PlainTextEdit.h"

#include <QPlainTextEdit>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((PlainTextEditWithHandler*)_this)

#include "signalrelays/PlainTextEdit.h"

namespace PlainTextEdit
{
    class PlainTextEditWithHandler : public QPlainTextEdit {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit PlainTextEditWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    void Handle_setBackgroundVisible(HandleRef _this, bool visible) {
        THIS->setBackgroundVisible(visible);
    }

    int32_t Handle_blockCount(HandleRef _this) {
        return THIS->blockCount();
    }

    void Handle_setCenterOnScroll(HandleRef _this, bool state) {
        THIS->setCenterOnScroll(state);
    }

    void Handle_setCursorWidth(HandleRef _this, int32_t width) {
        THIS->setCursorWidth(width);
    }

    void Handle_setDocumentTitle(HandleRef _this, const std::string& title) {
        THIS->setDocumentTitle(QString::fromStdString(title));
    }

    void Handle_setLineWrapMode(HandleRef _this, LineWrapMode mode) {
        THIS->setLineWrapMode(static_cast<QPlainTextEdit::LineWrapMode>(mode));
    }

    void Handle_setMaximumBlockCount(HandleRef _this, int32_t count) {
        THIS->setMaximumBlockCount(count);
    }

    void Handle_setOverwriteMode(HandleRef _this, bool overwrite) {
        THIS->setOverwriteMode(overwrite);
    }

    void Handle_setPlaceholderText(HandleRef _this, const std::string& text) {
        THIS->setPlaceholderText(QString::fromStdString(text));
    }

    void Handle_setPlainText(HandleRef _this, const std::string& text) {
        THIS->setPlainText(QString::fromStdString(text));
    }

    void Handle_setReadOnly(HandleRef _this, bool state) {
        THIS->setReadOnly(state);
    }

    void Handle_setTabChangesFocus(HandleRef _this, bool state) {
        THIS->setTabChangesFocus(state);
    }

    void Handle_setTabStopDistance(HandleRef _this, double distance) {
        THIS->setTabStopDistance(distance);
    }

    void Handle_setTextInteractionFlags(HandleRef _this, TextInteractionFlags tiFlags) {
        THIS->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(tiFlags));
    }

    void Handle_setUndoRedoEnabled(HandleRef _this, bool enabled) {
        THIS->setUndoRedoEnabled(enabled);
    }

    void Handle_setWordWrapMode(HandleRef _this, WrapMode mode) {
        THIS->setWordWrapMode(static_cast<QTextOption::WrapMode>(mode));
    }

    std::string Handle_toPlainText(HandleRef _this) {
        return THIS->toPlainText().toStdString();
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new PlainTextEditWithHandler(handler));
    }
}

#include "PlainTextEdit.moc"
