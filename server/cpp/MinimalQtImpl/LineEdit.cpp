#include "generated/LineEdit.h"
#include "LineEditInternal.h"

#include "ObjectInternal.h"
#include "WidgetInternal.h"
#include "ActionInternal.h"
#include "IconInternal.h"
#include "PointInternal.h"
#include "ValidatorInternal.h"
#include "MarginsInternal.h"

using namespace ::Object;
using namespace ::Widget;
using namespace ::Margins;
using namespace ::Point;
using namespace ::Icon;
using namespace ::Enums;
using namespace ::Action;
using namespace ::Menu;
using namespace ::Completer;
using namespace ::Validator;

#include "util/convert.h"

#define THIS (reinterpret_cast<QLineEdit*>(_this))

namespace LineEdit
{
    void Handle_addAction(HandleRef _this, Action::HandleRef action, ActionPosition position) {
        THIS->addAction(AS_QACTION_PTR(action), static_cast<QLineEdit::ActionPosition>(position));
    }

    Action::HandleRef Handle_addAction(HandleRef _this, Icon::HandleRef icon, ActionPosition position) {
        const auto action = THIS->addAction(QICON_VALUE(icon), static_cast<QLineEdit::ActionPosition>(position));
        return reinterpret_cast<Action::HandleRef>(action);
    }

    Alignment Handle_alignment(HandleRef _this) {
        return Alignment(THIS->alignment());
    }

    void Handle_backspace(HandleRef _this) {
        THIS->backspace();
    }

    Completer::HandleRef Handle_completer(HandleRef _this) {
        return reinterpret_cast<Completer::HandleRef>(THIS->completer());
    }

    Menu::HandleRef Handle_createStandardContextMenu(HandleRef _this) {
        return reinterpret_cast<Menu::HandleRef>(THIS->createStandardContextMenu());
    }

    void Handle_cursorBackward(HandleRef _this, bool mark, int32_t steps /* 1 */) {
        THIS->cursorBackward(mark, steps);
    }

    void Handle_cursorForward(HandleRef _this, bool mark, int32_t steps /* 1 */) {
        THIS->cursorForward(mark, steps);
    }

    CursorMoveStyle Handle_cursorMoveStyle(HandleRef _this) {
        return static_cast<CursorMoveStyle>(THIS->cursorMoveStyle());
    }

    int32_t Handle_cursorPosition(HandleRef _this) {
        return THIS->cursorPosition();
    }

    int32_t Handle_cursorPositionAt(HandleRef _this, Point::HandleRef pos) {
        return THIS->cursorPositionAt(QPOINT_VALUE(pos));
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

    std::string Handle_displayText(HandleRef _this) {
        return THIS->displayText().toStdString();
    }

    bool Handle_dragEnabled(HandleRef _this) {
        return THIS->dragEnabled();
    }

    EchoMode Handle_getEchoMode(HandleRef _this) {
        return static_cast<EchoMode>(THIS->echoMode());
    }

    void Handle_end(HandleRef _this, bool mark) {
        THIS->end(mark);
    }

    bool Handle_hasAcceptableInput(HandleRef _this) {
        return THIS->hasAcceptableInput();
    }

    bool Handle_hasFrame(HandleRef _this) {
        return THIS->hasFrame();
    }

    bool Handle_hasSelectedText(HandleRef _this) {
        return THIS->hasSelectedText();
    }

    void Handle_home(HandleRef _this, bool mark) {
        THIS->home(mark);
    }

    std::string Handle_inputMask(HandleRef _this) {
        return THIS->inputMask().toStdString();
    }

    void Handle_insert(HandleRef _this, const std::string& newText) {
        THIS->insert(QString::fromStdString(newText));
    }

    bool Handle_isClearButtonEnabled(HandleRef _this) {
        return THIS->isClearButtonEnabled();
    }

    bool Handle_isModified(HandleRef _this) {
        return THIS->isModified();
    }

    bool Handle_isReadOnly(HandleRef _this) {
        return THIS->isReadOnly();
    }

    bool Handle_isRedoAvailable(HandleRef _this) {
        return THIS->isRedoAvailable();
    }

    bool Handle_isUndoAvailable(HandleRef _this) {
        return THIS->isUndoAvailable();
    }

    int32_t Handle_maxLength(HandleRef _this) {
        return THIS->maxLength();
    }

    std::string Handle_placeholderText(HandleRef _this) {
        return THIS->placeholderText().toStdString();
    }

    std::string Handle_selectedText(HandleRef _this) {
        return THIS->selectedText().toStdString();
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

    void Handle_setAlignment(HandleRef _this, Enums::Alignment align) {
        THIS->setAlignment(static_cast<Qt::Alignment>(align.value));
    }

    void Handle_setClearButtonEnabled(HandleRef _this, bool enabled) {
        THIS->setClearButtonEnabled(enabled);
    }

    void Handle_setCompleter(HandleRef _this, Completer::HandleRef completer) {
        THIS->setCompleter(reinterpret_cast<QCompleter*>(completer));
    }

    void Handle_setCursorMoveStyle(HandleRef _this, CursorMoveStyle style) {
        THIS->setCursorMoveStyle(static_cast<Qt::CursorMoveStyle>(style));
    }

    void Handle_setCursorPosition(HandleRef _this, int32_t pos) {
        THIS->setCursorPosition(pos);
    }

    void Handle_setDragEnabled(HandleRef _this, bool enabled) {
        THIS->setDragEnabled(enabled);
    }

    void Handle_setEchoMode(HandleRef _this, EchoMode mode) {
        THIS->setEchoMode(static_cast<QLineEdit::EchoMode>(mode));
    }

    void Handle_setFrame(HandleRef _this, bool enabled) {
        THIS->setFrame(enabled);
    }

    void Handle_setInputMask(HandleRef _this, const std::string& mask) {
        return THIS->setInputMask(QString::fromStdString(mask));
    }

    void Handle_setMaxLength(HandleRef _this, int32_t length) {
        THIS->setMaxLength(length);
    }

    void Handle_setModified(HandleRef _this, bool modified) {
        THIS->setModified(modified);
    }

    void Handle_setPlaceholderText(HandleRef _this, const std::string& text) {
        THIS->setPlaceholderText(QString::fromStdString(text));
    }

    void Handle_setReadOnly(HandleRef _this, bool value) {
        THIS->setReadOnly(value);
    }

    void Handle_setSelection(HandleRef _this, int32_t start, int32_t length) {
        THIS->setSelection(start, length);
    }

    void Handle_setTextMargins(HandleRef _this, Margins::HandleRef margins) {
        THIS->setTextMargins(QMARGINS_VALUE(margins));
    }

    void Handle_setTextMargins(HandleRef _this, int32_t left, int32_t top, int32_t right, int32_t bottom) {
        THIS->setTextMargins(left, top, right, bottom);
    }

    void Handle_setValidator(HandleRef _this, ConstHandleRef validator) {
        THIS->setValidator(AS_QVALIDATOR_CONSTPTR(validator));
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    Margins::OwnedRef Handle_textMargins(HandleRef _this) {
        return MARGINS_HEAP_NEW(THIS->textMargins());
    }

    ConstHandleRef Handle_validator(HandleRef _this) {
        return AS_VALIDATOR_CONSTHANDLE(THIS->validator());
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

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
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

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QLineEdit(AS_QWIDGET_PTR(parent)));
    }

    HandleRef create(const std::string& contents, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QLineEdit(QString::fromStdString(contents), AS_QWIDGET_PTR(parent)));
    }
}
