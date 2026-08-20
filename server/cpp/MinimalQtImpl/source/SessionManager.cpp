#include "generated/SessionManager.h"
#include "SessionManagerInternal.h"

#include "util/convert.h"

using namespace ::Object;

#define THIS (reinterpret_cast<QSessionManager*>(_this))

namespace SessionManager
{
    bool Handle_allowsErrorInteraction(HandleRef _this) {
        return THIS->allowsErrorInteraction();
    }

    bool Handle_allowsInteraction(HandleRef _this) {
        return THIS->allowsInteraction();
    }

    void Handle_cancel(HandleRef _this) {
        return THIS->cancel();
    }

    std::vector<std::string> Handle_discardCommand(HandleRef _this) {
        return toVectorStrings(THIS->discardCommand());
    }

    bool Handle_isPhase2(HandleRef _this) {
        return THIS->isPhase2();
    }

    void Handle_release(HandleRef _this) {
        return THIS->release();
    }

    void Handle_requestPhase2(HandleRef _this) {
        return THIS->requestPhase2();
    }

    std::vector<std::string> Handle_restartCommand(HandleRef _this) {
        return toVectorStrings(THIS->restartCommand());
    }

    RestartHint Handle_getRestartHint(HandleRef _this) {
        return static_cast<RestartHint>(THIS->restartHint());
    }

    std::string Handle_sessionId(HandleRef _this) {
        return THIS->sessionId().toStdString();
    }

    std::string Handle_sessionKey(HandleRef _this) {
        return THIS->sessionKey().toStdString();
    }

    void Handle_setDiscardCommand(HandleRef _this, const std::vector<std::string>& command) {
        THIS->setDiscardCommand(toQStringList(command));
    }

    void Handle_setManagerProperty(HandleRef _this, const std::string& name, const std::vector<std::string>& value) {
        THIS->setManagerProperty(QString::fromStdString(name), toQStringList(value));
    }

    void Handle_setManagerProperty(HandleRef _this, const std::string& name, const std::string& value) {
        THIS->setManagerProperty(QString::fromStdString(name), QString::fromStdString(value));
    }

    void Handle_setRestartCommand(HandleRef _this, const std::vector<std::string>& command) {
        THIS->setRestartCommand(toQStringList(command));
    }

    void Handle_setRestartHint(HandleRef _this, RestartHint hint) {
        THIS->setRestartHint(static_cast<QSessionManager::RestartHint>(hint));
    }
}
