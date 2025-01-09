#include "generated/DockWidget.h"
#include "DockWidgetInternal.h"

#define THIS (reinterpret_cast<QDockWidget*>(_this))

namespace DockWidget
{
    DockWidgetAreas Handle_allowedAreas(HandleRef _this) {
        return THIS->allowedAreas();
    }

    void Handle_setAllowedAreas(HandleRef _this, DockWidgetAreas areas) {
        THIS->setAllowedAreas(static_cast<Qt::DockWidgetAreas>(areas));
    }

    DockWidgetFeatures Handle_features(HandleRef _this) {
        return THIS->features();
    }

    void Handle_setFeatures(HandleRef _this, DockWidgetFeatures features) {
        THIS->setFeatures(static_cast<QDockWidget::DockWidgetFeatures>(features));
    }

    bool Handle_isFloating(HandleRef _this) {
        return THIS->isFloating();
    }

    void Handle_setFloating(HandleRef _this, bool floating) {
        THIS->setFloating(floating);
    }

    Widget::HandleRef Handle_titleBarWidget(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->titleBarWidget());
    }

    void Handle_setTitleBarWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->setTitleBarWidget(AS_QWIDGET_PTR(widget));
    }

    Widget::HandleRef Handle_getWidget(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->widget());
    }

    void Handle_setWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->setWidget(AS_QWIDGET_PTR(widget));
    }

    bool Handle_isAreaAllowed(HandleRef _this, DockWidgetArea area) {
        return THIS->isAreaAllowed(static_cast<Qt::DockWidgetArea>(area));
    }

    Action::HandleRef Handle_toggleViewAction(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(THIS->toggleViewAction());
    }

    SignalConnectionRef Handle_connect_AllowedAreasChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDockWidget::allowedAreasChanged, [handler](Qt::DockWidgetAreas allowedAreas) {
            handler->allowedAreasChanged(allowedAreas);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_DockLocationChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDockWidget::dockLocationChanged, [handler](Qt::DockWidgetArea area) {
            handler->dockLocationChanged(static_cast<DockWidgetArea>(area));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FeaturesChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDockWidget::featuresChanged, [handler](QDockWidget::DockWidgetFeatures features) {
            handler->featuresChanged(features);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TopLevelChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDockWidget::topLevelChanged, [handler](bool topLevel) {
            handler->topLevelChanged(topLevel);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_VisibilityChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDockWidget::visibilityChanged, [handler](bool visible) {
            handler->visibilityChanged(visible);
        });
        return new __SignalConnection { connection };
    }

    HandleRef create(const CtorOptions& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto p) { return AS_QWIDGET_PTR(p); }, nullptr);
        const auto flags = opts.mapOrDefaultFlags_([](auto f) { return static_cast<Qt::WindowFlags>(f); }, Qt::WindowFlags());
        return reinterpret_cast<HandleRef>(new QDockWidget(parent, flags));
    }

    HandleRef create(const std::string& title, const CtorOptions& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto p) { return AS_QWIDGET_PTR(p); }, nullptr);
        const auto flags = opts.mapOrDefaultFlags_([](auto f) { return static_cast<Qt::WindowFlags>(f); }, Qt::WindowFlags());
        return reinterpret_cast<HandleRef>(new QDockWidget(QString::fromStdString(title), parent, flags));
    }
}
