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

    // resize event ========================================
#define RESIZE_THIS (reinterpret_cast<QResizeEvent*>(_this))

    Size::OwnedRef ResizeEvent_oldSize(ResizeEventRef _this) {
        return SIZE_HEAP_NEW(RESIZE_THIS->oldSize());
    }

    Size::OwnedRef ResizeEvent_size(ResizeEventRef _this) {
        return SIZE_HEAP_NEW(RESIZE_THIS->size());
    }

    // help event ==========================================
    // (nothing)

    // drop event ==========================================
#define DROPEVENT_THIS (reinterpret_cast<QDropEvent*>(_this))

    void DropEvent_acceptProposedAction(DropEventRef _this) {
        DROPEVENT_THIS->acceptProposedAction();
    }

    MouseButtons DropEvent_buttons(DropEventRef _this) {
        return MouseButtons(DROPEVENT_THIS->buttons());
    }

    DropAction DropEvent_dropAction(DropEventRef _this) {
        return static_cast<DropAction>(DROPEVENT_THIS->dropAction());
    }

    ConstHandleRef DropEvent_mimeData(DropEventRef _this) {
        return AS_MIMEDATA_CONST(DROPEVENT_THIS->mimeData()); // const!!
    }

    KeyboardModifiers DropEvent_modifiers(DropEventRef _this) {
        return KeyboardModifiers(DROPEVENT_THIS->modifiers());
    }

    PointF::OwnedRef DropEvent_position(DropEventRef _this) {
        return POINTF_HEAP_NEW(DROPEVENT_THIS->position());
    }

    DropActions DropEvent_possibleActions(DropEventRef _this) {
        return DropActions(DROPEVENT_THIS->possibleActions());
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
                clientLog(LogLevel::Warning, "DragMoveEvent_acceptDropAction: specified action was not in allowed set");
            }
        }
    }

    // input event =========================================
#define INPUTEVENT_THIS (reinterpret_cast<QInputEvent*>(_this))

    KeyboardModifiers InputEvent_modifiers(InputEventRef _this) {
        return KeyboardModifiers(INPUTEVENT_THIS->modifiers());
    }

    uint64_t InputEvent_timestamp(InputEventRef _this) {
        return INPUTEVENT_THIS->timestamp();
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

    // show event ==========================================
    // (nothing)

    // paint event =========================================
#define PAINTEVENT_THIS (reinterpret_cast<QPaintEvent*>(_this))

    Rect::OwnedRef PaintEvent_rect(PaintEventRef _this) {
        return RECT_HEAP_NEW(PAINTEVENT_THIS->rect());
    }

    Region::OwnedRef PaintEvent_region(PaintEventRef _this) {
        return REGION_HEAP_NEW(PAINTEVENT_THIS->region());
    }

    // dragleave event =====================================
    // (nothing)

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

    KeyboardModifiers KeyEvent_modifiers(KeyEventRef _this) {
        return KeyboardModifiers(KEYEVENT_THIS->modifiers());
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

    // dragmove event ======================================
    // (nothing)

    // pointer event =======================================
    // TODO

    // dragenter event =====================================
    // (nothing)

    // single point event ==================================
#define SINGLEPOINT_THIS (reinterpret_cast<QSinglePointEvent*>(_this))

    MouseButton SinglePointEvent_button(SinglePointEventRef _this) {
        return static_cast<MouseButton>(SINGLEPOINT_THIS->button());
    }

    MouseButtons SinglePointEvent_buttons(SinglePointEventRef _this) {
        return MouseButtons(SINGLEPOINT_THIS->buttons());
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

    // enter event =========================================
    // (nothing)

    // mouse event =========================================
#define MOUSEEVENT_THIS (reinterpret_cast<QMouseEvent*>(_this))

    MouseEventFlags MouseEvent_flags_(MouseEventRef _this) {
        return MouseEventFlags(MOUSEEVENT_THIS->flags());
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
}
