#include "generated/FileDialog.h"

#include <QFileDialog>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((FileDialogWithHandler*)_this)

namespace FileDialog
{
    class FileDialogWithHandler : public QFileDialog {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // Widget:
            { CustomContextMenuRequested, SIGNAL(customContextMenuRequested(QPoint)), SLOT(onCustomContextMenuRequested(QPoint)) },
            { WindowIconChanged, SIGNAL(windowIconChanged(QIcon)), SLOT(onWindowIconChanged(QIcon)) },
            { WindowTitleChanged, SIGNAL(windowTitleChanged(QString)), SLOT(onWindowTitleChanged(QString)) },
            // Dialog:
            { SignalMaskFlags::Accepted, SIGNAL(accepted()), SLOT(onAccepted()) },
            { Finished, SIGNAL(finished(int)), SLOT(onFinished(int)) },
            { SignalMaskFlags::Rejected, SIGNAL(rejected()), SLOT(onRejected()) },
            // FileDialog:
            { CurrentChanged, SIGNAL(currentChanged(QString)), SLOT(onCurrentChanged(QString)) },
            { CurrentUrlChanged, SIGNAL(currentUrlChanged(QUrl)), SLOT(onCurrentUrlChanged(QUrl)) },
            { DirectoryEntered, SIGNAL(directoryEntered(QString)), SLOT(onDirectoryEntered(QString)) },
            { DirectoryUrlEntered, SIGNAL(directoryUrlEntered(QUrl)), SLOT(onDirectoryUrlEntered(QUrl)) },
            { FileSelected, SIGNAL(fileSelected(QString)), SLOT(onFileSelected(QString)) },
            { FilesSelected, SIGNAL(filesSelected(QStringList)), SLOT(onFilesSelected(QStringList)) },
            { FilterSelected, SIGNAL(filterSelected(QString)), SLOT(onFilterSelected(QString)) },
            { UrlSelected, SIGNAL(urlSelected(QUrl)), SLOT(onUrlSelected(QUrl)) },
            { UrlsSelected, SIGNAL(urlsSelected(QList<QUrl>)), SLOT(onUrlsSelected(QList<QUrl>)) },
        };
    public:
        explicit FileDialogWithHandler(QWidget *parent, const std::shared_ptr<SignalHandler> &handler) : QFileDialog(parent), handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            handler->
                inherited_Dialog_SignalHandler()->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_Dialog_SignalHandler()->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Widget =================
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->
                inherited_Dialog_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->
                inherited_Dialog_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    windowIconChanged((Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->
                inherited_Dialog_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    windowTitleChanged(title.toStdString());
        }
        // Dialog =================
        void onAccepted() const {
            handler->
                inherited_Dialog_SignalHandler()->
                    accepted();
        }
        void onFinished(int result) const {
            handler->
                inherited_Dialog_SignalHandler()->
                    finished(result);
        }
        void onRejected() const {
            handler->
                inherited_Dialog_SignalHandler()->
                    rejected();
        }
        // FileDialog:
        void onCurrentChanged(const QString &path) const {
            handler->currentChanged(path.toStdString());
        }
        void onCurrentUrlChanged(const QUrl &url) const {
            handler->currentUrlChanged(url.toString().toStdString());
        }
        void onDirectoryEntered(const QString &directory) const {
            handler->directoryEntered(directory.toStdString());
        }
        void onDirectoryUrlEntered(const QUrl &directory) const {
            handler->directoryUrlEntered(directory.toString().toStdString());
        }
        void onFileSelected(const QString &file) const {
            handler->fileSelected(file.toStdString());
        }
        void onFilesSelected(const QStringList &selected) const {
            std::vector<std::string> selected2;
            for (auto &str : selected) {
                selected2.push_back(str.toStdString());
            }
            handler->filesSelected(selected2);
        }
        void onFilterSelected(const QString &filter) const {
            handler->filterSelected(filter.toStdString());
        }
        void onUrlSelected(const QUrl &url) const {
            handler->urlSelected(url.toString().toStdString());
        }
        void onUrlsSelected(const QList<QUrl> &urls) const {
            std::vector<std::string> urls2;
            for (auto &url: urls) {
                urls2.push_back(url.toString().toStdString());
            }
            handler->urlsSelected(urls2);
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
