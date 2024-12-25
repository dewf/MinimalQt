#include "generated/FileDialog.h"
#include "FileDialogInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define FILEDLG_THIS (WRAPPER->getActual())

namespace FileDialog
{
    void Handle_setAcceptMode(HandleRef _this, AcceptMode mode) {
        FILEDLG_THIS->setAcceptMode(static_cast<QFileDialog::AcceptMode>(mode));
    }

    void Handle_setDefaultSuffix(HandleRef _this, const std::string& suffix) {
        FILEDLG_THIS->setDefaultSuffix(QString::fromStdString(suffix));
    }

    void Handle_setFileMode(HandleRef _this, FileMode mode) {
        FILEDLG_THIS->setFileMode(static_cast<QFileDialog::FileMode>(mode));
    }

    void Handle_setOptions(HandleRef _this, Options opts) {
        FILEDLG_THIS->setOptions(static_cast<QFileDialog::Options>(opts));
    }

    void Handle_setSupportedSchemes(HandleRef _this, const std::vector<std::string>& schemes) {
        FILEDLG_THIS->setSupportedSchemes(toQStringList(schemes));
    }

    void Handle_setViewMode(HandleRef _this, ViewMode mode) {
        FILEDLG_THIS->setViewMode(static_cast<QFileDialog::ViewMode>(mode));
    }

    void Handle_setNameFilter(HandleRef _this, const std::string& filter) {
        FILEDLG_THIS->setNameFilter(QString::fromStdString(filter));
    }

    void Handle_setNameFilters(HandleRef _this, const std::vector<std::string>& filters) {
        QStringList qFilters;
        for (auto &filter: filters) {
            qFilters.append(QString::fromStdString(filter));
        }
        FILEDLG_THIS->setNameFilters(qFilters);
    }

    void Handle_setMimeTypeFilters(HandleRef _this, const std::vector<std::string>& filters) {
        QStringList qFilters;
        for (auto &filter: filters) {
            qFilters.append(QString::fromStdString(filter));
        }
        FILEDLG_THIS->setMimeTypeFilters(qFilters);
    }

    void Handle_setDirectory(HandleRef _this, const std::string& dir) {
        FILEDLG_THIS->setDirectory(QString::fromStdString(dir));
    }

    void Handle_selectFile(HandleRef _this, const std::string& file) {
        FILEDLG_THIS->selectFile(QString::fromStdString(file));
    }

    std::vector<std::string> Handle_selectedFiles(HandleRef _this) {
        std::vector<std::string> ret;
        for (auto &file : FILEDLG_THIS->selectedFiles()) {
            ret.push_back(file.toStdString());
        }
        return ret;
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(Widget::HandleRef parent, const std::shared_ptr<SignalHandler>& handler) {
        const auto parentWrapper = reinterpret_cast<Widget::SignalWrapper*>(parent);
        const auto fileDialog = new QFileDialog(parentWrapper->getActual());
        const auto wrapper = new SignalWrapper(fileDialog, handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}

#include "FileDialog.moc"
