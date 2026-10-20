#include "generated/FileDialog.h"
#include "FileDialogInternal.h"

#include "ObjectInternal.h"
#include "UrlInternal.h"
#include "DirInternal.h"

#include "LoggingInternal.h"
using namespace ::Logging;

#include "util/convert.h"

using namespace ::Object;
using namespace ::Icon;
using namespace ::Dialog;
using namespace ::Widget;
using namespace ::Enums;
using namespace ::Dir;
using namespace ::Url;
using namespace ::AbstractItemDelegate;
using namespace ::AbstractProxyModel;

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

    Flags<Filters> Handle_filter(HandleRef _this) {
        return static_cast<Flags<Filters>>(THIS->filter());
    }

    std::vector<std::string> Handle_history(HandleRef _this) {
        return fromQStringList(THIS->history());
    }

    AbstractItemDelegate::HandleRef Handle_itemDelegate(HandleRef _this) {
        return reinterpret_cast<AbstractItemDelegate::HandleRef>(THIS->itemDelegate());
    }

    std::string Handle_labelText(HandleRef _this, DialogLabel label) {
        return THIS->labelText(static_cast<QFileDialog::DialogLabel>(label)).toStdString();
    }

    std::vector<std::string> Handle_mimeTypeFilters(HandleRef _this) {
        return fromQStringList(THIS->mimeTypeFilters());
    }

    std::vector<std::string> Handle_nameFilters(HandleRef _this) {
        return fromQStringList(THIS->nameFilters());
    }

    Flags<Options> Handle_getOptions(HandleRef _this) {
        return static_cast<Flags<Options>>(THIS->options());
    }

    AbstractProxyModel::HandleRef Handle_proxyModel(HandleRef _this) {
        return reinterpret_cast<AbstractProxyModel::HandleRef>(THIS->proxyModel());
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
        return fromQStringList(THIS->selectedFiles());
    }

    std::string Handle_selectedMimeTypeFilter(HandleRef _this) {
        return THIS->selectedMimeTypeFilter().toStdString();
    }

    std::string Handle_selectedNameFilter(HandleRef _this) {
        return THIS->selectedNameFilter().toStdString();
    }

    OwnedListRef Handle_selectedUrls(HandleRef _this) {
        return URL_LIST_HEAP_NEW(THIS->selectedUrls());
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

    void Handle_setFilter(HandleRef _this, Flags<Filters> filters) {
        THIS->setFilter(static_cast<QDir::Filters>(filters.value()));
    }

    void Handle_setHistory(HandleRef _this, const std::vector<std::string>& paths) {
        THIS->setHistory(toQStringList(paths));
    }

    void Handle_setItemDelegate(HandleRef _this, AbstractItemDelegate::HandleRef delegate_) {
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

    void Handle_setOptions(HandleRef _this, Flags<Options> options_) {
        THIS->setOptions(static_cast<QFileDialog::Options>(options_.value()));
    }

    void Handle_setProxyModel(HandleRef _this, AbstractProxyModel::HandleRef proxyModel) {
        THIS->setProxyModel(reinterpret_cast<QAbstractProxyModel*>(proxyModel));
    }

    void Handle_setSidebarUrls(HandleRef _this, ListRef urls) {
        THIS->setSidebarUrls(QURL_LIST_VALUE(urls));
    }

    void Handle_setSupportedSchemes(HandleRef _this, const std::vector<std::string>& schemes) {
        THIS->setSupportedSchemes(toQStringList(schemes));
    }

    void Handle_setViewMode(HandleRef _this, ViewMode mode) {
        THIS->setViewMode(static_cast<QFileDialog::ViewMode>(mode));
    }

    OwnedListRef Handle_sidebarUrls(HandleRef _this) {
        return URL_LIST_HEAP_NEW(THIS->sidebarUrls());
    }

    std::vector<std::string> Handle_supportedSchemes(HandleRef _this) {
        return fromQStringList(THIS->supportedSchemes());
    }

    bool Handle_testOption(HandleRef _this, OptionEnum option) {
        return THIS->testOption(static_cast<QFileDialog::Option>(option));
    }

    ViewMode Handle_getViewMode(HandleRef _this) {
        return static_cast<ViewMode>(THIS->viewMode());
    }

    SignalConnectionRef Handle_connect_CurrentChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::currentChanged, [handler](const QString &path) {
            handler->sig_currentChanged(path.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CurrentUrlChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::currentUrlChanged, [handler](const QUrl &url) {
            QUrl url2(url);
            handler->sig_currentUrlChanged(reinterpret_cast<Url::HandleRef>(&url2));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_DirectoryEntered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::directoryEntered, [handler](const QString &directory) {
            handler->sig_directoryEntered(directory.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_DirectoryUrlEntered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::directoryUrlEntered, [handler](const QUrl &directory) {
            QUrl directory2(directory);
            handler->sig_directoryUrlEntered(reinterpret_cast<Url::HandleRef>(&directory2));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FileSelected(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::fileSelected, [handler](const QString &file) {
            handler->sig_fileSelected(file.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FilesSelected(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::filesSelected, [handler](const QStringList &selected) {
            handler->sig_filesSelected(fromQStringList(selected));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FilterSelected(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::filterSelected, [handler](const QString &filter) {
            handler->sig_filterSelected(filter.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_UrlSelected(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::urlSelected, [handler](const QUrl &url) {
            QUrl url2(url);
            handler->sig_urlSelected(reinterpret_cast<Url::HandleRef>(&url2));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_UrlsSelected(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QFileDialog::urlsSelected, [handler](const QList<QUrl> &urls) {
            QList<QUrl> urls2(urls);
            handler->sig_urlsSelected(reinterpret_cast<Url::ListRef>(&urls2));
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto fileDialog = AS_QFILEDIALOG_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(fileDialog);
        case Handle_CastTarget::Widget_Handle:
            return static_cast<QWidget*>(fileDialog);
        case Handle_CastTarget::Dialog_Handle:
            return static_cast<QDialog*>(fileDialog);
        }
        std::unreachable();
    }

    HandleRef create(Widget::HandleRef parent, Flags<WindowFlags> flags_) {
        auto intFlags = std::bit_cast<int>(flags_.value()); // Qt flags silliness
        return reinterpret_cast<HandleRef>(new QFileDialog(reinterpret_cast<QWidget*>(parent), static_cast<Qt::WindowFlags>(intFlags)));
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */, const std::optional<std::string>& caption /* {} */, const std::optional<std::string>& directory /* {} */, const std::optional<std::string>& filter /* {} */) {
        return reinterpret_cast<HandleRef>(
            new QFileDialog(
                AS_QWIDGET_PTR(parent),
                qstringFromNullable(caption),
                qstringFromNullable(directory),
                qstringFromNullable(filter)));
    }

    std::string getExistingDirectory(Widget::HandleRef parent /* nullptr */, const std::optional<std::string>& caption /* {} */, const std::optional<std::string>& dir /* {} */, Flags<Options> options_ /* Options::ShowDirsOnly */) {
        return QFileDialog::getExistingDirectory(
            AS_QWIDGET_PTR(parent),
            qstringFromNullable(caption),
            qstringFromNullable(dir),
            QFileDialog::Options::fromInt(options_.value())).toStdString();
    }

    Url::OwnedRef getExistingDirectoryUrl(Widget::HandleRef parent /* nullptr */, const std::optional<std::string>& caption /* {} */, Url::HandleRef dir /* nullptr */, Flags<Options> options_ /* Options::ShowDirsOnly */, const std::optional<std::vector<std::string>>& supportedSchemes /* {} */) {
        auto qSchemes = supportedSchemes.transform(toQStringList).value_or(QStringList());
        auto result =
            QFileDialog::getExistingDirectoryUrl(
                AS_QWIDGET_PTR(parent),
                qstringFromNullable(caption),
                QURL_VALUE(dir),
                QFileDialog::Options::fromInt(options_.value()),
                qSchemes);
        return URL_HEAP_NEW(result);
    }

    void getOpenFileContent(const std::string& nameFilter, const std::function<FileOpenCompletedFunc>& fileOpenCompleted, Widget::HandleRef parent /* nullptr */) {
        auto fileContentsReady = [fileOpenCompleted](const QString& qFilename, const QByteArray& qBytes) {
            if (qFilename.isEmpty()) {
                // nothin'
                fileOpenCompleted("", [] { return std::vector<uint8_t>(); });
            } else {
                // OK
                const auto filename = qFilename.toStdString();
                const QByteArray savedBytes = qBytes; // formally retain it for later, no doubt qBytes will not last long
                fileOpenCompleted(filename, [savedBytes] {
                    return std::vector<uint8_t>(savedBytes.constData(), savedBytes.constData() + savedBytes.size());
                });
            }
        };
        QFileDialog::getOpenFileContent(QString::fromStdString(nameFilter), fileContentsReady, AS_QWIDGET_PTR(parent));
    }

    GetOpenFileNameResult getOpenFileName(Widget::HandleRef parent /* nullptr */, const std::optional<std::string>& caption /* {} */, const std::optional<std::string>& dir /* {} */, const std::optional<std::string>& filter /* {} */, const std::optional<std::string>& selectedFilterInput /* {} */, const std::optional<Flags<Options>>& options_ /* {} */) {
        QString selectedFilterValue;
        QString *selectedFilterPtr = nullptr;
        if (selectedFilterInput.has_value())
        {
            selectedFilterValue = QString::fromStdString(selectedFilterInput.value());
            selectedFilterPtr = &selectedFilterValue;
        }
        QFileDialog::Options qoptions;
        if (options_.has_value())
        {
            qoptions = QFileDialog::Options::fromInt(options_.value().value());
        }
        auto qfilename =
            QFileDialog::getOpenFileName(
                AS_QWIDGET_PTR(parent),
                qstringFromNullable(caption),
                qstringFromNullable(dir),
                qstringFromNullable(filter),
                selectedFilterPtr,
                qoptions);
        GetOpenFileNameResult result;
        result.filename = qfilename.toStdString();
        if (selectedFilterPtr != nullptr)
        {
            result.selectedFilterOutput = selectedFilterPtr->toStdString();
        }
        return result;
    }

    GetOpenFileNamesResult getOpenFileNames(Widget::HandleRef parent /* nullptr */, const std::optional<std::string>& caption /* {} */, const std::optional<std::string>& dir /* {} */, const std::optional<std::string>& filter /* {} */, const std::optional<std::string>& selectedFilterInput /* {} */, const std::optional<Flags<Options>>& options_ /* {} */) {
        QString selectedFilterValue;
        QString *selectedFilterPtr = nullptr;
        if (selectedFilterInput.has_value())
        {
            selectedFilterValue = QString::fromStdString(selectedFilterInput.value());
            selectedFilterPtr = &selectedFilterValue;
        }
        QFileDialog::Options qoptions;
        if (options_.has_value())
        {
            qoptions = QFileDialog::Options::fromInt(options_.value().value());
        }
        auto qfilenamelist =
            QFileDialog::getOpenFileNames(
                AS_QWIDGET_PTR(parent),
                qstringFromNullable(caption),
                qstringFromNullable(dir),
                qstringFromNullable(filter),
                selectedFilterPtr,
                qoptions);
        GetOpenFileNamesResult result;
        result.filenames = fromQStringList(qfilenamelist);
        if (selectedFilterPtr != nullptr)
        {
            result.selectedFilterOutput = selectedFilterPtr->toStdString();
        }
        return result;
    }

    GetOpenFileUrlResult getOpenFileUrl(Widget::HandleRef parent /* nullptr */, const std::optional<std::string>& caption /* {} */, Url::HandleRef dir /* nullptr */, const std::optional<std::string>& filter /* {} */, const std::optional<std::string>& selectedFilterInput /* {} */, const std::optional<Flags<Options>>& options_ /* {} */, const std::optional<std::vector<std::string>>& supportedSchemes /* {} */) {
        QString selectedFilterValue;
        QString *selectedFilterPtr = nullptr;
        if (selectedFilterInput.has_value())
        {
            selectedFilterValue = QString::fromStdString(selectedFilterInput.value());
            selectedFilterPtr = &selectedFilterValue;
        }
        QFileDialog::Options qoptions;
        if (options_.has_value())
        {
            qoptions = QFileDialog::Options::fromInt(options_.value().value());
        }
        QStringList qschemes;
        if (supportedSchemes.has_value())
        {
            qschemes = toQStringList(supportedSchemes.value());
        }
        auto qurl =
            QFileDialog::getOpenFileUrl(
                AS_QWIDGET_PTR(parent),
                qstringFromNullable(caption),
                QURL_VALUE(dir),
                qstringFromNullable(filter),
                selectedFilterPtr,
                qoptions,
                qschemes);
        GetOpenFileUrlResult result;
        result.url = URL_HEAP_NEW(qurl);
        if (selectedFilterPtr != nullptr)
        {
            result.selectedFilterOutput = selectedFilterPtr->toStdString();
        }
        return result;
    }

    GetOpenFileUrlsResult getOpenFileUrls(Widget::HandleRef parent /* nullptr */, const std::optional<std::string>& caption /* {} */, Url::HandleRef dir /* nullptr */, const std::optional<std::string>& filter /* {} */, const std::optional<std::string>& selectedFilterInput /* {} */, const std::optional<Flags<Options>>& options_ /* {} */, const std::optional<std::vector<std::string>>& supportedSchemes /* {} */) {
        QString selectedFilterValue;
        QString *selectedFilterPtr = nullptr;
        if (selectedFilterInput.has_value())
        {
            selectedFilterValue = QString::fromStdString(selectedFilterInput.value());
            selectedFilterPtr = &selectedFilterValue;
        }
        QFileDialog::Options qoptions;
        if (options_.has_value())
        {
            qoptions = QFileDialog::Options::fromInt(options_.value().value());
        }
        QStringList qschemes;
        if (supportedSchemes.has_value())
        {
            qschemes = toQStringList(supportedSchemes.value());
        }
        auto qurlList =
            QFileDialog::getOpenFileUrls(
                AS_QWIDGET_PTR(parent),
                qstringFromNullable(caption),
                QURL_VALUE(dir),
                qstringFromNullable(filter),
                selectedFilterPtr,
                qoptions,
                qschemes);
        GetOpenFileUrlsResult result;
        result.urls = URL_LIST_HEAP_NEW(qurlList);
        if (selectedFilterPtr != nullptr)
        {
            result.selectedFilterOutput = selectedFilterPtr->toStdString();
        }
        return result;
    }

    GetSaveFileNameResult getSaveFileName(Widget::HandleRef parent /* nullptr */, const std::optional<std::string>& caption /* {} */, const std::optional<std::string>& dir /* {} */, const std::optional<std::string>& filter /* {} */, const std::optional<std::string>& selectedFilterInput /* {} */, const std::optional<Flags<Options>>& options_ /* {} */) {
        QString selectedFilterValue;
        QString *selectedFilterPtr = nullptr;
        if (selectedFilterInput.has_value())
        {
            selectedFilterValue = QString::fromStdString(selectedFilterInput.value());
            selectedFilterPtr = &selectedFilterValue;
        }
        QFileDialog::Options qoptions;
        if (options_.has_value())
        {
            qoptions = QFileDialog::Options::fromInt(options_.value().value());
        }
        auto qfilename =
            QFileDialog::getSaveFileName(
                AS_QWIDGET_PTR(parent),
                qstringFromNullable(caption),
                qstringFromNullable(dir),
                qstringFromNullable(filter),
                selectedFilterPtr,
                qoptions);
        GetSaveFileNameResult result;
        result.filename = qfilename.toStdString();
        if (selectedFilterPtr != nullptr)
        {
            result.selectedFilterOutput = selectedFilterPtr->toStdString();
        }
        return result;
    }

    GetSaveFileUrlResult getSaveFileUrl(Widget::HandleRef parent /* nullptr */, const std::optional<std::string>& caption /* {} */, Url::HandleRef dir /* nullptr */, const std::optional<std::string>& filter /* {} */, const std::optional<std::string>& selectedFilterInput /* {} */, const std::optional<Flags<Options>>& options_ /* {} */, const std::optional<std::vector<std::string>>& supportedSchemes /* {} */)
    {
        QString selectedFilterValue;
        QString *selectedFilterPtr = nullptr;
        if (selectedFilterInput.has_value())
        {
            selectedFilterValue = QString::fromStdString(selectedFilterInput.value());
            selectedFilterPtr = &selectedFilterValue;
        }
        QFileDialog::Options qoptions;
        if (options_.has_value())
        {
            qoptions = QFileDialog::Options::fromInt(options_.value().value());
        }
        QStringList qschemes;
        if (supportedSchemes.has_value())
        {
            qschemes = toQStringList(supportedSchemes.value());
        }
        auto qurl =
            QFileDialog::getSaveFileUrl(
                AS_QWIDGET_PTR(parent),
                qstringFromNullable(caption),
                QURL_VALUE(dir),
                qstringFromNullable(filter),
                selectedFilterPtr,
                qoptions,
                qschemes);
        GetSaveFileUrlResult result;
        result.url = URL_HEAP_NEW(qurl);
        if (selectedFilterPtr != nullptr)
        {
            result.selectedFilterOutput = selectedFilterPtr->toStdString();
        }
        return result;
    }

    void saveFileContent(const std::shared_ptr<NativeBuffer<uint8_t>>& fileContent, const std::string& fileNameHint, Widget::HandleRef parent /* nullptr */) {
        size_t len;
        auto ptr = fileContent->getSpan(&len);
        if (ptr != nullptr)
        {
            QByteArray qFileContent(reinterpret_cast<const char*>(ptr), static_cast<qsizetype>(len));
            QString qFileNameHint = QString::fromStdString(fileNameHint);
            QFileDialog::saveFileContent(qFileContent, qFileNameHint, AS_QWIDGET_PTR(parent));
        } else
        {
            clientLog(LogLevel::Warning, "FileDialog::saveFileContent: buffer ptr was null, so did nothing");
        }
    }
}
