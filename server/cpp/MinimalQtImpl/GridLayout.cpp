#include "generated/GridLayout.h"
#include "GridLayoutInternal.h"

#include <utility>
#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define GRIDLAYOUT_THIS (WRAPPER->getActual())

namespace GridLayout {
    void Handle_setHorizontalSpacing(HandleRef _this, int32_t value) {
        GRIDLAYOUT_THIS->setHorizontalSpacing(value);
    }

    void Handle_setVerticalSpacing(HandleRef _this, int32_t value) {
        GRIDLAYOUT_THIS->setVerticalSpacing(value);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t row, int32_t col) {
        GRIDLAYOUT_THIS->addWidget(reinterpret_cast<QWidget *>(widget), row, col);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t row, int32_t col, Alignment align) {
        GRIDLAYOUT_THIS->addWidget(reinterpret_cast<QWidget *>(widget), row, col, (Qt::AlignmentFlag) align);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t row, int32_t col, int32_t rowSpan, int32_t colSpan) {
        GRIDLAYOUT_THIS->addWidget(reinterpret_cast<QWidget *>(widget), row, col, rowSpan, colSpan);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t row, int32_t col, int32_t rowSpan, int32_t colSpan, Enums::Alignment align) {
        GRIDLAYOUT_THIS->addWidget(reinterpret_cast<QWidget *>(widget), row, col, rowSpan, colSpan, (Qt::AlignmentFlag) align);
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t row, int32_t col) {
        GRIDLAYOUT_THIS->addLayout(reinterpret_cast<QLayout *>(layout), row, col);
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t row, int32_t col, Enums::Alignment align) {
        GRIDLAYOUT_THIS->addLayout(reinterpret_cast<QLayout *>(layout), row, col, (Qt::AlignmentFlag) align);
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t row, int32_t col, int32_t rowSpan, int32_t colSpan) {
        GRIDLAYOUT_THIS->addLayout(reinterpret_cast<QLayout *>(layout), row, col, rowSpan, colSpan);
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t row, int32_t col, int32_t rowSpan, int32_t colSpan, Enums::Alignment align) {
        GRIDLAYOUT_THIS->addLayout(reinterpret_cast<QLayout *>(layout), row, col, rowSpan, colSpan, (Qt::AlignmentFlag) align);
    }

    void Handle_setRowMinimumHeight(HandleRef _this, int32_t row, int32_t minHeight) {
        GRIDLAYOUT_THIS->setRowMinimumHeight(row, minHeight);
    }

    void Handle_setRowStretch(HandleRef _this, int32_t row, int32_t stretch) {
        GRIDLAYOUT_THIS->setRowStretch(row, stretch);
    }

    void Handle_setColumnMinimumWidth(HandleRef _this, int32_t column, int32_t minWidth) {
        GRIDLAYOUT_THIS->setColumnMinimumWidth(column, minWidth);
    }

    void Handle_setColumnStretch(HandleRef _this, int32_t column, int32_t stretch) {
        GRIDLAYOUT_THIS->setColumnStretch(column, stretch);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QGridLayout(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
