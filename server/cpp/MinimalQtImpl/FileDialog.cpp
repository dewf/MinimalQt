#include "generated/FileDialog.h"

#include <QFileDialog>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((FileDialogWithHandler*)_this)

#include "signalrelays/FileDialog.h"

namespace FileDialog
{
    class FileDialogWithHandler : public QFileDialog {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit FileDialogWithHandler(QWidget *parent, const std::shared_ptr<SignalHandler> &handler) : QFileDialog(parent), relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    void Handle_setAcceptMode(HandleRef _this, AcceptMode mode) {
        THIS->setAcceptMode(static_cast<QFileDialog::AcceptMode>(mode));
    }

    void Handle_setDefaultSuffix(HandleRef _this, const std::string& suffix) {
        THIS->setDefaultSuffix(QString::fromStdString(suffix));
    }

    void Handle_setFileMode(HandleRef _this, FileMode mode) {
        THIS->setFileMode(static_cast<QFileDialog::FileMode>(mode));
    }

    void Handle_setOptions(HandleRef _this, Options opts) {
        THIS->setOptions(static_cast<QFileDialog::Options>(opts));
    }

    void Handle_setSupportedSchemes(HandleRef _this, const std::vector<std::string>& schemes) {
        THIS->setSupportedSchemes(toQStringList(schemes));
    }

    void Handle_setViewMode(HandleRef _this, ViewMode mode) {
        THIS->setViewMode(static_cast<QFileDialog::ViewMode>(mode));
    }

    void Handle_setNameFilter(HandleRef _this, const std::string& filter) {
        THIS->setNameFilter(QString::fromStdString(filter));
    }

    void Handle_setNameFilters(HandleRef _this, const std::vector<std::string>& filters) {
        QStringList qFilters;
        for (auto &filter: filters) {
            qFilters.append(QString::fromStdString(filter));
        }
        THIS->setNameFilters(qFilters);
    }

    void Handle_setMimeTypeFilters(HandleRef _this, const std::vector<std::string>& filters) {
        QStringList qFilters;
        for (auto &filter: filters) {
            qFilters.append(QString::fromStdString(filter));
        }
        THIS->setMimeTypeFilters(qFilters);
    }

    void Handle_setDirectory(HandleRef _this, const std::string& dir) {
        THIS->setDirectory(QString::fromStdString(dir));
    }

    void Handle_selectFile(HandleRef _this, const std::string& file) {
        THIS->selectFile(QString::fromStdString(file));
    }

    std::vector<std::string> Handle_selectedFiles(HandleRef _this) {
        std::vector<std::string> ret;
        for (auto &file : THIS->selectedFiles()) {
            ret.push_back(file.toStdString());
        }
        return ret;
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent, const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new FileDialogWithHandler(reinterpret_cast<QWidget *>(parent), handler));
    }
}

#include "FileDialog.moc"
