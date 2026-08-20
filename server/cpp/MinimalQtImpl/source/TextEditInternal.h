#pragma once

#include "generated/TextEdit.h"
#include <QTextEdit>

#define AS_QTEXTEDIT_EXTRASEL_PTR(x) (reinterpret_cast<QTextEdit::ExtraSelection*>(x))
#define QTEXTEDIT_EXTRASEL_VALUE(x) (*AS_QTEXTEDIT_EXTRASEL_PTR(x))
#define TEXTEDIT_EXTRASEL_HEAP_NEW(...) (reinterpret_cast<TextEdit::ExtraSelection::OwnedRef>(new QTextEdit::ExtraSelection(__VA_ARGS__)))

namespace TextEdit {
    namespace ExtraSelection {
    }
}
