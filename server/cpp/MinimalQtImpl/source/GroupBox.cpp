#include "generated/GroupBox.h"
#include "GroupBoxInternal.h"

#include "ObjectInternal.h"
#include "WidgetInternal.h"

using namespace ::Object;
using namespace ::Icon;
using namespace ::Enums;
using namespace ::Widget;

#define THIS (reinterpret_cast<QGroupBox*>(_this))

namespace GroupBox
{
    Flags<Alignment> Handle_alignment(HandleRef _this) {
        return static_cast<Flags<Alignment>>(THIS->alignment());
    }

    bool Handle_isCheckable(HandleRef _this) {
        return THIS->isCheckable();
    }

    bool Handle_isChecked(HandleRef _this) {
        return THIS->isChecked();
    }

    bool Handle_isFlat(HandleRef _this) {
        return THIS->isFlat();
    }

    void Handle_setAlignment(HandleRef _this, int32_t alignment) {
        THIS->setAlignment(alignment);
    }

    void Handle_setCheckable(HandleRef _this, bool state) {
        THIS->setCheckable(state);
    }

    void Handle_setFlat(HandleRef _this, bool state) {
        THIS->setFlat(state);
    }

    void Handle_setTitle(HandleRef _this, const std::string& title) {
        THIS->setTitle(QString::fromStdString(title));
    }

    std::string Handle_title(HandleRef _this) {
        return THIS->title().toStdString();
    }

    void Handle_setChecked(HandleRef _this, bool state) {
        THIS->setChecked(state);
    }

    SignalConnectionRef Handle_connect_Clicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGroupBox::clicked, [handler](bool checked_) {
            handler->sig_clicked(checked_);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Toggled(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGroupBox::toggled, [handler](bool state) {
            handler->sig_toggled(state);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QGroupBox(AS_QWIDGET_PTR(parent)));
    }

    HandleRef create(const std::string& title, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QGroupBox(QString::fromStdString(title), AS_QWIDGET_PTR(parent)));
    }
}
