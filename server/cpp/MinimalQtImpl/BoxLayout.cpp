#include "generated/BoxLayout.h"
#include "BoxLayoutInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define BOXLAYOUT_THIS (WRAPPER->getActual())

namespace BoxLayout
{
    void Handle_setDirection(HandleRef _this, Direction dir) {
        auto qDir = static_cast<QBoxLayout::Direction>(dir);
        BOXLAYOUT_THIS->setDirection(qDir);
    }

    void Handle_addSpacing(HandleRef _this, int32_t size) {
        BOXLAYOUT_THIS->addSpacing(size);
    }

    void Handle_addStretch(HandleRef _this, int32_t stretch) {
        BOXLAYOUT_THIS->addStretch(stretch);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget) {
        BOXLAYOUT_THIS->addWidget(reinterpret_cast<QWidget *>(widget));
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t stretch) {
        BOXLAYOUT_THIS->addWidget(reinterpret_cast<QWidget *>(widget), stretch);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t stretch, Enums::Alignment align) {
        BOXLAYOUT_THIS->addWidget(reinterpret_cast<QWidget *>(widget), stretch, static_cast<Qt::AlignmentFlag>(align));
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout) {
        BOXLAYOUT_THIS->addLayout(reinterpret_cast<QLayout *>(layout));
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t stretch) {
        BOXLAYOUT_THIS->addLayout(reinterpret_cast<QLayout *>(layout), stretch);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(Direction dir, const std::shared_ptr<SignalHandler>& handler) {
        auto qDir = static_cast<QBoxLayout::Direction>(dir);
        const auto wrapper = new SignalWrapper(new QBoxLayout(qDir), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    class NullBoxLayoutHandler : public ServerObject, public SignalHandler, public Layout::SignalHandler, public Object::SignalHandler {
    public:
        void destroyedByQt() override {}
        void destroyed(Object::HandleRef obj) override {}
        void objectNameChanged(const std::string &objectName) override {}
        Object::SignalHandler * inherited_Object_SignalHandler() override { return this; }
        Layout::SignalHandler * inherited_Layout_SignalHandler() override { return this; }
    };

    HandleRef createNoHandler(Direction dir) {
        auto qDir = static_cast<QBoxLayout::Direction>(dir);
        const auto wrapper = new SignalWrapper(new QBoxLayout(qDir), std::make_shared<NullBoxLayoutHandler>());
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
