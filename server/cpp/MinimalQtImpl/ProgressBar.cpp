#include "generated/ProgressBar.h"

#include <QProgressBar>

#include "util/SignalStuff.h"
#include "util/convert.h"
#include "IconInternal.h"

#define THIS ((ProgressBarWithHandler*)_this)

namespace ProgressBar
{
    class ProgressBarWithHandler : public QProgressBar {
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
            // ProgressBar:
            { ValueChanged, SIGNAL(valueChanged(int)), SLOT(onValueChanged(int)) },
        };
    public:
        explicit ProgressBarWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            handler->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Widget ==================
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->
                inherited_Widget_SignalHandler()->
                    customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowIconChanged((Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowTitleChanged(title.toStdString());
        }
        // ProgressBar =============
        void onValueChanged(int value) const {
            handler->valueChanged(value);
        }
    };

    void Handle_setAlignment(HandleRef _this, Alignment align) {
        THIS->setAlignment(static_cast<Qt::Alignment>(align));
    }

    void Handle_setFormat(HandleRef _this, const std::string& format) {
        THIS->setFormat(QString::fromStdString(format));
    }

    void Handle_setInvertedAppearance(HandleRef _this, bool invert) {
        THIS->setInvertedAppearance(invert);
    }

    void Handle_setMaximum(HandleRef _this, int32_t value) {
        THIS->setMaximum(value);
    }

    void Handle_setMinimum(HandleRef _this, int32_t value) {
        THIS->setMinimum(value);
    }

    void Handle_setOrientation(HandleRef _this, Orientation orient) {
        THIS->setOrientation(static_cast<Qt::Orientation>(orient));
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    void Handle_setTextDirection(HandleRef _this, Direction direction) {
        THIS->setTextDirection(static_cast<QProgressBar::Direction>(direction));
    }

    void Handle_setTextVisible(HandleRef _this, bool visible) {
        THIS->setTextVisible(visible);
    }

    void Handle_setValue(HandleRef _this, int32_t value) {
        THIS->setValue(value);
    }

    void Handle_setRange(HandleRef _this, int32_t min, int32_t max) {
        THIS->setRange(min, max);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new ProgressBarWithHandler(handler));
    }
}

#include "ProgressBar.moc"
