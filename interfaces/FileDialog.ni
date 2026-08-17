module FileDialog;

import Object;
import Icon;
import Dialog;
import Widget;
import Enums;
import Dir;
import Url;
import AbstractItemDelegate;
import AbstractProxyModel;

interface SignalHandler extends Dialog.SignalHandler {
    void currentChanged(string path);
    void currentUrlChanged(Url.Handle url);
    void directoryEntered(string directory);
    void directoryUrlEntered(Url.Handle directory);
    void fileSelected(string file);
    void filesSelected(Array<string> selected);
    void filterSelected(string filter);
    void urlSelected(Url.Handle url);
    void urlsSelected(Url.List urls);
}

enum FileMode {
    AnyFile,
    ExistingFile,
    Directory,
    ExistingFiles
}

enum ViewMode {
    Detail,
    List
}

enum AcceptMode {
    Open,
    Save
}

enum DialogLabel { LookIn, FileName, FileType, Accept, Reject }

@withflags(Options)
enum OptionEnum {
    ShowDirsOnly                = 0x00000001,
    DontResolveSymlinks         = 0x00000002,
    DontConfirmOverwrite        = 0x00000004,
    DontUseNativeDialog         = 0x00000008,
    ReadOnly                    = 0x00000010,
    HideNameFilterDetails       = 0x00000020,
    DontUseCustomDirectoryIcons = 0x00000040
}

opaque Handle extends Dialog.Handle {

    AcceptMode getAcceptMode();
    string defaultSuffix();
    Dir.Owned directory();
    Url.Owned directoryUrl();
    FileMode getFileMode();
    Dir.Filters filter();
    Array<string> history();

    // QAbstractFileIconProvider * iconProvider() const
    // TODO

    AbstractItemDelegate.Handle itemDelegate();
    string labelText(DialogLabel label);
    Array<string> mimeTypeFilters();
    Array<string> nameFilters();

    // void open(QObject *receiver, const char *member)
    // hmmm

    Options getOptions();
    AbstractProxyModel.Handle proxyModel();
    bool restoreState(Array<byte> state);
    Array<byte> saveState();
    void selectFile(string filename);
    void selectMimeTypeFilter(string filter);
    void selectNameFilter(string filter);
    void selectUrl(Url.Handle url);
    Array<string> selectedFiles();
    string selectedMimeTypeFilter();
    string selectedNameFilter();
    Url.OwnedList selectedUrls();
    void setAcceptMode(AcceptMode mode);
    void setDefaultSuffix(string suffix);
    void setDirectory(string directory);
    void setDirectory(Dir.Handle directory);
    void setDirectoryUrl(Url.Handle directory);
    void setFileMode(FileMode mode);
    void setFilter(Dir.Filters filters);
    void setHistory(Array<string> paths);

    // void setIconProvider(QAbstractFileIconProvider *provider)
    // TODO

    void setItemDelegate(AbstractItemDelegate.Handle delegate_);
    void setLabelText(DialogLabel label, string text);
    void setMimeTypeFilters(Array<string> filters);
    void setNameFilter(string filter);
    void setNameFilters(Array<string> filters);
    void setOption(OptionEnum option, bool on = true);
    void setOptions(Options options_);
    void setProxyModel(AbstractProxyModel.Handle proxyModel);
    void setSidebarUrls(Url.List urls);
    void setSupportedSchemes(Array<string> schemes);
    void setViewMode(ViewMode mode);
    Url.OwnedList sidebarUrls();
    Array<string> supportedSchemes();
    bool testOption(OptionEnum option);
    ViewMode getViewMode();

    // signals ============================
    SignalConnection connect_CurrentChanged(SignalHandler handler);
    SignalConnection connect_CurrentUrlChanged(SignalHandler handler);
    SignalConnection connect_DirectoryEntered(SignalHandler handler);
    SignalConnection connect_DirectoryUrlEntered(SignalHandler handler);
    SignalConnection connect_FileSelected(SignalHandler handler);
    SignalConnection connect_FilesSelected(SignalHandler handler);
    SignalConnection connect_FilterSelected(SignalHandler handler);
    SignalConnection connect_UrlSelected(SignalHandler handler);
    SignalConnection connect_UrlsSelected(SignalHandler handler);
}

// ctors
Handle create(Widget.Handle parent, WindowFlags flags_);
options CreateOpts {
    Widget.Handle parent;
    string caption;
    string directory;
    string filter;
}
Handle create(CreateOpts opts);

// static methods

// getExistingDirectory ========================================================
options GetExistingDirectoryOpts {
    Widget.Handle parent;
    string caption;
    string dir;
    Options options_;
}
string getExistingDirectory(GetExistingDirectoryOpts opts);

// getExistingDirectoryUrl =====================================================
options GetExistingDirectoryUrlOpts {
    Widget.Handle parent;
    string caption;
    Url.Handle dir;
    Options options_;
    Array<string> supportedSchemes;
}
Url.Owned getExistingDirectoryUrl(GetExistingDirectoryUrlOpts opts);

// getOpenFileContent ==========================================================
sumtype FileContentResult {
    NoFileSelected,
    ContentReady(string filename, Array<byte> fileContent)
}
delegate void FileOpenCompletedFunc(FileContentResult result);
void getOpenFileContent(string nameFilter, FileOpenCompletedFunc completedFunc, Option<Widget.Handle> parent);

// getOpenFileName =============================================================
options GetOpenFileNameOpts {
    Widget.Handle parent;
    string caption;
    string dir;
    string filter;
    string selectedFilterInput;
    Options options_;
}
struct GetOpenFileNameResult {
    string filename;
    string selectedFilterOutput;
}
GetOpenFileNameResult getOpenFileName(GetOpenFileNameOpts opts);

// getOpenFileNames ============================================================
options GetOpenFileNamesOpts {
    Widget.Handle parent;
    string caption;
    string dir;
    string filter;
    string selectedFilterInput;
    Options options_;
}
struct GetOpenFileNamesResult {
    Array<string> filenames;
    string selectedFilterOutput;
}
GetOpenFileNamesResult getOpenFileNames(GetOpenFileNamesOpts opts);

// getOpenFileUrl ==============================================================
options GetOpenFileUrlOpts {
    Widget.Handle parent;
    string caption;
    Url.Handle dir;
    string filter;
    string selectedFilterInput;
    Options options_;
    Array<string> supportedSchemes;
}
struct GetOpenFileUrlResult {
    Url.Owned url;
    string selectedFilterOutput;
}
GetOpenFileUrlResult getOpenFileUrl(GetOpenFileUrlOpts opts);

// getOpenFileUrls ==============================================================
options GetOpenFileUrlsOpts {
    Widget.Handle parent;
    string caption;
    Url.Handle dir;
    string filter;
    string selectedFilterInput;
    Options options_;
    Array<string> supportedSchemes;
}
struct GetOpenFileUrlsResult {
    Url.OwnedList urls;
    string selectedFilterOutput;
}
GetOpenFileUrlsResult getOpenFileUrls(GetOpenFileUrlsOpts opts);

// getSaveFileName ==============================================================
options GetSaveFileNameOpts {
    Widget.Handle parent;
    string caption;
    string dir;
    string filter;
    string selectedFilterInput;
    Options options_;
}
struct GetSaveFileNameResult {
    string filename;
    string selectedFilterOutput;
}
GetSaveFileNameResult getSaveFileName(GetSaveFileNameOpts opts);

// getSaveFileUrl ===============================================================
options GetSaveFileUrlOpts {
    Widget.Handle parent;
    string caption;
    Url.Handle dir;
    string filter;
    string selectedFilterInput;
    Options options_;
    Array<string> supportedSchemes;
}
struct GetSaveFileUrlResult {
    Url.Owned url;
    string selectedFilterOutput;
}
GetSaveFileUrlResult getSaveFileUrl(GetSaveFileUrlOpts opts);

// saveFileContent ==============================================================
void saveFileContent(Array<byte> fileContent, string fileNameHint, Option<Widget.Handle> parent);
