#include "generated/BoxLayout.h"

#include <QBoxLayout>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((BoxLayoutWithHandler*)_this)

#include "BoxLayoutInternal.h"

namespace BoxLayout
{
    class BoxLayoutWithHandler : public QBoxLayout {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit BoxLayoutWithHandler(QBoxLayout::Direction direction, const std::shared_ptr<SignalHandler>& handler)
            : QBoxLayout(direction), relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
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
