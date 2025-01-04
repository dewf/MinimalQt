#include "generated/FileDialog.h"
#include "FileDialogInternal.h"

#include "UrlInternal.h"
#include "DirInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define FILEDLG_THIS (WRAPPER->getActual())

namespace FileDialog
{
    AcceptMode Handle_getAcceptMode(HandleRef _this) {
        return static_cast<AcceptMode>(FILEDLG_THIS->acceptMode());
    }

    void Handle_setAcceptMode(HandleRef _this, AcceptMode mode) {
        FILEDLG_THIS->setAcceptMode(static_cast<QFileDialog::AcceptMode>(mode));
    }

    std::string Handle_defaultSuffix(HandleRef _this) {
        return FILEDLG_THIS->defaultSuffix().toStdString();
    }

    void Handle_setDefaultSuffix(HandleRef _this, const std::string& suffix) {
        FILEDLG_THIS->setDefaultSuffix(QString::fromStdString(suffix));
    }

    FileMode Handle_getFileMode(HandleRef _this) {
        return static_cast<FileMode>(FILEDLG_THIS->fileMode());
    }

    void Handle_setFileMode(HandleRef _this, FileMode mode) {
        FILEDLG_THIS->setFileMode(static_cast<QFileDialog::FileMode>(mode));
    }

    Options Handle_getOptions(HandleRef _this) {
        return FILEDLG_THIS->options();
    }

    void Handle_setOptions(HandleRef _this, Options opts) {
        FILEDLG_THIS->setOptions(static_cast<QFileDialog::Options>(opts));
    }

    std::vector<std::string> Handle_supportedSchemes(HandleRef _this) {
        return toVectorStrings(FILEDLG_THIS->supportedSchemes());
    }

    void Handle_setSupportedSchemes(HandleRef _this, const std::vector<std::string>& schemes) {
        FILEDLG_THIS->setSupportedSchemes(toQStringList(schemes));
    }

    ViewMode Handle_getViewMode(HandleRef _this) {
        return static_cast<ViewMode>(FILEDLG_THIS->viewMode());
    }

    void Handle_setViewMode(HandleRef _this, ViewMode mode) {
        FILEDLG_THIS->setViewMode(static_cast<QFileDialog::ViewMode>(mode));
    }

    Dir::OwnedRef Handle_directory(HandleRef _this) {
        return DIR_HEAP_NEW(FILEDLG_THIS->directory());
    }

    Url::OwnedRef Handle_directoryUrl(HandleRef _this) {
        return URL_HEAP_NEW(FILEDLG_THIS->directoryUrl());
    }

    std::vector<std::string> Handle_mimeTypeFilters(HandleRef _this) {
        return toVectorStrings(FILEDLG_THIS->mimeTypeFilters());
    }

    std::vector<std::string> Handle_nameFilters(HandleRef _this) {
        return toVectorStrings(FILEDLG_THIS->nameFilters());
    }

    void Handle_setDirectory(HandleRef _this, const std::string& dir) {
        FILEDLG_THIS->setDirectory(QString::fromStdString(dir));
    }

    void Handle_setDirectory(HandleRef _this, Dir::HandleRef dir) {
        FILEDLG_THIS->setDirectory(QDIR_VALUE(dir));
    }

    void Handle_setDirectoryUrl(HandleRef _this, Url::HandleRef url) {
        FILEDLG_THIS->setDirectoryUrl(QURL_VALUE(url));
    }

    void Handle_setMimeTypeFilters(HandleRef _this, const std::vector<std::string>& filters) {
        FILEDLG_THIS->setMimeTypeFilters(toQStringList(filters));
    }

    void Handle_setNameFilter(HandleRef _this, const std::string& filter) {
        FILEDLG_THIS->setNameFilter(QString::fromStdString(filter));
    }

    void Handle_setNameFilters(HandleRef _this, const std::vector<std::string>& filters) {
        FILEDLG_THIS->setNameFilters(toQStringList(filters));
    }

    void Handle_selectFile(HandleRef _this, const std::string& file) {
        FILEDLG_THIS->selectFile(QString::fromStdString(file));
    }

    std::vector<std::string> Handle_selectedFiles(HandleRef _this) {
        return toVectorStrings(FILEDLG_THIS->selectedFiles());
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(Widget::HandleRef parent, WindowFlags flags_, const std::shared_ptr<SignalHandler>& handler) {
        const auto parentWrapper = reinterpret_cast<Widget::SignalWrapper*>(parent);
        QWidget* parentWidget = parentWrapper != nullptr ? parentWrapper->getActual() : nullptr;
        const auto dlg = new QFileDialog(parentWidget, static_cast<Qt::WindowFlags>(flags_));
        const auto wrapper = new SignalWrapper(dlg, handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler, const CreateOpts& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto handle) {
            const auto parentWrapper = reinterpret_cast<Widget::SignalWrapper*>(handle);
            return parentWrapper->getActual();
        }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto directory = opts.mapOrDefaultDirectory(QString::fromStdString, QString());
        const auto filter = opts.mapOrDefaultFilter(QString::fromStdString, QString());
        // !
        const auto dlg = new QFileDialog(parent, caption, directory, filter);
        const auto wrapper = new SignalWrapper(dlg, handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    std::string getExistingDirectory(const GetExistingDirectoryOpts& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto handle) {
            const auto parentWrapper = reinterpret_cast<Widget::SignalWrapper*>(handle);
            return parentWrapper->getActual();
        }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir(QString::fromStdString, QString());
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x); }, static_cast<QFileDialog::Options>(QFileDialog::ShowDirsOnly));
        //
        const auto result = QFileDialog::getExistingDirectory(parent, caption, dir, options);
        return result.toStdString();
    }

    Url::OwnedRef getExistingDirectoryUrl(const GetExistingDirectoryUrlOpts& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto handle) {
            const auto parentWrapper = reinterpret_cast<Widget::SignalWrapper*>(handle);
            return parentWrapper->getActual();
        }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir([](auto urlHandle) { return QURL_VALUE(urlHandle); }, QUrl());
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x); }, static_cast<QFileDialog::Options>(QFileDialog::ShowDirsOnly));
        const auto supportedSchemes = opts.mapOrDefaultSupportedSchemes(toQStringList, QStringList());
        //
        const auto result = QFileDialog::getExistingDirectoryUrl(parent, caption, dir, options, supportedSchemes);
        return URL_HEAP_NEW(result);
    }

    void getOpenFileContent(const std::string& nameFilter, const std::function<FileOpenCompletedFunc>& completedFunc, const std::optional<Widget::HandleRef>& parent) {
        QWidget *qParent = nullptr;
        if (parent.has_value()) {
            const auto parentWrapper = reinterpret_cast<Widget::SignalWrapper*>(parent.value());
            qParent = parentWrapper->getActual();
        }
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
        const auto parent = opts.mapOrDefaultParent([](auto handle) {
            const auto parentWrapper = reinterpret_cast<Widget::SignalWrapper*>(handle);
            return parentWrapper->getActual();
        }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir(QString::fromStdString, QString());
        const auto filter = opts.mapOrDefaultFilter(QString::fromStdString, QString());
        QString selectedFilterValue;
        QString *selectedFilter = nullptr;
        if (std::string value; opts.hasSelectedFilterInput(&value)) {
            selectedFilterValue = QString::fromStdString(value);
            selectedFilter = &selectedFilterValue;
        }
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x); }, QFileDialog::Options());
        //
        GetOpenFileNameResult result;
        result.filename = QFileDialog::getOpenFileName(parent, caption, dir, filter, selectedFilter, options).toStdString();
        if (selectedFilter != nullptr) {
            result.selectedFilterOutput = selectedFilter->toStdString();
        }
        return result;
    }

    GetOpenFileNamesResult getOpenFileNames(const GetOpenFileNamesOpts& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto handle) {
            const auto parentWrapper = reinterpret_cast<Widget::SignalWrapper*>(handle);
            return parentWrapper->getActual();
        }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir(QString::fromStdString, QString());
        const auto filter = opts.mapOrDefaultFilter(QString::fromStdString, QString());
        QString selectedFilterValue;
        QString *selectedFilter = nullptr;
        if (std::string value; opts.hasSelectedFilterInput(&value)) {
            selectedFilterValue = QString::fromStdString(value);
            selectedFilter = &selectedFilterValue;
        }
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x); }, QFileDialog::Options());
        //
        GetOpenFileNamesResult result;
        result.filenames = toVectorStrings(QFileDialog::getOpenFileNames(parent, caption, dir, filter, selectedFilter, options));
        if (selectedFilter != nullptr) {
            result.selectedFilterOutput = selectedFilter->toStdString();
        }
        return result;
    }

    GetOpenFileUrlResult getOpenFileUrl(const GetOpenFileUrlOpts& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto handle) {
            const auto parentWrapper = reinterpret_cast<Widget::SignalWrapper*>(handle);
            return parentWrapper->getActual();
        }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir([](auto x) { return QURL_VALUE(x); }, QUrl());
        const auto filter = opts.mapOrDefaultFilter(QString::fromStdString, QString());
        QString selectedFilterValue;
        QString *selectedFilter = nullptr;
        if (std::string value; opts.hasSelectedFilterInput(&value)) {
            selectedFilterValue = QString::fromStdString(value);
            selectedFilter = &selectedFilterValue;
        }
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x); }, QFileDialog::Options());
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
        const auto parent = opts.mapOrDefaultParent([](auto handle) {
            const auto parentWrapper = reinterpret_cast<Widget::SignalWrapper*>(handle);
            return parentWrapper->getActual();
        }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir([](auto x) { return QURL_VALUE(x); }, QUrl());
        const auto filter = opts.mapOrDefaultFilter(QString::fromStdString, QString());
        QString selectedFilterValue;
        QString *selectedFilter = nullptr;
        if (std::string value; opts.hasSelectedFilterInput(&value)) {
            selectedFilterValue = QString::fromStdString(value);
            selectedFilter = &selectedFilterValue;
        }
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x); }, QFileDialog::Options());
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
        const auto parent = opts.mapOrDefaultParent([](auto handle) {
            const auto parentWrapper = reinterpret_cast<Widget::SignalWrapper*>(handle);
            return parentWrapper->getActual();
        }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir(QString::fromStdString, QString());
        const auto filter = opts.mapOrDefaultFilter(QString::fromStdString, QString());
        QString selectedFilterValue;
        QString *selectedFilter = nullptr;
        if (std::string value; opts.hasSelectedFilterInput(&value)) {
            selectedFilterValue = QString::fromStdString(value);
            selectedFilter = &selectedFilterValue;
        }
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x); }, QFileDialog::Options());
        //
        GetSaveFileNameResult result;
        result.filename = QFileDialog::getSaveFileName(parent, caption, dir, filter, selectedFilter, options).toStdString();
        if (selectedFilter != nullptr) {
            result.selectedFilterOutput = selectedFilter->toStdString();
        }
        return result;
    }

    GetSaveFileUrlResult getSaveFileUrl(const GetSaveFileUrlOpts& opts) {
        const auto parent = opts.mapOrDefaultParent([](auto handle) {
            const auto parentWrapper = reinterpret_cast<Widget::SignalWrapper*>(handle);
            return parentWrapper->getActual();
        }, static_cast<QWidget*>(nullptr));
        const auto caption = opts.mapOrDefaultCaption(QString::fromStdString, QString());
        const auto dir = opts.mapOrDefaultDir([](auto x) { return QURL_VALUE(x); }, QUrl());
        const auto filter = opts.mapOrDefaultFilter(QString::fromStdString, QString());
        QString selectedFilterValue;
        QString *selectedFilter = nullptr;
        if (std::string value; opts.hasSelectedFilterInput(&value)) {
            selectedFilterValue = QString::fromStdString(value);
            selectedFilter = &selectedFilterValue;
        }
        const auto options = opts.mapOrDefaultOptions_([](auto x) { return static_cast<QFileDialog::Options>(x); }, QFileDialog::Options());
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
        QByteArray qFileContent(reinterpret_cast<const char*>(fileContent.data()), fileContent.size());
        QString qFileNameHint = QString::fromStdString(fileNameHint);
        QWidget *qParent = nullptr;
        if (parent.has_value()) {
            const auto parentWrapper = reinterpret_cast<Widget::SignalWrapper*>(parent.value());
            qParent = parentWrapper->getActual();
        }
        QFileDialog::saveFileContent(qFileContent, qFileNameHint, qParent);
    }
}
