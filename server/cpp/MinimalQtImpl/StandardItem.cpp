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

    std::string Handle_accessibleText(HandleRef _this) {
        return THIS->accessibleText().toStdString();
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

    Brush::OwnedRef Handle_background(HandleRef _this) {
        return BRUSH_HEAP_NEW(THIS->background());
    }

    CheckState Handle_checkState(HandleRef _this) {
        return static_cast<CheckState>(THIS->checkState());
    }

    HandleRef Handle_child(HandleRef _this, int32_t row, int32_t column /* 0 */) {
        const auto ret = THIS->child(row, column);
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

    int32_t Handle_columnCount(HandleRef _this) {
        return THIS->columnCount();
    }

    Variant::OwnedRef Handle_data(HandleRef _this, ItemDataRole role) {
        return VARIANT_HEAP_NEW(THIS->data(static_cast<int>(role)));
    }

    ItemFlags Handle_getFlags(HandleRef _this) {
        return ItemFlags(THIS->flags());
    }

    Font::OwnedRef Handle_font(HandleRef _this) {
        return FONT_HEAP_NEW(THIS->font());
    }

    Brush::OwnedRef Handle_foreground(HandleRef _this) {
        return BRUSH_HEAP_NEW(THIS->foreground());
    }

    bool Handle_hasChildren(HandleRef _this) {
        return THIS->hasChildren();
    }

    Icon::OwnedRef Handle_icon(HandleRef _this) {
        return ICON_HEAP_NEW(THIS->icon());
    }

    ModelIndex::OwnedRef Handle_index(HandleRef _this) {
        return MODELINDEX_HEAP_NEW(THIS->index());
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

    bool Handle_isAutoTristate(HandleRef _this) {
        return THIS->isAutoTristate();
    }

    bool Handle_isCheckable(HandleRef _this) {
        return THIS->isCheckable();
    }

    bool Handle_isDragEnabled(HandleRef _this) {
        return THIS->isDragEnabled();
    }

    bool Handle_isDropEnabled(HandleRef _this) {
        return THIS->isDropEnabled();
    }

    bool Handle_isEditable(HandleRef _this) {
        return THIS->isEditable();
    }

    bool Handle_isEnabled(HandleRef _this) {
        return THIS->isEnabled();
    }

    bool Handle_isSelectable(HandleRef _this) {
        return THIS->isSelectable();
    }

    bool Handle_isUserTristate(HandleRef _this) {
        return THIS->isUserTristate();
    }

    StandardItemModel_HandleRef Handle_model(HandleRef _this) {
        return reinterpret_cast<StandardItemModel_HandleRef>(THIS->model());
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

    int32_t Handle_rowCount(HandleRef _this) {
        return THIS->rowCount();
    }

    void Handle_setAccessibleDescription(HandleRef _this, const std::string& description) {
        THIS->setAccessibleDescription(QString::fromStdString(description));
    }

    void Handle_setAccessibleText(HandleRef _this, const std::string& accessibleText) {
        THIS->setAccessibleText(QString::fromStdString(accessibleText));
    }

    void Handle_setAutoTristate(HandleRef _this, bool tristate) {
        THIS->setAutoTristate(tristate);
    }

    void Handle_setBackground(HandleRef _this, Brush::HandleRef brush) {
        THIS->setBackground(QBRUSH_VALUE(brush));
    }

    void Handle_setCheckState(HandleRef _this, CheckState state) {
        return THIS->setCheckState(static_cast<Qt::CheckState>(state));
    }

    void Handle_setCheckable(HandleRef _this, bool checkable) {
        THIS->setCheckable(checkable);
    }

    void Handle_setChild(HandleRef _this, int32_t row, int32_t column, HandleRef item) {
        THIS->setChild(row, column, AS_ITEM(item));
    }

    void Handle_setChild(HandleRef _this, int32_t row, HandleRef item) {
        THIS->setChild(row, AS_ITEM(item));
    }

    void Handle_setColumnCount(HandleRef _this, int32_t columns) {
        THIS->setColumnCount(columns);
    }

    void Handle_setData(HandleRef _this, Variant::HandleRef value, ItemDataRole role) {
        THIS->setData(QVARIANT_VALUE(value), static_cast<int>(role));
    }

    void Handle_setDragEnabled(HandleRef _this, bool dragEnabled) {
        THIS->setDragEnabled(dragEnabled);
    }

    void Handle_setDropEnabled(HandleRef _this, bool dropEnabled) {
        THIS->setDropEnabled(dropEnabled);
    }

    void Handle_setEditable(HandleRef _this, bool editable) {
        THIS->setEditable(editable);
    }

    void Handle_setEnabled(HandleRef _this, bool enabled) {
        THIS->setEnabled(enabled);
    }

    void Handle_setFlags(HandleRef _this, ItemFlags flags_) {
        THIS->setFlags(static_cast<Qt::ItemFlags>(flags_.value));
    }

    void Handle_setFont(HandleRef _this, Font::HandleRef font) {
        THIS->setFont(QFONT_VALUE(font));
    }

    void Handle_setForeground(HandleRef _this, Brush::HandleRef brush) {
        THIS->setForeground(QBRUSH_VALUE(brush));
    }

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        THIS->setIcon(QICON_VALUE(icon));
    }

    void Handle_setRowCount(HandleRef _this, int32_t rows) {
        THIS->setRowCount(rows);
    }

    void Handle_setSelectable(HandleRef _this, bool selectable) {
        THIS->setSelectable(selectable);
    }

    void Handle_setSizeHint(HandleRef _this, Size size) {
        THIS->setSizeHint(toQSize(size));
    }

    void Handle_setStatusTip(HandleRef _this, const std::string& statusTip) {
        THIS->setStatusTip(QString::fromStdString(statusTip));
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    void Handle_setTextAlignment(HandleRef _this, Alignment alignment) {
        THIS->setTextAlignment(static_cast<Qt::Alignment>(alignment.value));
    }

    void Handle_setToolTip(HandleRef _this, const std::string& toolTip) {
        THIS->setToolTip(QString::fromStdString(toolTip));
    }

    void Handle_setUserTristate(HandleRef _this, bool tristate) {
        THIS->setUserTristate(tristate);
    }

    void Handle_setWhatsThis(HandleRef _this, const std::string& whatsThis) {
        THIS->setWhatsThis(QString::fromStdString(whatsThis));
    }

    Size Handle_sizeHint(HandleRef _this) {
        return toSize(THIS->sizeHint());
    }

    void Handle_sortChildren(HandleRef _this, int32_t column, SortOrder order /* SortOrder::AscendingOrder */) {
        THIS->sortChildren(column, static_cast<Qt::SortOrder>(order));
    }

    std::string Handle_statusTip(HandleRef _this) {
        return THIS->statusTip().toStdString();
    }

    HandleRef Handle_takeChild(HandleRef _this, int32_t row, int32_t column /* 0 */) {
        return reinterpret_cast<HandleRef>(THIS->takeChild(row, column));
    }

    std::vector<HandleRef> Handle_takeColumn(HandleRef _this, int32_t column) {
        return listToArray(THIS->takeColumn(column));
    }

    std::vector<HandleRef> Handle_takeRow(HandleRef _this, int32_t row) {
        return listToArray(THIS->takeRow(row));
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    Alignment Handle_textAlignment(HandleRef _this) {
        return Alignment(THIS->textAlignment());
    }

    std::string Handle_toolTip(HandleRef _this) {
        return THIS->toolTip().toStdString();
    }

    int32_t Handle_type(HandleRef _this) {
        return THIS->type();
    }

    std::string Handle_whatsThis(HandleRef _this) {
        return THIS->whatsThis().toStdString();
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

    HandleRef create(int32_t rows, int32_t columns /* 1 */) {
        return reinterpret_cast<HandleRef>(new QStandardItem(rows, columns));
    }
}
