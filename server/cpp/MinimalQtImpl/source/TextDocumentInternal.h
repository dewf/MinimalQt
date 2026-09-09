#pragma once

#include "generated/TextDocument.h"
#include <QTextDocument>

#define AS_QTEXTDOCUMENT_PTR(x) (reinterpret_cast<QTextDocument*>(x))

namespace TextDocument {
}
