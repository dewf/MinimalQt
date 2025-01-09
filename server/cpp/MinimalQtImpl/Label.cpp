#include "generated/Label.h"
#include "LabelInternal.h"

#include "PixmapInternal.h"
#include "ObjectInternal.h"

#define THIS (reinterpret_cast<QLabel*>(_this))

namespace Label
{
    Alignment Handle_alignment(HandleRef _this) {
        return THIS->alignment();
    }

    void Handle_setAlignment(HandleRef _this, Alignment align) {
        THIS->setAlignment(static_cast<Qt::AlignmentFlag>(align));
    }

    bool Handle_hasSelectedText(HandleRef _this) {
        return THIS->hasSelectedText();
    }

    int32_t Handle_indent(HandleRef _this) {
        return THIS->indent();
    }

    void Handle_setIndent(HandleRef _this, int32_t indent) {
        THIS->setIndent(indent);
    }

    int32_t Handle_margin(HandleRef _this) {
        return THIS->margin();
    }

    void Handle_setMargin(HandleRef _this, int32_t margin) {
        THIS->setMargin(margin);
    }

    bool Handle_openExternalLinks(HandleRef _this) {
        return THIS->openExternalLinks();
    }

    void Handle_setOpenExternalLinks(HandleRef _this, bool state) {
        THIS->setOpenExternalLinks(state);
    }

    Pixmap::OwnedRef Handle_getPixmap(HandleRef _this) {
        return new Pixmap::__Owned { THIS->pixmap() };
    }

    void Handle_setPixmap(HandleRef _this, Pixmap::HandleRef pixmap) {
        THIS->setPixmap(pixmap->qPixmap);
    }

    bool Handle_hasScaledContents(HandleRef _this) {
        return THIS->hasScaledContents();
    }

    void Handle_setScaledContents(HandleRef _this, bool state) {
        THIS->setScaledContents(state);
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

    TextFormat Handle_getTextFormat(HandleRef _this) {
        return static_cast<TextFormat>(THIS->textFormat());
    }

    void Handle_setTextFormat(HandleRef _this, TextFormat format) {
        THIS->setTextFormat(static_cast<Qt::TextFormat>(format));
    }

    TextInteractionFlags Handle_getTextInteractionFlags(HandleRef _this) {
        return THIS->textInteractionFlags();
    }

    void Handle_setTextInteractionFlags(HandleRef _this, TextInteractionFlags interactionFlags) {
        THIS->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(interactionFlags));
    }

    bool Handle_wordWrap(HandleRef _this) {
        return THIS->wordWrap();
    }

    void Handle_setWordWrap(HandleRef _this, bool state) {
        THIS->setWordWrap(state);
    }

    Widget::HandleRef Handle_buddy(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->buddy());
    }

    void Handle_setBuddy(HandleRef _this, Widget::HandleRef buddy) {
        THIS->setBuddy(AS_QWIDGET_PTR(buddy));
    }

    int32_t Handle_selectionStart(HandleRef _this) {
        return THIS->selectionStart();
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_setSelection(HandleRef _this, int32_t start, int32_t length) {
        THIS->setSelection(start, length);
    }

    void Handle_setNum(HandleRef _this, int32_t num) {
        THIS->setNum(num);
    }

    void Handle_setNum(HandleRef _this, double num) {
        THIS->setNum(num);
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

    HandleRef create(const CreateOptions& opts) {
        QWidget *parent = opts.mapOrDefaultParent([](auto handle) { return reinterpret_cast<Widget::SignalWrapper*>(handle)->getActual(); }, static_cast<QWidget*>(nullptr));
        const auto qFlags = opts.mapOrDefaultFlags_([](auto flags) { return static_cast<Qt::WindowFlags>(flags); }, Qt::WindowFlags());
        return reinterpret_cast<HandleRef>(new QLabel(parent, qFlags));
    }

    HandleRef create(const std::string& text, const CreateOptions& opts) {
        QWidget *parent = opts.mapOrDefaultParent([](auto handle) { return reinterpret_cast<Widget::SignalWrapper*>(handle)->getActual(); }, static_cast<QWidget*>(nullptr));
        const auto qFlags = opts.mapOrDefaultFlags_([](auto flags) { return static_cast<Qt::WindowFlags>(flags); }, Qt::WindowFlags());
        return reinterpret_cast<HandleRef>(new QLabel(QString::fromStdString(text), parent, qFlags));
    }
}
