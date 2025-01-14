#include "generated/GridLayout.h"
#include "GridLayoutInternal.h"

#include "LayoutInternal.h"
#include "WidgetInternal.h"

#include "util/convert.h"

#define THIS (reinterpret_cast<QGridLayout*>(_this))

namespace GridLayout {
    int32_t Handle_horizontalSpacing(HandleRef _this) {
        return THIS->horizontalSpacing();
    }

    void Handle_setHorizontalSpacing(HandleRef _this, int32_t value) {
        THIS->setHorizontalSpacing(value);
    }

    int32_t Handle_verticalSpacing(HandleRef _this) {
        return THIS->verticalSpacing();
    }

    void Handle_setVerticalSpacing(HandleRef _this, int32_t value) {
        THIS->setVerticalSpacing(value);
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t row, int32_t column, Alignment alignment /* 0 */) {
        THIS->addLayout(AS_QLAYOUT_PTR(layout), row, column, static_cast<Qt::Alignment>(alignment.value));
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t row, int32_t column, int32_t rowSpan, int32_t columnSpan, Alignment alignment /* 0 */) {
        THIS->addLayout(AS_QLAYOUT_PTR(layout), row, column, rowSpan, columnSpan, static_cast<Qt::Alignment>(alignment.value));
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t row, int32_t column, Alignment alignment /* 0 */) {
        THIS->addWidget(AS_QWIDGET_PTR(widget), row, column, static_cast<Qt::Alignment>(alignment.value));
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t fromRow, int32_t fromColumn, int32_t rowSpan, int32_t columnSpan, Alignment alignment /* 0 */) {
        THIS->addWidget(AS_QWIDGET_PTR(widget), fromRow, fromColumn, rowSpan, columnSpan, static_cast<Qt::Alignment>(alignment.value));
    }

    Rect Handle_cellRect(HandleRef _this, int32_t row, int32_t column) {
        return toRect(THIS->cellRect(row, column));
    }

    int32_t Handle_columnCount(HandleRef _this) {
        return THIS->columnCount();
    }

    int32_t Handle_columnMinimumWidth(HandleRef _this, int32_t column) {
        return THIS->columnMinimumWidth(column);
    }

    int32_t Handle_columnStretch(HandleRef _this, int32_t column) {
        return THIS->columnStretch(column);
    }

    Handle::ItemPositionResult Handle_getItemPosition(HandleRef _this, int32_t index) {
        Handle::ItemPositionResult result { 0, 0, 0, 0};
        THIS->getItemPosition(index, &result.row, &result.column, &result.rowSpan, &result.columnSpan);
        return result;
    }

    Corner Handle_originCorner(HandleRef _this) {
        return static_cast<Corner>(THIS->originCorner());
    }

    int32_t Handle_rowCount(HandleRef _this) {
        return THIS->rowCount();
    }

    int32_t Handle_rowMinimumHeight(HandleRef _this, int32_t row) {
        return THIS->rowMinimumHeight(row);
    }

    int32_t Handle_rowStretch(HandleRef _this, int32_t row) {
        return THIS->rowStretch(row);
    }

    void Handle_setColumnMinimumWidth(HandleRef _this, int32_t column, int32_t minWidth) {
        THIS->setColumnMinimumWidth(column, minWidth);
    }

    void Handle_setColumnStretch(HandleRef _this, int32_t column, int32_t stretch) {
        THIS->setColumnStretch(column, stretch);
    }

    void Handle_setOriginCorner(HandleRef _this, Corner corner) {
        THIS->setOriginCorner(static_cast<Qt::Corner>(corner));
    }

    void Handle_setRowMinimumHeight(HandleRef _this, int32_t row, int32_t minHeight) {
        THIS->setRowMinimumHeight(row, minHeight);
    }

    void Handle_setRowStretch(HandleRef _this, int32_t row, int32_t stretch) {
        THIS->setRowStretch(row, stretch);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        return reinterpret_cast<HandleRef>(new QGridLayout(qParent));
    }
}
