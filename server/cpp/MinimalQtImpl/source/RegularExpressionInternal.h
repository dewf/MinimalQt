#pragma once

#include "generated/RegularExpression.h"
#include <QRegularExpression>

#define AS_QREGEX_MATCH_PTR(x) (reinterpret_cast<QRegularExpressionMatch*>(x))
#define QREGEX_MATCH_VALUE(x) (x != nullptr ? *AS_QREGEX_MATCH_PTR(x) : QRegularExpressionMatch())
#define REGEX_MATCH_HEAP_NEW(...) (reinterpret_cast<RegularExpression::Match::OwnedRef>(new QRegularExpressionMatch(__VA_ARGS__)))

#define AS_QREGEX_MATCHITERATOR_PTR(x) (reinterpret_cast<QRegularExpressionMatchIterator*>(x))
#define QREGEX_MATCHITERATOR_VALUE(x) (x != nullptr ? *AS_QREGEX_MATCHITERATOR_PTR(x) : QRegularExpressionMatchIterator())
#define REGEX_MATCHITERATOR_HEAP_NEW(...) (reinterpret_cast<RegularExpression::MatchIterator::OwnedRef>(new QRegularExpressionMatchIterator(__VA_ARGS__)))

#define AS_QREGEX_PTR(x) (reinterpret_cast<QRegularExpression*>(x))
#define QREGEX_VALUE(x) (x != nullptr ? *AS_QREGEX_PTR(x) : QRegularExpression())
#define REGEX_HEAP_NEW(...) (reinterpret_cast<RegularExpression::OwnedRef>(new QRegularExpression(__VA_ARGS__)))

namespace RegularExpression {
}
