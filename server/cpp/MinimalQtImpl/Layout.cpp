#include "generated/Layout.h"

#include <QWidget>
#include <QLayout>

#define THIS ((QLayout*)_this)

namespace Layout
{
    bool Handle_isEnabled(HandleRef _this) {
        return THIS->isEnabled();
    }

    void Handle_setEnabled(HandleRef _this, bool enabled) {
        THIS->setEnabled(enabled);
    }

    SizeConstraint Handle_getSizeConstraint(HandleRef _this) {
        return static_cast<SizeConstraint>(THIS->sizeConstraint());
    }

    void Handle_setSizeConstraint(HandleRef _this, SizeConstraint constraint) {
        THIS->setSizeConstraint(static_cast<QLayout::SizeConstraint>(constraint));
    }

    int32_t Handle_spacing(HandleRef _this) {
        return THIS->spacing();
    }

    void Handle_setSpacing(HandleRef _this, int32_t spacing) {
        THIS->setSpacing(spacing);
    }

    std::tuple<int32_t,int32_t,int32_t,int32_t> Handle_getContentsMargins(HandleRef _this) {
        int left, top, right, bottom;
        THIS->getContentsMargins(&left, &top, &right, &bottom);
        return { left, top, right, bottom };
    }

    void Handle_setContentsMargins(HandleRef _this, int32_t left, int32_t top, int32_t right, int32_t bottom) {
        THIS->setContentsMargins(left, top, right, bottom);
    }

    void Handle_removeAll(HandleRef _this) {
        QLayoutItem *item;
        while ((item = THIS->takeAt(0)) != nullptr) {
            item->widget()->setParent(nullptr);
            delete item;
        }
    }

    void Handle_activate(HandleRef _this) {
        THIS->activate();
    }

    void Handle_update(HandleRef _this) {
        THIS->update();
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }
}
