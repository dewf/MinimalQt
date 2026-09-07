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

@methodprefix("sig_")
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
Handle create(Widget.Handle parent = null, Option<string> caption = none, Option<string> directory = none, Option<string> filter = none);

// static methods

// getExistingDirectory ========================================================
string getExistingDirectory(Widget.Handle parent = null, Option<string> caption = none, Option<string> dir = none, Options options_ = ShowDirsOnly);

// getExistingDirectoryUrl =====================================================
Url.Owned getExistingDirectoryUrl(
    Widget.Handle parent = null,
    Option<string> caption = none,
    Url.Handle dir = null,
    Options options_ = ShowDirsOnly,
    Option<Array<string>> supportedSchemes = none);

// getOpenFileContent ==========================================================
delegate Array<byte> ContentThunk(); // consider return a Buffer<byte> instead so we're not making copies via the NI stack?
delegate void FileOpenCompletedFunc(string fileName, ContentThunk fileContentThunk);
void getOpenFileContent(string nameFilter, FileOpenCompletedFunc fileOpenCompleted, Widget.Handle parent = null);

// getOpenFileName =============================================================
struct GetOpenFileNameResult {
    string filename;
    string selectedFilterOutput;
}
GetOpenFileNameResult getOpenFileName(
    Widget.Handle parent = null,
    Option<string> caption = none,
    Option<string> dir = none,
    Option<string> filter = none,
    Option<string> selectedFilterInput = none,
    Option<Options> options_ = none);

// getOpenFileNames ============================================================
struct GetOpenFileNamesResult {
    Array<string> filenames;
    string selectedFilterOutput;
}
GetOpenFileNamesResult getOpenFileNames(
    Widget.Handle parent = null,
    Option<string> caption = none,
    Option<string> dir = none,
    Option<string> filter = none,
    Option<string> selectedFilterInput = none,
    Option<Options> options_ = none
);

// getOpenFileUrl ==============================================================
struct GetOpenFileUrlResult {
    Url.Owned url;
    string selectedFilterOutput;
}
GetOpenFileUrlResult getOpenFileUrl(
    Widget.Handle parent = null,
    Option<string> caption = none,
    Url.Handle dir = null,
    Option<string> filter = none,
    Option<string> selectedFilterInput = none,
    Option<Options> options_ = none,
    Option<Array<string>> supportedSchemes = none
);

// getOpenFileUrls ==============================================================
struct GetOpenFileUrlsResult {
    Url.OwnedList urls;
    string selectedFilterOutput;
}
GetOpenFileUrlsResult getOpenFileUrls(
    Widget.Handle parent = null,
    Option<string> caption = none,
    Url.Handle dir = null,
    Option<string> filter = none,
    Option<string> selectedFilterInput = none,
    Option<Options> options_ = none,
    Option<Array<string>> supportedSchemes = none
);

// getSaveFileName ==============================================================
struct GetSaveFileNameResult {
    string filename;
    string selectedFilterOutput;
}
GetSaveFileNameResult getSaveFileName(
    Widget.Handle parent = null,
    Option<string> caption = none,
    Option<string> dir = none,
    Option<string> filter = none,
    Option<string> selectedFilterInput = none,
    Option<Options> options_ = none
);

// getSaveFileUrl ===============================================================
struct GetSaveFileUrlResult {
    Url.Owned url;
    string selectedFilterOutput;
}
GetSaveFileUrlResult getSaveFileUrl(
    Widget.Handle parent = null,
    Option<string> caption = none,
    Url.Handle dir = null,
    Option<string> filter = none,
    Option<string> selectedFilterInput = none,
    Option<Options> options_ = none,
    Option<Array<string>> supportedSchemes = none
);

// saveFileContent ==============================================================
void saveFileContent(Buffer<byte> fileContent, string fileNameHint, Widget.Handle parent = null);
