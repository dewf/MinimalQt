#include "generated/GridLayout.h"
#include "GridLayoutInternal.h"

#include <utility>

#include "WidgetInternal.h"
#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define GRIDLAYOUT_THIS (WRAPPER->getActual())

namespace GridLayout {
    int32_t Handle_horizontalSpacing(HandleRef _this) {
        return GRIDLAYOUT_THIS->horizontalSpacing();
    }

    void Handle_setHorizontalSpacing(HandleRef _this, int32_t value) {
        GRIDLAYOUT_THIS->setHorizontalSpacing(value);
    }

    int32_t Handle_verticalSpacing(HandleRef _this) {
        return GRIDLAYOUT_THIS->verticalSpacing();
    }

    void Handle_setVerticalSpacing(HandleRef _this, int32_t value) {
        GRIDLAYOUT_THIS->setVerticalSpacing(value);
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t row, int32_t column, const std::optional<Alignment>& alignment) {
        const auto layoutWrapper = reinterpret_cast<Layout::SignalWrapper*>(layout);
        const auto qAlignment = optionalMap<Alignment,Qt::Alignment>(alignment, [](auto align) { return static_cast<Qt::Alignment>(align); });
        GRIDLAYOUT_THIS->addLayout(layoutWrapper->getActual(), row, column, qAlignment.value_or(Qt::Alignment()));
    }

    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t row, int32_t column, int32_t rowSpan, int32_t columnSpan, const std::optional<Alignment>& alignment) {
        const auto layoutWrapper = reinterpret_cast<Layout::SignalWrapper*>(layout);
        const auto qAlignment = optionalMap<Alignment,Qt::Alignment>(alignment, [](auto align) { return static_cast<Qt::Alignment>(align); });
        GRIDLAYOUT_THIS->addLayout(layoutWrapper->getActual(), row, column, rowSpan, columnSpan, qAlignment.value_or(Qt::Alignment()));
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t row, int32_t column, const std::optional<Alignment>& alignment) {
        const auto widgetWrapper = reinterpret_cast<Widget::SignalWrapper*>(widget);
        const auto qAlignment = optionalMap<Alignment,Qt::Alignment>(alignment, [](auto align) { return static_cast<Qt::Alignment>(align); });
        GRIDLAYOUT_THIS->addWidget(widgetWrapper->getActual(), row, column, qAlignment.value_or(Qt::Alignment()));
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t fromRow, int32_t fromColumn, int32_t rowSpan, int32_t columnSpan, const std::optional<Alignment>& alignment) {
        const auto widgetWrapper = reinterpret_cast<Widget::SignalWrapper*>(widget);
        const auto qAlignment = optionalMap<Alignment,Qt::Alignment>(alignment, [](auto align) { return static_cast<Qt::Alignment>(align); });
        GRIDLAYOUT_THIS->addWidget(widgetWrapper->getActual(), fromRow, fromColumn, rowSpan, columnSpan, qAlignment.value_or(Qt::Alignment()));
    }

    Rect Handle_cellRect(HandleRef _this, int32_t row, int32_t column) {
        return toRect(GRIDLAYOUT_THIS->cellRect(row, column));
    }

    int32_t Handle_columnCount(HandleRef _this) {
        return GRIDLAYOUT_THIS->columnCount();
    }

    int32_t Handle_columnMinimumWidth(HandleRef _this, int32_t column) {
        return GRIDLAYOUT_THIS->columnMinimumWidth(column);
    }

    int32_t Handle_columnStretch(HandleRef _this, int32_t column) {
        return GRIDLAYOUT_THIS->columnStretch(column);
    }

    Handle::ItemPositionResult Handle_getItemPosition(HandleRef _this, int32_t index) {
        Handle::ItemPositionResult result { 0, 0, 0, 0};
        GRIDLAYOUT_THIS->getItemPosition(index, &result.row, &result.column, &result.rowSpan, &result.columnSpan);
        return result;
    }

    Corner Handle_originCorner(HandleRef _this) {
        return static_cast<Corner>(GRIDLAYOUT_THIS->originCorner());
    }

    int32_t Handle_rowCount(HandleRef _this) {
        return GRIDLAYOUT_THIS->rowCount();
    }

    int32_t Handle_rowMinimumHeight(HandleRef _this, int32_t row) {
        return GRIDLAYOUT_THIS->rowMinimumHeight(row);
    }

    int32_t Handle_rowStretch(HandleRef _this, int32_t row) {
        return GRIDLAYOUT_THIS->rowStretch(row);
    }

    void Handle_setColumnMinimumWidth(HandleRef _this, int32_t column, int32_t minWidth) {
        GRIDLAYOUT_THIS->setColumnMinimumWidth(column, minWidth);
    }

    void Handle_setColumnStretch(HandleRef _this, int32_t column, int32_t stretch) {
        GRIDLAYOUT_THIS->setColumnStretch(column, stretch);
    }

    void Handle_setOriginCorner(HandleRef _this, Corner corner) {
        GRIDLAYOUT_THIS->setOriginCorner(static_cast<Qt::Corner>(corner));
    }

    void Handle_setRowMinimumHeight(HandleRef _this, int32_t row, int32_t minHeight) {
        GRIDLAYOUT_THIS->setRowMinimumHeight(row, minHeight);
    }

    void Handle_setRowStretch(HandleRef _this, int32_t row, int32_t stretch) {
        GRIDLAYOUT_THIS->setRowStretch(row, stretch);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler, const std::optional<Widget::HandleRef>& parent) {
        QWidget *qParent = nullptr;
        if (parent.has_value()) {
            const auto parentWrapper = reinterpret_cast<Widget::SignalWrapper*>(parent.value());
            qParent = parentWrapper->getActual();
        }
        const auto wrapper = new SignalWrapper(new QGridLayout(qParent), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
