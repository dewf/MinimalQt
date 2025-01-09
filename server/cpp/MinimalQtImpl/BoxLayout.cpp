#include "generated/BoxLayout.h"
#include "BoxLayoutInternal.h"

#include "WidgetInternal.h"

#define THIS (reinterpret_cast<QBoxLayout*>(_this))

namespace BoxLayout
{
    void Handle_setDirection(HandleRef _this, Direction dir) {
        const auto qDir = static_cast<QBoxLayout::Direction>(dir);
        THIS->setDirection(qDir);
    }

    void Handle_addSpacing(HandleRef _this, int32_t size) {
        THIS->addSpacing(size);
    }

    void Handle_addStretch(HandleRef _this, int32_t stretch) {
        THIS->addStretch(stretch);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, const Handle::AddWidgetOptions& opts) {
        const auto stretch = opts.getOrDefaultStretch(0);
        const auto align = static_cast<Qt::Alignment>(opts.getOrDefaultAlign(0));
        THIS->addWidget(AS_QWIDGET_PTR(widget), stretch, align);
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, const Handle::AddLayoutOptions& opts) {
        THIS->addLayout(AS_QLAYOUT_PTR(layout), opts.getOrDefaultStretch(0));
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->addWidget(AS_QWIDGET_PTR(widget));
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t stretch) {
        THIS->addWidget(AS_QWIDGET_PTR(widget), stretch);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t stretch, Enums::Alignment align) {
        THIS->addWidget(AS_QWIDGET_PTR(widget), stretch, static_cast<Qt::AlignmentFlag>(align));
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout) {
        THIS->addLayout(AS_QLAYOUT_PTR(layout));
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t stretch) {
        THIS->addLayout(AS_QLAYOUT_PTR(layout), stretch);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Direction dir, const std::shared_ptr<SignalHandler>& handler) {
        const auto qDir = static_cast<QBoxLayout::Direction>(dir);
        return reinterpret_cast<HandleRef>(new QBoxLayout(qDir));
    }
}
