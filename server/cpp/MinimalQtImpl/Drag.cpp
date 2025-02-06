#include "generated/Drag.h"
#include "DragInternal.h"

#include "ObjectInternal.h"
#include "MimeDataInternal.h"
#include "PixmapInternal.h"
#include "PointInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Enums;
using namespace ::Pixmap;
using namespace ::Common;
using namespace ::Point;
using namespace ::MimeData;

#define THIS (AS_QDRAG_PTR(_this))

namespace Drag
{
    DropAction Handle_defaultAction(HandleRef _this) {
        return static_cast<DropAction>(THIS->defaultAction());
    }

    Pixmap::OwnedRef Handle_dragCursor(HandleRef _this, DropAction action) {
        return PIXMAP_HEAP_NEW(THIS->dragCursor(static_cast<Qt::DropAction>(action)));
    }

    DropAction Handle_exec(HandleRef _this, DropActions supportedActions /* DropActions::MoveAction */) {
        return static_cast<DropAction>(THIS->exec(static_cast<Qt::DropActions>(supportedActions.value)));
    }

    DropAction Handle_exec(HandleRef _this, DropActions supportedActions, DropAction defaultDropAction) {
        const auto result = THIS->exec(static_cast<Qt::DropActions>(supportedActions.value), static_cast<Qt::DropAction>(defaultDropAction));
        return static_cast<DropAction>(result);
    }

    Point::OwnedRef Handle_hotSpot(HandleRef _this) {
        return POINT_HEAP_NEW(THIS->hotSpot());
    }

    MimeData::HandleRef Handle_mimeData(HandleRef _this) {
        return reinterpret_cast<MimeData::HandleRef>(THIS->mimeData());
    }

    Pixmap::OwnedRef Handle_pixmap(HandleRef _this) {
        return PIXMAP_HEAP_NEW(THIS->pixmap());
    }

    void Handle_setDragCursor(HandleRef _this, Pixmap::HandleRef cursor, DropAction action) {
        THIS->setDragCursor(QPIXMAP_VALUE(cursor), static_cast<Qt::DropAction>(action));
    }

    void Handle_setHotSpot(HandleRef _this, Point::HandleRef hotspot) {
        THIS->setHotSpot(QPOINT_VALUE(hotspot));
    }

    void Handle_setMimeData(HandleRef _this, MimeData::HandleRef data) {
        THIS->setMimeData(AS_QMIMEDATA_PTR(data));
    }

    void Handle_setPixmap(HandleRef _this, Pixmap::HandleRef pixmap) {
        THIS->setPixmap(QPIXMAP_VALUE(pixmap));
    }

    Object::HandleRef Handle_source(HandleRef _this) {
        return reinterpret_cast<Object::HandleRef>(THIS->source());
    }

    DropActions Handle_supportedActions(HandleRef _this) {
        return DropActions(THIS->supportedActions());
    }

    Object::HandleRef Handle_target(HandleRef _this) {
        return reinterpret_cast<Object::HandleRef>(THIS->target());
    }

    SignalConnectionRef Handle_connect_ActionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDrag::actionChanged, [handler](Qt::DropAction action) {
            handler->actionChanged(static_cast<DropAction>(action));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TargetChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDrag::targetChanged, [handler](QObject *newTarget) {
            handler->targetChanged(reinterpret_cast<Object::HandleRef>(newTarget));
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Object::HandleRef dragSource) {
        return reinterpret_cast<HandleRef>(new QDrag(AS_QOBJECT_PTR(dragSource)));
    }

    void cancel() {
        QDrag::cancel();
    }
}
