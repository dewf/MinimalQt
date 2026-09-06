module Url;

// import String; // for list stuff

@withflags(AceProcessingOptions)
enum AceProcessingOption : uint {
    IgnoreIDNWhitelist = 0x1,
    AceTransitionalProcessing = 0x2,
}

@withflags(ComponentFormattingOptions)
enum ComponentFormattingOption : uint {
    PrettyDecoded = 0x000000,
    EncodeSpaces = 0x100000,
    EncodeUnicode = 0x200000,
    EncodeDelimiters = 0x400000 | 0x800000,
    EncodeReserved = 0x1000000,
    DecodeReserved = 0x2000000,
    // 0x4000000 used to indicate full-decode mode

    FullyEncoded = EncodeSpaces | EncodeUnicode | EncodeDelimiters | EncodeReserved,
    FullyDecoded = FullyEncoded | DecodeReserved | 0x4000000
}

// @withflags(FormattingOptions) // see FormattingOptions below
enum UrlFormattingOption : uint {
    None = 0x0,
    RemoveScheme = 0x1,
    RemovePassword = 0x2,
    RemoveUserInfo = RemovePassword | 0x4,
    RemovePort = 0x8,
    RemoveAuthority = RemoveUserInfo | RemovePort | 0x10,
    RemovePath = 0x20,
    RemoveQuery = 0x40,
    RemoveFragment = 0x80,
    // 0x100 was a private code in Qt 4, keep unused for a while
    PreferLocalFile = 0x200,
    StripTrailingSlash = 0x400,
    RemoveFilename = 0x800,
    NormalizePathSegments = 0x1000
}

// I *think* this is right ... it's declared in qurl.h as QUrlTwoFlags<UrlFormattingOption, ComponentFormattingOption>
flags FormattingOptions : uint {
    // === from UrlFormattingOption ===
    None = 0x0,
    RemoveScheme = 0x1,
    RemovePassword = 0x2,
    RemoveUserInfo = RemovePassword | 0x4,
    RemovePort = 0x8,
    RemoveAuthority = RemoveUserInfo | RemovePort | 0x10,
    RemovePath = 0x20,
    RemoveQuery = 0x40,
    RemoveFragment = 0x80,
    // 0x100 was a private code in Qt 4, keep unused for a while
    PreferLocalFile = 0x200,
    StripTrailingSlash = 0x400,
    RemoveFilename = 0x800,
    NormalizePathSegments = 0x1000,

    // === from ComponentFormattingOption ===
    PrettyDecoded = 0x000000,
    EncodeSpaces = 0x100000,
    EncodeUnicode = 0x200000,
    EncodeDelimiters = 0x400000 | 0x800000,
    EncodeReserved = 0x1000000,
    DecodeReserved = 0x2000000,
    // 0x4000000 used to indicate full-decode mode

    FullyEncoded = EncodeSpaces | EncodeUnicode | EncodeDelimiters | EncodeReserved,
    FullyDecoded = FullyEncoded | DecodeReserved | 0x4000000
}

enum ParsingMode {
    TolerantMode,
    StrictMode,
    DecodedMode
}

@withflags(UserInputResolutionOptions)
enum UserInputResolutionOption {
    DefaultResolution,
    AssumeLocalFile
}

@nodispose
opaque Handle {
    int hashCode();

    Owned adjusted(FormattingOptions options_);
    string authority(ComponentFormattingOptions options_ = PrettyDecoded);
    void clear();
    string errorString();
    string fileName(ComponentFormattingOptions options_ = FullyDecoded);
    string fragment(ComponentFormattingOptions options_ = PrettyDecoded);
    bool hasFragment();
    bool hasQuery();
    string host(ComponentFormattingOptions options_ = FullyDecoded);
    bool isEmpty();
    bool isLocalFile();
    bool isParentOf(Handle childUrl);
    bool isRelative();
    bool isValid();
    bool matches(Handle url, FormattingOptions options_);
    string password(ComponentFormattingOptions options_ = FullyDecoded);
    string path(ComponentFormattingOptions options_ = FullyDecoded);
    int port(int defaultPort = -1);
    string query(ComponentFormattingOptions options_ = PrettyDecoded);
    Owned resolved(Handle relative);
    string scheme();
    void setAuthority(string authority, ParsingMode mode = TolerantMode);
    void setFragment(string fragment, ParsingMode mode = TolerantMode);
    void setHost(string host, ParsingMode mode = DecodedMode);
    void setPassword(string password, ParsingMode mode = DecodedMode);
    void setPath(string path, ParsingMode mode = DecodedMode);
    void setPort(int port);
    void setQuery(string query, ParsingMode mode = TolerantMode);

    // void	setQuery(const QUrlQuery &query)

    void setScheme(string scheme);
    void setUrl(string url, ParsingMode parsingMode = TolerantMode);
    void setUserInfo(string userInfo, ParsingMode mode = TolerantMode);
    void setUserName(string userName, ParsingMode mode = DecodedMode);
    void swap(Handle other);

    // CFURLRef	toCFURL() const

    string toDisplayString(FormattingOptions options_ = PrettyDecoded);
    Array<byte> toEncoded(FormattingOptions options_ = FullyEncoded);
    string toLocalFile();

    // NSURL *	toNSURL() const

    string toString2(FormattingOptions options_ = PrettyDecoded);
    string url(FormattingOptions options_ = PrettyDecoded);
    string userInfo(ComponentFormattingOptions options_ = PrettyDecoded);
    string userName(ComponentFormattingOptions options_ = FullyDecoded);

    // operator stuff =====================
    // QUrl &	operator=(QUrl &&other)
    // QUrl &	operator=(const QString &url)
    // QUrl &	operator=(const QUrl &url)

    // deprecated:
    string util_toAbsoluteInternal();
}
opaque Owned extends Handle;

Owned create();
Owned create(string url, ParsingMode parsingMode = TolerantMode);
Owned create(Handle other);

// utility func, might delete
Owned util_createFromAbsolute(string absoluteUrl);

// static methods =====================

string fromAce(Array<byte> domain, AceProcessingOptions options_ = 0);

// QUrl	fromCFURL(CFURLRef url)
// QUrl	fromEncoded(QByteArrayView input, QUrl::ParsingMode mode = TolerantMode)

Owned fromLocalFile(string localFile);

// QUrl	fromNSURL(const NSURL *url)

Owned fromPercentEncoding(Array<byte> input);
OwnedList fromStringList(Array<string> urls, ParsingMode mode = TolerantMode);
Owned fromUserInput(string userInput, Option<string> workingDirectory = none, UserInputResolutionOptions options_ = DefaultResolution);
Array<string> idnWhitelist();
void setIdnWhitelist(Array<string> list);
Array<byte> toAce(string domain, AceProcessingOptions options_ = 0);
Array<byte> toPercentEncoding(string input, Option<Array<byte>> exclude = none, Option<Array<byte>> include = none);
Array<string> toStringList(List urls, FormattingOptions options_ = PrettyDecoded);

// operators ==========================

// bool	operator!=(const QUrl &lhs, const QUrl &rhs)
// QDataStream &	operator<<(QDataStream &out, const QUrl &url)
// bool	operator==(const QUrl &lhs, const QUrl &rhs)
// QDataStream &	operator>>(QDataStream &in, QUrl &url)

// list ===============================

@nodispose
opaque List {
    int count();
    Owned itemAt(int index);
    Array<Owned> items();

    // deprecated:
    Array<string> util_itemsAbsolute();
}
opaque OwnedList extends List;

OwnedList util_createFromArray(Array<Handle> urls);

// deprecated:
OwnedList util_createFromAbsoluteList(Array<string> absoluteUrls);
