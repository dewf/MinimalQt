#include "generated/ListView.h"
#include "ListViewInternal.h"

#include "ModelIndexInternal.h"
#include "ObjectInternal.h"
#include "WidgetInternal.h"
#include "SizeInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Size;
using namespace ::Enums;
using namespace ::Icon;
using namespace ::AbstractListModel;
using namespace ::ModelIndex;
using namespace ::AbstractItemView;
using namespace ::Widget;

#define THIS (reinterpret_cast<QListView*>(_this))

namespace ListView
{
    int32_t Handle_batchSize(HandleRef _this) {
        return THIS->batchSize();
    }

    void Handle_clearPropertyFlags(HandleRef _this) {
        THIS->clearPropertyFlags();
    }

    Flow Handle_getFlow(HandleRef _this) {
        return static_cast<Flow>(THIS->flow());
    }

    Size::OwnedRef Handle_gridSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->gridSize());
    }

    bool Handle_isRowHidden(HandleRef _this, int32_t row) {
        return THIS->isRowHidden(row);
    }

    bool Handle_isSelectionRectVisible(HandleRef _this) {
        return THIS->isSelectionRectVisible();
    }

    bool Handle_isWrapping(HandleRef _this) {
        return THIS->isWrapping();
    }

    Alignment Handle_itemAlignment(HandleRef _this) {
        return Alignment(THIS->itemAlignment());
    }

    LayoutMode Handle_getLayoutMode(HandleRef _this) {
        return static_cast<LayoutMode>(THIS->layoutMode());
    }

    int32_t Handle_modelColumn(HandleRef _this) {
        return THIS->modelColumn();
    }

    Movement Handle_getMovement(HandleRef _this) {
        return static_cast<Movement>(THIS->movement());
    }

    ResizeMode Handle_getResizeMode(HandleRef _this) {
        return static_cast<ResizeMode>(THIS->resizeMode());
    }

    void Handle_setBatchSize(HandleRef _this, int32_t batchSize) {
        THIS->setBatchSize(batchSize);
    }

    void Handle_setFlow(HandleRef _this, Flow flow) {
        THIS->setFlow(static_cast<QListView::Flow>(flow));
    }

    void Handle_setGridSize(HandleRef _this, Size::HandleRef size) {
        THIS->setGridSize(QSIZE_VALUE(size));
    }

    void Handle_setItemAlignment(HandleRef _this, Alignment align) {
        THIS->setItemAlignment(static_cast<Qt::Alignment>(align.value));
    }

    void Handle_setLayoutMode(HandleRef _this, LayoutMode mode) {
        THIS->setLayoutMode(static_cast<QListView::LayoutMode>(mode));
    }

    void Handle_setModelColumn(HandleRef _this, int32_t column) {
        THIS->setModelColumn(column);
    }

    void Handle_setMovement(HandleRef _this, Movement movement) {
        THIS->setMovement(static_cast<QListView::Movement>(movement));
    }

    void Handle_setResizeMode(HandleRef _this, ResizeMode mode) {
        THIS->setResizeMode(static_cast<QListView::ResizeMode>(mode));
    }

    void Handle_setRowHidden(HandleRef _this, int32_t row, bool hide) {
        THIS->setRowHidden(row, hide);
    }

    void Handle_setSelectionRectVisible(HandleRef _this, bool show) {
        THIS->setSelectionRectVisible(show);
    }

    void Handle_setSpacing(HandleRef _this, int32_t space) {
        THIS->setSpacing(space);
    }

    void Handle_setUniformItemSizes(HandleRef _this, bool enable) {
        THIS->setUniformItemSizes(enable);
    }

    void Handle_setViewMode(HandleRef _this, ViewMode mode) {
        THIS->setViewMode(static_cast<QListView::ViewMode>(mode));
    }

    void Handle_setWordWrap(HandleRef _this, bool on) {
        THIS->setWordWrap(on);
    }

    void Handle_setWrapping(HandleRef _this, bool enable) {
        THIS->setWrapping(enable);
    }

    int32_t Handle_spacing(HandleRef _this) {
        return THIS->spacing();
    }

    bool Handle_uniformItemSizes(HandleRef _this) {
        return THIS->uniformItemSizes();
    }

    ViewMode Handle_getViewMode(HandleRef _this) {
        return static_cast<ViewMode>(THIS->viewMode());
    }

    bool Handle_wordWrap(HandleRef _this) {
        return THIS->wordWrap();
    }

    SignalConnectionRef Handle_connect_IndexesMoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QListView::indexesMoved, [handler](const QModelIndexList &indexes) {
            // non-const indexes first:
            const auto indexes2 = fromQList<QModelIndex,QModelIndex>(indexes, idFunc<QModelIndex>);
            // and the pointers to them:
            const auto ptrs = vectorMap<QModelIndex,ModelIndex::HandleRef>(indexes2, [](auto mi) { return reinterpret_cast<ModelIndex::HandleRef>(&mi); });
            handler->indexesMoved(ptrs);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QListView(AS_QWIDGET_PTR(parent)));
    }
}

