#include "generated/ListView.h"
#include "ListViewInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define LISTVIEW_THIS (WRAPPER->getActual())

namespace ListView
{
    int32_t Handle_batchSize(HandleRef _this) {
        return LISTVIEW_THIS->batchSize();
    }

    void Handle_setBatchSize(HandleRef _this, int32_t size) {
        LISTVIEW_THIS->setBatchSize(size);
    }

    Flow Handle_getFlow(HandleRef _this) {
        return static_cast<Flow>(LISTVIEW_THIS->flow());
    }

    void Handle_setFlow(HandleRef _this, Flow flow) {
        LISTVIEW_THIS->setFlow(static_cast<QListView::Flow>(flow));
    }

    Size Handle_gridSize(HandleRef _this) {
        return toSize(LISTVIEW_THIS->gridSize());
    }

    void Handle_setGridSize(HandleRef _this, Size size) {
        LISTVIEW_THIS->setGridSize(toQSize(size));
    }

    bool Handle_isWrapping(HandleRef _this) {
        return LISTVIEW_THIS->isWrapping();
    }

    void Handle_setWrapping(HandleRef _this, bool wrapping) {
        LISTVIEW_THIS->setWrapping(wrapping);
    }

    Alignment Handle_itemAlignment(HandleRef _this) {
        return LISTVIEW_THIS->itemAlignment();
    }

    void Handle_setItemAlignment(HandleRef _this, Alignment align) {
        LISTVIEW_THIS->setItemAlignment(static_cast<Qt::Alignment>(align));
    }

    LayoutMode Handle_getLayoutMode(HandleRef _this) {
        return static_cast<LayoutMode>(LISTVIEW_THIS->layoutMode());
    }

    void Handle_setLayoutMode(HandleRef _this, LayoutMode mode) {
        LISTVIEW_THIS->setLayoutMode(static_cast<QListView::LayoutMode>(mode));
    }

    int32_t Handle_modelColumn(HandleRef _this) {
        return LISTVIEW_THIS->modelColumn();
    }

    void Handle_setModelColumn(HandleRef _this, int32_t column) {
        LISTVIEW_THIS->setModelColumn(column);
    }

    Movement Handle_getMovement(HandleRef _this) {
        return static_cast<Movement>(LISTVIEW_THIS->movement());
    }

    void Handle_setMovement(HandleRef _this, Movement movement) {
        LISTVIEW_THIS->setMovement(static_cast<QListView::Movement>(movement));
    }

    ResizeMode Handle_getResizeMode(HandleRef _this) {
        return static_cast<ResizeMode>(LISTVIEW_THIS->resizeMode());
    }

    void Handle_setResizeMode(HandleRef _this, ResizeMode mode) {
        LISTVIEW_THIS->setResizeMode(static_cast<QListView::ResizeMode>(mode));
    }

    bool Handle_isSelectionRectVisible(HandleRef _this) {
        return LISTVIEW_THIS->isSelectionRectVisible();
    }

    void Handle_setSelectionRectVisible(HandleRef _this, bool visible) {
        LISTVIEW_THIS->setSelectionRectVisible(visible);
    }

    int32_t Handle_spacing(HandleRef _this) {
        return LISTVIEW_THIS->spacing();
    }

    void Handle_setSpacing(HandleRef _this, int32_t spacing) {
        LISTVIEW_THIS->setSpacing(spacing);
    }

    bool Handle_uniformItemSizes(HandleRef _this) {
        return LISTVIEW_THIS->uniformItemSizes();
    }

    void Handle_setUniformItemSizes(HandleRef _this, bool state) {
        LISTVIEW_THIS->setUniformItemSizes(state);
    }

    ViewMode Handle_getViewMode(HandleRef _this) {
        return static_cast<ViewMode>(LISTVIEW_THIS->viewMode());
    }

    void Handle_setViewMode(HandleRef _this, ViewMode mode) {
        LISTVIEW_THIS->setViewMode(static_cast<QListView::ViewMode>(mode));
    }

    bool Handle_wordWrap(HandleRef _this) {
        return LISTVIEW_THIS->wordWrap();
    }

    void Handle_setWordWrap(HandleRef _this, bool state) {
        LISTVIEW_THIS->setWordWrap(state);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QListView(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
