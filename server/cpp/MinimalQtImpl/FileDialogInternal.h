#pragma once

#include "generated/FileDialog.h"
#include "DialogInternal.h"

#include <QUrl>

namespace FileDialog {
    class SignalRelay : public Dialog::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
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
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) :
            Dialog::SignalRelay(relayFor, SignalHandler::as_Dialog_SignalHandler(handler)),
            handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Dialog::SignalRelay::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, relayFor, this);
                lastMask = newMask;
            }
        }
    public slots:
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
}
