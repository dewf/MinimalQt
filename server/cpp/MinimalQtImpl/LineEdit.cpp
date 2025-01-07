#include "generated/LineEdit.h"

#include "ActionInternal.h"
#include "LineEditInternal.h"
#include "IconInternal.h"
#include "MenuInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define LINEEDIT_THIS (WRAPPER->getActual())

namespace LineEdit
{
    bool Handle_hasAcceptableInput(HandleRef _this) {
        return LINEEDIT_THIS->hasAcceptableInput();
    }

    Alignment Handle_getAlignment(HandleRef _this) {
        return LINEEDIT_THIS->alignment();
    }

    void Handle_setAlignment(HandleRef _this, Enums::Alignment align) {
        LINEEDIT_THIS->setAlignment(static_cast<Qt::Alignment>(align));
    }

    bool Handle_isClearButtonEnabled(HandleRef _this) {
        return LINEEDIT_THIS->isClearButtonEnabled();
    }

    void Handle_setClearButtonEnabled(HandleRef _this, bool enabled) {
        LINEEDIT_THIS->setClearButtonEnabled(enabled);
    }

    CursorMoveStyle Handle_getCursorMoveStyle(HandleRef _this) {
        return static_cast<CursorMoveStyle>(LINEEDIT_THIS->cursorMoveStyle());
    }

    void Handle_setCursorMoveStyle(HandleRef _this, CursorMoveStyle style) {
        LINEEDIT_THIS->setCursorMoveStyle(static_cast<Qt::CursorMoveStyle>(style));
    }

    int32_t Handle_cursorPosition(HandleRef _this) {
        return LINEEDIT_THIS->cursorPosition();
    }

    void Handle_setCursorPosition(HandleRef _this, int32_t pos) {
        LINEEDIT_THIS->setCursorPosition(pos);
    }

    std::string Handle_displayText(HandleRef _this) {
        return LINEEDIT_THIS->displayText().toStdString();
    }

    bool Handle_dragEnabled(HandleRef _this) {
        return LINEEDIT_THIS->dragEnabled();
    }

    void Handle_setDragEnabled(HandleRef _this, bool enabled) {
        LINEEDIT_THIS->setDragEnabled(enabled);
    }

    EchoMode Handle_getEchoMode(HandleRef _this) {
        return static_cast<EchoMode>(LINEEDIT_THIS->echoMode());
    }

    void Handle_setEchoMode(HandleRef _this, EchoMode mode) {
        LINEEDIT_THIS->setEchoMode(static_cast<QLineEdit::EchoMode>(mode));
    }

    bool Handle_hasFrame(HandleRef _this) {
        return LINEEDIT_THIS->hasFrame();
    }

    void Handle_setFrame(HandleRef _this, bool enabled) {
        LINEEDIT_THIS->setFrame(enabled);
    }

    bool Handle_hasSelectedText(HandleRef _this) {
        return LINEEDIT_THIS->hasSelectedText();
    }

    std::string Handle_inputMask(HandleRef _this) {
        return LINEEDIT_THIS->inputMask().toStdString();
    }

    void Handle_setInputMask(HandleRef _this, const std::string& mask) {
        return LINEEDIT_THIS->setInputMask(QString::fromStdString(mask));
    }

    int32_t Handle_maxLength(HandleRef _this) {
        return LINEEDIT_THIS->maxLength();
    }

    void Handle_setMaxLength(HandleRef _this, int32_t length) {
        LINEEDIT_THIS->setMaxLength(length);
    }

    bool Handle_isModified(HandleRef _this) {
        return LINEEDIT_THIS->isModified();
    }

    void Handle_setModified(HandleRef _this, bool modified) {
        LINEEDIT_THIS->setModified(modified);
    }

    std::string Handle_placeholderText(HandleRef _this) {
        return LINEEDIT_THIS->placeholderText().toStdString();
    }

    void Handle_setPlaceholderText(HandleRef _this, const std::string& text) {
        LINEEDIT_THIS->setPlaceholderText(QString::fromStdString(text));
    }

    bool Handle_isReadOnly(HandleRef _this) {
        return LINEEDIT_THIS->isReadOnly();
    }

    void Handle_setReadOnly(HandleRef _this, bool value) {
        LINEEDIT_THIS->setReadOnly(value);
    }

    bool Handle_isRedoAvailable(HandleRef _this) {
        return LINEEDIT_THIS->isRedoAvailable();
    }

    std::string Handle_selectedText(HandleRef _this) {
        return LINEEDIT_THIS->selectedText().toStdString();
    }

    std::string Handle_text(HandleRef _this) {
        return LINEEDIT_THIS->text().toStdString();
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        LINEEDIT_THIS->setText(QString::fromStdString(text));
    }

    bool Handle_isUndoAvailable(HandleRef _this) {
        return LINEEDIT_THIS->isUndoAvailable();
    }

    void Handle_addAction(HandleRef _this, Action::HandleRef action, ActionPosition position) {
        const auto wrapper = reinterpret_cast<Action::SignalWrapper*>(action);
        LINEEDIT_THIS->addAction(wrapper->getActual(), static_cast<QLineEdit::ActionPosition>(position));
    }

    void Handle_addAction(HandleRef _this, Icon::HandleRef icon, ActionPosition position) {
        LINEEDIT_THIS->addAction(QICON_VALUE(icon), static_cast<QLineEdit::ActionPosition>(position));
    }

    void Handle_backspace(HandleRef _this) {
        LINEEDIT_THIS->backspace();
    }

    Menu::HandleRef Handle_createStandardContextMenu(HandleRef _this, const std::shared_ptr<Menu::SignalHandler>& handler) {
        const auto menu = LINEEDIT_THIS->createStandardContextMenu();
        const auto wrapper = new Menu::SignalWrapper(menu, handler);
        return reinterpret_cast<Menu::HandleRef>(wrapper);
    }

    void Handle_cursorBackward(HandleRef _this, bool mark, const std::optional<int32_t>& steps) {
        LINEEDIT_THIS->cursorBackward(mark, steps.value_or(1));
    }

    void Handle_cursorForward(HandleRef _this, bool mark, const std::optional<int32_t>& steps) {
        LINEEDIT_THIS->cursorForward(mark, steps.value_or(1));
    }

    int32_t Handle_cursorPositionAt(HandleRef _this, Point pos) {
        return LINEEDIT_THIS->cursorPositionAt(toQPoint(pos));
    }

    void Handle_cursorWordBackward(HandleRef _this, bool mark) {
        LINEEDIT_THIS->cursorWordBackward(mark);
    }

    void Handle_cursorWordForward(HandleRef _this, bool mark) {
        LINEEDIT_THIS->cursorWordForward(mark);
    }

    void Handle_del(HandleRef _this) {
        LINEEDIT_THIS->del();
    }

    void Handle_deselect(HandleRef _this) {
        LINEEDIT_THIS->deselect();
    }

    void Handle_end(HandleRef _this, bool mark) {
        LINEEDIT_THIS->end(mark);
    }

    void Handle_home(HandleRef _this, bool mark) {
        LINEEDIT_THIS->home(mark);
    }

    void Handle_insert(HandleRef _this, const std::string& newText) {
        LINEEDIT_THIS->insert(QString::fromStdString(newText));
    }

    int32_t Handle_selectionEnd(HandleRef _this) {
        return LINEEDIT_THIS->selectionEnd();
    }

    int32_t Handle_selectionLength(HandleRef _this) {
        return LINEEDIT_THIS->selectionLength();
    }

    int32_t Handle_selectionStart(HandleRef _this) {
        return LINEEDIT_THIS->selectionStart();
    }

    void Handle_setSelection(HandleRef _this, int32_t start, int32_t length) {
        LINEEDIT_THIS->setSelection(start, length);
    }

    void Handle_setTextMargins(HandleRef _this, Margins margins) {
        LINEEDIT_THIS->setTextMargins(toQMargins(margins));
    }

    void Handle_setTextMargins(HandleRef _this, int32_t left, int32_t top, int32_t right, int32_t bottom) {
        LINEEDIT_THIS->setTextMargins(left, top, right, bottom);
    }

    Margins Handle_textMargins(HandleRef _this) {
        return toMargins(LINEEDIT_THIS->textMargins());
    }

    void Handle_clear(HandleRef _this) {
        LINEEDIT_THIS->clear();
    }

    void Handle_copy(HandleRef _this) {
        LINEEDIT_THIS->copy();
    }

    void Handle_cut(HandleRef _this) {
        LINEEDIT_THIS->cut();
    }

    void Handle_paste(HandleRef _this) {
        LINEEDIT_THIS->paste();
    }

    void Handle_redo(HandleRef _this) {
        LINEEDIT_THIS->redo();
    }

    void Handle_selectAll(HandleRef _this) {
        LINEEDIT_THIS->selectAll();
    }

    void Handle_undo(HandleRef _this) {
        LINEEDIT_THIS->undo();
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler, const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        const auto wrapper = new SignalWrapper(new QLineEdit(qParent), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler, const std::string& contents, const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        const auto wrapper = new SignalWrapper(new QLineEdit(QString::fromStdString(contents), qParent), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
