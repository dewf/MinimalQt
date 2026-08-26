#include "generated/DockWidget.h"
#include "DockWidgetInternal.h"

#include "ObjectInternal.h"

using namespace ::Object;
using namespace ::Widget;
using namespace ::Enums;
using namespace ::Action;

#define THIS (reinterpret_cast<QDockWidget*>(_this))

namespace DockWidget
{
    Flags<DockWidgetAreas> Handle_allowedAreas(HandleRef _this) {
        return static_cast<Flags<DockWidgetAreas>>(THIS->allowedAreas());
    }

    Flags<DockWidgetFeatures> Handle_features(HandleRef _this) {
        return static_cast<Flags<DockWidgetFeatures>>(THIS->features());
    }

    bool Handle_isAreaAllowed(HandleRef _this, DockWidgetArea area) {
        return THIS->isAreaAllowed(static_cast<Qt::DockWidgetArea>(area));
    }

    bool Handle_isFloating(HandleRef _this) {
        return THIS->isFloating();
    }

    void Handle_setAllowedAreas(HandleRef _this, Flags<DockWidgetAreas> areas) {
        THIS->setAllowedAreas(static_cast<Qt::DockWidgetAreas>(areas.value()));
    }

    void Handle_setFeatures(HandleRef _this, Flags<DockWidgetFeatures> features) {
        THIS->setFeatures(static_cast<QDockWidget::DockWidgetFeatures>(features.value()));
    }

    void Handle_setFloating(HandleRef _this, bool floating) {
        THIS->setFloating(floating);
    }

    void Handle_setTitleBarWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->setTitleBarWidget(AS_QWIDGET_PTR(widget));
    }

    void Handle_setWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->setWidget(AS_QWIDGET_PTR(widget));
    }

    Widget::HandleRef Handle_titleBarWidget(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->titleBarWidget());
    }

    Action::HandleRef Handle_toggleViewAction(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(THIS->toggleViewAction());
    }

    Widget::HandleRef Handle_widget(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->widget());
    }

    SignalConnectionRef Handle_connect_AllowedAreasChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDockWidget::allowedAreasChanged, [handler](Qt::DockWidgetAreas allowedAreas) {
            handler->sig_allowedAreasChanged(static_cast<Flags<DockWidgetAreas>>(allowedAreas));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_DockLocationChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDockWidget::dockLocationChanged, [handler](Qt::DockWidgetArea area) {
            handler->sig_dockLocationChanged(static_cast<DockWidgetArea>(area));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FeaturesChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDockWidget::featuresChanged, [handler](QDockWidget::DockWidgetFeatures features) {
            handler->sig_featuresChanged(static_cast<Flags<DockWidgetFeatures>>(features));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TopLevelChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDockWidget::topLevelChanged, [handler](bool topLevel) {
            handler->sig_topLevelChanged(topLevel);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_VisibilityChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDockWidget::visibilityChanged, [handler](bool visible) {
            handler->sig_visibilityChanged(visible);
        });
        return new __SignalConnection { connection };
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */, Flags<WindowFlags> flags_ /* 0 */) {
        auto intFlags = std::bit_cast<int>(flags_.value());
        return reinterpret_cast<HandleRef>(new QDockWidget(AS_QWIDGET_PTR(parent), static_cast<Qt::WindowFlags>(intFlags)));
    }

    HandleRef create(const std::string& title, Widget::HandleRef parent /* nullptr */, Flags<WindowFlags> flags_ /* 0 */) {
        auto intFlags = std::bit_cast<int>(flags_.value());
        return reinterpret_cast<HandleRef>(new QDockWidget(QString::fromStdString(title), AS_QWIDGET_PTR(parent), static_cast<Qt::WindowFlags>(intFlags)));
    }
}
