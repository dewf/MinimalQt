#include "generated/Url.h"
#include "UrlInternal.h"
#include "util/convert.h"

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
    std::vector<HandleRef> List_items(ListRef _this) {
        std::vector<HandleRef> ret;
        for (auto i = 0; i< _this->qList.count(); i++) {
            const auto x = &_this->qList.at(i);
            ret.push_back((HandleRef)x);
        }
        return ret;
    }

    std::vector<std::string> List_itemsAbsolute(ListRef _this) {
        return fromQList<QUrl,std::string>(_this->qList, [](auto url) { return url.toString().toStdString(); });
    }

    void List_dispose(ListRef _this) {
        delete _this;
    }

    ListRef createFromAbsoluteList(const std::vector<std::string>& absoluteUrls) {
        const auto qUrls = toQList<std::string,QUrl>(absoluteUrls, [](auto url) { return QUrl(QString::fromStdString(url)); });
        return new __List { qUrls };
    }
}
