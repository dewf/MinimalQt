#include "generated/StandardItem.h"

#include "BrushInternal.h"
#include "FontInternal.h"
#include "IconInternal.h"
#include "StandardItemInternal.h"
#include "VariantInternal.h"
#include "ModelIndexInternal.h"

#include "util/convert.h"

#define THIS ((QStandardItem*)_this)
#define AS_ITEM(x) (reinterpret_cast<QStandardItem*>(x))

namespace StandardItem
{
    std::string Handle_accessibleDescription(HandleRef _this) {
        return THIS->accessibleDescription().toStdString();
    }

    void Handle_setAccessibleDescription(HandleRef _this, const std::string& description) {
        THIS->setAccessibleDescription(QString::fromStdString(description));
    }

    std::string Handle_accessibleText(HandleRef _this) {
        return THIS->accessibleText().toStdString();
    }

    void Handle_setAccessibleText(HandleRef _this, const std::string& accessibleText) {
        THIS->setAccessibleText(QString::fromStdString(accessibleText));
    }

    bool Handle_isAutoTristate(HandleRef _this) {
        return THIS->isAutoTristate();
    }

    void Handle_setAutoTristate(HandleRef _this, bool tristate) {
        THIS->setAutoTristate(tristate);
    }

    Brush::OwnedRef Handle_background(HandleRef _this) {
        return new Brush::__Owned { THIS->background() };
    }

    void Handle_setBackground(HandleRef _this, Brush::HandleRef brush) {
        THIS->setBackground(brush->qBrush);
    }

    CheckState Handle_checkState(HandleRef _this) {
        return static_cast<CheckState>(THIS->checkState());
    }

    void Handle_setCheckState(HandleRef _this, CheckState state) {
        return THIS->setCheckState(static_cast<Qt::CheckState>(state));
    }

    bool Handle_isCheckable(HandleRef _this) {
        return THIS->isCheckable();
    }

    void Handle_setCheckable(HandleRef _this, bool checkable) {
        THIS->setCheckable(checkable);
    }

    int32_t Handle_columnCount(HandleRef _this) {
        return THIS->columnCount();
    }

    void Handle_setColumnCount(HandleRef _this, int32_t columns) {
        THIS->setColumnCount(columns);
    }

    bool Handle_isDragEnabled(HandleRef _this) {
        return THIS->isDragEnabled();
    }

    void Handle_setDragEnabled(HandleRef _this, bool dragEnabled) {
        THIS->setDragEnabled(dragEnabled);
    }

    bool Handle_isDropEnabled(HandleRef _this) {
        return THIS->isDropEnabled();
    }

    void Handle_setDropEnabled(HandleRef _this, bool dropEnabled) {
        THIS->setDropEnabled(dropEnabled);
    }

    bool Handle_isEditable(HandleRef _this) {
        return THIS->isEditable();
    }

    void Handle_setEditable(HandleRef _this, bool editable) {
        THIS->setEditable(editable);
    }

    bool Handle_isEnabled(HandleRef _this) {
        return THIS->isEnabled();
    }

    void Handle_setEnabled(HandleRef _this, bool enabled) {
        THIS->setEnabled(enabled);
    }

    ItemFlags Handle_getFlags(HandleRef _this) {
        return THIS->flags();
    }

    void Handle_setFlags(HandleRef _this, ItemFlags flags_) {
        THIS->setFlags(static_cast<Qt::ItemFlags>(flags_));
    }

    Font::OwnedRef Handle_getFont(HandleRef _this) {
        return FONT_HEAP_NEW(THIS->font());
    }

    void Handle_setFont(HandleRef _this, Font::HandleRef font) {
        THIS->setFont(QFONT_VALUE(font));
    }

    Brush::OwnedRef Handle_foreground(HandleRef _this) {
        return new Brush::__Owned { THIS->foreground() };
    }

    void Handle_setForeground(HandleRef _this, Brush::HandleRef brush) {
        THIS->setForeground(brush->qBrush);
    }

    Icon::OwnedRef Handle_getIcon(HandleRef _this) {
        return ICON_HEAP_NEW(THIS->icon());
    }

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        THIS->setIcon(QICON_VALUE(icon));
    }

    int32_t Handle_rowCount(HandleRef _this) {
        return THIS->rowCount();
    }

    void Handle_setRowCount(HandleRef _this, int32_t rows) {
        THIS->setRowCount(rows);
    }

    bool Handle_isSelectable(HandleRef _this) {
        return THIS->isSelectable();
    }

    void Handle_setSelectable(HandleRef _this, bool selectable) {
        THIS->setSelectable(selectable);
    }

    Size Handle_sizeHint(HandleRef _this) {
        return toSize(THIS->sizeHint());
    }

    void Handle_setSizeHint(HandleRef _this, Size size) {
        THIS->setSizeHint(toQSize(size));
    }

    std::string Handle_statusTip(HandleRef _this) {
        return THIS->statusTip().toStdString();
    }

    void Handle_setStatusTip(HandleRef _this, const std::string& statusTip) {
        THIS->setStatusTip(QString::fromStdString(statusTip));
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    Alignment Handle_textAlignment(HandleRef _this) {
        return THIS->textAlignment();
    }

    void Handle_setTextAlignment(HandleRef _this, Alignment alignment) {
        THIS->setTextAlignment(static_cast<Qt::Alignment>(alignment));
    }

    std::string Handle_toolTip(HandleRef _this) {
        return THIS->toolTip().toStdString();
    }

    void Handle_setToolTip(HandleRef _this, const std::string& toolTip) {
        THIS->setToolTip(QString::fromStdString(toolTip));
    }

    int32_t Handle_type_(HandleRef _this) {
        return THIS->type();
    }

    bool Handle_isUserTristate(HandleRef _this) {
        return THIS->isUserTristate();
    }

    void Handle_setUserTristate(HandleRef _this, bool tristate) {
        THIS->setUserTristate(tristate);
    }

    std::string Handle_whatsThis(HandleRef _this) {
        return THIS->whatsThis().toStdString();
    }

    void Handle_setWhatsThis(HandleRef _this, const std::string& whatsThis) {
        THIS->setWhatsThis(QString::fromStdString(whatsThis));
    }

    void Handle_appendColumn(HandleRef _this, const std::vector<HandleRef>& items) {
        THIS->appendColumn(arrayToList(items));
    }

    void Handle_appendRow(HandleRef _this, const std::vector<HandleRef>& items) {
        THIS->appendRow(arrayToList(items));
    }

    void Handle_appendRow(HandleRef _this, HandleRef item) {
        THIS->appendRow(AS_ITEM(item));
    }

    void Handle_appendRows(HandleRef _this, const std::vector<HandleRef>& items) {
        THIS->appendRows(arrayToList(items));
    }

    HandleRef Handle_child(HandleRef _this, int32_t row, const std::optional<int32_t>& column) {
        const auto ret = THIS->child(row, column.value_or(0));
        return reinterpret_cast<HandleRef>(ret);
    }

    void Handle_clearData(HandleRef _this) {
        THIS->clearData();
    }

    HandleRef Handle_clone(HandleRef _this) {
        const auto ret = THIS->clone();
        return reinterpret_cast<HandleRef>(ret);
    }

    int32_t Handle_column(HandleRef _this) {
        return THIS->column();
    }

    Variant::OwnedRef Handle_data(HandleRef _this, const std::optional<int32_t>& role) {
        const auto ret = THIS->data(role.value_or(Qt::UserRole + 1));
        return new Variant::__Owned { ret };
    }

    bool Handle_hasChildren(HandleRef _this) {
        return THIS->hasChildren();
    }

    ModelIndex::OwnedRef Handle_index(HandleRef _this) {
        return new ModelIndex::__Owned { THIS->index() };
    }

    void Handle_insertColumn(HandleRef _this, int32_t column, const std::vector<HandleRef>& items) {
        THIS->insertColumn(column, arrayToList(items));
    }

    void Handle_insertColumns(HandleRef _this, int32_t column, int32_t count) {
        THIS->insertColumns(column, count);
    }

    void Handle_insertRow(HandleRef _this, int32_t row, const std::vector<HandleRef>& items) {
        THIS->insertRow(row, arrayToList(items));
    }

    void Handle_insertRow(HandleRef _this, int32_t row, HandleRef item) {
        THIS->insertRow(row, AS_ITEM(item));
    }

    void Handle_insertRows(HandleRef _this, int32_t row, const std::vector<HandleRef>& items) {
        THIS->insertRows(row, arrayToList(items));
    }

    void Handle_insertRows(HandleRef _this, int32_t row, int32_t count) {
        THIS->insertRows(row, count);
    }

    HandleRef Handle_parent(HandleRef _this) {
        return reinterpret_cast<HandleRef>(THIS->parent());
    }

    void Handle_removeColumn(HandleRef _this, int32_t column) {
        THIS->removeColumn(column);
    }

    void Handle_removeColumns(HandleRef _this, int32_t column, int32_t count) {
        THIS->removeColumns(column, count);
    }

    void Handle_removeRow(HandleRef _this, int32_t row) {
        THIS->removeRow(row);
    }

    void Handle_removeRows(HandleRef _this, int32_t row, int32_t count) {
        THIS->removeRows(row, count);
    }

    int32_t Handle_row(HandleRef _this) {
        return THIS->row();
    }

    void Handle_setChild(HandleRef _this, int32_t row, int32_t column, HandleRef item) {
        THIS->setChild(row, column, AS_ITEM(item));
    }

    void Handle_setChild(HandleRef _this, int32_t row, HandleRef item) {
        THIS->setChild(row, AS_ITEM(item));
    }

    void Handle_setData(HandleRef _this, Variant::HandleRef value, const std::optional<int32_t>& role) {
        THIS->setData(value->value, role.value_or(Qt::UserRole + 1));
    }

    void Handle_sortChildren(HandleRef _this, int32_t column, const std::optional<SortOrder>& order) {
        const auto qOrder = static_cast<Qt::SortOrder>(order.value_or(SortOrder::AscendingOrder));
        THIS->sortChildren(column, qOrder);
    }

    HandleRef Handle_takeChild(HandleRef _this, int32_t row, const std::optional<int32_t>& column) {
        return reinterpret_cast<HandleRef>(THIS->takeChild(row, column.value_or(0)));
    }

    std::vector<HandleRef> Handle_takeColumn(HandleRef _this, int32_t column) {
        return listToArray(THIS->takeColumn(column));
    }

    std::vector<HandleRef> Handle_takeRow(HandleRef _this, int32_t row) {
        return listToArray(THIS->takeRow(row));
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QStandardItem());
    }

    HandleRef create(const std::string& text) {
        return reinterpret_cast<HandleRef>(new QStandardItem(QString::fromStdString(text)));
    }

    HandleRef create(Icon::HandleRef icon, const std::string& text) {
        return reinterpret_cast<HandleRef>(new QStandardItem(QICON_VALUE(icon), QString::fromStdString(text)));
    }

    HandleRef create(int32_t rows, int32_t columns) {
        return reinterpret_cast<HandleRef>(new QStandardItem(rows, columns));
    }
}
