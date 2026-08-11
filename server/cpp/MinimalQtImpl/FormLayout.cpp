#include "generated/FormLayout.h"
#include "FormLayoutInternal.h"

#include "LayoutInternal.h"
#include "WidgetInternal.h"
#include "LayoutItemInternal.h"

#include "util/convert.h"

using namespace ::Enums;
using namespace ::Layout;
using namespace ::Widget;
using namespace ::LayoutItem;

#define THIS (reinterpret_cast<QFormLayout*>(_this))

namespace FormLayout
{
    void Handle_addRow(HandleRef _this, Widget::HandleRef label, Widget::HandleRef field) {
        THIS->addRow(AS_QWIDGET_PTR(label), AS_QWIDGET_PTR(field));
    }

    void Handle_addRow(HandleRef _this, Layout::HandleRef layout) {
        THIS->addRow(AS_QLAYOUT_PTR(layout));
    }

    void Handle_addRow(HandleRef _this, Widget::HandleRef widget) {
        THIS->addRow(AS_QWIDGET_PTR(widget));
    }

    void Handle_addRow(HandleRef _this, Widget::HandleRef label, Layout::HandleRef field) {
        THIS->addRow(AS_QWIDGET_PTR(label), AS_QLAYOUT_PTR(field));
    }

    void Handle_addRow(HandleRef _this, const std::string& labelText, Layout::HandleRef field) {
        THIS->addRow(QString::fromStdString(labelText), AS_QLAYOUT_PTR(field));
    }

    void Handle_addRow(HandleRef _this, const std::string& labelText, Widget::HandleRef field) {
        THIS->addRow(QString::fromStdString(labelText), AS_QWIDGET_PTR(field));
    }

    FieldGrowthPolicy Handle_getFieldGrowthPolicy(HandleRef _this) {
        return static_cast<FieldGrowthPolicy>(THIS->fieldGrowthPolicy());
    }

    Flags<Alignment> Handle_formAlignment(HandleRef _this) {
        return static_cast<Flags<Alignment>>(THIS->formAlignment());
    }

    PositionResult Handle_getItemPosition(HandleRef _this, int32_t index) {
        int row;
        QFormLayout::ItemRole qRole;
        THIS->getItemPosition(index, &row, &qRole);
        return { row, static_cast<ItemRole>(qRole) };
    }

    PositionResult Handle_getLayoutPosition(HandleRef _this, Layout::HandleRef layout) {
        int row;
        QFormLayout::ItemRole qRole;
        THIS->getLayoutPosition(AS_QLAYOUT_PTR(layout), &row, &qRole);
        return { row, static_cast<ItemRole>(qRole) };
    }

    PositionResult Handle_getWidgetPosition(HandleRef _this, Widget::HandleRef widget) {
        int row;
        QFormLayout::ItemRole qRole;
        THIS->getWidgetPosition(AS_QWIDGET_PTR(widget), &row, &qRole);
        return { row, static_cast<ItemRole>(qRole) };
    }

    int32_t Handle_horizontalSpacing(HandleRef _this) {
        return THIS->horizontalSpacing();
    }

    void Handle_insertRow(HandleRef _this, int32_t row, Widget::HandleRef label, Widget::HandleRef field) {
        THIS->insertRow(row, AS_QWIDGET_PTR(label), AS_QWIDGET_PTR(field));
    }

    void Handle_insertRow(HandleRef _this, int32_t row, Layout::HandleRef layout) {
        THIS->insertRow(row, AS_QLAYOUT_PTR(layout));
    }

    void Handle_insertRow(HandleRef _this, int32_t row, Widget::HandleRef widget) {
        THIS->insertRow(row, AS_QWIDGET_PTR(widget));
    }

    void Handle_insertRow(HandleRef _this, int32_t row, Widget::HandleRef label, Layout::HandleRef field) {
        THIS->insertRow(row, AS_QWIDGET_PTR(label), AS_QLAYOUT_PTR(field));
    }

    void Handle_insertRow(HandleRef _this, int32_t row, const std::string& labelText, Layout::HandleRef field) {
        THIS->insertRow(row, QString::fromStdString(labelText), AS_QLAYOUT_PTR(field));
    }

    void Handle_insertRow(HandleRef _this, int32_t row, const std::string& labelText, Widget::HandleRef field) {
        THIS->insertRow(row, QString::fromStdString(labelText), AS_QWIDGET_PTR(field));
    }

    bool Handle_isRowVisible(HandleRef _this, int32_t row) {
        return THIS->isRowVisible(row);
    }

    bool Handle_isRowVisible(HandleRef _this, Layout::HandleRef layout) {
        return THIS->isRowVisible(AS_QLAYOUT_PTR(layout));
    }

    bool Handle_isRowVisible(HandleRef _this, Widget::HandleRef widget) {
        return THIS->isRowVisible(AS_QWIDGET_PTR(widget));
    }

    LayoutItem::HandleRef Handle_itemAt(HandleRef _this, int32_t row, ItemRole role) {
        return reinterpret_cast<LayoutItem::HandleRef>(THIS->itemAt(row, static_cast<QFormLayout::ItemRole>(role)));
    }

    Flags<Alignment> Handle_labelAlignment(HandleRef _this) {
        return static_cast<Flags<Alignment>>(THIS->labelAlignment());
    }

    Widget::HandleRef Handle_labelForField(HandleRef _this, Widget::HandleRef field) {
        return reinterpret_cast<Widget::HandleRef>(THIS->labelForField(AS_QWIDGET_PTR(field)));
    }

    Widget::HandleRef Handle_labelForField(HandleRef _this, Layout::HandleRef field) {
        return reinterpret_cast<Widget::HandleRef>(THIS->labelForField(AS_QLAYOUT_PTR(field)));
    }

    void Handle_removeRow(HandleRef _this, int32_t row) {
        THIS->removeRow(row);
    }

    void Handle_removeRow(HandleRef _this, Layout::HandleRef layout) {
        THIS->removeRow(AS_QLAYOUT_PTR(layout));
    }

    void Handle_removeRow(HandleRef _this, Widget::HandleRef widget) {
        THIS->removeRow(AS_QWIDGET_PTR(widget));
    }

    int32_t Handle_rowCount(HandleRef _this) {
        return THIS->rowCount();
    }

    RowWrapPolicy Handle_rowWrapPolicy(HandleRef _this) {
        return static_cast<RowWrapPolicy>(THIS->rowWrapPolicy());
    }

    void Handle_setFieldGrowthPolicy(HandleRef _this, FieldGrowthPolicy policy) {
        THIS->setFieldGrowthPolicy(static_cast<QFormLayout::FieldGrowthPolicy>(policy));
    }

    void Handle_setFormAlignment(HandleRef _this, Flags<Alignment> alignment) {
        THIS->setFormAlignment(static_cast<Qt::Alignment>(alignment.value()));
    }

    void Handle_setHorizontalSpacing(HandleRef _this, int32_t spacing) {
        THIS->setHorizontalSpacing(spacing);
    }

    void Handle_setItem(HandleRef _this, int32_t row, ItemRole role, LayoutItem::HandleRef item) {
        THIS->setItem(row, static_cast<QFormLayout::ItemRole>(role), AS_QLAYOUTITEM_PTR(item));
    }

    void Handle_setLabelAlignment(HandleRef _this, Flags<Alignment> alignment) {
        THIS->setLabelAlignment(static_cast<Qt::Alignment>(alignment.value()));
    }

    void Handle_setLayout(HandleRef _this, int32_t row, ItemRole role, Layout::HandleRef layout) {
        THIS->setLayout(row, static_cast<QFormLayout::ItemRole>(role), AS_QLAYOUT_PTR(layout));
    }

    void Handle_setRowVisible(HandleRef _this, int32_t row, bool on) {
        THIS->setRowVisible(row, on);
    }

    void Handle_setRowVisible(HandleRef _this, Layout::HandleRef layout, bool on) {
        THIS->setRowVisible(AS_QLAYOUT_PTR(layout), on);
    }

    void Handle_setRowVisible(HandleRef _this, Widget::HandleRef widget, bool on) {
        THIS->setRowVisible(AS_QWIDGET_PTR(widget), on);
    }

    void Handle_setRowWrapPolicy(HandleRef _this, RowWrapPolicy policy) {
        THIS->setRowWrapPolicy(static_cast<QFormLayout::RowWrapPolicy>(policy));
    }

    void Handle_setVerticalSpacing(HandleRef _this, int32_t spacing) {
        THIS->setVerticalSpacing(spacing);
    }

    void Handle_setWidget(HandleRef _this, int32_t row, ItemRole role, Widget::HandleRef widget) {
        THIS->setWidget(row, static_cast<QFormLayout::ItemRole>(role), AS_QWIDGET_PTR(widget));
    }

    TakeRowResult Handle_takeRow(HandleRef _this, int32_t row) {
        const auto [labelItem, fieldItem] = THIS->takeRow(row);
        return { reinterpret_cast<LayoutItem::HandleRef>(labelItem), reinterpret_cast<LayoutItem::HandleRef>(fieldItem) };
    }

    TakeRowResult Handle_takeRow(HandleRef _this, Layout::HandleRef layout) {
        const auto [labelItem, fieldItem] = THIS->takeRow(AS_QLAYOUT_PTR(layout));
        return { reinterpret_cast<LayoutItem::HandleRef>(labelItem), reinterpret_cast<LayoutItem::HandleRef>(fieldItem) };
    }

    TakeRowResult Handle_takeRow(HandleRef _this, Widget::HandleRef widget) {
        const auto [labelItem, fieldItem] = THIS->takeRow(AS_QWIDGET_PTR(widget));
        return { reinterpret_cast<LayoutItem::HandleRef>(labelItem), reinterpret_cast<LayoutItem::HandleRef>(fieldItem) };
    }

    int32_t Handle_verticalSpacing(HandleRef _this) {
        return THIS->verticalSpacing();
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QFormLayout(AS_QWIDGET_PTR(parent)));
    }
}
