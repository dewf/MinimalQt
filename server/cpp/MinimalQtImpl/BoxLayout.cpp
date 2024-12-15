#include "generated/BoxLayout.h"

#include <QBoxLayout>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((BoxLayoutWithHandler*)_this)

namespace BoxLayout
{
    class BoxLayoutWithHandler : public QBoxLayout {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { SignalMaskFlags::Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { SignalMaskFlags::ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // Layout: (none)
            // BoxLayout: (none)
        };
    public:
        explicit BoxLayoutWithHandler(QBoxLayout::Direction direction, std::shared_ptr<SignalHandler> handler) : QBoxLayout(direction), handler(std::move(handler)) {}
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
                inherited_Layout_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_Layout_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Layout (none)
        // BoxLayout (none)
    };

    void Handle_setDirection(HandleRef _this, Direction dir) {
        auto qDir = static_cast<QBoxLayout::Direction>(dir);
        THIS->setDirection(qDir);
    }

    void Handle_addSpacing(HandleRef _this, int32_t size) {
        THIS->addSpacing(size);
    }

    void Handle_addStretch(HandleRef _this, int32_t stretch) {
        THIS->addStretch(stretch);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->addWidget(reinterpret_cast<QWidget *>(widget));
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t stretch) {
        THIS->addWidget(reinterpret_cast<QWidget *>(widget), stretch);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t stretch, Enums::Alignment align) {
        THIS->addWidget(reinterpret_cast<QWidget *>(widget), stretch, static_cast<Qt::AlignmentFlag>(align));
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout) {
        THIS->addLayout(reinterpret_cast<QLayout *>(layout));
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t stretch) {
        THIS->addLayout(reinterpret_cast<QLayout *>(layout), stretch);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Direction dir, const std::shared_ptr<SignalHandler>& handler) {
        auto qDir = static_cast<QBoxLayout::Direction>(dir);
        return reinterpret_cast<HandleRef>(new BoxLayoutWithHandler(qDir, handler));
    }

    HandleRef createNoHandler(Direction dir) {
        return reinterpret_cast<HandleRef>(new QBoxLayout((QBoxLayout::Direction) dir));
    }
}

#include "BoxLayout.moc"
