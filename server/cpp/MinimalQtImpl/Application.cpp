#include "generated/Application.h"
#include "ApplicationInternal.h"

#include "ObjectInternal.h"

#include <QStyleFactory>

#define THIS (reinterpret_cast<QApplication*>(_this))

namespace Application
{
    SignalConnectionRef Handle_connect_FocusChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QApplication::focusChanged, [handler](QWidget *old, QWidget *now) {
            handler->focusChanged(reinterpret_cast<Widget::HandleRef>(old), reinterpret_cast<Widget::HandleRef>(now));
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::vector<std::string>& args) {
        auto argc = static_cast<int>(args.size());
        const auto argv = new char*[argc];
        for (int i = 0; i< argc; i++) {
            argv[i] = const_cast<char*>(args[i].c_str());
        }
        const auto ret = new QApplication(argc, argv);
        delete[] argv;
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
        QMetaObject::invokeMethod(QCoreApplication::instance(), func, Qt::QueuedConnection);
    }
}
