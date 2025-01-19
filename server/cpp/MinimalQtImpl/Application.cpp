#include "generated/Application.h"

#include <QApplication>
#include <QStyleFactory>

#define THIS ((QApplication*)_this)

namespace Application
{
    void Handle_setQuitOnLastWindowClosed(HandleRef _this, bool state) {
        THIS->setQuitOnLastWindowClosed(state);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
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

    HandleRef create(const std::vector<std::string>& args) {
        auto argc = (int)args.size();
        auto argv = new char*[argc];
        for (int i = 0; i< argc; i++) {
            argv[i] = const_cast<char*>(args[i].c_str());
        }
        auto ret = new QApplication(argc, argv);
        delete[] argv;
        return (HandleRef)ret;
    }

    void executeOnMainThread(const std::function<MainThreadFunc>& func) {
        QMetaObject::invokeMethod(QCoreApplication::instance(), func, Qt::QueuedConnection);
    }
}
