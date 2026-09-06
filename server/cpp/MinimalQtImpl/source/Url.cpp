#include "generated/Url.h"
#include "UrlInternal.h"

#include "util/convert.h"

#include <QList>

#define THIS (AS_QURL_PTR(_this))

namespace Url
{
    int32_t Handle_hashCode(HandleRef _this) {
        return static_cast<int32_t>(qHash(*THIS));
    }

    OwnedRef Handle_adjusted(HandleRef _this, Flags<FormattingOptions> options_) {
        auto qflags = toQFormattingOptions(options_);
        return URL_HEAP_NEW(THIS->adjusted(qflags));
    }

    std::string Handle_authority(HandleRef _this, Flags<ComponentFormattingOptions> options_ /* ComponentFormattingOptions::PrettyDecoded */) {
        auto qflags = QUrl::ComponentFormattingOptions::fromInt(options_.value());
        return THIS->authority(qflags).toStdString();
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    std::string Handle_errorString(HandleRef _this) {
        return THIS->errorString().toStdString();
    }

    std::string Handle_fileName(HandleRef _this, Flags<ComponentFormattingOptions> options_ /* ComponentFormattingOptions::FullyDecoded */) {
        auto qflags = QUrl::ComponentFormattingOptions::fromInt(options_.value());
        return THIS->fileName(qflags).toStdString();
    }

    std::string Handle_fragment(HandleRef _this, Flags<ComponentFormattingOptions> options_ /* ComponentFormattingOptions::PrettyDecoded */) {
        auto qflags = QUrl::ComponentFormattingOptions::fromInt(options_.value());
        return THIS->fragment(qflags).toStdString();
    }

    bool Handle_hasFragment(HandleRef _this) {
        return THIS->hasFragment();
    }

    bool Handle_hasQuery(HandleRef _this) {
        return THIS->hasQuery();
    }

    std::string Handle_host(HandleRef _this, Flags<ComponentFormattingOptions> options_ /* ComponentFormattingOptions::FullyDecoded */) {
        auto qflags = QUrl::ComponentFormattingOptions::fromInt(options_.value());
        return THIS->host(qflags).toStdString();
    }

    bool Handle_isEmpty(HandleRef _this) {
        return THIS->isEmpty();
    }

    bool Handle_isLocalFile(HandleRef _this) {
        return THIS->isLocalFile();
    }

    bool Handle_isParentOf(HandleRef _this, HandleRef childUrl) {
        return THIS->isParentOf(QURL_VALUE(childUrl));
    }

    bool Handle_isRelative(HandleRef _this) {
        return THIS->isRelative();
    }

    bool Handle_isValid(HandleRef _this) {
        return THIS->isValid();
    }

    bool Handle_matches(HandleRef _this, HandleRef url, Flags<FormattingOptions> options_) {
        auto qflags = toQFormattingOptions(options_);
        return THIS->matches(QURL_VALUE(url), qflags);
    }

    std::string Handle_password(HandleRef _this, Flags<ComponentFormattingOptions> options_ /* ComponentFormattingOptions::FullyDecoded */) {
        auto qflags = QUrl::ComponentFormattingOptions::fromInt(options_.value());
        return THIS->password(qflags).toStdString();
    }

    std::string Handle_path(HandleRef _this, Flags<ComponentFormattingOptions> options_ /* ComponentFormattingOptions::FullyDecoded */) {
        auto qflags = QUrl::ComponentFormattingOptions::fromInt(options_.value());
        return THIS->path(qflags).toStdString();
    }

    int32_t Handle_port(HandleRef _this, int32_t defaultPort /* -1 */) {
        return THIS->port(defaultPort);
    }

    std::string Handle_query(HandleRef _this, Flags<ComponentFormattingOptions> options_ /* ComponentFormattingOptions::PrettyDecoded */) {
        auto qflags = QUrl::ComponentFormattingOptions::fromInt(options_.value());
        return THIS->query(qflags).toStdString();
    }

    OwnedRef Handle_resolved(HandleRef _this, HandleRef relative) {
        return URL_HEAP_NEW(THIS->resolved(QURL_VALUE(relative)));
    }

    std::string Handle_scheme(HandleRef _this) {
        return THIS->scheme().toStdString();
    }

    void Handle_setAuthority(HandleRef _this, const std::string& authority, ParsingMode mode /* ParsingMode::TolerantMode */) {
        THIS->setAuthority(QString::fromStdString(authority), static_cast<QUrl::ParsingMode>(mode));
    }

    void Handle_setFragment(HandleRef _this, const std::string& fragment, ParsingMode mode /* ParsingMode::TolerantMode */) {
        THIS->setFragment(QString::fromStdString(fragment), static_cast<QUrl::ParsingMode>(mode));
    }

    void Handle_setHost(HandleRef _this, const std::string& host, ParsingMode mode /* ParsingMode::DecodedMode */) {
        THIS->setHost(QString::fromStdString(host), static_cast<QUrl::ParsingMode>(mode));
    }

    void Handle_setPassword(HandleRef _this, const std::string& password, ParsingMode mode /* ParsingMode::DecodedMode */) {
        THIS->setPassword(QString::fromStdString(password), static_cast<QUrl::ParsingMode>(mode));
    }

    void Handle_setPath(HandleRef _this, const std::string& path, ParsingMode mode /* ParsingMode::DecodedMode */) {
        THIS->setPath(QString::fromStdString(path), static_cast<QUrl::ParsingMode>(mode));
    }

    void Handle_setPort(HandleRef _this, int32_t port) {
        THIS->setPort(port);
    }

    void Handle_setQuery(HandleRef _this, const std::string& query, ParsingMode mode /* ParsingMode::TolerantMode */) {
        THIS->setQuery(QString::fromStdString(query), static_cast<QUrl::ParsingMode>(mode));
    }

    void Handle_setScheme(HandleRef _this, const std::string& scheme) {
        THIS->setScheme(QString::fromStdString(scheme));
    }

    void Handle_setUrl(HandleRef _this, const std::string& url, ParsingMode parsingMode /* ParsingMode::TolerantMode */) {
        THIS->setUrl(QString::fromStdString(url), static_cast<QUrl::ParsingMode>(parsingMode));
    }

    void Handle_setUserInfo(HandleRef _this, const std::string& userInfo, ParsingMode mode /* ParsingMode::TolerantMode */) {
        THIS->setUserInfo(QString::fromStdString(userInfo), static_cast<QUrl::ParsingMode>(mode));
    }

    void Handle_setUserName(HandleRef _this, const std::string& userName, ParsingMode mode /* ParsingMode::DecodedMode */) {
        THIS->setUserName(QString::fromStdString(userName), static_cast<QUrl::ParsingMode>(mode));
    }

    void Handle_swap(HandleRef _this, HandleRef other) {
        if (other != nullptr)
        {
            THIS->swap(*AS_QURL_PTR(other));
        } else
        {
            // nothing to swap
            *THIS = QUrl();
        }
    }

    std::string Handle_toDisplayString(HandleRef _this, Flags<FormattingOptions> options_ /* FormattingOptions::PrettyDecoded */) {
        auto qflags = toQFormattingOptions(options_);
        return THIS->toDisplayString(qflags).toStdString();
    }

    std::vector<uint8_t> Handle_toEncoded(HandleRef _this, Flags<FormattingOptions> options_ /* FormattingOptions::FullyEncoded */) {
        auto qflags = toQFormattingOptions(options_);
        return fromQByteArray(THIS->toEncoded(qflags));
    }

    std::string Handle_toLocalFile(HandleRef _this) {
        return THIS->toLocalFile().toStdString();
    }

    std::string Handle_toString2(HandleRef _this, Flags<FormattingOptions> options_ /* FormattingOptions::PrettyDecoded */) {
        auto qflags = toQFormattingOptions(options_);
        return THIS->toString(qflags).toStdString();
    }

    std::string Handle_url(HandleRef _this, Flags<FormattingOptions> options_ /* FormattingOptions::PrettyDecoded */) {
        auto qflags = toQFormattingOptions(options_);
        return THIS->url(qflags).toStdString();
    }

    std::string Handle_userInfo(HandleRef _this, Flags<ComponentFormattingOptions> options_ /* ComponentFormattingOptions::PrettyDecoded */) {
        auto qflags = QUrl::ComponentFormattingOptions::fromInt(options_.value());
        return THIS->userInfo(qflags).toStdString();
    }

    std::string Handle_userName(HandleRef _this, Flags<ComponentFormattingOptions> options_ /* ComponentFormattingOptions::FullyDecoded */) {
        auto qflags = QUrl::ComponentFormattingOptions::fromInt(options_.value());
        return THIS->userName(qflags).toStdString();
    }

    std::string Handle_util_toAbsoluteInternal(HandleRef _this) {
        return THIS->toString().toStdString();
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return URL_HEAP_NEW();
    }

    OwnedRef create(const std::string& url, ParsingMode parsingMode /* ParsingMode::TolerantMode */) {
        return URL_HEAP_NEW(QString::fromStdString(url), static_cast<QUrl::ParsingMode>(parsingMode));
    }

    OwnedRef create(HandleRef other) {
        return URL_HEAP_NEW(QURL_VALUE(other));
    }

    OwnedRef util_createFromAbsolute(const std::string& absoluteUrl) {
        return URL_HEAP_NEW(QString::fromStdString(absoluteUrl));
    }

    std::string fromAce(const std::vector<uint8_t>& domain, Flags<AceProcessingOptions> options_ /* 0 */) {
        return QUrl::fromAce(toQByteArray(domain), QUrl::AceProcessingOptions::fromInt(options_.value())).toStdString();
    }

    OwnedRef fromLocalFile(const std::string& localFile) {
        return URL_HEAP_NEW(QUrl::fromLocalFile(QString::fromStdString(localFile)));
    }

    OwnedRef fromPercentEncoding(const std::vector<uint8_t>& input) {
        return URL_HEAP_NEW(QUrl::fromPercentEncoding(toQByteArray(input)));
    }

    OwnedListRef fromStringList(const std::vector<std::string>& urls, ParsingMode mode /* ParsingMode::TolerantMode */) {
        auto qUrlsList = toQStringList(urls);
        return URL_LIST_HEAP_NEW(QUrl::fromStringList(qUrlsList, static_cast<QUrl::ParsingMode>(mode)));
    }

    OwnedRef fromUserInput(const std::string& userInput, const std::optional<std::string>& workingDirectory /* {} */, Flags<UserInputResolutionOptions> options_ /* UserInputResolutionOptions::DefaultResolution */) {
        auto qWorkingDir = workingDirectory
                .transform(QString::fromStdString)
                .value_or(QString());
        return URL_HEAP_NEW(QUrl::fromUserInput(QString::fromStdString(userInput), qWorkingDir, QUrl::UserInputResolutionOptions::fromInt(options_.value())));
    }

    std::vector<std::string> idnWhitelist() {
        return fromQStringList(QUrl::idnWhitelist());
    }

    void setIdnWhitelist(const std::vector<std::string>& list) {
        QUrl::setIdnWhitelist(toQStringList(list));
    }

    std::vector<uint8_t> toAce(const std::string& domain, Flags<AceProcessingOptions> options_ /* 0 */) {
        return fromQByteArray(QUrl::toAce(QString::fromStdString(domain), QUrl::AceProcessingOptions::fromInt(options_.value())));
    }

    std::vector<uint8_t> toPercentEncoding(const std::string& input, const std::optional<std::vector<uint8_t>>& exclude /* {} */, const std::optional<std::vector<uint8_t>>& include /* {} */) {
        return fromQByteArray(
            QUrl::toPercentEncoding(
                QString::fromStdString(input),
                exclude.transform(toQByteArray).value_or(QByteArray()),
                include.transform(toQByteArray).value_or(QByteArray())));
    }

    std::vector<std::string> toStringList(ListRef urls, Flags<FormattingOptions> options_ /* FormattingOptions::PrettyDecoded */) {
        return fromQStringList(
            QUrl::toStringList(
                QURL_LIST_VALUE(urls),
                toQFormattingOptions(options_)));
    }

    // list ====================================================
#define LIST_THIS (AS_QURL_LIST_PTR(_this))

    int32_t List_count(ListRef _this) {
        return LIST_THIS->count();
    }

    OwnedRef List_itemAt(ListRef _this, int32_t index) {
        return URL_HEAP_NEW(LIST_THIS->at(index));
    }

    std::vector<OwnedRef> List_items(ListRef _this) {
        return fromQList<QUrl,OwnedRef>(*LIST_THIS, [](const auto& url)
        {
            return URL_HEAP_NEW(url);
        });
    }

    std::vector<std::string> List_util_itemsAbsolute(ListRef _this) {
        return fromQList<QUrl,std::string>(*LIST_THIS, [](const auto& url)
        {
            return url.toString().toStdString();
        });
    }

    void OwnedList_dispose(OwnedListRef _this) {
        delete LIST_THIS;
    }

    OwnedListRef util_createFromArray(const std::vector<HandleRef>& urls) {
        auto raw =
            toQList<HandleRef,QUrl>(urls, [](HandleRef url)
            {
                return QURL_VALUE(url);
            });
        return URL_LIST_HEAP_NEW(raw);
    }

    OwnedListRef util_createFromAbsoluteList(const std::vector<std::string>& absoluteUrls) {
        const auto qUrls = toQList<std::string,QUrl>(absoluteUrls, [](const auto& url)
        {
            return QUrl(QString::fromStdString(url));
        });
        return URL_LIST_HEAP_NEW(qUrls);
    }
}
