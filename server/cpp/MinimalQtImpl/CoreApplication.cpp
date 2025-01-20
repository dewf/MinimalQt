#include "generated/CoreApplication.h"
#include "CoreApplicationInternal.h"

#include "ObjectInternal.h"

#define THIS (reinterpret_cast<QCoreApplication*>(_this))

namespace CoreApplication
{
    void Handle_exit(HandleRef _this, int32_t returnCode /* 0 */) {
        THIS->exit(returnCode);
    }

    void Handle_quit(HandleRef _this) {
        THIS->quit();
    }

    SignalConnectionRef Handle_connect_AboutToQuit(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCoreApplication::aboutToQuit, [handler] {
            handler->aboutToQuit();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ApplicationNameChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCoreApplication::applicationNameChanged, [handler] {
            handler->applicationNameChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ApplicationVersionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCoreApplication::applicationVersionChanged, [handler] {
            handler->applicationVersionChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_OrganizationDomainChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCoreApplication::organizationDomainChanged, [handler] {
            handler->organizationDomainChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_OrganizationNameChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCoreApplication::organizationNameChanged, [handler] {
            handler->organizationNameChanged();
        });
        return new __SignalConnection { connection };
    }
}
