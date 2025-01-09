#include "generated/PlainTextEdit.h"
#include "PlainTextEditInternal.h"

#include "ObjectInternal.h"
#include "util/convert.h"

#define THIS (reinterpret_cast<QPlainTextEdit*>(_this))

namespace PlainTextEdit
{
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

    SignalConnectionRef Handle_connect_BlockCountChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QPlainTextEdit::blockCountChanged, [handler](int newBlockCount) {
            handler->blockCountChanged(newBlockCount);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CopyAvailable(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QPlainTextEdit::copyAvailable, [handler](bool yes) {
            handler->copyAvailable(yes);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CursorPositionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QPlainTextEdit::cursorPositionChanged, [handler] {
            handler->cursorPositionChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ModificationChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QPlainTextEdit::modificationChanged, [handler](bool changed) {
            handler->modificationChanged(changed);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_RedoAvailable(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QPlainTextEdit::redoAvailable, [handler](bool available) {
            handler->redoAvailable(available);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SelectionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QPlainTextEdit::selectionChanged, [handler] {
            handler->selectionChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TextChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QPlainTextEdit::textChanged, [handler] {
            handler->textChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_UndoAvailable(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QPlainTextEdit::undoAvailable, [handler](bool available) {
            handler->undoAvailable(available);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_UpdateRequest(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QPlainTextEdit::updateRequest, [handler](const QRect &rect, int dy) {
            handler->updateRequest(toRect(rect), dy);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QPlainTextEdit());
    }
}
