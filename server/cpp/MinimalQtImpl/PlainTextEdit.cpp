#include "generated/PlainTextEdit.h"
#include "PlainTextEditInternal.h"

#include "ObjectInternal.h"
#include "RegularExpressionInternal.h"
#include "TextCharFormatInternal.h"
#include "TextCursorInternal.h"
#include "TextEditInternal.h"
#include "UrlInternal.h"
#include "VariantInternal.h"
#include "WidgetInternal.h"

#include "util/convert.h"

#define THIS (reinterpret_cast<QPlainTextEdit*>(_this))

namespace PlainTextEdit
{
    std::string Handle_anchorAt(HandleRef _this, Point pos) {
        return THIS->anchorAt(toQPoint(pos)).toStdString();
    }

    bool Handle_backgroundVisible(HandleRef _this) {
        return THIS->backgroundVisible();
    }

    int32_t Handle_blockCount(HandleRef _this) {
        return THIS->blockCount();
    }

    bool Handle_canPaste(HandleRef _this) {
        return THIS->canPaste();
    }

    bool Handle_centerOnScroll(HandleRef _this) {
        return THIS->centerOnScroll();
    }

    Menu::HandleRef Handle_createStandardContextMenu(HandleRef _this) {
        return reinterpret_cast<Menu::HandleRef>(THIS->createStandardContextMenu());
    }

    Menu::HandleRef Handle_createStandardContextMenu(HandleRef _this, Point position) {
        return reinterpret_cast<Menu::HandleRef>(THIS->createStandardContextMenu());
    }

    TextCharFormat::OwnedRef Handle_currentCharFormat(HandleRef _this) {
        return TEXTCHARFORMAT_HEAP_NEW(THIS->currentCharFormat());
    }

    TextCursor::OwnedRef Handle_cursorForPosition(HandleRef _this, Point pos) {
        return TEXTCURSOR_HEAP_NEW(THIS->cursorForPosition(toQPoint(pos)));
    }

    Rect Handle_cursorRect(HandleRef _this) {
        return toRect(THIS->cursorRect());
    }

    Rect Handle_cursorRect(HandleRef _this, TextCursor::HandleRef cursor) {
        return toRect(THIS->cursorRect(QTEXTCURSOR_VALUE(cursor)));
    }

    int32_t Handle_cursorWidth(HandleRef _this) {
        return THIS->cursorWidth();
    }

    TextDocument::HandleRef Handle_document(HandleRef _this) {
        return reinterpret_cast<TextDocument::HandleRef>(THIS->document());
    }

    std::string Handle_documentTitle(HandleRef _this) {
        return THIS->documentTitle().toStdString();
    }

    void Handle_ensureCursorVisible(HandleRef _this) {
        THIS->ensureCursorVisible();
    }

    std::vector<ExtraSelection::OwnedRef> Handle_extraSelections(HandleRef _this) {
        return fromQList<QTextEdit::ExtraSelection,ExtraSelection::OwnedRef>(THIS->extraSelections(), [](auto sel) {
            return TEXTEDIT_EXTRASEL_HEAP_NEW(sel.cursor, sel.format);
        });
    }

    bool Handle_find(HandleRef _this, const std::string& exp, FindFlags options_ /* 0 */) {
        return THIS->find(QString::fromStdString(exp), static_cast<QTextDocument::FindFlags>(options_.value));
    }

    bool Handle_find(HandleRef _this, RegularExpression::HandleRef exp, FindFlags options_ /* 0 */) {
        return THIS->find(QREGEX_VALUE(exp), static_cast<QTextDocument::FindFlags>(options_.value));
    }

    bool Handle_isReadOnly(HandleRef _this) {
        return THIS->isReadOnly();
    }

    bool Handle_isUndoRedoEnabled(HandleRef _this) {
        return THIS->isUndoRedoEnabled();
    }

    LineWrapMode Handle_getLineWrapMode(HandleRef _this) {
        return static_cast<LineWrapMode>(THIS->lineWrapMode());
    }

    Variant::OwnedRef Handle_loadResource(HandleRef _this, int32_t type, Url::HandleRef name) {
        return VARIANT_HEAP_NEW(THIS->loadResource(type, QURL_VALUE(name)));
    }

    int32_t Handle_maximumBlockCount(HandleRef _this) {
        return THIS->maximumBlockCount();
    }

    void Handle_mergeCurrentCharFormat(HandleRef _this, TextCharFormat::HandleRef modifier) {
        return THIS->mergeCurrentCharFormat(QTEXTCHARFORMAT_VALUE(modifier));
    }

    void Handle_moveCursor(HandleRef _this, MoveOperation operation, MoveMode mode /* MoveMode::MoveAnchor */) {
        THIS->moveCursor(static_cast<QTextCursor::MoveOperation>(operation), static_cast<QTextCursor::MoveMode>(mode));
    }

    bool Handle_overwriteMode(HandleRef _this) {
        return THIS->overwriteMode();
    }

    std::string Handle_placeholderText(HandleRef _this) {
        return THIS->placeholderText().toStdString();
    }

    void Handle_setBackgroundVisible(HandleRef _this, bool visible) {
        THIS->setBackgroundVisible(visible);
    }

    void Handle_setCenterOnScroll(HandleRef _this, bool state) {
        THIS->setCenterOnScroll(state);
    }

    void Handle_setCurrentCharFormat(HandleRef _this, TextCharFormat::HandleRef format) {
        THIS->setCurrentCharFormat(QTEXTCHARFORMAT_VALUE(format));
    }

    void Handle_setCursorWidth(HandleRef _this, int32_t width) {
        THIS->setCursorWidth(width);
    }

    void Handle_setDocument(HandleRef _this, TextDocument::HandleRef document) {
        THIS->setDocument(reinterpret_cast<QTextDocument*>(document));
    }

    void Handle_setDocumentTitle(HandleRef _this, const std::string& title) {
        THIS->setDocumentTitle(QString::fromStdString(title));
    }

    void Handle_setExtraSelections(HandleRef _this, const std::vector<ExtraSelection::HandleRef>& selections) {
        const auto qSelections = toQList<ExtraSelection::HandleRef,QTextEdit::ExtraSelection>(selections, [](auto sel) {
            return QTEXTEDIT_EXTRASEL_VALUE(sel);
        });
        THIS->setExtraSelections(qSelections);
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

    void Handle_setReadOnly(HandleRef _this, bool state) {
        THIS->setReadOnly(state);
    }

    void Handle_setTabChangesFocus(HandleRef _this, bool state) {
        THIS->setTabChangesFocus(state);
    }

    void Handle_setTabStopDistance(HandleRef _this, double distance) {
        THIS->setTabStopDistance(distance);
    }

    void Handle_setTextCursor(HandleRef _this, TextCursor::HandleRef cursor) {
        THIS->setTextCursor(QTEXTCURSOR_VALUE(cursor));
    }

    void Handle_setTextInteractionFlags(HandleRef _this, TextInteractionFlags tiFlags) {
        THIS->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(tiFlags.value));
    }

    void Handle_setUndoRedoEnabled(HandleRef _this, bool enabled) {
        THIS->setUndoRedoEnabled(enabled);
    }

    void Handle_setWordWrapMode(HandleRef _this, WrapMode mode) {
        THIS->setWordWrapMode(static_cast<QTextOption::WrapMode>(mode));
    }

    bool Handle_tabChangesFocus(HandleRef _this) {
        return THIS->tabChangesFocus();
    }

    double Handle_tabStopDistance(HandleRef _this) {
        return THIS->tabStopDistance();
    }

    TextCursor::OwnedRef Handle_textCursor(HandleRef _this) {
        return TEXTCURSOR_HEAP_NEW(THIS->textCursor());
    }

    TextInteractionFlags Handle_getTextInteractionFlags(HandleRef _this) {
        return TextInteractionFlags(THIS->textInteractionFlags());
    }

    std::string Handle_toPlainText(HandleRef _this) {
        return THIS->toPlainText().toStdString();
    }

    WrapMode Handle_wordWrapMode(HandleRef _this) {
        return static_cast<WrapMode>(THIS->wordWrapMode());
    }

    void Handle_appendHtml(HandleRef _this, const std::string& html) {
        THIS->appendHtml(QString::fromStdString(html));
    }

    void Handle_appendPlainText(HandleRef _this, const std::string& text) {
        THIS->appendPlainText(QString::fromStdString(text));
    }

    void Handle_centerCursor(HandleRef _this) {
        THIS->centerCursor();
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

    void Handle_insertPlainText(HandleRef _this, const std::string& text) {
        THIS->insertPlainText(QString::fromStdString(text));
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

    void Handle_setPlainText(HandleRef _this, const std::string& text) {
        THIS->setPlainText(QString::fromStdString(text));
    }

    void Handle_undo(HandleRef _this) {
        THIS->undo();
    }

    void Handle_zoomIn(HandleRef _this, const std::optional<int32_t>& range) {
        THIS->zoomIn(range.value_or(1));
    }

    void Handle_zoomOut(HandleRef _this, const std::optional<int32_t>& range) {
        THIS->zoomOut(range.value_or(1));
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

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QPlainTextEdit(AS_QWIDGET_PTR(parent)));
    }

    HandleRef create(const std::string& text, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QPlainTextEdit(QString::fromStdString(text), AS_QWIDGET_PTR(parent)));
    }
}
