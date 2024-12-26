#include "generated/ListView.h"
#include "ListViewInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define LISTVIEW_THIS (WRAPPER->getActual())

namespace ListView
{
    void Handle_setBatchSize(HandleRef _this, int32_t size) {
        LISTVIEW_THIS->setBatchSize(size);
    }

    void Handle_setFlow(HandleRef _this, Flow flow) {
        LISTVIEW_THIS->setFlow(static_cast<QListView::Flow>(flow));
    }

    void Handle_setGridSize(HandleRef _this, Size size) {
        LISTVIEW_THIS->setGridSize(toQSize(size));
    }

    void Handle_setWrapping(HandleRef _this, bool wrapping) {
        LISTVIEW_THIS->setWrapping(wrapping);
    }

    void Handle_setItemAlignment(HandleRef _this, Alignment align) {
        LISTVIEW_THIS->setItemAlignment(static_cast<Qt::Alignment>(align));
    }

    void Handle_setLayoutMode(HandleRef _this, LayoutMode mode) {
        LISTVIEW_THIS->setLayoutMode(static_cast<QListView::LayoutMode>(mode));
    }

    void Handle_setModelColumn(HandleRef _this, int32_t column) {
        LISTVIEW_THIS->setModelColumn(column);
    }

    void Handle_setMovement(HandleRef _this, Movement movement) {
        LISTVIEW_THIS->setMovement(static_cast<QListView::Movement>(movement));
    }

    void Handle_setResizeMode(HandleRef _this, ResizeMode mode) {
        LISTVIEW_THIS->setResizeMode(static_cast<QListView::ResizeMode>(mode));
    }

    void Handle_setSelectionRectVisible(HandleRef _this, bool visible) {
        LISTVIEW_THIS->setSelectionRectVisible(visible);
    }

    void Handle_setSpacing(HandleRef _this, int32_t spacing) {
        LISTVIEW_THIS->setSpacing(spacing);
    }

    void Handle_setUniformItemSizes(HandleRef _this, bool state) {
        LISTVIEW_THIS->setUniformItemSizes(state);
    }

    void Handle_setViewMode(HandleRef _this, ViewMode mode) {
        LISTVIEW_THIS->setViewMode(static_cast<QListView::ViewMode>(mode));
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
