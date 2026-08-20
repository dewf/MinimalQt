#include "generated/Url.h"
#include "UrlInternal.h"

#include "util/convert.h"

#include <QList>

#define THIS (AS_QURL_PTR(_this))

namespace Url
{
    std::string Handle_toAbsoluteInternal(HandleRef _this) {
        return THIS->toString().toStdString();
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef createFromAbsolute(const std::string& absoluteUrl) {
        return URL_HEAP_NEW(QString::fromStdString(absoluteUrl));
    }

    // list ====================================================
#define LIST_THIS (reinterpret_cast<QList<QUrl>*>(_this))

    int32_t List_count(ListRef _this) {
        return LIST_THIS->count();
    }

    OwnedRef List_itemAt(ListRef _this, int32_t index) {
        return URL_HEAP_NEW(LIST_THIS->at(index));
    }

    std::vector<OwnedRef> List_items(ListRef _this) {
        return fromQList<QUrl,OwnedRef>(*LIST_THIS, [](const auto& url) {
            return URL_HEAP_NEW(url);
        });
    }

    std::vector<std::string> List_itemsAbsolute(ListRef _this) {
        return fromQList<QUrl,std::string>(*LIST_THIS, [](const auto& url) { return url.toString().toStdString(); });
    }

    void OwnedList_dispose(OwnedListRef _this) {
        delete LIST_THIS;
    }

    OwnedListRef createFromAbsoluteList(const std::vector<std::string>& absoluteUrls) {
        const auto qUrls = toQList<std::string,QUrl>(absoluteUrls, [](const auto& url) { return QUrl(QString::fromStdString(url)); });
        return URL_LIST_HEAP_NEW(qUrls);
    }
}
