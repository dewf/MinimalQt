#include "generated/Label.h"
#include "LabelInternal.h"

#include <utility>
#include "util/convert.h"

#include "PixmapInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define LABEL_THIS (WRAPPER->getActual())

namespace Label
{
    Alignment Handle_alignment(HandleRef _this) {
        return LABEL_THIS->alignment();
    }

    void Handle_setAlignment(HandleRef _this, Alignment align) {
        LABEL_THIS->setAlignment(static_cast<Qt::AlignmentFlag>(align));
    }

    bool Handle_hasSelectedText(HandleRef _this) {
        return LABEL_THIS->hasSelectedText();
    }

    int32_t Handle_indent(HandleRef _this) {
        return LABEL_THIS->indent();
    }

    void Handle_setIndent(HandleRef _this, int32_t indent) {
        LABEL_THIS->setIndent(indent);
    }

    int32_t Handle_margin(HandleRef _this) {
        return LABEL_THIS->margin();
    }

    void Handle_setMargin(HandleRef _this, int32_t margin) {
        LABEL_THIS->setMargin(margin);
    }

    bool Handle_openExternalLinks(HandleRef _this) {
        return LABEL_THIS->openExternalLinks();
    }

    void Handle_setOpenExternalLinks(HandleRef _this, bool state) {
        LABEL_THIS->setOpenExternalLinks(state);
    }

    Pixmap::OwnedRef Handle_getPixmap(HandleRef _this) {
        return new Pixmap::__Owned { LABEL_THIS->pixmap() };
    }

    void Handle_setPixmap(HandleRef _this, Pixmap::HandleRef pixmap) {
        LABEL_THIS->setPixmap(pixmap->qPixmap);
    }

    bool Handle_hasScaledContents(HandleRef _this) {
        return LABEL_THIS->hasScaledContents();
    }

    void Handle_setScaledContents(HandleRef _this, bool state) {
        LABEL_THIS->setScaledContents(state);
    }

    std::string Handle_selectedText(HandleRef _this) {
        return LABEL_THIS->selectedText().toStdString();
    }

    std::string Handle_text(HandleRef _this) {
        return LABEL_THIS->text().toStdString();
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        LABEL_THIS->setText(QString::fromStdString(text));
    }

    TextFormat Handle_getTextFormat(HandleRef _this) {
        return static_cast<TextFormat>(LABEL_THIS->textFormat());
    }

    void Handle_setTextFormat(HandleRef _this, TextFormat format) {
        LABEL_THIS->setTextFormat(static_cast<Qt::TextFormat>(format));
    }

    TextInteractionFlags Handle_getTextInteractionFlags(HandleRef _this) {
        return LABEL_THIS->textInteractionFlags();
    }

    void Handle_setTextInteractionFlags(HandleRef _this, TextInteractionFlags interactionFlags) {
        LABEL_THIS->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(interactionFlags));
    }

    bool Handle_wordWrap(HandleRef _this) {
        return LABEL_THIS->wordWrap();
    }

    void Handle_setWordWrap(HandleRef _this, bool state) {
        LABEL_THIS->setWordWrap(state);
    }

    Widget::HandleRef Handle_buddy(HandleRef _this) {
        if (const auto widget = LABEL_THIS->buddy(); widget != nullptr) {
            const auto wrapper = wrapperForQObject(widget);
            assert(wrapper != nullptr);
            return reinterpret_cast<Widget::HandleRef>(wrapper);
        }
        return nullptr;
    }

    void Handle_setBuddy(HandleRef _this, Widget::HandleRef buddy) {
        const auto widget = reinterpret_cast<Widget::SignalWrapper*>(buddy);
        LABEL_THIS->setBuddy(widget->getActual());
    }

    int32_t Handle_selectionStart(HandleRef _this) {
        return LABEL_THIS->selectionStart();
    }

    void Handle_clear(HandleRef _this) {
        LABEL_THIS->clear();
    }

    void Handle_setSelection(HandleRef _this, int32_t start, int32_t length) {
        LABEL_THIS->setSelection(start, length);
    }

    void Handle_setNum(HandleRef _this, int32_t num) {
        LABEL_THIS->setNum(num);
    }

    void Handle_setNum(HandleRef _this, double num) {
        LABEL_THIS->setNum(num);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    class NullSignalHandler : public ServerObject, public SignalHandler, public Frame::SignalHandler, public Widget::SignalHandler, public Object::SignalHandler {
    public:
        // object
        void destroyedByQt() override {}
        void destroyed(Object::HandleRef obj) override {}
        void objectNameChanged(const std::string &objectName) override {}
        // widget
        Object::SignalHandler * inherited_Object_SignalHandler() override { return this; }
        void customContextMenuRequested(Point pos) override {}
        void windowIconChanged(Icon::HandleRef icon) override {}
        void windowTitleChanged(const std::string &title) override {}
        // frame
        Widget::SignalHandler * inherited_Widget_SignalHandler() override { return this; }
        // label
        Frame::SignalHandler * inherited_Frame_SignalHandler() override { return this; }
        void linkActivated(const std::string &link) override {}
        void linkHovered(const std::string &link) override {}
    };

    HandleRef createNoHandler() {
        const auto wrapper = new SignalWrapper(new QLabel(), std::make_shared<NullSignalHandler>());
        return reinterpret_cast<HandleRef>(wrapper);
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler, const CreateOptions& opts) {
        QWidget *parent = opts.mapOrDefaultParent([](auto handle) { return reinterpret_cast<Widget::SignalWrapper*>(handle)->getActual(); }, static_cast<QWidget*>(nullptr));
        const auto qFlags = opts.mapOrDefaultFlags_([](auto flags) { return static_cast<Qt::WindowFlags>(flags); }, Qt::WindowFlags());
        const auto wrapper = new SignalWrapper(new QLabel(parent, qFlags), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    HandleRef create(const std::string& text, const std::shared_ptr<SignalHandler>& handler, const CreateOptions& opts) {
        QWidget *parent = opts.mapOrDefaultParent([](auto handle) { return reinterpret_cast<Widget::SignalWrapper*>(handle)->getActual(); }, static_cast<QWidget*>(nullptr));
        const auto qFlags = opts.mapOrDefaultFlags_([](auto flags) { return static_cast<Qt::WindowFlags>(flags); }, Qt::WindowFlags());
        const auto wrapper = new SignalWrapper(new QLabel(QString::fromStdString(text), parent, qFlags), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
