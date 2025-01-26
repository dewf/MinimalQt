#include "generated/GuiApplication.h"
#include "GuiApplicationInternal.h"

#include "ObjectInternal.h"

using namespace ::Object;
using namespace ::CoreApplication;
using namespace ::Enums;
using namespace ::SessionManager;
using namespace ::Screen;
using namespace ::Window;

#define THIS (reinterpret_cast<QGuiApplication*>(_this))

namespace GuiApplication
{
    SignalConnectionRef Handle_connect_ApplicationDisplayNameChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGuiApplication::applicationDisplayNameChanged, [handler] {
            handler->applicationDisplayNameChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ApplicationStateChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGuiApplication::applicationStateChanged, [handler](Qt::ApplicationState state) {
            handler->applicationStateChanged(static_cast<ApplicationState>(state));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CommitDataRequest(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGuiApplication::commitDataRequest, [handler](QSessionManager &sessionManager) {
            handler->commitDataRequest(reinterpret_cast<SessionManager::HandleRef>(&sessionManager));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FocusObjectChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGuiApplication::focusObjectChanged, [handler](QObject *focusObject) {
            handler->focusObjectChanged(reinterpret_cast<Object::HandleRef>(focusObject));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FocusWindowChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGuiApplication::focusWindowChanged, [handler](QWindow *focusWindow) {
            handler->focusWindowChanged(reinterpret_cast<Window::HandleRef>(focusWindow));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FontDatabaseChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGuiApplication::fontDatabaseChanged, [handler] {
            handler->fontDatabaseChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_LastWindowClosed(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGuiApplication::lastWindowClosed, [handler] {
            handler->lastWindowClosed();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_LayoutDirectionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGuiApplication::layoutDirectionChanged, [handler](Qt::LayoutDirection direction) {
            handler->layoutDirectionChanged(static_cast<LayoutDirection>(direction));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_PrimaryScreenChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGuiApplication::primaryScreenChanged, [handler](QScreen *screen) {
            handler->primaryScreenChanged(reinterpret_cast<Screen::HandleRef>(screen));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SaveStateRequest(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGuiApplication::saveStateRequest, [handler](QSessionManager &sessionManager) {
            handler->saveStateRequest(reinterpret_cast<SessionManager::HandleRef>(&sessionManager));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ScreenAdded(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGuiApplication::screenAdded, [handler](QScreen *screen) {
            handler->screenAdded(reinterpret_cast<Screen::HandleRef>(screen));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ScreenRemoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGuiApplication::screenRemoved, [handler](QScreen *screen) {
            handler->screenRemoved(reinterpret_cast<Screen::HandleRef>(screen));
        });
        return new __SignalConnection { connection };
    }

    void setQuitOnLastWindowClosed(bool state) {
        QGuiApplication::setQuitOnLastWindowClosed(state);
    }
}
