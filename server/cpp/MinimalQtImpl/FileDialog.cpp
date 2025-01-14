#include "generated/FileDialog.h"
#include "FileDialogInternal.h"

#include "ObjectInternal.h"
#include "UrlInternal.h"
#include "DirInternal.h"

#include "util/convert.h"

#define THIS (reinterpret_cast<QFileDialog*>(_this))

namespace FileDialog
{
    AcceptMode Handle_getAcceptMode(HandleRef _this) {
        return static_cast<AcceptMode>(THIS->acceptMode());
    }

    void Handle_setAcceptMode(HandleRef _this, AcceptMode mode) {
        THIS->setAcceptMode(static_cast<QFileDialog::AcceptMode>(mode));
    }

    std::string Handle_defaultSuffix(HandleRef _this) {
        return THIS->defaultSuffix().toStdString();
    }

    void Handle_setDefaultSuffix(HandleRef _this, const std::string& suffix) {
        THIS->setDefaultSuffix(QString::fromStdString(suffix));
    }

    FileMode Handle_getFileMode(HandleRef _this) {
        return static_cast<FileMode>(THIS->fileMode());
    }

    void Handle_setFileMode(HandleRef _this, FileMode mode) {
        THIS->setFileMode(static_cast<QFileDialog::FileMode>(mode));
    }

    Options Handle_getOptions(HandleRef _this) {
        return Options(THIS->options());
    }

    void Handle_setOptions(HandleRef _this, Options opts) {
        THIS->setOptions(static_cast<QFileDialog::Options>(opts.value));
    }

    std::vector<std::string> Handle_supportedSchemes(HandleRef _this) {
        return toVectorStrings(THIS->supportedSchemes());
    }

    void Handle_setSupportedSchemes(HandleRef _this, const std::vector<std::string>& schemes) {
        THIS->setSupportedSchemes(toQStringList(schemes));
    }

    ViewMode Handle_getViewMode(HandleRef _this) {
        return static_cast<ViewMode>(THIS->viewMode());
    }

    void Handle_setViewMode(HandleRef _this, ViewMode mode) {
        THIS->setViewMode(static_cast<QFileDialog::ViewMode>(mode));
    }

    Dir::OwnedRef Handle_directory(HandleRef _this) {
        return DIR_HEAP_NEW(THIS->directory());
    }

    Url::OwnedRef Handle_directoryUrl(HandleRef _this) {
        return URL_HEAP_NEW(THIS->directoryUrl());
    }

    std::vector<std::string> Handle_mimeTypeFilters(HandleRef _this) {
        return toVectorStrings(THIS->mimeTypeFilters());
    }

    std::vector<std::string> Handle_nameFilters(HandleRef _this) {
        return toVectorStrings(THIS->nameFilters());
    }

    void Handle_setDirectory(HandleRef _this, const std::string& dir) {
        THIS->setDirectory(QString::fromStdString(dir));
    }

    void Handle_setDirectory(HandleRef _this, Dir::HandleRef dir) {
        THIS->setDirectory(QDIR_VALUE(dir));
    }

    void Handle_setDirectoryUrl(HandleRef _this, Url::HandleRef url) {
        THIS->setDirectoryUrl(QURL_VALUE(url));
    }

    void Handle_setMimeTypeFilters(HandleRef _this, const std::vector<std::string>& filters) {
        THIS->setMimeTypeFilters(toQStringList(filters));
    }

    void Handle_setNameFilter(HandleRef _this, const std::string& filter) {
        THIS->setNameFilter(QString::fromStdString(filter));
    }

    void Handle_setNameFilters(HandleRef _this, const std::vector<std::string>& filters) {
        THIS->setNameFilters(toQStringList(filters));
    }

    void Handle_selectFile(HandleRef _this, const std::string& file) {
        THIS->selectFile(QString::fromStdString(file));
    }

    std::vector<std::string> Handle_selectedFiles(HandleRef _this) {
        return toVectorStrings(THIS->selectedFiles());
    }

    SignalConnectionRef Handle_connect_CurrentChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::currentChanged, [handler](const QString &path) {
            handler->currentChanged(path.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CurrentUrlChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::currentUrlChanged, [handler](const QUrl &url) {
            handler->currentUrlChanged((Url::HandleRef)&url);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_DirectoryEntered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::directoryEntered, [handler](const QString &directory) {
            handler->directoryEntered(directory.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_DirectoryUrlEntered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::directoryUrlEntered, [handler](const QUrl &directory) {
            handler->directoryUrlEntered((Url::HandleRef)&directory);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FileSelected(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::fileSelected, [handler](const QString &file) {
            handler->fileSelected(file.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FilesSelected(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::filesSelected, [handler](const QStringList &selected) {
            handler->filesSelected(toVectorStrings(selected));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FilterSelected(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::filterSelected, [handler](const QString &filter) {
            handler->filterSelected(filter.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_UrlSelected(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::urlSelected, [handler](const QUrl &url) {
            handler->urlSelected((Url::HandleRef)&url);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_UrlsSelected(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::urlsSelected, [handler](const QList<QUrl> &urls) {
            const auto urls2 = fromQList<QUrl,Url::HandleRef>(urls, [](auto url) { return (Url::HandleRef)&url; }); // seems sketchy
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent, WindowFlags flags_) {
        return reinterpret_cast<HandleRef>(new QFileDialog(reinterpret_cast<QWidget*>(parent), static_cast<Qt::WindowFlags>(flags_.value)));
    }

    HandleRef create(const CreateOpts& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto p) { return reinterpret_cast<QWidget*>(p); }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto directory = opts.mapOrDefaultDirectory(QString::fromStdString, QString());
        const auto filter = opts.mapOrDefaultFilter(QString::fromStdString, QString());
        //
        return reinterpret_cast<HandleRef>(new QFileDialog(parent, caption, directory, filter));
    }

    std::string getExistingDirectory(const GetExistingDirectoryOpts& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto p) { return reinterpret_cast<QWidget*>(p); }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir(QString::fromStdString, QString());
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x.value); }, static_cast<QFileDialog::Options>(QFileDialog::ShowDirsOnly));
        //
        const auto result = QFileDialog::getExistingDirectory(parent, caption, dir, options);
        return result.toStdString();
    }

    Url::OwnedRef getExistingDirectoryUrl(const GetExistingDirectoryUrlOpts& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto p) { return reinterpret_cast<QWidget*>(p); }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir([](auto urlHandle) { return QURL_VALUE(urlHandle); }, QUrl());
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x.value); }, static_cast<QFileDialog::Options>(QFileDialog::ShowDirsOnly));
        const auto supportedSchemes = opts.mapOrDefaultSupportedSchemes(toQStringList, QStringList());
        //
        const auto result = QFileDialog::getExistingDirectoryUrl(parent, caption, dir, options, supportedSchemes);
        return URL_HEAP_NEW(result);
    }

    void getOpenFileContent(const std::string& nameFilter, const std::function<FileOpenCompletedFunc>& completedFunc, const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        auto fileContentsReady = [completedFunc](const QString& qFilename, const QByteArray& qBytes) {
            if (qFilename.isEmpty()) {
                // nothin'
                completedFunc(std::make_shared<FileContentResult::NoFileSelected>());
            } else {
                // OK
                const auto filename = qFilename.toStdString();
                const auto bytes = std::vector<uint8_t>(qBytes.constData(), qBytes.constData() + qBytes.size());
                completedFunc(std::make_shared<FileContentResult::ContentReady>(filename, bytes));
            }
        };
        QFileDialog::getOpenFileContent(QString::fromStdString(nameFilter), fileContentsReady, qParent);
    }

    GetOpenFileNameResult getOpenFileName(const GetOpenFileNameOpts& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto p) { return reinterpret_cast<QWidget*>(p); }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir(QString::fromStdString, QString());
        const auto filter = opts.mapOrDefaultFilter(QString::fromStdString, QString());
        QString selectedFilterValue;
        QString *selectedFilter = nullptr;
        if (std::string value; opts.hasSelectedFilterInput(&value)) {
            selectedFilterValue = QString::fromStdString(value);
            selectedFilter = &selectedFilterValue;
        }
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x.value); }, QFileDialog::Options());
        //
        GetOpenFileNameResult result;
        result.filename = QFileDialog::getOpenFileName(parent, caption, dir, filter, selectedFilter, options).toStdString();
        if (selectedFilter != nullptr) {
            result.selectedFilterOutput = selectedFilter->toStdString();
        }
        return result;
    }

    GetOpenFileNamesResult getOpenFileNames(const GetOpenFileNamesOpts& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto p) { return reinterpret_cast<QWidget*>(p); }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir(QString::fromStdString, QString());
        const auto filter = opts.mapOrDefaultFilter(QString::fromStdString, QString());
        QString selectedFilterValue;
        QString *selectedFilter = nullptr;
        if (std::string value; opts.hasSelectedFilterInput(&value)) {
            selectedFilterValue = QString::fromStdString(value);
            selectedFilter = &selectedFilterValue;
        }
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x.value); }, QFileDialog::Options());
        //
        GetOpenFileNamesResult result;
        result.filenames = toVectorStrings(QFileDialog::getOpenFileNames(parent, caption, dir, filter, selectedFilter, options));
        if (selectedFilter != nullptr) {
            result.selectedFilterOutput = selectedFilter->toStdString();
        }
        return result;
    }

    GetOpenFileUrlResult getOpenFileUrl(const GetOpenFileUrlOpts& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto p) { return reinterpret_cast<QWidget*>(p); }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir([](auto x) { return QURL_VALUE(x); }, QUrl());
        const auto filter = opts.mapOrDefaultFilter(QString::fromStdString, QString());
        QString selectedFilterValue;
        QString *selectedFilter = nullptr;
        if (std::string value; opts.hasSelectedFilterInput(&value)) {
            selectedFilterValue = QString::fromStdString(value);
            selectedFilter = &selectedFilterValue;
        }
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x.value); }, QFileDialog::Options());
        const auto supportedSchemes = opts.mapOrDefaultSupportedSchemes(toQStringList, QStringList());
        //
        const auto url = QFileDialog::getOpenFileUrl(parent, caption, dir, filter, selectedFilter, options, supportedSchemes);
        GetOpenFileUrlResult result;
        result.url = URL_HEAP_NEW(url);
        if (selectedFilter != nullptr) {
            result.selectedFilterOutput = selectedFilter->toStdString();
        }
        return result;
    }

    GetOpenFileUrlsResult getOpenFileUrls(const GetOpenFileUrlsOpts& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto p) { return reinterpret_cast<QWidget*>(p); }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir([](auto x) { return QURL_VALUE(x); }, QUrl());
        const auto filter = opts.mapOrDefaultFilter(QString::fromStdString, QString());
        QString selectedFilterValue;
        QString *selectedFilter = nullptr;
        if (std::string value; opts.hasSelectedFilterInput(&value)) {
            selectedFilterValue = QString::fromStdString(value);
            selectedFilter = &selectedFilterValue;
        }
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x.value); }, QFileDialog::Options());
        const auto supportedSchemes = opts.mapOrDefaultSupportedSchemes(toQStringList, QStringList());
        //
        const auto urls = QFileDialog::getOpenFileUrls(parent, caption, dir, filter, selectedFilter, options, supportedSchemes);
        GetOpenFileUrlsResult result;
        for (auto &url : urls) {
            result.urls.push_back(URL_HEAP_NEW(url));
        }
        if (selectedFilter != nullptr) {
            result.selectedFilterOutput = selectedFilter->toStdString();
        }
        return result;
    }

    GetSaveFileNameResult getSaveFileName(const GetSaveFileNameOpts& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto p) { return reinterpret_cast<QWidget*>(p); }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir(QString::fromStdString, QString());
        const auto filter = opts.mapOrDefaultFilter(QString::fromStdString, QString());
        QString selectedFilterValue;
        QString *selectedFilter = nullptr;
        if (std::string value; opts.hasSelectedFilterInput(&value)) {
            selectedFilterValue = QString::fromStdString(value);
            selectedFilter = &selectedFilterValue;
        }
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x.value); }, QFileDialog::Options());
        //
        GetSaveFileNameResult result;
        result.filename = QFileDialog::getSaveFileName(parent, caption, dir, filter, selectedFilter, options).toStdString();
        if (selectedFilter != nullptr) {
            result.selectedFilterOutput = selectedFilter->toStdString();
        }
        return result;
    }

    GetSaveFileUrlResult getSaveFileUrl(const GetSaveFileUrlOpts& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto p) { return reinterpret_cast<QWidget*>(p); }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir([](auto x) { return QURL_VALUE(x); }, QUrl());
        const auto filter = opts.mapOrDefaultFilter(QString::fromStdString, QString());
        QString selectedFilterValue;
        QString *selectedFilter = nullptr;
        if (std::string value; opts.hasSelectedFilterInput(&value)) {
            selectedFilterValue = QString::fromStdString(value);
            selectedFilter = &selectedFilterValue;
        }
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x.value); }, QFileDialog::Options());
        const auto supportedSchemes = opts.mapOrDefaultSupportedSchemes(toQStringList, QStringList());
        //
        const auto url = QFileDialog::getSaveFileUrl(parent, caption, dir, filter, selectedFilter, options, supportedSchemes);
        GetSaveFileUrlResult result;
        result.url = URL_HEAP_NEW(url);
        if (selectedFilter != nullptr) {
            result.selectedFilterOutput = selectedFilter->toStdString();
        }
        return result;
    }

    void saveFileContent(const std::vector<uint8_t>& fileContent, const std::string& fileNameHint, const std::optional<Widget::HandleRef>& parent) {
        QByteArray qFileContent(reinterpret_cast<const char*>(fileContent.data()), static_cast<qsizetype>(fileContent.size()));
        QString qFileNameHint = QString::fromStdString(fileNameHint);
        const auto qParent = Widget::fromOptionalHandle(parent);
        QFileDialog::saveFileContent(qFileContent, qFileNameHint, qParent);
    }
}
