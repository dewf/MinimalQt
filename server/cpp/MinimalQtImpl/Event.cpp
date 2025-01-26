#include "generated/Event.h"
#include "EventInternal.h"

using namespace ::Enums;
using namespace ::KeySequence;

#define THIS (AS_QEVENT_PTR(_this))

namespace Event
{
    void Handle_accept(HandleRef _this) {
        THIS->accept();
    }

    void Handle_ignore(HandleRef _this) {
        THIS->ignore();
    }

#define DRAGMOVE_THIS (AS_QDRAGMOVEEVENT_PTR(_this))
    DropAction DragMoveEvent_Handle_proposedAction(DragMoveEvent_HandleRef _this) {
        return static_cast<DropAction>(DRAGMOVE_THIS->proposedAction());
    }

    void DragMoveEvent_Handle_acceptProposedAction(DragMoveEvent_HandleRef _this) {
        DRAGMOVE_THIS->acceptProposedAction();
    }

    DropActions DragMoveEvent_Handle_possibleActions(DragMoveEvent_HandleRef _this) {
        return DropActions(DRAGMOVE_THIS->possibleActions());
    }

    void DragMoveEvent_Handle_acceptDropAction(DragMoveEvent_HandleRef _this, DropAction action) {
        const auto qtAction = static_cast<Qt::DropAction>(action);
        if (qtAction == DRAGMOVE_THIS->proposedAction()) {
            DRAGMOVE_THIS->acceptProposedAction();
        } else {
            if (DRAGMOVE_THIS->possibleActions().testFlag(qtAction)) {
                DRAGMOVE_THIS->setDropAction(qtAction);
                DRAGMOVE_THIS->accept();
            } else {
                printf("DragMoveEvent_acceptDropAction: specified action was not in allowed set\n");
            }
        }
    }

    // input event ===============================================
#define INPUTEVENT_THIS (AS_QINPUTEVENT_PTR(_this))
    KeyboardModifiers InputEvent_Handle_modifiers(InputEvent_HandleRef _this) {
        return KeyboardModifiers(INPUTEVENT_THIS->modifiers());
    }

    uint64_t InputEvent_Handle_timestamp(InputEvent_HandleRef _this) {
        return INPUTEVENT_THIS->timestamp();
    }

    // keyevent ==================================================
#define KEYEVENT_THIS (AS_QKEYEVENT_PTR(_this))

    int32_t KeyEvent_Handle_count(KeyEvent_HandleRef _this) {
        return KEYEVENT_THIS->count();
    }

    bool KeyEvent_Handle_isAutoRepeat(KeyEvent_HandleRef _this) {
        return KEYEVENT_THIS->isAutoRepeat();
    }

    int32_t KeyEvent_Handle_key(KeyEvent_HandleRef _this) {
        return KEYEVENT_THIS->key();
    }

    bool KeyEvent_Handle_matches(KeyEvent_HandleRef _this, StandardKey key) {
        return KEYEVENT_THIS->matches(static_cast<QKeySequence::StandardKey>(key));
    }

    KeyboardModifiers KeyEvent_Handle_modifiers(KeyEvent_HandleRef _this) {
        return KeyboardModifiers(KEYEVENT_THIS->modifiers());
    }

    uint32_t KeyEvent_Handle_nativeModifiers(KeyEvent_HandleRef _this) {
        return KEYEVENT_THIS->nativeModifiers();
    }

    uint32_t KeyEvent_Handle_nativeScanCode(KeyEvent_HandleRef _this) {
        return KEYEVENT_THIS->nativeScanCode();
    }

    uint32_t KeyEvent_Handle_nativeVirtualKey(KeyEvent_HandleRef _this) {
        return KEYEVENT_THIS->nativeVirtualKey();
    }

    std::string KeyEvent_Handle_text(KeyEvent_HandleRef _this) {
        return KEYEVENT_THIS->text().toStdString();
    }
}
