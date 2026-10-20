#include "generated/TextEdit.h"
#include "TextEditInternal.h"

#include "ColorInternal.h"
#include "FontInternal.h"
#include "RegularExpressionInternal.h"
#include "TextCursorInternal.h"
#include "TextCharFormatInternal.h"
#include "UrlInternal.h"
#include "VariantInternal.h"
#include "ObjectInternal.h"
#include "PointInternal.h"
#include "RectInternal.h"
#include "WidgetInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Widget;
using namespace ::Point;
using namespace ::Rect;
using namespace ::Enums;
using namespace ::AbstractScrollArea;
using namespace ::Menu;
using namespace ::TextCursor;
using namespace ::TextCharFormat;
using namespace ::TextDocument;
using namespace ::TextOption;
using namespace ::RegularExpression;
using namespace ::Url;
using namespace ::Color;
using namespace ::Font;
using namespace ::Variant;

#define THIS (reinterpret_cast<QTextEdit*>(_this))

namespace TextEdit
{
    // ExtraSelection struct ==============================
    namespace ExtraSelection {

        #define EXTRASEL_THIS (reinterpret_cast<QTextEdit::ExtraSelection*>(_this))

        TextCursor::OwnedRef Handle_cursor(HandleRef _this) {
            return TEXTCURSOR_HEAP_NEW(EXTRASEL_THIS->cursor);
        }

        TextCharFormat::OwnedRef Handle_format(HandleRef _this) {
            return TEXTCHARFORMAT_HEAP_NEW(EXTRASEL_THIS->format);
        }

        void Owned_dispose(OwnedRef _this) {
            delete EXTRASEL_THIS;
        }

        OwnedRef create(TextCursor::HandleRef cursor, TextCharFormat::HandleRef format) {
            return TEXTEDIT_EXTRASEL_HEAP_NEW(QTEXTCURSOR_VALUE(cursor), QTEXTCHARFORMAT_VALUE(format));
        }
    }

    // TextEdit proper ======================================

    bool Handle_acceptRichText(HandleRef _this) {
        return THIS->acceptRichText();
    }

    Flags<Alignment> Handle_alignment(HandleRef _this) {
        return static_cast<Flags<Alignment>>(THIS->alignment());
    }

    std::string Handle_anchorAt(HandleRef _this, Point::HandleRef pos) {
        return THIS->anchorAt(QPOINT_VALUE(pos)).toStdString();
    }

    Flags<AutoFormatting> Handle_getAutoFormatting(HandleRef _this) {
        return static_cast<Flags<AutoFormatting>>(THIS->autoFormatting());
    }

    bool Handle_canPaste(HandleRef _this) {
        return THIS->canPaste();
    }

    Menu::HandleRef Handle_createStandardContextMenu(HandleRef _this) {
        return reinterpret_cast<Menu::HandleRef>(THIS->createStandardContextMenu());
    }

    Menu::HandleRef Handle_createStandardContextMenu(HandleRef _this, Point::HandleRef position) {
        return reinterpret_cast<Menu::HandleRef>(THIS->createStandardContextMenu(QPOINT_VALUE(position)));
    }

    TextCharFormat::OwnedRef Handle_currentCharFormat(HandleRef _this) {
        return TEXTCHARFORMAT_HEAP_NEW(THIS->currentCharFormat());
    }

    Font::OwnedRef Handle_currentFont(HandleRef _this) {
        return FONT_HEAP_NEW(THIS->currentFont());
    }

    TextCursor::OwnedRef Handle_cursorForPosition(HandleRef _this, Point::HandleRef pos) {
        return TEXTCURSOR_HEAP_NEW(THIS->cursorForPosition(QPOINT_VALUE(pos)));
    }

    Rect::OwnedRef Handle_cursorRect(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->cursorRect());
    }

    Rect::OwnedRef Handle_cursorRect(HandleRef _this, TextCursor::HandleRef cursor) {
        return RECT_HEAP_NEW(THIS->cursorRect());
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
        return fromQList<QTextEdit::ExtraSelection,ExtraSelection::OwnedRef>(THIS->extraSelections(),
            [](auto es) {
                return TEXTEDIT_EXTRASEL_HEAP_NEW(es);
            });
    }

    bool Handle_find(HandleRef _this, const std::string& exp, Flags<FindFlags> options_ /* 0 */) {
        return THIS->find(QString::fromStdString(exp), static_cast<QTextDocument::FindFlags>(options_.value()));
    }

    bool Handle_find(HandleRef _this, RegularExpression::HandleRef exp, Flags<FindFlags> options_ /* 0 */) {
        return THIS->find(QREGEX_VALUE(exp), static_cast<QTextDocument::FindFlags>(options_.value()));
    }

    std::string Handle_fontFamily(HandleRef _this) {
        return THIS->fontFamily().toStdString();
    }

    bool Handle_fontItalic(HandleRef _this) {
        return THIS->fontItalic();
    }

    double Handle_fontPointSize(HandleRef _this) {
        return THIS->fontPointSize();
    }

    bool Handle_fontUnderline(HandleRef _this) {
        return THIS->fontUnderline();
    }

    int32_t Handle_fontWeight(HandleRef _this) {
        return THIS->fontWeight();
    }

    bool Handle_isReadOnly(HandleRef _this) {
        return THIS->isReadOnly();
    }

    bool Handle_isUndoRedoEnabled(HandleRef _this) {
        return THIS->isUndoRedoEnabled();
    }

    int32_t Handle_lineWrapColumnOrWidth(HandleRef _this) {
        return THIS->lineWrapColumnOrWidth();
    }

    LineWrapMode Handle_getLineWrapMode(HandleRef _this) {
        return static_cast<LineWrapMode>(THIS->lineWrapMode());
    }

    Variant::OwnedRef Handle_loadResource(HandleRef _this, int32_t type, Url::HandleRef name) {
        return VARIANT_HEAP_NEW(THIS->loadResource(type, QURL_VALUE(name)));
    }

    void Handle_mergeCurrentCharFormat(HandleRef _this, TextCharFormat::HandleRef modifier) {
        THIS->mergeCurrentCharFormat(QTEXTCHARFORMAT_VALUE(modifier));
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

    void Handle_setAcceptRichText(HandleRef _this, bool accept) {
        THIS->setAcceptRichText(accept);
    }

    void Handle_setAutoFormatting(HandleRef _this,  Flags<AutoFormatting> features) {
        THIS->setAutoFormatting(static_cast<QTextEdit::AutoFormatting>(features.value())); // Qt uint/int nonsense
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
        const auto qList = toQList<ExtraSelection::HandleRef,QTextEdit::ExtraSelection>(selections, [](auto es) {
            return QTEXTEDIT_EXTRASEL_VALUE(es);
        });
        THIS->setExtraSelections(qList);
    }

    void Handle_setLineWrapColumnOrWidth(HandleRef _this, int32_t w) {
        THIS->setLineWrapColumnOrWidth(w);
    }

    void Handle_setLineWrapMode(HandleRef _this, LineWrapMode mode) {
        THIS->setLineWrapMode(static_cast<QTextEdit::LineWrapMode>(mode));
    }

    void Handle_setOverwriteMode(HandleRef _this, bool overwrite) {
        THIS->setOverwriteMode(overwrite);
    }

    void Handle_setPlaceholderText(HandleRef _this, const std::string& placeholderText) {
        THIS->setPlaceholderText(QString::fromStdString(placeholderText));
    }

    void Handle_setReadOnly(HandleRef _this, bool ro) {
        THIS->setReadOnly(ro);
    }

    void Handle_setTabChangesFocus(HandleRef _this, bool b) {
        THIS->setTabChangesFocus(b);
    }

    void Handle_setTabStopDistance(HandleRef _this, double distance) {
        THIS->setTabStopDistance(distance);
    }

    void Handle_setTextCursor(HandleRef _this, TextCursor::HandleRef cursor) {
        THIS->setTextCursor(QTEXTCURSOR_VALUE(cursor));
    }

    void Handle_setTextInteractionFlags(HandleRef _this, Flags<TextInteractionFlags> flags_) {
        THIS->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(flags_.value()));
    }

    void Handle_setUndoRedoEnabled(HandleRef _this, bool enable) {
        THIS->setUndoRedoEnabled(enable);
    }

    void Handle_setWordWrapMode(HandleRef _this, WrapMode policy) {
        THIS->setWordWrapMode(static_cast<QTextOption::WrapMode>(policy));
    }

    bool Handle_tabChangesFocus(HandleRef _this) {
        return THIS->tabChangesFocus();
    }

    double Handle_tabStopDistance(HandleRef _this) {
        return THIS->tabStopDistance();
    }

    Color::OwnedRef Handle_textBackgroundColor(HandleRef _this) {
        return COLOR_HEAP_NEW(THIS->textBackgroundColor());
    }

    Color::OwnedRef Handle_textColor(HandleRef _this) {
        return COLOR_HEAP_NEW(THIS->textColor());
    }

    TextCursor::OwnedRef Handle_textCursor(HandleRef _this) {
        return TEXTCURSOR_HEAP_NEW(THIS->textCursor());
    }

    Flags<TextInteractionFlags> Handle_textInteractionFlags(HandleRef _this) {
        return static_cast<Flags<TextInteractionFlags>>(THIS->textInteractionFlags());
    }

    std::string Handle_toHtml(HandleRef _this) {
        return THIS->toHtml().toStdString();
    }

    std::string Handle_toMarkdown(HandleRef _this, Flags<MarkdownFeatures> features /* MarkDownFeatures::MarkdownDialectGitHub */) {
        return THIS->toMarkdown(static_cast<QTextDocument::MarkdownFeatures>(features.value())).toStdString();
    }

    std::string Handle_toPlainText(HandleRef _this) {
        return THIS->toPlainText().toStdString();
    }

    WrapMode Handle_wordWrapMode(HandleRef _this) {
        return static_cast<WrapMode>(THIS->wordWrapMode());
    }

    void Handle_append(HandleRef _this, const std::string& text) {
        THIS->append(QString::fromStdString(text));
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

    void Handle_insertHtml(HandleRef _this, const std::string& text) {
        THIS->insertHtml(QString::fromStdString(text));
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

    void Handle_scrollToAnchor(HandleRef _this, const std::string& name) {
        THIS->scrollToAnchor(QString::fromStdString(name));
    }

    void Handle_selectAll(HandleRef _this) {
        THIS->selectAll();
    }

    void Handle_setAlignment(HandleRef _this, Flags<Alignment> a) {
        THIS->setAlignment(static_cast<Qt::Alignment>(a.value()));
    }

    void Handle_setCurrentFont(HandleRef _this, Font::HandleRef f) {
        THIS->setCurrentFont(QFONT_VALUE(f));
    }

    void Handle_setFontFamily(HandleRef _this, const std::string& fontFamily) {
        THIS->setFontFamily(QString::fromStdString(fontFamily));
    }

    void Handle_setFontItalic(HandleRef _this, bool italic) {
        THIS->setFontItalic(italic);
    }

    void Handle_setFontPointSize(HandleRef _this, double s) {
        THIS->setFontPointSize(s);
    }

    void Handle_setFontUnderline(HandleRef _this, bool underline) {
        THIS->setFontUnderline(underline);
    }

    void Handle_setFontWeight(HandleRef _this, int32_t weight) {
        THIS->setFontWeight(weight);
    }

    void Handle_setHtml(HandleRef _this, const std::string& text) {
        THIS->setHtml(QString::fromStdString(text));
    }

    void Handle_setMarkdown(HandleRef _this, const std::string& markdown) {
        THIS->setMarkdown(QString::fromStdString(markdown));
    }

    void Handle_setPlainText(HandleRef _this, const std::string& text) {
        THIS->setPlainText(QString::fromStdString(text));
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    void Handle_setTextBackgroundColor(HandleRef _this, Color::HandleRef c) {
        THIS->setTextBackgroundColor(QCOLOR_VALUE(c));
    }

    void Handle_setTextColor(HandleRef _this, Color::HandleRef c) {
        THIS->setTextColor(QCOLOR_VALUE(c));
    }

    void Handle_undo(HandleRef _this) {
        THIS->undo();
    }

    void Handle_zoomIn(HandleRef _this, int32_t range /* 1 */) {
        THIS->zoomIn(range);
    }

    void Handle_zoomOut(HandleRef _this, int32_t range /* 1 */) {
        THIS->zoomOut(range);
    }

    SignalConnectionRef Handle_connect_CopyAvailable(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextEdit::copyAvailable, [handler](bool b) {
            handler->sig_copyAvailable(b);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CurrentCharFormatChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextEdit::currentCharFormatChanged, [handler](const QTextCharFormat &format) {
            QTextCharFormat format2(format);
            handler->sig_currentCharFormatChanged(reinterpret_cast<TextCharFormat::HandleRef>(&format2));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CursorPositionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextEdit::cursorPositionChanged, [handler] {
            handler->sig_cursorPositionChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_RedoAvailable(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextEdit::redoAvailable, [handler](bool b) {
            handler->sig_redoAvailable(b);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SelectionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextEdit::selectionChanged, [handler] {
            handler->sig_selectionChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TextChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextEdit::textChanged, [handler] {
            handler->sig_textChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_UndoAvailable(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextEdit::undoAvailable, [handler](bool b) {
            handler->sig_undoAvailable(b);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto edit = AS_QTEXTEDIT_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(edit);
        case Handle_CastTarget::Widget_Handle:
            return static_cast<QWidget*>(edit);
        case Handle_CastTarget::Frame_Handle:
            return static_cast<QFrame*>(edit);
        case Handle_CastTarget::AbstractScrollArea_Handle:
            return static_cast<QAbstractScrollArea*>(edit);
        }
        std::unreachable();
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QTextEdit(AS_QWIDGET_PTR(parent)));
    }

    HandleRef create(const std::string& text, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QTextEdit(QString::fromStdString(text), AS_QWIDGET_PTR(parent)));
    }
}
