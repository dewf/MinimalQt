#include "generated/Splitter.h"
#include "SplitterInternal.h"

#include "WidgetInternal.h"
#include "ObjectInternal.h"
#include "SplitterHandleInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Widget;
using namespace ::Frame;
using namespace ::Enums;
using namespace ::SplitterHandle;

#define THIS (reinterpret_cast<QSplitter*>(_this))

namespace Splitter
{
    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->addWidget(AS_QWIDGET_PTR(widget));
    }

    bool Handle_childrenCollapsible(HandleRef _this) {
        return THIS->childrenCollapsible();
    }

    int32_t Handle_count(HandleRef _this) {
        return THIS->count();
    }

    RangeResult Handle_getRange(HandleRef _this, int32_t index) {
        RangeResult result { 0, 0 };
        THIS->getRange(index, &result.min, &result.max);
        return result;
    }

    SplitterHandle::HandleRef Handle_getHandle(HandleRef _this, int32_t index) {
        return reinterpret_cast<SplitterHandle::HandleRef>(THIS->handle(index));
    }

    int32_t Handle_handleWidth(HandleRef _this) {
        return THIS->handleWidth();
    }

    int32_t Handle_indexOf(HandleRef _this, Widget::HandleRef widget) {
        return THIS->indexOf(AS_QWIDGET_PTR(widget));
    }

    void Handle_insertWidget(HandleRef _this, int32_t index, Widget::HandleRef widget) {
        THIS->insertWidget(index, AS_QWIDGET_PTR(widget));
    }

    bool Handle_isCollapsible(HandleRef _this, int32_t index) {
        return THIS->isCollapsible(index);
    }

    bool Handle_opaqueResize(HandleRef _this) {
        return THIS->opaqueResize();
    }

    Orientation Handle_orientation(HandleRef _this) {
        return static_cast<Orientation>(THIS->orientation());
    }

    void Handle_refresh(HandleRef _this) {
        THIS->refresh();
    }

    Widget::HandleRef Handle_replaceWidget(HandleRef _this, int32_t index, Widget::HandleRef widget) {
        return reinterpret_cast<Widget::HandleRef>(THIS->replaceWidget(index, AS_QWIDGET_PTR(widget)));
    }

    bool Handle_restoreState(HandleRef _this, const std::vector<uint8_t>& state) {
        return THIS->restoreState(toQByteArray(state));
    }

    std::vector<uint8_t> Handle_saveState(HandleRef _this) {
        return fromQByteArray(THIS->saveState());
    }

    void Handle_setChildrenCollapsible(HandleRef _this, bool value) {
        THIS->setChildrenCollapsible(value);
    }

    void Handle_setCollapsible(HandleRef _this, int32_t index, bool collapse) {
        THIS->setCollapsible(index, collapse);
    }

    void Handle_setHandleWidth(HandleRef _this, int32_t width) {
        THIS->setHandleWidth(width);
    }

    void Handle_setOpaqueResize(HandleRef _this, bool opaque_ /* true */) {
        THIS->setOpaqueResize(opaque_);
    }

    void Handle_setOrientation(HandleRef _this, Orientation orientation) {
        THIS->setOrientation(static_cast<Qt::Orientation>(orientation));
    }

    void Handle_setSizes(HandleRef _this, const std::vector<int32_t>& list) {
        const auto qSizes = toQList<int32_t,int>(list, &idFunc<int>);
        THIS->setSizes(qSizes);
    }

    void Handle_setStretchFactor(HandleRef _this, int32_t index, int32_t stretch) {
        THIS->setStretchFactor(index, stretch);
    }

    std::vector<int32_t> Handle_sizes(HandleRef _this) {
        return fromQList<int,int32_t>(THIS->sizes(), &idFunc<int>);
    }

    Widget::HandleRef Handle_widget(HandleRef _this, int32_t index) {
        return reinterpret_cast<Widget::HandleRef>(THIS->widget(index));
    }

    SignalConnectionRef Handle_connect_SplitterMoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QSplitter::splitterMoved, [handler](int index, int stretch) {
            handler->sig_splitterMoved(index, stretch);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QSplitter(AS_QWIDGET_PTR(parent)));
    }

    HandleRef create(Orientation orientation, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QSplitter(static_cast<Qt::Orientation>(orientation), AS_QWIDGET_PTR(parent)));
    }

    // ext methods block for: SplitterHandle::HandleRef ====
    HandleRef ext__SplitterHandle_Handle_splitter(SplitterHandle::HandleRef _this) {
        return reinterpret_cast<HandleRef>(AS_QSPLITTERHANDLE_PTR(_this)->splitter());
    }
    // ==============================
}
