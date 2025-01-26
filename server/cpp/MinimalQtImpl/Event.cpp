#include "generated/Event.h"
#include "EventInternal.h"

using namespace ::Enums;

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
}
