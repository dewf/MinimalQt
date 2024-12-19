#include "generated/Label.h"
#include "LabelInternal.h"

#include <QLabel>
#include <utility>
#include "util/convert.h"

#include "PixmapInternal.h"

#define THIS ((LabelWithHandler*)_this)

namespace Label
{
    class LabelWithHandler : public QLabel {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit LabelWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    void Handle_setAlignment(HandleRef _this, Alignment align) {
        THIS->setAlignment(static_cast<Qt::AlignmentFlag>(align));
    }

    bool Handle_hasSelectedText(HandleRef _this) {
        return THIS->hasSelectedText();
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

    void Handle_setPixmap(HandleRef _this, Pixmap::HandleRef pixmap) {
        THIS->setPixmap(pixmap->qPixmap);
    }

    void Handle_setScaledContents(HandleRef _this, bool state) {
        THIS->setScaledContents(state);
    }

    std::string Handle_selectedText(HandleRef _this) {
        return THIS->selectedText().toStdString();
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    void Handle_setTextFormat(HandleRef _this, TextFormat format) {
        THIS->setTextFormat(static_cast<Qt::TextFormat>(format));
    }

    void Handle_setTextInteractionFlags(HandleRef _this, TextInteractionFlags interactionFlags) {
        THIS->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(interactionFlags));
    }

    void Handle_setWordWrap(HandleRef _this, bool state) {
        THIS->setWordWrap(state);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new LabelWithHandler(handler));
    }

    HandleRef createNoHandler() {
        return reinterpret_cast<HandleRef>(new QLabel());
    }
}

#include "Label.moc"
