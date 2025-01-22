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

    std::string Handle_defaultSuffix(HandleRef _this) {
        return THIS->defaultSuffix().toStdString();
    }

    Dir::OwnedRef Handle_directory(HandleRef _this) {
        return DIR_HEAP_NEW(THIS->directory());
    }

    Url::OwnedRef Handle_directoryUrl(HandleRef _this) {
        return URL_HEAP_NEW(THIS->directoryUrl());
    }

    FileMode Handle_getFileMode(HandleRef _this) {
        return static_cast<FileMode>(THIS->fileMode());
    }

    Filters Handle_filter(HandleRef _this) {
        return static_cast<Filters>(THIS->filter());
    }

    std::vector<std::string> Handle_history(HandleRef _this) {
        return toVectorStrings(THIS->history());
    }

    AbstractItemDelegate_HandleRef Handle_itemDelegate(HandleRef _this) {
        return reinterpret_cast<AbstractItemDelegate_HandleRef>(THIS->itemDelegate());
    }

    std::string Handle_labelText(HandleRef _this, DialogLabel label) {
        return THIS->labelText(static_cast<QFileDialog::DialogLabel>(label)).toStdString();
    }

    std::vector<std::string> Handle_mimeTypeFilters(HandleRef _this) {
        return toVectorStrings(THIS->mimeTypeFilters());
    }

    std::vector<std::string> Handle_nameFilters(HandleRef _this) {
        return toVectorStrings(THIS->nameFilters());
    }

    Options Handle_getOptions(HandleRef _this) {
        return Options(THIS->options());
    }

    AbstractProxyModel_HandleRef Handle_proxyModel(HandleRef _this) {
        return reinterpret_cast<AbstractProxyModel_HandleRef>(THIS->proxyModel());
    }

    bool Handle_restoreState(HandleRef _this, const std::vector<uint8_t>& state) {
        return THIS->restoreState(toQByteArray(state));
    }

    std::vector<uint8_t> Handle_saveState(HandleRef _this) {
        return fromQByteArray(THIS->saveState());
    }

    void Handle_selectFile(HandleRef _this, const std::string& filename) {
        THIS->selectFile(QString::fromStdString(filename));
    }

    void Handle_selectMimeTypeFilter(HandleRef _this, const std::string& filter) {
        THIS->selectMimeTypeFilter(QString::fromStdString(filter));
    }

    void Handle_selectNameFilter(HandleRef _this, const std::string& filter) {
        THIS->selectNameFilter(QString::fromStdString(filter));
    }

    void Handle_selectUrl(HandleRef _this, Url::HandleRef url) {
        THIS->selectUrl(QURL_VALUE(url));
    }

    std::vector<std::string> Handle_selectedFiles(HandleRef _this) {
        return toVectorStrings(THIS->selectedFiles());
    }

    std::string Handle_selectedMimeTypeFilter(HandleRef _this) {
        return THIS->selectedMimeTypeFilter().toStdString();
    }

    std::string Handle_selectedNameFilter(HandleRef _this) {
        return THIS->selectedNameFilter().toStdString();
    }

    ListRef Handle_selectedUrls(HandleRef _this) {
        return new Url::__List { THIS->selectedUrls() };
    }

    void Handle_setAcceptMode(HandleRef _this, AcceptMode mode) {
        THIS->setAcceptMode(static_cast<QFileDialog::AcceptMode>(mode));
    }

    void Handle_setDefaultSuffix(HandleRef _this, const std::string& suffix) {
        THIS->setDefaultSuffix(QString::fromStdString(suffix));
    }

    void Handle_setDirectory(HandleRef _this, const std::string& directory) {
        THIS->setDirectory(QString::fromStdString(directory));
    }

    void Handle_setDirectory(HandleRef _this, Dir::HandleRef directory) {
        THIS->setDirectory(QDIR_VALUE(directory));
    }

    void Handle_setDirectoryUrl(HandleRef _this, Url::HandleRef url) {
        THIS->setDirectoryUrl(QURL_VALUE(url));
    }

    void Handle_setFileMode(HandleRef _this, FileMode mode) {
        THIS->setFileMode(static_cast<QFileDialog::FileMode>(mode));
    }

    void Handle_setFilter(HandleRef _this, Filters filters) {
        THIS->setFilter(static_cast<QDir::Filters>(filters.value));
    }

    void Handle_setHistory(HandleRef _this, const std::vector<std::string>& paths) {
        THIS->setHistory(toQStringList(paths));
    }

    void Handle_setItemDelegate(HandleRef _this, AbstractItemDelegate_HandleRef delegate_) {
        THIS->setItemDelegate(reinterpret_cast<QAbstractItemDelegate*>(delegate_));
    }

    void Handle_setLabelText(HandleRef _this, DialogLabel label, const std::string& text) {
        THIS->setLabelText(static_cast<QFileDialog::DialogLabel>(label), QString::fromStdString(text));
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

    void Handle_setOption(HandleRef _this, OptionEnum option, bool on /* true */) {
        THIS->setOption(static_cast<QFileDialog::Option>(option), on);
    }

    void Handle_setOptions(HandleRef _this, Options options_) {
        THIS->setOptions(static_cast<QFileDialog::Options>(options_.value));
    }

    void Handle_setProxyModel(HandleRef _this, AbstractProxyModel_HandleRef proxyModel) {
        THIS->setProxyModel(reinterpret_cast<QAbstractProxyModel*>(proxyModel));
    }

    void Handle_setSidebarUrls(HandleRef _this, ListRef urls) {
        THIS->setSidebarUrls(urls->qList);
    }

    void Handle_setSupportedSchemes(HandleRef _this, const std::vector<std::string>& schemes) {
        THIS->setSupportedSchemes(toQStringList(schemes));
    }

    void Handle_setViewMode(HandleRef _this, ViewMode mode) {
        THIS->setViewMode(static_cast<QFileDialog::ViewMode>(mode));
    }

    ListRef Handle_sidebarUrls(HandleRef _this) {
        return new __List { THIS->sidebarUrls() };
    }

    std::vector<std::string> Handle_supportedSchemes(HandleRef _this) {
        return toVectorStrings(THIS->supportedSchemes());
    }

    bool Handle_testOption(HandleRef _this, OptionEnum option) {
        return THIS->testOption(static_cast<QFileDialog::Option>(option));
    }

    ViewMode Handle_getViewMode(HandleRef _this) {
        return static_cast<ViewMode>(THIS->viewMode());
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
            Url::__List urlList { urls };
            handler->urlsSelected(&urlList);
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
