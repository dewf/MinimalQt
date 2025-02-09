#include "generated/Label.h"
#include "LabelInternal.h"

#include "PixmapInternal.h"
#include "ObjectInternal.h"

using namespace ::Object;
using namespace ::Frame;
using namespace ::Icon;
using namespace ::Enums;
using namespace ::Pixmap;
using namespace ::Widget;

#define THIS (reinterpret_cast<QLabel*>(_this))

namespace Label
{
    Alignment Handle_alignment(HandleRef _this) {
        return Alignment(THIS->alignment());
    }

    Widget::HandleRef Handle_buddy(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->buddy());
    }

    bool Handle_hasScaledContents(HandleRef _this) {
        return THIS->hasScaledContents();
    }

    bool Handle_hasSelectedText(HandleRef _this) {
        return THIS->hasSelectedText();
    }

    int32_t Handle_indent(HandleRef _this) {
        return THIS->indent();
    }

    int32_t Handle_margin(HandleRef _this) {
        return THIS->margin();
    }

    bool Handle_openExternalLinks(HandleRef _this) {
        return THIS->openExternalLinks();
    }

    Pixmap::OwnedRef Handle_pixmap(HandleRef _this) {
        return PIXMAP_HEAP_NEW(THIS->pixmap());
    }

    std::string Handle_selectedText(HandleRef _this) {
        return THIS->selectedText().toStdString();
    }

    int32_t Handle_selectionStart(HandleRef _this) {
        return THIS->selectionStart();
    }

    void Handle_setAlignment(HandleRef _this, Alignment align) {
        THIS->setAlignment(static_cast<Qt::AlignmentFlag>(align.value));
    }

    void Handle_setBuddy(HandleRef _this, Widget::HandleRef buddy) {
        THIS->setBuddy(AS_QWIDGET_PTR(buddy));
    }

    void Handle_setIndent(HandleRef _this, int32_t indent) {
        THIS->setIndent(indent);
    }

    void Handle_setMargin(HandleRef _this, int32_t margin) {
        THIS->setMargin(margin);
    }

    void Handle_setOpenExternalLinks(HandleRef _this, bool state) {
        THIS->setOpenExternalLinks(state);
    }

    void Handle_setScaledContents(HandleRef _this, bool state) {
        THIS->setScaledContents(state);
    }

    void Handle_setSelection(HandleRef _this, int32_t start, int32_t length) {
        THIS->setSelection(start, length);
    }

    void Handle_setTextFormat(HandleRef _this, TextFormatEnum format) {
        THIS->setTextFormat(static_cast<Qt::TextFormat>(format));
    }

    void Handle_setTextInteractionFlags(HandleRef _this, TextInteractionFlags interactionFlags) {
        THIS->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(interactionFlags.value));
    }

    void Handle_setWordWrap(HandleRef _this, bool state) {
        THIS->setWordWrap(state);
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    TextFormatEnum Handle_textFormat(HandleRef _this) {
        return static_cast<TextFormatEnum>(THIS->textFormat());
    }

    TextInteractionFlags Handle_textInteractionFlags(HandleRef _this) {
        return TextInteractionFlags(THIS->textInteractionFlags());
    }

    bool Handle_wordWrap(HandleRef _this) {
        return THIS->wordWrap();
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_setNum(HandleRef _this, int32_t num) {
        THIS->setNum(num);
    }

    void Handle_setNum(HandleRef _this, double num) {
        THIS->setNum(num);
    }

    void Handle_setPixmap(HandleRef _this, Pixmap::HandleRef pixmap) {
        THIS->setPixmap(QPIXMAP_VALUE(pixmap));
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    SignalConnectionRef Handle_connect_LinkActivated(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QLabel::linkActivated, [handler](const QString& link) {
            handler->linkActivated(link.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_LinkHovered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QLabel::linkHovered, [handler](const QString& link) {
            handler->linkHovered(link.toStdString());
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */, WindowFlags flags_ /* 0 */) {
        return reinterpret_cast<HandleRef>(new QLabel(AS_QWIDGET_PTR(parent), static_cast<Qt::WindowFlags>(flags_.value)));
    }

    HandleRef create(const std::string& text, Widget::HandleRef parent /* nullptr */, WindowFlags flags_ /* 0 */) {
        return reinterpret_cast<HandleRef>(new QLabel(QString::fromStdString(text), AS_QWIDGET_PTR(parent), static_cast<Qt::WindowFlags>(flags_.value)));
    }
}
