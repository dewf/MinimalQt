#include "generated/LineEdit.h"
#include "LineEditInternal.h"

#include "ObjectInternal.h"
#include "WidgetInternal.h"
#include "ActionInternal.h"
#include "IconInternal.h"

#include "util/convert.h"

#define THIS (reinterpret_cast<QLineEdit*>(_this))

namespace LineEdit
{
    bool Handle_hasAcceptableInput(HandleRef _this) {
        return THIS->hasAcceptableInput();
    }

    Alignment Handle_getAlignment(HandleRef _this) {
        return THIS->alignment();
    }

    void Handle_setAlignment(HandleRef _this, Enums::Alignment align) {
        THIS->setAlignment(static_cast<Qt::Alignment>(align));
    }

    bool Handle_isClearButtonEnabled(HandleRef _this) {
        return THIS->isClearButtonEnabled();
    }

    void Handle_setClearButtonEnabled(HandleRef _this, bool enabled) {
        THIS->setClearButtonEnabled(enabled);
    }

    CursorMoveStyle Handle_getCursorMoveStyle(HandleRef _this) {
        return static_cast<CursorMoveStyle>(THIS->cursorMoveStyle());
    }

    void Handle_setCursorMoveStyle(HandleRef _this, CursorMoveStyle style) {
        THIS->setCursorMoveStyle(static_cast<Qt::CursorMoveStyle>(style));
    }

    int32_t Handle_cursorPosition(HandleRef _this) {
        return THIS->cursorPosition();
    }

    void Handle_setCursorPosition(HandleRef _this, int32_t pos) {
        THIS->setCursorPosition(pos);
    }

    std::string Handle_displayText(HandleRef _this) {
        return THIS->displayText().toStdString();
    }

    bool Handle_dragEnabled(HandleRef _this) {
        return THIS->dragEnabled();
    }

    void Handle_setDragEnabled(HandleRef _this, bool enabled) {
        THIS->setDragEnabled(enabled);
    }

    EchoMode Handle_getEchoMode(HandleRef _this) {
        return static_cast<EchoMode>(THIS->echoMode());
    }

    void Handle_setEchoMode(HandleRef _this, EchoMode mode) {
        THIS->setEchoMode(static_cast<QLineEdit::EchoMode>(mode));
    }

    bool Handle_hasFrame(HandleRef _this) {
        return THIS->hasFrame();
    }

    void Handle_setFrame(HandleRef _this, bool enabled) {
        THIS->setFrame(enabled);
    }

    bool Handle_hasSelectedText(HandleRef _this) {
        return THIS->hasSelectedText();
    }

    std::string Handle_inputMask(HandleRef _this) {
        return THIS->inputMask().toStdString();
    }

    void Handle_setInputMask(HandleRef _this, const std::string& mask) {
        return THIS->setInputMask(QString::fromStdString(mask));
    }

    int32_t Handle_maxLength(HandleRef _this) {
        return THIS->maxLength();
    }

    void Handle_setMaxLength(HandleRef _this, int32_t length) {
        THIS->setMaxLength(length);
    }

    bool Handle_isModified(HandleRef _this) {
        return THIS->isModified();
    }

    void Handle_setModified(HandleRef _this, bool modified) {
        THIS->setModified(modified);
    }

    std::string Handle_placeholderText(HandleRef _this) {
        return THIS->placeholderText().toStdString();
    }

    void Handle_setPlaceholderText(HandleRef _this, const std::string& text) {
        THIS->setPlaceholderText(QString::fromStdString(text));
    }

    bool Handle_isReadOnly(HandleRef _this) {
        return THIS->isReadOnly();
    }

    void Handle_setReadOnly(HandleRef _this, bool value) {
        THIS->setReadOnly(value);
    }

    bool Handle_isRedoAvailable(HandleRef _this) {
        return THIS->isRedoAvailable();
    }

    std::string Handle_selectedText(HandleRef _this) {
        return THIS->selectedText().toStdString();
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    bool Handle_isUndoAvailable(HandleRef _this) {
        return THIS->isUndoAvailable();
    }

    void Handle_addAction(HandleRef _this, Action::HandleRef action, ActionPosition position) {
        THIS->addAction(AS_QACTION_PTR(action), static_cast<QLineEdit::ActionPosition>(position));
    }

    void Handle_addAction(HandleRef _this, Icon::HandleRef icon, ActionPosition position) {
        THIS->addAction(QICON_VALUE(icon), static_cast<QLineEdit::ActionPosition>(position));
    }

    void Handle_backspace(HandleRef _this) {
        THIS->backspace();
    }

    Menu::HandleRef Handle_createStandardContextMenu(HandleRef _this, const std::shared_ptr<Menu::SignalHandler>& handler) {
        return reinterpret_cast<Menu::HandleRef>(THIS->createStandardContextMenu());
    }

    void Handle_cursorBackward(HandleRef _this, bool mark, const std::optional<int32_t>& steps) {
        THIS->cursorBackward(mark, steps.value_or(1));
    }

    void Handle_cursorForward(HandleRef _this, bool mark, const std::optional<int32_t>& steps) {
        THIS->cursorForward(mark, steps.value_or(1));
    }

    int32_t Handle_cursorPositionAt(HandleRef _this, Point pos) {
        return THIS->cursorPositionAt(toQPoint(pos));
    }

    void Handle_cursorWordBackward(HandleRef _this, bool mark) {
        THIS->cursorWordBackward(mark);
    }

    void Handle_cursorWordForward(HandleRef _this, bool mark) {
        THIS->cursorWordForward(mark);
    }

    void Handle_del(HandleRef _this) {
        THIS->del();
    }

    void Handle_deselect(HandleRef _this) {
        THIS->deselect();
    }

    void Handle_end(HandleRef _this, bool mark) {
        THIS->end(mark);
    }

    void Handle_home(HandleRef _this, bool mark) {
        THIS->home(mark);
    }

    void Handle_insert(HandleRef _this, const std::string& newText) {
        THIS->insert(QString::fromStdString(newText));
    }

    int32_t Handle_selectionEnd(HandleRef _this) {
        return THIS->selectionEnd();
    }

    int32_t Handle_selectionLength(HandleRef _this) {
        return THIS->selectionLength();
    }

    int32_t Handle_selectionStart(HandleRef _this) {
        return THIS->selectionStart();
    }

    void Handle_setSelection(HandleRef _this, int32_t start, int32_t length) {
        THIS->setSelection(start, length);
    }

    void Handle_setTextMargins(HandleRef _this, Margins margins) {
        THIS->setTextMargins(toQMargins(margins));
    }

    void Handle_setTextMargins(HandleRef _this, int32_t left, int32_t top, int32_t right, int32_t bottom) {
        THIS->setTextMargins(left, top, right, bottom);
    }

    Margins Handle_textMargins(HandleRef _this) {
        return toMargins(THIS->textMargins());
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_copy(HandleRef _this) {
        THIS->copy();
    }

    void Handle_cut(HandleRef _this) {
        THIS->cut();
    }

    void Handle_paste(HandleRef _this) {
        THIS->paste();
    }

    void Handle_redo(HandleRef _this) {
        THIS->redo();
    }

    void Handle_selectAll(HandleRef _this) {
        THIS->selectAll();
    }

    void Handle_undo(HandleRef _this) {
        THIS->undo();
    }

    SignalConnectionRef Handle_connect_CursorPositionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QLineEdit::cursorPositionChanged, [handler](int oldPos, int newPos) {
            handler->cursorPositionChanged(oldPos, newPos);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_EditingFinished(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QLineEdit::editingFinished, [handler] {
            handler->editingFinished();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_InputRejected(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QLineEdit::inputRejected, [handler] {
            handler->inputRejected();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ReturnPressed(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QLineEdit::returnPressed, [handler] {
            handler->returnPressed();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SelectionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QLineEdit::selectionChanged, [handler] {
            handler->selectionChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TextChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QLineEdit::textChanged, [handler](const QString& text) {
            handler->textChanged(text.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TextEdited(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QLineEdit::textEdited, [handler](const QString& text) {
            handler->textEdited(text.toStdString());
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        return reinterpret_cast<HandleRef>(new QLineEdit(qParent));
    }

    HandleRef create(const std::string& contents, const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        return reinterpret_cast<HandleRef>(new QLineEdit(QString::fromStdString(contents), qParent));
    }
}
