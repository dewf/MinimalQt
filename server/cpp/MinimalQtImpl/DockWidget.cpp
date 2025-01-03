#include "generated/DockWidget.h"

#include "ActionInternal.h"
#include "DockWidgetInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define DOCKWIDGET_THIS (WRAPPER->getActual())

namespace DockWidget
{
    DockWidgetAreas Handle_allowedAreas(HandleRef _this) {
        return DOCKWIDGET_THIS->allowedAreas();
    }

    void Handle_setAllowedAreas(HandleRef _this, DockWidgetAreas areas) {
        DOCKWIDGET_THIS->setAllowedAreas(static_cast<Qt::DockWidgetAreas>(areas));
    }

    DockWidgetFeatures Handle_features(HandleRef _this) {
        return DOCKWIDGET_THIS->features();
    }

    void Handle_setFeatures(HandleRef _this, DockWidgetFeatures features) {
        DOCKWIDGET_THIS->setFeatures(static_cast<QDockWidget::DockWidgetFeatures>(features));
    }

    bool Handle_isFloating(HandleRef _this) {
        return DOCKWIDGET_THIS->isFloating();
    }

    void Handle_setFloating(HandleRef _this, bool floating) {
        DOCKWIDGET_THIS->setFloating(floating);
    }

    Widget::HandleRef Handle_titleBarWidget(HandleRef _this) {
        if (const auto result = DOCKWIDGET_THIS->titleBarWidget(); result != nullptr) {
            // wrapper should already exist ...
            const auto wrapper = wrapperForQObject(result);
            assert(wrapper != nullptr);
            return reinterpret_cast<Widget::HandleRef>(wrapper);
        }
        return nullptr;
    }

    void Handle_setTitleBarWidget(HandleRef _this, Widget::HandleRef widget) {
        const auto widgetWrapper = reinterpret_cast<Widget::SignalWrapper*>(widget);
        DOCKWIDGET_THIS->setTitleBarWidget(widgetWrapper->getActual());
    }

    Widget::HandleRef Handle_getWidget(HandleRef _this) {
        if (const auto result = DOCKWIDGET_THIS->widget(); result != nullptr) {
            // wrapper should already exist ...
            const auto wrapper = wrapperForQObject(result);
            assert(wrapper != nullptr);
            return reinterpret_cast<Widget::HandleRef>(wrapper);
        }
        return nullptr;
    }

    void Handle_setWidget(HandleRef _this, Widget::HandleRef widget) {
        const auto widgetWrapper = reinterpret_cast<Widget::SignalWrapper*>(widget);
        DOCKWIDGET_THIS->setWidget(widgetWrapper->getActual());
    }

    bool Handle_isAreaAllowed(HandleRef _this, DockWidgetArea area) {
        return DOCKWIDGET_THIS->isAreaAllowed(static_cast<Qt::DockWidgetArea>(area));
    }

    std::shared_ptr<ToggleViewActionResult::Base> Handle_toggleViewAction(HandleRef _this) {
        if (const auto action = DOCKWIDGET_THIS->toggleViewAction(); action != nullptr) {
            // check for existing wrapper
            if (const auto existing = wrapperForQObject(action); existing != nullptr) {
                const auto handleRef = reinterpret_cast<Action::HandleRef>(existing);
                return std::make_shared<ToggleViewActionResult::AlreadyExists>(handleRef);
            }
            // action exists but lacks wrapper
            // return a function which can create one on-demand
            const auto func = [action](const std::shared_ptr<Action::SignalHandler>& handler) {
                const auto wrapper = new Action::SignalWrapper(action, handler);
                return reinterpret_cast<Action::HandleRef>(wrapper);
            };
            return std::make_shared<ToggleViewActionResult::NeedsWrapper>(func);
        }
        // else (according to docs, I don't think this can happen)
        return std::make_shared<ToggleViewActionResult::NoAction>();
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void processOptions(const CtorOptions& opts, QWidget*& parent, Qt::WindowFlags& flags) {
        Widget::HandleRef outParent;
        if (opts.hasParent(&outParent)) {
            parent = reinterpret_cast<Widget::SignalWrapper*>(outParent)->getActual();
        } else {
            parent = nullptr;
        }
        Enums::WindowFlags outFlags;
        if (opts.hasFlags_(&outFlags)) {
            flags = static_cast<Qt::WindowFlags>(outFlags);
        } else {
            flags = Qt::WindowFlags();
        }
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler, const CtorOptions& opts) {
        QWidget *parent;
        Qt::WindowFlags flags;
        processOptions(opts, parent, flags);
        const auto dock = new QDockWidget(parent, flags);
        const auto wrapper = new SignalWrapper(dock, handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    HandleRef create(const std::string& title, const std::shared_ptr<SignalHandler>& handler, const CtorOptions& opts) {
        QWidget *parent;
        Qt::WindowFlags flags;
        processOptions(opts, parent, flags);
        const auto dock = new QDockWidget(QString::fromStdString(title), parent, flags);
        const auto wrapper = new SignalWrapper(dock, handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
