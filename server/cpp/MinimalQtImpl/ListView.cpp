#include "generated/ListView.h"
#include "ListViewInternal.h"

#include <QListView>
#include <utility>
#include "util/convert.h"

#define THIS ((ListViewWithHandler*)_this)

namespace ListView
{
    class ListViewWithHandler : public QListView {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit ListViewWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    void Handle_setBatchSize(HandleRef _this, int32_t size) {
        THIS->setBatchSize(size);
    }

    void Handle_setFlow(HandleRef _this, Flow flow) {
        THIS->setFlow(static_cast<QListView::Flow>(flow));
    }

    void Handle_setGridSize(HandleRef _this, Size size) {
        THIS->setGridSize(toQSize(size));
    }

    void Handle_setWrapping(HandleRef _this, bool wrapping) {
        THIS->setWrapping(wrapping);
    }

    void Handle_setItemAlignment(HandleRef _this, Alignment align) {
        THIS->setItemAlignment(static_cast<Qt::Alignment>(align));
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

    void Handle_setSelectionRectVisible(HandleRef _this, bool visible) {
        THIS->setSelectionRectVisible(visible);
    }

    void Handle_setSpacing(HandleRef _this, int32_t spacing) {
        THIS->setSpacing(spacing);
    }

    void Handle_setUniformItemSizes(HandleRef _this, bool state) {
        THIS->setUniformItemSizes(state);
    }

    void Handle_setViewMode(HandleRef _this, ViewMode mode) {
        THIS->setViewMode(static_cast<QListView::ViewMode>(mode));
    }

    void Handle_setWordWrap(HandleRef _this, bool state) {
        THIS->setWordWrap(state);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new ListViewWithHandler(handler));
    }
}

#include "ListView.moc"
