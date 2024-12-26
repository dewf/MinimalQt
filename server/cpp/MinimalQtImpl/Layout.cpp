#include "generated/Layout.h"
#include "LayoutInternal.h"

#include <QWidget>
#include <QLayout>

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define LAYOUT_THIS (WRAPPER->getActual())

namespace Layout
{
    bool Handle_isEnabled(HandleRef _this) {
        return LAYOUT_THIS->isEnabled();
    }

    void Handle_setEnabled(HandleRef _this, bool enabled) {
        LAYOUT_THIS->setEnabled(enabled);
    }

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

    std::tuple<int32_t,int32_t,int32_t,int32_t> Handle_getContentsMargins(HandleRef _this) {
        int left, top, right, bottom;
        LAYOUT_THIS->getContentsMargins(&left, &top, &right, &bottom);
        return { left, top, right, bottom };
    }

    void Handle_setContentsMargins(HandleRef _this, int32_t left, int32_t top, int32_t right, int32_t bottom) {
        LAYOUT_THIS->setContentsMargins(left, top, right, bottom);
    }

    void Handle_removeAll(HandleRef _this) {
        QLayoutItem *item;
        while ((item = LAYOUT_THIS->takeAt(0)) != nullptr) {
            item->widget()->setParent(nullptr);
            delete item;
        }
    }

    void Handle_activate(HandleRef _this) {
        LAYOUT_THIS->activate();
    }

    void Handle_update(HandleRef _this) {
        LAYOUT_THIS->update();
    }
}
