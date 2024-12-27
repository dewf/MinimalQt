#include "generated/Label.h"
#include "LabelInternal.h"

#include <utility>
#include "util/convert.h"

#include "PixmapInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define LABEL_THIS (WRAPPER->getActual())

namespace Label
{
    void Handle_setAlignment(HandleRef _this, Alignment align) {
        LABEL_THIS->setAlignment(static_cast<Qt::AlignmentFlag>(align));
    }

    bool Handle_hasSelectedText(HandleRef _this) {
        return LABEL_THIS->hasSelectedText();
    }

    void Handle_setIndent(HandleRef _this, int32_t indent) {
        LABEL_THIS->setIndent(indent);
    }

    void Handle_setMargin(HandleRef _this, int32_t margin) {
        LABEL_THIS->setMargin(margin);
    }

    void Handle_setOpenExternalLinks(HandleRef _this, bool state) {
        LABEL_THIS->setOpenExternalLinks(state);
    }

    void Handle_setPixmap(HandleRef _this, Pixmap::HandleRef pixmap) {
        LABEL_THIS->setPixmap(pixmap->qPixmap);
    }

    void Handle_setScaledContents(HandleRef _this, bool state) {
        LABEL_THIS->setScaledContents(state);
    }

    std::string Handle_selectedText(HandleRef _this) {
        return LABEL_THIS->selectedText().toStdString();
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        LABEL_THIS->setText(QString::fromStdString(text));
    }

    void Handle_setTextFormat(HandleRef _this, TextFormat format) {
        LABEL_THIS->setTextFormat(static_cast<Qt::TextFormat>(format));
    }

    void Handle_setTextInteractionFlags(HandleRef _this, TextInteractionFlags interactionFlags) {
        LABEL_THIS->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(interactionFlags));
    }

    void Handle_setWordWrap(HandleRef _this, bool state) {
        LABEL_THIS->setWordWrap(state);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QLabel(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
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
}
