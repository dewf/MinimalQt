#include "generated/Screen.h"
#include "ScreenInternal.h"

#include "ObjectInternal.h"
#include "PixmapInternal.h"
#include "PointInternal.h"
#include "TransformInternal.h"
#include "SizeInternal.h"
#include "SizeFInternal.h"
#include "RectInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Point;
using namespace ::Size;
using namespace ::SizeF;
using namespace ::Rect;
using namespace ::Enums;
using namespace ::Pixmap;
using namespace ::Transform;

#define THIS (AS_QSCREEN_PTR(_this))

namespace Screen
{
    int32_t Handle_angleBetween(HandleRef _this, ScreenOrientation a, ScreenOrientation b) {
        return THIS->angleBetween(static_cast<Qt::ScreenOrientation>(a), static_cast<Qt::ScreenOrientation>(b));
    }

    Rect::OwnedRef Handle_availableGeometry(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->availableGeometry());
    }

    Size::OwnedRef Handle_availableSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->availableSize());
    }

    Rect::OwnedRef Handle_availableVirtualGeometry(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->availableVirtualGeometry());
    }

    Size::OwnedRef Handle_availableVirtualSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->availableVirtualSize());
    }

    int32_t Handle_depth(HandleRef _this) {
        return THIS->depth();
    }

    double Handle_devicePixelRatio(HandleRef _this) {
        return THIS->devicePixelRatio();
    }

    Rect::OwnedRef Handle_geometry(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->geometry());
    }

    Pixmap::OwnedRef Handle_grabWindow(HandleRef _this, size_t window /* 0 */, int32_t x /* 0 */, int32_t y /* 0 */, int32_t width /* -1 */, int32_t height /* -1 */) {
        return PIXMAP_HEAP_NEW(THIS->grabWindow(window, x, y, width, height));
    }

    bool Handle_isLandscape(HandleRef _this, ScreenOrientation o) {
        return THIS->isLandscape(static_cast<Qt::ScreenOrientation>(o));
    }

    bool Handle_isPortrait(HandleRef _this, ScreenOrientation o) {
        return THIS->isPortrait(static_cast<Qt::ScreenOrientation>(o));
    }

    double Handle_logicalDotsPerInch(HandleRef _this) {
        return THIS->logicalDotsPerInch();
    }

    double Handle_logicalDotsPerInchX(HandleRef _this) {
        return THIS->logicalDotsPerInchX();
    }

    double Handle_logicalDotsPerInchY(HandleRef _this) {
        return THIS->logicalDotsPerInchY();
    }

    std::string Handle_manufacturer(HandleRef _this) {
        return THIS->manufacturer().toStdString();
    }

    Rect::OwnedRef Handle_mapBetween(HandleRef _this, ScreenOrientation a, ScreenOrientation b, Rect::HandleRef rect) {
        const auto result = THIS->mapBetween(static_cast<Qt::ScreenOrientation>(a), static_cast<Qt::ScreenOrientation>(b), QRECT_VALUE(rect));
        return RECT_HEAP_NEW(result);
    }

    std::string Handle_model(HandleRef _this) {
        return THIS->model().toStdString();
    }

    std::string Handle_name(HandleRef _this) {
        return THIS->name().toStdString();
    }

    ScreenOrientation Handle_nativeOrientation(HandleRef _this) {
        return static_cast<ScreenOrientation>(THIS->nativeOrientation());
    }

    ScreenOrientation Handle_orientation(HandleRef _this) {
        return static_cast<ScreenOrientation>(THIS->orientation());
    }

    double Handle_physicalDotsPerInch(HandleRef _this) {
        return THIS->physicalDotsPerInch();
    }

    double Handle_physicalDotsPerInchX(HandleRef _this) {
        return THIS->physicalDotsPerInchX();
    }

    double Handle_physicalDotsPerInchY(HandleRef _this) {
        return THIS->physicalDotsPerInchY();
    }

    SizeF::OwnedRef Handle_physicalSize(HandleRef _this) {
        return SIZEF_HEAP_NEW(THIS->physicalSize());
    }

    ScreenOrientation Handle_primaryOrientation(HandleRef _this) {
        return static_cast<ScreenOrientation>(THIS->primaryOrientation());
    }

    double Handle_refreshRate(HandleRef _this) {
        return THIS->refreshRate();
    }

    std::string Handle_serialNumber(HandleRef _this) {
        return THIS->serialNumber().toStdString();
    }

    Size::OwnedRef Handle_size(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->size());
    }

    Transform::OwnedRef Handle_transformBetween(HandleRef _this, ScreenOrientation a, ScreenOrientation b, Rect::HandleRef target) {
        return TRANSFORM_HEAP_NEW(THIS->transformBetween(static_cast<Qt::ScreenOrientation>(a), static_cast<Qt::ScreenOrientation>(b), QRECT_VALUE(target)));
    }

    Rect::OwnedRef Handle_virtualGeometry(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->virtualGeometry());
    }

    HandleRef Handle_virtualSiblingAt(HandleRef _this, Point::HandleRef point) {
        return reinterpret_cast<HandleRef>(THIS->virtualSiblingAt(QPOINT_VALUE(point)));
    }

    std::vector<HandleRef> Handle_virtualSiblings(HandleRef _this) {
        return fromQList<QScreen*,HandleRef>(THIS->virtualSiblings(), [](auto scr) { return reinterpret_cast<HandleRef>(scr); });
    }

    Size::OwnedRef Handle_virtualSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->virtualSize());
    }

    SignalConnectionRef Handle_connect_AvailableGeometryChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::availableGeometryChanged, [handler](const QRect &geometry) {
            handler->sig_availableGeometryChanged(RECT_HEAP_NEW(geometry));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_GeometryChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::geometryChanged, [handler](const QRect &geometry) {
            handler->sig_geometryChanged(RECT_HEAP_NEW(geometry));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_LogicalDotsPerInchChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::logicalDotsPerInchChanged, [handler](qreal dpi) {
            handler->sig_logicalDotsPerInchChanged(dpi);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_OrientationChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::orientationChanged, [handler](Qt::ScreenOrientation orientation) {
            handler->sig_orientationChanged(static_cast<ScreenOrientation>(orientation));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_PhysicalDotsPerInchChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::physicalDotsPerInchChanged, [handler](qreal dpi) {
            handler->sig_physicalDotsPerInchChanged(dpi);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_PhysicalSizeChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::physicalSizeChanged, [handler](const QSizeF &size) {
            handler->sig_physicalSizeChanged(SIZEF_HEAP_NEW(size));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_PrimaryOrientationChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::primaryOrientationChanged, [handler](Qt::ScreenOrientation orientation) {
            handler->sig_primaryOrientationChanged(static_cast<ScreenOrientation>(orientation));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_RefreshRateChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::refreshRateChanged, [handler](qreal refreshRate) {
            handler->sig_refreshRateChanged(refreshRate);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_VirtualGeometryChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::virtualGeometryChanged, [handler](const QRect &rect) {
            handler->sig_virtualGeometryChanged(RECT_HEAP_NEW(rect));
        });
        return new __SignalConnection { connection };
    }
}
