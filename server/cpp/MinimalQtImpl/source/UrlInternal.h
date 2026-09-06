#pragma once

#include "generated/Url.h"
#include <QUrl>

#define AS_QURL_PTR(x) (reinterpret_cast<QUrl*>(x))
#define QURL_VALUE(x) (x != nullptr ? *AS_QURL_PTR(x) : QUrl())
#define URL_HEAP_NEW(...) (reinterpret_cast<Url::OwnedRef>(new QUrl(__VA_ARGS__)))

#define AS_QURL_LIST_PTR(x) (reinterpret_cast<QList<QUrl>*>(x))
#define QURL_LIST_VALUE(x) (x != nullptr ? *AS_QURL_LIST_PTR(x) : QList<QUrl>())
#define URL_LIST_HEAP_NEW(...) (reinterpret_cast<Url::OwnedListRef>(new QList<QUrl>(__VA_ARGS__)))

namespace Url {
    inline QUrl::FormattingOptions toQFormattingOptions(const Flags<FormattingOptions>& flags)
    {
        auto intFlags = static_cast<int>(flags.value());
        return static_cast<QUrl::FormattingOptions>(intFlags);
    }
}
