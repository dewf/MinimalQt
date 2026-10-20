#include "generated/CoreApplication.h"
#include "CoreApplicationInternal.h"

#include "ObjectInternal.h"

using namespace ::Object;

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
            handler->sig_aboutToQuit();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ApplicationNameChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCoreApplication::applicationNameChanged, [handler] {
            handler->sig_applicationNameChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ApplicationVersionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCoreApplication::applicationVersionChanged, [handler] {
            handler->sig_applicationVersionChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_OrganizationDomainChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCoreApplication::organizationDomainChanged, [handler] {
            handler->sig_organizationDomainChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_OrganizationNameChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCoreApplication::organizationNameChanged, [handler] {
            handler->sig_organizationNameChanged();
        });
        return new __SignalConnection { connection };
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto core = AS_QCOREAPPLICATION_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(core);
        }
        std::unreachable();
    }
}
