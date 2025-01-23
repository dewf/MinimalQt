#include "generated/Screen.h"
#include "ScreenInternal.h"

#include "ObjectInternal.h"
#include "PixmapInternal.h"
#include "TransformInternal.h"
#include "util/convert.h"

#define THIS (AS_QSCREEN_PTR(_this))

namespace Screen
{
    int32_t Handle_angleBetween(HandleRef _this, ScreenOrientation a, ScreenOrientation b) {
        return THIS->angleBetween(static_cast<Qt::ScreenOrientation>(a), static_cast<Qt::ScreenOrientation>(b));
    }

    Rect Handle_availableGeometry(HandleRef _this) {
        return toRect(THIS->availableGeometry());
    }

    Size Handle_availableSize(HandleRef _this) {
        return toSize(THIS->availableSize());
    }

    Rect Handle_availableVirtualGeometry(HandleRef _this) {
        return toRect(THIS->availableVirtualGeometry());
    }

    Size Handle_availableVirtualSize(HandleRef _this) {
        return toSize(THIS->availableVirtualSize());
    }

    int32_t Handle_depth(HandleRef _this) {
        return THIS->depth();
    }

    double Handle_devicePixelRatio(HandleRef _this) {
        return THIS->devicePixelRatio();
    }

    Rect Handle_geometry(HandleRef _this) {
        return toRect(THIS->geometry());
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

    Rect Handle_mapBetween(HandleRef _this, ScreenOrientation a, ScreenOrientation b, Rect rect) {
        return toRect(THIS->mapBetween(static_cast<Qt::ScreenOrientation>(a), static_cast<Qt::ScreenOrientation>(b), toQRect(rect)));
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

    SizeF Handle_physicalSize(HandleRef _this) {
        return toSizeF(THIS->physicalSize());
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

    Size Handle_size(HandleRef _this) {
        return toSize(THIS->size());
    }

    Transform::OwnedRef Handle_transformBetween(HandleRef _this, ScreenOrientation a, ScreenOrientation b, Rect target) {
        return TRANSFORM_HEAP_NEW(THIS->transformBetween(static_cast<Qt::ScreenOrientation>(a), static_cast<Qt::ScreenOrientation>(b), toQRect(target)));
    }

    Rect Handle_virtualGeometry(HandleRef _this) {
        return toRect(THIS->virtualGeometry());
    }

    HandleRef Handle_virtualSiblingAt(HandleRef _this, Point point) {
        return reinterpret_cast<HandleRef>(THIS->virtualSiblingAt(toQPoint(point)));
    }

    std::vector<HandleRef> Handle_virtualSiblings(HandleRef _this) {
        return fromQList<QScreen*,HandleRef>(THIS->virtualSiblings(), [](auto scr) { return reinterpret_cast<HandleRef>(scr); });
    }

    Size Handle_virtualSize(HandleRef _this) {
        return toSize(THIS->virtualSize());
    }

    SignalConnectionRef Handle_connect_AvailableGeometryChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::availableGeometryChanged, [handler](const QRect &geometry) {
            handler->availableGeometryChanged(toRect(geometry));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_GeometryChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::geometryChanged, [handler](const QRect &geometry) {
            handler->geometryChanged(toRect(geometry));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_LogicalDotsPerInchChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::logicalDotsPerInchChanged, [handler](qreal dpi) {
            handler->logicalDotsPerInchChanged(dpi);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_OrientationChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::orientationChanged, [handler](Qt::ScreenOrientation orientation) {
            handler->orientationChanged(static_cast<ScreenOrientation>(orientation));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_PhysicalDotsPerInchChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::physicalDotsPerInchChanged, [handler](qreal dpi) {
            handler->physicalDotsPerInchChanged(dpi);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_PhysicalSizeChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::physicalSizeChanged, [handler](const QSizeF &size) {
            handler->physicalSizeChanged(toSizeF(size));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_PrimaryOrientationChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::primaryOrientationChanged, [handler](Qt::ScreenOrientation orientation) {
            handler->primaryOrientationChanged(static_cast<ScreenOrientation>(orientation));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_RefreshRateChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::refreshRateChanged, [handler](qreal refreshRate) {
            handler->refreshRateChanged(refreshRate);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_VirtualGeometryChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QScreen::virtualGeometryChanged, [handler](const QRect &rect) {
            handler->virtualGeometryChanged(toRect(rect));
        });
        return new __SignalConnection { connection };
    }
}
