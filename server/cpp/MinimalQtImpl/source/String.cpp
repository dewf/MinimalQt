#include "generated/String.h"
#include "StringInternal.h"
#include "util/convert.h"

namespace String
{
    // list ====================================================
#define LIST_THIS (AS_QSTRING_LIST_PTR(_this))

    std::vector<std::string> List_getValues(ListRef _this) {
        return fromQList<QString,std::string>(*LIST_THIS, [](const auto& str) { return str.toStdString(); });
    }

    void OwnedList_dispose(OwnedListRef _this) {
        delete LIST_THIS;
    }

    OwnedListRef createFromStrings(const std::vector<std::string>& values) {
        auto qStrs = toQList<std::string,QString>(values, [](const auto& str) { return QString::fromStdString(str); });
        return STRING_LIST_HEAP_NEW(qStrs);
    }
}
