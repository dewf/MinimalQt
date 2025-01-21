#include "generated/Screen.h"
#include "ScreenInternal.h"

#include "ObjectInternal.h"
#include "util/convert.h"

#define THIS (AS_QSCREEN_PTR(_this))

namespace Screen
{
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
