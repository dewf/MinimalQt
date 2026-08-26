#include "generated/Application.h"
#include "ApplicationInternal.h"

#include "ObjectInternal.h"
#include "LoggingInternal.h"

#include <QStyleFactory>
#include <QThread>

using namespace ::GuiApplication;
using namespace ::Object;
using namespace ::Widget;
using namespace ::Logging;

#define THIS (reinterpret_cast<QApplication*>(_this))

namespace Application
{
    SignalConnectionRef Handle_connect_FocusChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QApplication::focusChanged, [handler](QWidget *old, QWidget *now) {
            handler->sig_focusChanged(reinterpret_cast<Widget::HandleRef>(old), reinterpret_cast<Widget::HandleRef>(now));
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    // we have to store these long-term, because QApplication takes its sweet time to read them! (on Linux, anyway)
    static int _argc = -1;
    static char** _argv = nullptr;

    HandleRef create(const std::vector<std::string>& args) {
        _argc = static_cast<int>(args.size());
        _argv = new char*[_argc];
        for (int i = 0; i< _argc; i++) {
            _argv[i] = const_cast<char*>(args[i].c_str());
        }
        const auto ret = new QApplication(_argc, _argv);
        return reinterpret_cast<HandleRef>(ret);
    }

    void setStyle(const std::string& name) {
        QApplication::setStyle(QString::fromStdString(name));
    }

    int32_t exec() {
        return QApplication::exec();
    }

    void quit() {
        QApplication::quit();
    }

    std::vector<std::string> availableStyles() {
        std::vector<std::string> result;
        for (auto & key : QStyleFactory::keys()) {
            result.push_back(key.toStdString());
        }
        return result;
    }

    void executeOnMainThread(const std::function<MainThreadFunc>& func) {
        if (QThread::currentThread() == QCoreApplication::instance()->thread()) {
            // already in the GUI thread, execute directly (with a warning)
            clientLog(LogLevel::Warning, "Application::executeOnMainThread() - already on the GUI thread!");
            func();
        } else {
            // OK
            QMetaObject::invokeMethod(QCoreApplication::instance(), func, Qt::BlockingQueuedConnection);
        }
    }
}
