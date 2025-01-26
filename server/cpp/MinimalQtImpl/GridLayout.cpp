#include "generated/GridLayout.h"
#include "GridLayoutInternal.h"

#include "LayoutInternal.h"
#include "LayoutItemInternal.h"
#include "WidgetInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Common;
using namespace ::Widget;
using namespace ::Layout;
using namespace ::Enums;
using namespace ::LayoutItem;

#define THIS (reinterpret_cast<QGridLayout*>(_this))

namespace GridLayout {
    void Handle_addItem(HandleRef _this, LayoutItem::HandleRef item, int32_t row, int32_t column, int32_t rowSpan /* 1 */, int32_t columnSpan /* 1 */, Alignment alignment /* 0 */) {
        THIS->addItem(AS_QLAYOUTITEM_PTR(item), row, column, rowSpan, columnSpan, static_cast<Qt::Alignment>(alignment.value));
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

    ItemPositionResult Handle_getItemPosition(HandleRef _this, int32_t index) {
        int row, col, rowSpan, colSpan;
        THIS->getItemPosition(index, &row, &col, &rowSpan, &colSpan);
        return ItemPositionResult { row, col, rowSpan, colSpan };
    }

    int32_t Handle_horizontalSpacing(HandleRef _this) {
        return THIS->horizontalSpacing();
    }

    LayoutItem::HandleRef Handle_itemAtPosition(HandleRef _this, int32_t row, int32_t column) {
        return reinterpret_cast<LayoutItem::HandleRef>(THIS->itemAtPosition(row, column));
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

    void Handle_setColumnMinimumWidth(HandleRef _this, int32_t column, int32_t minSize) {
        THIS->setColumnMinimumWidth(column, minSize);
    }

    void Handle_setColumnStretch(HandleRef _this, int32_t column, int32_t stretch) {
        THIS->setColumnStretch(column, stretch);
    }

    void Handle_setHorizontalSpacing(HandleRef _this, int32_t spacing) {
        THIS->setHorizontalSpacing(spacing);
    }

    void Handle_setOriginCorner(HandleRef _this, Corner corner) {
        THIS->setOriginCorner(static_cast<Qt::Corner>(corner));
    }

    void Handle_setRowMinimumHeight(HandleRef _this, int32_t row, int32_t minSize) {
        THIS->setRowMinimumHeight(row, minSize);
    }

    void Handle_setRowStretch(HandleRef _this, int32_t row, int32_t stretch) {
        THIS->setRowStretch(row, stretch);
    }

    void Handle_setVerticalSpacing(HandleRef _this, int32_t spacing) {
        THIS->setVerticalSpacing(spacing);
    }

    int32_t Handle_verticalSpacing(HandleRef _this) {
        return THIS->verticalSpacing();
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QGridLayout(AS_QWIDGET_PTR(parent)));
    }
}
