#include "generated/ListView.h"
#include "ListViewInternal.h"
#include "ModelIndexInternal.h"

#include "ObjectInternal.h"
#include "WidgetInternal.h"
#include "util/convert.h"

#define THIS (reinterpret_cast<QListView*>(_this))

namespace ListView
{
    int32_t Handle_batchSize(HandleRef _this) {
        return THIS->batchSize();
    }

    void Handle_setBatchSize(HandleRef _this, int32_t size) {
        THIS->setBatchSize(size);
    }

    Flow Handle_getFlow(HandleRef _this) {
        return static_cast<Flow>(THIS->flow());
    }

    void Handle_setFlow(HandleRef _this, Flow flow) {
        THIS->setFlow(static_cast<QListView::Flow>(flow));
    }

    Size Handle_gridSize(HandleRef _this) {
        return toSize(THIS->gridSize());
    }

    void Handle_setGridSize(HandleRef _this, Size size) {
        THIS->setGridSize(toQSize(size));
    }

    Alignment Handle_itemAlignment(HandleRef _this) {
        return THIS->itemAlignment();
    }

    void Handle_setItemAlignment(HandleRef _this, Alignment align) {
        THIS->setItemAlignment(static_cast<Qt::Alignment>(align));
    }

    LayoutMode Handle_getLayoutMode(HandleRef _this) {
        return static_cast<LayoutMode>(THIS->layoutMode());
    }

    void Handle_setLayoutMode(HandleRef _this, LayoutMode mode) {
        THIS->setLayoutMode(static_cast<QListView::LayoutMode>(mode));
    }

    int32_t Handle_modelColumn(HandleRef _this) {
        return THIS->modelColumn();
    }

    void Handle_setModelColumn(HandleRef _this, int32_t column) {
        THIS->setModelColumn(column);
    }

    Movement Handle_getMovement(HandleRef _this) {
        return static_cast<Movement>(THIS->movement());
    }

    void Handle_setMovement(HandleRef _this, Movement movement) {
        THIS->setMovement(static_cast<QListView::Movement>(movement));
    }

    ResizeMode Handle_getResizeMode(HandleRef _this) {
        return static_cast<ResizeMode>(THIS->resizeMode());
    }

    void Handle_setResizeMode(HandleRef _this, ResizeMode mode) {
        THIS->setResizeMode(static_cast<QListView::ResizeMode>(mode));
    }

    bool Handle_isSelectionRectVisible(HandleRef _this) {
        return THIS->isSelectionRectVisible();
    }

    void Handle_setSelectionRectVisible(HandleRef _this, bool visible) {
        THIS->setSelectionRectVisible(visible);
    }

    int32_t Handle_spacing(HandleRef _this) {
        return THIS->spacing();
    }

    void Handle_setSpacing(HandleRef _this, int32_t spacing) {
        THIS->setSpacing(spacing);
    }

    bool Handle_uniformItemSizes(HandleRef _this) {
        return THIS->uniformItemSizes();
    }

    void Handle_setUniformItemSizes(HandleRef _this, bool state) {
        THIS->setUniformItemSizes(state);
    }

    ViewMode Handle_getViewMode(HandleRef _this) {
        return static_cast<ViewMode>(THIS->viewMode());
    }

    void Handle_setViewMode(HandleRef _this, ViewMode mode) {
        THIS->setViewMode(static_cast<QListView::ViewMode>(mode));
    }

    bool Handle_wordWrap(HandleRef _this) {
        return THIS->wordWrap();
    }

    void Handle_setWordWrap(HandleRef _this, bool state) {
        THIS->setWordWrap(state);
    }

    bool Handle_isWrapping(HandleRef _this) {
        return THIS->isWrapping();
    }

    void Handle_setWrapping(HandleRef _this, bool wrapping) {
        THIS->setWrapping(wrapping);
    }

    void Handle_clearPropertyFlags(HandleRef _this) {
        THIS->clearPropertyFlags();
    }

    bool Handle_isRowHidden(HandleRef _this, int32_t row) {
        return THIS->isRowHidden(row);
    }

    void Handle_setRowHidden(HandleRef _this, int32_t row, bool hide) {
        THIS->setRowHidden(row, hide);
    }

    SignalConnectionRef Handle_connect_IndexesMoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QListView::indexesMoved, [handler](const QModelIndexList &indexes) {
            // oof, we really need to solve this whole ModelIndex/Variant Handle-vs-Owned problem
            std::vector<ModelIndex::__Owned> indexes2;
            std::vector<ModelIndex::HandleRef> pointers;
            int count = 0;
            for (auto &index : indexes) {
                indexes2.push_back(ModelIndex::__Owned { index });
                pointers.push_back(&indexes2[count++]);
            }
            handler->indexesMoved(pointers);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler, const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        return reinterpret_cast<HandleRef>(new QListView(qParent));
    }
}
