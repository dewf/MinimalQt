#pragma once

#include "generated/Url.h"

#include <QUrl>

#define AS_QURL_PTR(x) (reinterpret_cast<QUrl*>(x))
#define QURL_VALUE(x) (*AS_QURL_PTR(x))
#define URL_HEAP_NEW(...) (reinterpret_cast<Url::OwnedRef>(new QUrl(__VA_ARGS__)))

namespace Url {
    struct __List {
        QList<QUrl> qList;
    };
}
