#include "generated/Layout.h"
#include "LayoutInternal.h"

#include <QWidget>
#include <QLayout>

#include "WidgetInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define LAYOUT_THIS (WRAPPER->getActual())

namespace Layout
{
    // void Handle_removeAll(HandleRef _this) {
    //     QLayoutItem *item;
    //     while ((item = LAYOUT_THIS->takeAt(0)) != nullptr) {
    //         item->widget()->setParent(nullptr);
    //         delete item;
    //     }
    // }

    SizeConstraint Handle_getSizeConstraint(HandleRef _this) {
        return static_cast<SizeConstraint>(LAYOUT_THIS->sizeConstraint());
    }

    void Handle_setSizeConstraint(HandleRef _this, SizeConstraint constraint) {
        LAYOUT_THIS->setSizeConstraint(static_cast<QLayout::SizeConstraint>(constraint));
    }

    int32_t Handle_spacing(HandleRef _this) {
        return LAYOUT_THIS->spacing();
    }

    void Handle_setSpacing(HandleRef _this, int32_t spacing) {
        LAYOUT_THIS->setSpacing(spacing);
    }

    bool Handle_isEnabled(HandleRef _this) {
        return LAYOUT_THIS->isEnabled();
    }

    void Handle_setEnabled(HandleRef _this, bool enabled) {
        LAYOUT_THIS->setEnabled(enabled);
    }

    bool Handle_activate(HandleRef _this) {
        return LAYOUT_THIS->activate();
    }

    void Handle_addWidget(HandleRef _this, WidgetHandleRef widget) {
        const auto wrapper = reinterpret_cast<Widget::SignalWrapper*>(widget);
        LAYOUT_THIS->addWidget(wrapper->getActual());
    }

    Margins Handle_contentsMargins(HandleRef _this) {
        int left, top, right, bottom;
        LAYOUT_THIS->getContentsMargins(&left, &top, &right, &bottom);
        return Margins { left, top, right, bottom };
    }

    Rect Handle_contentsRect(HandleRef _this) {
        return toRect(LAYOUT_THIS->contentsRect());
    }

    int32_t Handle_count(HandleRef _this) {
        return LAYOUT_THIS->count();
    }

    int32_t Handle_indexOf(HandleRef _this, WidgetHandleRef widget) {
        const auto wrapper = reinterpret_cast<Widget::SignalWrapper*>(widget);
        return LAYOUT_THIS->indexOf(wrapper->getActual());
    }

    WidgetHandleRef Handle_menuBar(HandleRef _this) {
        if (const auto widget = LAYOUT_THIS->menuBar(); widget != nullptr) {
            const auto wrapper = wrapperForQObject(widget);
            assert(wrapper != nullptr);
            return reinterpret_cast<WidgetHandleRef>(wrapper);
        }
        return nullptr;
    }

    WidgetHandleRef Handle_parentWidget(HandleRef _this) {
        if (const auto widget = LAYOUT_THIS->parentWidget(); widget != nullptr) {
            const auto wrapper = wrapperForQObject(widget);
            assert(wrapper != nullptr);
            return reinterpret_cast<WidgetHandleRef>(wrapper);
        }
        return nullptr;
    }

    void Handle_removeWidget(HandleRef _this, WidgetHandleRef widget) {
        const auto wrapper = reinterpret_cast<Widget::SignalWrapper*>(widget);
        LAYOUT_THIS->removeWidget(wrapper->getActual());
    }

    void Handle_setAlignment(HandleRef _this, WidgetHandleRef widget, Alignment alignment) {
        const auto wrapper = reinterpret_cast<Widget::SignalWrapper*>(widget);
        LAYOUT_THIS->setAlignment(wrapper->getActual(), static_cast<Qt::Alignment>(alignment));
    }

    void Handle_setAlignment(HandleRef _this, HandleRef layout, Alignment alignment) {
        const auto wrapper = reinterpret_cast<Layout::SignalWrapper*>(layout);
        LAYOUT_THIS->setAlignment(wrapper->getActual(), static_cast<Qt::Alignment>(alignment));
    }

    void Handle_setContentsMargins(HandleRef _this, Margins margins) {
        LAYOUT_THIS->setContentsMargins(toQMargins(margins));
    }

    void Handle_setContentsMargins(HandleRef _this, int32_t left, int32_t top, int32_t right, int32_t bottom) {
        LAYOUT_THIS->setContentsMargins(left, top, right, bottom);
    }

    void Handle_setMenuBar(HandleRef _this, WidgetHandleRef widget) {
        const auto wrapper = reinterpret_cast<Widget::SignalWrapper*>(widget);
        LAYOUT_THIS->setMenuBar(wrapper->getActual());
    }

    void Handle_unsetContentsMargins(HandleRef _this) {
        LAYOUT_THIS->unsetContentsMargins();
    }

    void Handle_update(HandleRef _this) {
        LAYOUT_THIS->update();
    }
}

