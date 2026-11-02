#include "generated/ListWidgetItem.h"
#include "ListWidgetItemInternal.h"

#include "BrushInternal.h"
#include "FontInternal.h"
#include "IconInternal.h"
#include "SizeInternal.h"
#include "VariantInternal.h"

using namespace ::Brush;
using namespace ::Enums;
using namespace ::Variant;
using namespace ::Font;
using namespace ::Icon;
using namespace ::Size;

namespace ListWidgetItem
{
#define THIS (AS_QLISTWIDGETITEM_PTR(_this))

    Brush::OwnedRef Handle_background(HandleRef _this) {
        return BRUSH_HEAP_NEW(THIS->background());
    }

    CheckState Handle_checkState(HandleRef _this) {
        return static_cast<CheckState>(THIS->checkState());
    }

    HandleRef Handle_clone(HandleRef _this) {
        return reinterpret_cast<HandleRef>(THIS->clone());
    }

    Variant::OwnedRef Handle_data(HandleRef _this, int32_t role) {
        return VARIANT_HEAP_NEW(THIS->data(role));
    }

    Flags<ItemFlags> Handle_flags_(HandleRef _this) {
        return Flags<ItemFlags>(THIS->flags());
    }

    Font::OwnedRef Handle_font(HandleRef _this) {
        return FONT_HEAP_NEW(THIS->font());
    }

    Brush::OwnedRef Handle_foreground(HandleRef _this) {
        return BRUSH_HEAP_NEW(THIS->foreground());
    }

    Icon::OwnedRef Handle_icon(HandleRef _this) {
        return ICON_HEAP_NEW(THIS->icon());
    }

    bool Handle_isHidden(HandleRef _this) {
        return THIS->isHidden();
    }

    bool Handle_isSelected(HandleRef _this) {
        return THIS->isSelected();
    }

    void Handle_setBackground(HandleRef _this, Brush::HandleRef brush) {
        return THIS->setBackground(QBRUSH_VALUE(brush));
    }

    void Handle_setCheckState(HandleRef _this, CheckState state) {
        THIS->setCheckState(static_cast<Qt::CheckState>(state));
    }

    void Handle_setData(HandleRef _this, int32_t role, Variant::HandleRef value) {
        THIS->setData(role, QVARIANT_VALUE(value));
    }

    void Handle_setFlags(HandleRef _this, Flags<ItemFlags> flags_) {
        THIS->setFlags(Qt::ItemFlags::fromInt(flags_.value()));
    }

    void Handle_setFont(HandleRef _this, Font::HandleRef font) {
        THIS->setFont(QFONT_VALUE(font));
    }

    void Handle_setForeground(HandleRef _this, Brush::HandleRef brush) {
        THIS->setForeground(QBRUSH_VALUE(brush));
    }

    void Handle_setHidden(HandleRef _this, bool hide) {
        THIS->setHidden(hide);
    }

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        THIS->setIcon(QICON_VALUE(icon));
    }

    void Handle_setSelected(HandleRef _this, bool select) {
        THIS->setSelected(select);
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
        THIS->setTextAlignment(Qt::Alignment::fromInt(alignment.value()));
    }

    void Handle_setToolTip(HandleRef _this, const std::string& toolTip) {
        THIS->setToolTip(QString::fromStdString(toolTip));
    }

    void Handle_setWhatsThis(HandleRef _this, const std::string& whatsThis) {
        THIS->setWhatsThis(QString::fromStdString(whatsThis));
    }

    Size::OwnedRef Handle_sizeHint(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->sizeHint());
    }

    std::string Handle_statusTip(HandleRef _this) {
        return THIS->statusTip().toStdString();
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    int32_t Handle_textAlignment(HandleRef _this) {
        return THIS->textAlignment();
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

    HandleRef create(HandleRef other) {
        auto other2 = AS_QLISTWIDGETITEM_PTR(other);
        return reinterpret_cast<HandleRef>(new QListWidgetItem(*other2));
    }
}
