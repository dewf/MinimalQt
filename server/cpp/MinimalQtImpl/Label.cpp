#include "generated/Label.h"

#include <QLabel>
#include <utility>
#include "util/convert.h"

#include "util/SignalStuff.h"
#include "PixmapInternal.h"

#define THIS ((LabelWithHandler*)_this)

namespace Label
{
    class LabelWithHandler : public QLabel {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // Widget:
            { CustomContextMenuRequested, SIGNAL(customContextMenuRequested(QPoint)), SLOT(onCustomContextMenuRequested(QPoint)) },
            { WindowIconChanged, SIGNAL(windowIconChanged(QIcon)), SLOT(onWindowIconChanged(QIcon)) },
            { WindowTitleChanged, SIGNAL(windowTitleChanged(QString)), SLOT(onWindowTitleChanged(QString)) },
            // Frame:
            // ..... (none)
            // Label:
            { LinkActivated, SIGNAL(linkActivated(QString)), SLOT(onLinkActivated(QString)) },
            { LinkHovered, SIGNAL(linkHovered(QString)), SLOT(onLinkHovered(QString)) },
        };
    public:
        explicit LabelWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanged_OLD(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            handler->
                inherited_Frame_SignalHandler()->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_Frame_SignalHandler()->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Widget ==================
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->
                inherited_Frame_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->
                inherited_Frame_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    windowIconChanged((Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->
                inherited_Frame_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    windowTitleChanged(title.toStdString());
        }
        // Frame ====================
        // ...... (none)
        // Label ====================
        void onLinkActivated(const QString& link) const {
            handler->linkActivated(link.toStdString());
        }
        void onLinkHovered(const QString& link) const {
            handler->linkHovered(link.toStdString());
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
