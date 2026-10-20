#include "generated/StandardItem.h"
#include "StandardItemInternal.h"

#include "BrushInternal.h"
#include "FontInternal.h"
#include "IconInternal.h"
#include "VariantInternal.h"
#include "ModelIndexInternal.h"
#include "SizeInternal.h"

#include "util/convert.h"

using namespace ::Icon;
using namespace ::Enums;
using namespace ::Variant;
using namespace ::ModelIndex;
using namespace ::Brush;
using namespace ::Font;
using namespace ::Size;

#define THIS ((QStandardItem*)_this)
#define CONST_THIS ((const QStandardItem*)_this)

namespace StandardItem
{
    // const handle ========================================================

    std::string ConstHandle_accessibleDescription(ConstHandleRef _this) {
        return CONST_THIS->accessibleDescription().toStdString();
    }

    std::string ConstHandle_accessibleText(ConstHandleRef _this) {
        return CONST_THIS->accessibleText().toStdString();
    }

    Brush::OwnedRef ConstHandle_background(ConstHandleRef _this) {
        return BRUSH_HEAP_NEW(CONST_THIS->background());
    }

    CheckState ConstHandle_checkState(ConstHandleRef _this) {
        return static_cast<CheckState>(CONST_THIS->checkState());
    }

    HandleRef ConstHandle_child(ConstHandleRef _this, int32_t row, int32_t column /* 0 */) {
        const auto ret = CONST_THIS->child(row, column);
        return reinterpret_cast<HandleRef>(ret);
    }

    HandleRef ConstHandle_clone(ConstHandleRef _this) {
        const auto ret = CONST_THIS->clone();
        return reinterpret_cast<HandleRef>(ret);
    }

    int32_t ConstHandle_column(ConstHandleRef _this) {
        return CONST_THIS->column();
    }

    int32_t ConstHandle_columnCount(ConstHandleRef _this) {
        return CONST_THIS->columnCount();
    }

    Variant::OwnedRef ConstHandle_data(ConstHandleRef _this, int32_t role /* static_cast<int32_t>(ItemDataRole::UserRole) + 1 */) {
        return VARIANT_HEAP_NEW(CONST_THIS->data(role));
    }

    Flags<ItemFlags> ConstHandle_getFlags(ConstHandleRef _this) {
        return static_cast<Flags<ItemFlags>>(CONST_THIS->flags());
    }

    Font::OwnedRef ConstHandle_font(ConstHandleRef _this) {
        return FONT_HEAP_NEW(CONST_THIS->font());
    }

    Brush::OwnedRef ConstHandle_foreground(ConstHandleRef _this) {
        return BRUSH_HEAP_NEW(CONST_THIS->foreground());
    }

    bool ConstHandle_hasChildren(ConstHandleRef _this) {
        return CONST_THIS->hasChildren();
    }

    Icon::OwnedRef ConstHandle_icon(ConstHandleRef _this) {
        return ICON_HEAP_NEW(CONST_THIS->icon());
    }

    ModelIndex::OwnedRef ConstHandle_index(ConstHandleRef _this) {
        return MODELINDEX_HEAP_NEW(CONST_THIS->index());
    }

    bool ConstHandle_isAutoTristate(ConstHandleRef _this) {
        return CONST_THIS->isAutoTristate();
    }

    bool ConstHandle_isCheckable(ConstHandleRef _this) {
        return CONST_THIS->isCheckable();
    }

    bool ConstHandle_isDragEnabled(ConstHandleRef _this) {
        return CONST_THIS->isDragEnabled();
    }

    bool ConstHandle_isDropEnabled(ConstHandleRef _this) {
        return CONST_THIS->isDropEnabled();
    }

    bool ConstHandle_isEditable(ConstHandleRef _this) {
        return CONST_THIS->isEditable();
    }

    bool ConstHandle_isEnabled(ConstHandleRef _this) {
        return CONST_THIS->isEnabled();
    }

    bool ConstHandle_isSelectable(ConstHandleRef _this) {
        return CONST_THIS->isSelectable();
    }

    bool ConstHandle_isUserTristate(ConstHandleRef _this) {
        return CONST_THIS->isUserTristate();
    }

    HandleRef ConstHandle_parent(ConstHandleRef _this) {
        return reinterpret_cast<HandleRef>(CONST_THIS->parent());
    }

    int32_t ConstHandle_row(ConstHandleRef _this) {
        return CONST_THIS->row();
    }

    int32_t ConstHandle_rowCount(ConstHandleRef _this) {
        return CONST_THIS->rowCount();
    }

    Size::OwnedRef ConstHandle_sizeHint(ConstHandleRef _this) {
        return SIZE_HEAP_NEW(CONST_THIS->sizeHint());
    }

    std::string ConstHandle_statusTip(ConstHandleRef _this) {
        return CONST_THIS->statusTip().toStdString();
    }

    std::string ConstHandle_text(ConstHandleRef _this) {
        return CONST_THIS->text().toStdString();
    }

    Flags<Alignment> ConstHandle_textAlignment(ConstHandleRef _this) {
        return static_cast<Flags<Alignment>>(CONST_THIS->textAlignment());
    }

    std::string ConstHandle_toolTip(ConstHandleRef _this) {
        return CONST_THIS->toolTip().toStdString();
    }

    int32_t ConstHandle_type(ConstHandleRef _this) {
        return CONST_THIS->type();
    }

    std::string ConstHandle_whatsThis(ConstHandleRef _this) {
        return CONST_THIS->whatsThis().toStdString();
    }

    // mutable handle (non-const) ==============================================================

    void Handle_appendColumn(HandleRef _this, const std::vector<HandleRef>& items) {
        THIS->appendColumn(arrayToList(items));
    }

    void Handle_appendRow(HandleRef _this, const std::vector<HandleRef>& items) {
        THIS->appendRow(arrayToList(items));
    }

    void Handle_appendRow(HandleRef _this, HandleRef item) {
        THIS->appendRow(AS_QSTANDARDITEM_PTR(item));
    }

    void Handle_appendRows(HandleRef _this, const std::vector<HandleRef>& items) {
        THIS->appendRows(arrayToList(items));
    }

    void Handle_clearData(HandleRef _this) {
        THIS->clearData();
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
        THIS->insertRow(row, AS_QSTANDARDITEM_PTR(item));
    }

    void Handle_insertRows(HandleRef _this, int32_t row, const std::vector<HandleRef>& items) {
        THIS->insertRows(row, arrayToList(items));
    }

    void Handle_insertRows(HandleRef _this, int32_t row, int32_t count) {
        THIS->insertRows(row, count);
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
        THIS->setChild(row, column, AS_QSTANDARDITEM_PTR(item));
    }

    void Handle_setChild(HandleRef _this, int32_t row, HandleRef item) {
        THIS->setChild(row, AS_QSTANDARDITEM_PTR(item));
    }

    void Handle_setColumnCount(HandleRef _this, int32_t columns) {
        THIS->setColumnCount(columns);
    }

    void Handle_setData(HandleRef _this, Variant::HandleRef value, int32_t role) {
        THIS->setData(QVARIANT_VALUE(value), role);
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

    void Handle_setFlags(HandleRef _this, Flags<ItemFlags> flags_) {
        THIS->setFlags(static_cast<Qt::ItemFlags>(flags_.value()));
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

    void Handle_setSizeHint(HandleRef _this, Size::HandleRef size) {
        THIS->setSizeHint(QSIZE_VALUE(size));
    }

    void Handle_setStatusTip(HandleRef _this, const std::string& statusTip) {
        THIS->setStatusTip(QString::fromStdString(statusTip));
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    void Handle_setTextAlignment(HandleRef _this, Flags<Alignment> alignment) {
        THIS->setTextAlignment(static_cast<Qt::Alignment>(alignment.value()));
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

    void Handle_sortChildren(HandleRef _this, int32_t column, SortOrder order /* SortOrder::AscendingOrder */) {
        THIS->sortChildren(column, static_cast<Qt::SortOrder>(order));
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

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto item = AS_QSTANDARDITEM_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::ConstHandle:
            // same
            // also, uh ... no 'owned' version?
            return item;
        }
        std::unreachable();
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
