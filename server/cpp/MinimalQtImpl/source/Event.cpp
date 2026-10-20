#include "generated/Event.h"
#include "EventInternal.h"

#include "PointFInternal.h"
#include "PointInternal.h"
#include "SizeInternal.h"
#include "MimeDataInternal.h"
#include "ObjectInternal.h"
#include "RegionInternal.h"
#include "RectInternal.h"

#include "LoggingInternal.h"
using namespace ::Logging;

#include "util/convert.h"

using namespace ::Object;
using namespace ::Size;
using namespace ::Point;
using namespace ::PointF;
using namespace ::Rect;
using namespace ::Enums;
using namespace ::KeySequence;
using namespace ::Region;
using namespace ::MimeData;

#define EVENT_THIS (reinterpret_cast<QEvent*>(_this))

namespace Event
{
    void Handle_accept(HandleRef _this) {
        EVENT_THIS->accept();
    }

    void Handle_ignore(HandleRef _this) {
        EVENT_THIS->ignore();
    }

    bool Handle_isAccepted(HandleRef _this) {
        return EVENT_THIS->isAccepted();
    }

    bool Handle_isInputEvent(HandleRef _this) {
        return EVENT_THIS->isInputEvent();
    }

    bool Handle_isPointerEvent(HandleRef _this) {
        return EVENT_THIS->isPointerEvent();
    }

    bool Handle_isSinglePointEvent(HandleRef _this) {
        return EVENT_THIS->isSinglePointEvent();
    }

    void Handle_setAccepted(HandleRef _this, bool accepted) {
        return EVENT_THIS->setAccepted(accepted);
    }

    bool Handle_spontaneous(HandleRef _this) {
        return EVENT_THIS->spontaneous();
    }

    Type Handle_type_(HandleRef _this) {
        return static_cast<Type>(EVENT_THIS->type());
    }

    // resize event ========================================
#define RESIZE_THIS (reinterpret_cast<QResizeEvent*>(_this))

    Size::OwnedRef ResizeEvent_oldSize(ResizeEventRef _this) {
        return SIZE_HEAP_NEW(RESIZE_THIS->oldSize());
    }

    Size::OwnedRef ResizeEvent_size(ResizeEventRef _this) {
        return SIZE_HEAP_NEW(RESIZE_THIS->size());
    }

    void* ResizeEvent_staticCast(ResizeEventRef obj, ResizeEvent_CastTarget target) {
        auto resizeEvent = AS_QRESIZEEVENT_PTR(obj);
        switch (target)
        {
        case ResizeEvent_CastTarget::Handle:
            return static_cast<QEvent*>(resizeEvent);
        }
        std::unreachable();
    }

    // help event ==========================================

    void* HelpEvent_staticCast(HelpEventRef obj, HelpEvent_CastTarget target) {
        auto help = AS_QHELPEVENT_PTR(obj);
        switch (target)
        {
        case HelpEvent_CastTarget::Handle:
            return static_cast<QEvent*>(help);
        }
        std::unreachable();
    }

    // drop event ==========================================
#define DROPEVENT_THIS (reinterpret_cast<QDropEvent*>(_this))

    void DropEvent_acceptProposedAction(DropEventRef _this) {
        DROPEVENT_THIS->acceptProposedAction();
    }

    Flags<MouseButtons> DropEvent_buttons(DropEventRef _this) {
        return static_cast<Flags<MouseButtons>>(DROPEVENT_THIS->buttons());
    }

    DropAction DropEvent_dropAction(DropEventRef _this) {
        return static_cast<DropAction>(DROPEVENT_THIS->dropAction());
    }

    ConstHandleRef DropEvent_mimeData(DropEventRef _this) {
        return AS_MIMEDATA_CONST(DROPEVENT_THIS->mimeData()); // const!!
    }

    Flags<KeyboardModifiers> DropEvent_modifiers(DropEventRef _this) {
        return static_cast<Flags<KeyboardModifiers>>(DROPEVENT_THIS->modifiers());
    }

    PointF::OwnedRef DropEvent_position(DropEventRef _this) {
        return POINTF_HEAP_NEW(DROPEVENT_THIS->position());
    }

    Flags<DropActions> DropEvent_possibleActions(DropEventRef _this) {
        return static_cast<Flags<DropActions>>(DROPEVENT_THIS->possibleActions());
    }

    DropAction DropEvent_proposedAction(DropEventRef _this) {
        return static_cast<DropAction>(DROPEVENT_THIS->proposedAction());
    }

    void DropEvent_setDropAction(DropEventRef _this, DropAction action) {
        DROPEVENT_THIS->setDropAction(static_cast<Qt::DropAction>(action));
    }

    Object::HandleRef DropEvent_source(DropEventRef _this) {
        return reinterpret_cast<Object::HandleRef>(DROPEVENT_THIS->source());
    }

    void DropEvent_acceptDropAction(DropEventRef _this, DropAction action) {
        const auto qtAction = static_cast<Qt::DropAction>(action);
        if (qtAction == DROPEVENT_THIS->proposedAction()) {
            DROPEVENT_THIS->acceptProposedAction();
        } else {
            if (DROPEVENT_THIS->possibleActions().testFlag(qtAction)) {
                DROPEVENT_THIS->setDropAction(qtAction);
                DROPEVENT_THIS->accept();
            } else {
                clientLog(LogLevel::Warning, "DropEvent_acceptDropAction: specified action was not in allowed set");
            }
        }
    }

    void* DropEvent_staticCast(DropEventRef obj, DropEvent_CastTarget target) {
        auto drop = AS_QDROPEVENT_PTR(obj);
        switch (target)
        {
        case DropEvent_CastTarget::Handle:
            return static_cast<QEvent*>(drop);
        }
        std::unreachable();
    }

    // input event =========================================
#define INPUTEVENT_THIS (reinterpret_cast<QInputEvent*>(_this))

    Flags<KeyboardModifiers> InputEvent_modifiers(InputEventRef _this) {
        return static_cast<Flags<KeyboardModifiers>>(INPUTEVENT_THIS->modifiers());
    }

    uint64_t InputEvent_timestamp(InputEventRef _this) {
        return INPUTEVENT_THIS->timestamp();
    }

    void* InputEvent_staticCast(InputEventRef obj, InputEvent_CastTarget target) {
        auto input = AS_QINPUTEVENT_PTR(obj);
        switch (target)
        {
        case InputEvent_CastTarget::Handle:
            return static_cast<QEvent*>(input);
        }
        std::unreachable();
    }

    // focus event =========================================
#define FOCUSEVENT_THIS (reinterpret_cast<QFocusEvent*>(_this))

    bool FocusEvent_gotFocus(FocusEventRef _this) {
        return FOCUSEVENT_THIS->gotFocus();
    }

    bool FocusEvent_lostFocus(FocusEventRef _this) {
        return FOCUSEVENT_THIS->lostFocus();
    }

    FocusReason FocusEvent_reason(FocusEventRef _this) {
        return static_cast<FocusReason>(FOCUSEVENT_THIS->reason());
    }

    void* FocusEvent_staticCast(FocusEventRef obj, FocusEvent_CastTarget target) {
        auto focus = AS_QFOCUSEVENT_PTR(obj);
        switch (target)
        {
        case FocusEvent_CastTarget::Handle:
            return static_cast<QEvent*>(focus);
        }
        std::unreachable();
    }

    // show event ==========================================

    void* ShowEvent_staticCast(ShowEventRef obj, ShowEvent_CastTarget target) {
        auto show = AS_QSHOWEVENT_PTR(obj);
        switch (target)
        {
        case ShowEvent_CastTarget::Handle:
            return static_cast<QEvent*>(show);
        }
        std::unreachable();
    }

    // paint event =========================================
#define PAINTEVENT_THIS (reinterpret_cast<QPaintEvent*>(_this))

    Rect::OwnedRef PaintEvent_rect(PaintEventRef _this) {
        return RECT_HEAP_NEW(PAINTEVENT_THIS->rect());
    }

    Region::OwnedRef PaintEvent_region(PaintEventRef _this) {
        return REGION_HEAP_NEW(PAINTEVENT_THIS->region());
    }

    void* PaintEvent_staticCast(PaintEventRef obj, PaintEvent_CastTarget target) {
        auto paint = AS_QPAINTEVENT_PTR(obj);
        switch (target)
        {
        case PaintEvent_CastTarget::Handle:
            return static_cast<QEvent*>(paint);
        }
        std::unreachable();
    }

    // dragleave event =====================================

    void* DragLeaveEvent_staticCast(DragLeaveEventRef obj, DragLeaveEvent_CastTarget target) {
        auto dragleave = AS_QDRAGLEAVEEVENT_PTR(obj);
        switch (target)
        {
        case DragLeaveEvent_CastTarget::Handle:
            return static_cast<QEvent*>(dragleave);
        }
        std::unreachable();
    }

    // contextmenu event ===================================
#define CONTEXTMENU_THIS (reinterpret_cast<QContextMenuEvent*>(_this))

    Point::OwnedRef ContextMenuEvent_globalPos(ContextMenuEventRef _this) {
        return POINT_HEAP_NEW(CONTEXTMENU_THIS->globalPos());
    }

    int32_t ContextMenuEvent_globalX(ContextMenuEventRef _this) {
        return CONTEXTMENU_THIS->globalX();
    }

    int32_t ContextMenuEvent_globalY(ContextMenuEventRef _this) {
        return CONTEXTMENU_THIS->globalY();
    }

    Point::OwnedRef ContextMenuEvent_pos(ContextMenuEventRef _this) {
        return POINT_HEAP_NEW(CONTEXTMENU_THIS->pos());
    }

    ContextMenuEvent::Reason ContextMenuEvent_getReason(ContextMenuEventRef _this) {
        return static_cast<ContextMenuEvent::Reason>(CONTEXTMENU_THIS->reason());
    }

    int32_t ContextMenuEvent_x(ContextMenuEventRef _this) {
        return CONTEXTMENU_THIS->x();
    }

    int32_t ContextMenuEvent_y(ContextMenuEventRef _this) {
        return CONTEXTMENU_THIS->y();
    }

    void* ContextMenuEvent_staticCast(ContextMenuEventRef obj, ContextMenuEvent_CastTarget target) {
        auto cme = AS_QCONTEXTMENUEVENT_PTR(obj);
        switch (target)
        {
        case ContextMenuEvent_CastTarget::Handle:
            return static_cast<QEvent*>(cme);
        case ContextMenuEvent_CastTarget::InputEvent:
            return static_cast<QInputEvent*>(cme);
        }
        std::unreachable();
    }

    // dragmove event ======================================
#define DRAGMOVE_THIS (reinterpret_cast<QDragMoveEvent*>(_this))

    void DragMoveEvent_accept(DragMoveEventRef _this, Rect::HandleRef rectangle) {
        DRAGMOVE_THIS->accept(QRECT_VALUE(rectangle));
    }

    void DragMoveEvent_accept(DragMoveEventRef _this) {
        DRAGMOVE_THIS->accept();
    }

    Rect::OwnedRef DragMoveEvent_answerRect(DragMoveEventRef _this) {
        return RECT_HEAP_NEW(DRAGMOVE_THIS->answerRect());
    }

    void DragMoveEvent_ignore(DragMoveEventRef _this, Rect::HandleRef rectangle) {
        DRAGMOVE_THIS->ignore(QRECT_VALUE(rectangle));
    }

    void DragMoveEvent_ignore(DragMoveEventRef _this) {
        DRAGMOVE_THIS->ignore();
    }

    void* DragMoveEvent_staticCast(DragMoveEventRef obj, DragMoveEvent_CastTarget target) {
        auto dragmove = AS_QDRAGMOVEEVENT_PTR(obj);
        switch (target)
        {
        case DragMoveEvent_CastTarget::Handle:
            return static_cast<QEvent*>(dragmove);
        case DragMoveEvent_CastTarget::DropEvent:
            return static_cast<QDropEvent*>(dragmove);
        }
        std::unreachable();
    }

    // key event ===========================================
#define KEYEVENT_THIS (reinterpret_cast<QKeyEvent*>(_this))

    int32_t KeyEvent_count(KeyEventRef _this) {
        return KEYEVENT_THIS->count();
    }

    bool KeyEvent_isAutoRepeat(KeyEventRef _this) {
        return KEYEVENT_THIS->isAutoRepeat();
    }

    int32_t KeyEvent_key(KeyEventRef _this) {
        return KEYEVENT_THIS->key();
    }

    bool KeyEvent_matches(KeyEventRef _this, StandardKey key) {
        return KEYEVENT_THIS->matches(static_cast<QKeySequence::StandardKey>(key));
    }

    Flags<KeyboardModifiers> KeyEvent_modifiers(KeyEventRef _this) {
        return static_cast<Flags<KeyboardModifiers>>(KEYEVENT_THIS->modifiers());
    }

    uint32_t KeyEvent_nativeModifiers(KeyEventRef _this) {
        return KEYEVENT_THIS->nativeModifiers();
    }

    uint32_t KeyEvent_nativeScanCode(KeyEventRef _this) {
        return KEYEVENT_THIS->nativeScanCode();
    }

    uint32_t KeyEvent_nativeVirtualKey(KeyEventRef _this) {
        return KEYEVENT_THIS->nativeVirtualKey();
    }

    std::string KeyEvent_text(KeyEventRef _this) {
        return KEYEVENT_THIS->text().toStdString();
    }

    void* KeyEvent_staticCast(KeyEventRef obj, KeyEvent_CastTarget target) {
        auto key = AS_QKEYEVENT_PTR(obj);
        switch (target)
        {
        case KeyEvent_CastTarget::Handle:
            return static_cast<QEvent*>(key);
        case KeyEvent_CastTarget::InputEvent:
            return static_cast<QInputEvent*>(key);
        }
        std::unreachable();
    }

    // pointer event =======================================

    void* PointerEvent_staticCast(PointerEventRef obj, PointerEvent_CastTarget target) {
        auto pointer = AS_QPOINTEREVENT_PTR(obj);
        switch (target)
        {
        case PointerEvent_CastTarget::Handle:
            return static_cast<QEvent*>(pointer);
        case PointerEvent_CastTarget::InputEvent:
            return static_cast<QInputEvent*>(pointer);
        }
        std::unreachable();
    }

    // dragenter event =====================================

    void* DragEnterEvent_staticCast(DragEnterEventRef obj, DragEnterEvent_CastTarget target) {
        auto dragenter = AS_QDRAGENTEREVENT_PTR(obj);
        switch (target)
        {
        case DragEnterEvent_CastTarget::Handle:
            return static_cast<QEvent*>(dragenter);
        case DragEnterEvent_CastTarget::DropEvent:
            return static_cast<QDropEvent*>(dragenter);
        case DragEnterEvent_CastTarget::DragMoveEvent:
            return static_cast<QDragMoveEvent*>(dragenter);
        }
        std::unreachable();
    }

    // single point event ==================================
#define SINGLEPOINT_THIS (reinterpret_cast<QSinglePointEvent*>(_this))

    MouseButton SinglePointEvent_button(SinglePointEventRef _this) {
        return static_cast<MouseButton>(SINGLEPOINT_THIS->button());
    }

    Flags<MouseButtons> SinglePointEvent_buttons(SinglePointEventRef _this) {
        return static_cast<Flags<MouseButtons>>(SINGLEPOINT_THIS->buttons());
    }

    Object::HandleRef SinglePointEvent_exclusivePointGrabber(SinglePointEventRef _this) {
        return reinterpret_cast<Object::HandleRef>(SINGLEPOINT_THIS->exclusivePointGrabber());
    }

    PointF::OwnedRef SinglePointEvent_globalPosition(SinglePointEventRef _this) {
        return POINTF_HEAP_NEW(SINGLEPOINT_THIS->globalPosition());
    }

    PointF::OwnedRef SinglePointEvent_position(SinglePointEventRef _this) {
        return POINTF_HEAP_NEW(SINGLEPOINT_THIS->position());
    }

    PointF::OwnedRef SinglePointEvent_scenePosition(SinglePointEventRef _this) {
        return POINTF_HEAP_NEW(SINGLEPOINT_THIS->scenePosition());
    }

    void SinglePointEvent_setExclusivePointGrabber(SinglePointEventRef _this, Object::HandleRef exclusiveGrabber) {
        SINGLEPOINT_THIS->setExclusivePointGrabber(AS_QOBJECT_PTR(exclusiveGrabber));
    }

    void* SinglePointEvent_staticCast(SinglePointEventRef obj, SinglePointEvent_CastTarget target) {
        auto single = AS_QSINGLEPOINTEVENT_PTR(obj);
        switch (target)
        {
        case SinglePointEvent_CastTarget::Handle:
            return static_cast<QEvent*>(single);
        case SinglePointEvent_CastTarget::InputEvent:
            return static_cast<QInputEvent*>(single);
        case SinglePointEvent_CastTarget::PointerEvent:
            return static_cast<QPointerEvent*>(single);
        }
        std::unreachable();
    }

    // enter event =========================================

    void* EnterEvent_staticCast(EnterEventRef obj, EnterEvent_CastTarget target) {
        auto enter = AS_QENTEREVENT_PTR(obj);
        switch (target)
        {
        case EnterEvent_CastTarget::Handle:
            return static_cast<QEvent*>(enter);
        case EnterEvent_CastTarget::InputEvent:
            return static_cast<QInputEvent*>(enter);
        case EnterEvent_CastTarget::PointerEvent:
            return static_cast<QPointerEvent*>(enter);
        case EnterEvent_CastTarget::SinglePointEvent:
            return static_cast<QSinglePointEvent*>(enter);
        }
        std::unreachable();
    }

    // mouse event =========================================
#define MOUSEEVENT_THIS (reinterpret_cast<QMouseEvent*>(_this))

    Flags<MouseEventFlags> MouseEvent_flags_(MouseEventRef _this) {
        return static_cast<Flags<MouseEventFlags>>(MOUSEEVENT_THIS->flags());
    }

    void* MouseEvent_staticCast(MouseEventRef obj, MouseEvent_CastTarget target) {
        auto mouse = AS_QMOUSEEVENT_PTR(obj);
        switch (target)
        {
        case MouseEvent_CastTarget::Handle:
            return static_cast<QEvent*>(mouse);
        case MouseEvent_CastTarget::InputEvent:
            return static_cast<QInputEvent*>(mouse);
        case MouseEvent_CastTarget::PointerEvent:
            return static_cast<QPointerEvent*>(mouse);
        case MouseEvent_CastTarget::SinglePointEvent:
            return static_cast<QSinglePointEvent*>(mouse);
        }
        std::unreachable();
    }

    // wheel event =========================================
#define WHEELEVENT_THIS (reinterpret_cast<QWheelEvent*>(_this))

    Point::OwnedRef WheelEvent_angleDelta(WheelEventRef _this) {
        return POINT_HEAP_NEW(WHEELEVENT_THIS->angleDelta());
    }

    bool WheelEvent_inverted(WheelEventRef _this) {
        return WHEELEVENT_THIS->inverted();
    }

    ScrollPhase WheelEvent_phase(WheelEventRef _this) {
        return static_cast<ScrollPhase>(WHEELEVENT_THIS->phase());
    }

    Point::OwnedRef WheelEvent_pixelDelta(WheelEventRef _this) {
        return POINT_HEAP_NEW(WHEELEVENT_THIS->pixelDelta());
    }

    void* WheelEvent_staticCast(WheelEventRef obj, WheelEvent_CastTarget target) {
        auto wheel = AS_QWHEELEVENT_PTR(obj);
        switch (target)
        {
        case WheelEvent_CastTarget::Handle:
            return static_cast<QEvent*>(wheel);
        case WheelEvent_CastTarget::InputEvent:
            return static_cast<QInputEvent*>(wheel);
        case WheelEvent_CastTarget::PointerEvent:
            return static_cast<QPointerEvent*>(wheel);
        case WheelEvent_CastTarget::SinglePointEvent:
            return static_cast<QSinglePointEvent*>(wheel);
        }
        std::unreachable();
    }
}
