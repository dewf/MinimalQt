#include "generated/MessageBox.h"
#include "MessageBoxInternal.h"

#include "ObjectInternal.h"
#include "AbstractButtonInternal.h"
#include "CheckBoxInternal.h"
#include "WidgetInternal.h"
#include "PushButtonInternal.h"
#include "PixmapInternal.h"
#include "util/convert.h"

using namespace ::Object;
using namespace ::Icon;
using namespace ::Enums;
using namespace ::Dialog;
using namespace ::AbstractButton;
using namespace ::PushButton;
using namespace ::CheckBox;
using namespace ::Widget;
using namespace ::Pixmap;

#define THIS (reinterpret_cast<QMessageBox*>(_this))

namespace MessageBox
{
    void Handle_addButton(HandleRef _this, AbstractButton::HandleRef button, ButtonRole role) {
        THIS->addButton(AS_QABSTRACTBUTTON_PTR(button), static_cast<QMessageBox::ButtonRole>(role));
    }

    PushButton::HandleRef Handle_addButton(HandleRef _this, StandardButton button) {
        return reinterpret_cast<PushButton::HandleRef>(THIS->addButton(static_cast<QMessageBox::StandardButton>(button)));
    }

    PushButton::HandleRef Handle_addButton(HandleRef _this, const std::string& text, ButtonRole role) {
        return reinterpret_cast<PushButton::HandleRef>(THIS->addButton(QString::fromStdString(text), static_cast<QMessageBox::ButtonRole>(role)));
    }

    AbstractButton::HandleRef Handle_button(HandleRef _this, StandardButton which) {
        return reinterpret_cast<AbstractButton::HandleRef>(THIS->button(static_cast<QMessageBox::StandardButton>(which)));
    }

    ButtonRole Handle_getButtonRole(HandleRef _this, AbstractButton::HandleRef button) {
        return static_cast<ButtonRole>(THIS->buttonRole(AS_QABSTRACTBUTTON_PTR(button)));
    }

    std::vector<AbstractButton::HandleRef> Handle_buttons(HandleRef _this) {
        return fromQList<QAbstractButton*,AbstractButton::HandleRef>(THIS->buttons(), [](auto button) {
            return reinterpret_cast<AbstractButton::HandleRef>(button);
        });
    }

    CheckBox::HandleRef Handle_checkBox(HandleRef _this) {
        return reinterpret_cast<CheckBox::HandleRef>(THIS->checkBox());
    }

    AbstractButton::HandleRef Handle_clickedButton(HandleRef _this) {
        return reinterpret_cast<AbstractButton::HandleRef>(THIS->clickedButton());
    }

    PushButton::HandleRef Handle_defaultButton(HandleRef _this) {
        return reinterpret_cast<PushButton::HandleRef>(THIS->defaultButton());
    }

    std::string Handle_detailedText(HandleRef _this) {
        return THIS->detailedText().toStdString();
    }

    AbstractButton::HandleRef Handle_escapeButton(HandleRef _this) {
        return reinterpret_cast<AbstractButton::HandleRef>(THIS->escapeButton());
    }

    Icon Handle_getIcon(HandleRef _this) {
        return static_cast<Icon>(THIS->icon());
    }

    Pixmap::OwnedRef Handle_iconPixmap(HandleRef _this) {
        return PIXMAP_HEAP_NEW(THIS->iconPixmap());
    }

    std::string Handle_informativeText(HandleRef _this) {
        return THIS->informativeText().toStdString();
    }

    Flags<OptionEnumSet> Handle_getOptions(HandleRef _this) {
        return static_cast<Flags<OptionEnumSet>>(THIS->options());
    }

    void Handle_removeButton(HandleRef _this, AbstractButton::HandleRef button) {
        THIS->removeButton(AS_QABSTRACTBUTTON_PTR(button));
    }

    void Handle_setCheckBox(HandleRef _this, CheckBox::HandleRef cb) {
        THIS->setCheckBox(reinterpret_cast<QCheckBox*>(cb));
    }

    void Handle_setDefaultButton(HandleRef _this, StandardButton button) {
        THIS->setDefaultButton(static_cast<QMessageBox::StandardButton>(button));
    }

    void Handle_setDefaultButton(HandleRef _this, PushButton::HandleRef button) {
        THIS->setDefaultButton(reinterpret_cast<QPushButton*>(button));
    }

    void Handle_setDetailedText(HandleRef _this, const std::string& text) {
        THIS->setDetailedText(QString::fromStdString(text));
    }

    void Handle_setEscapeButton(HandleRef _this, AbstractButton::HandleRef button) {
        THIS->setEscapeButton(AS_QABSTRACTBUTTON_PTR(button));
    }

    void Handle_setEscapeButton(HandleRef _this, StandardButton button) {
        THIS->setEscapeButton(static_cast<QMessageBox::StandardButton>(button));
    }

    void Handle_setIcon(HandleRef _this, Icon icon) {
        THIS->setIcon(static_cast<QMessageBox::Icon>(icon));
    }

    void Handle_setIconPixmap(HandleRef _this, Pixmap::HandleRef pixmap) {
        THIS->setIconPixmap(QPIXMAP_VALUE(pixmap));
    }

    void Handle_setInformativeText(HandleRef _this, const std::string& text) {
        THIS->setInformativeText(QString::fromStdString(text));
    }

    void Handle_setOption(HandleRef _this, OptionEnum option, bool on /* true */) {
        THIS->setOption(static_cast<QMessageBox::Option>(option), on);
    }

    void Handle_setOptions(HandleRef _this, Flags<OptionEnumSet> opts) {
        THIS->setOptions(static_cast<QMessageBox::Options>(opts.value()));
    }

    void Handle_setStandardButtons(HandleRef _this, Flags<StandardButtons> buttons) {
        THIS->setStandardButtons(static_cast<QMessageBox::StandardButtons>(buttons.value()));
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    void Handle_setTextFormat(HandleRef _this, TextFormatEnum format) {
        THIS->setTextFormat(static_cast<Qt::TextFormat>(format));
    }

    void Handle_setTextInteractionFlags(HandleRef _this, Flags<TextInteractionFlags> tiFlags) {
        THIS->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(tiFlags.value()));
    }

    void Handle_setWindowModality(HandleRef _this, WindowModality windowModality) {
        THIS->setWindowModality(static_cast<Qt::WindowModality>(windowModality));
    }

    void Handle_setWindowTitle(HandleRef _this, const std::string& title) {
        THIS->setWindowTitle(QString::fromStdString(title));
    }

    StandardButton Handle_getStandardButton(HandleRef _this, AbstractButton::HandleRef button) {
        return static_cast<StandardButton>(THIS->standardButton(AS_QABSTRACTBUTTON_PTR(button)));
    }

    Flags<StandardButtons> Handle_getStandardButtons(HandleRef _this) {
        return static_cast<Flags<StandardButtons>>(THIS->standardButtons());
    }

    bool Handle_testOption(HandleRef _this, OptionEnum option) {
        return THIS->testOption(static_cast<QMessageBox::Option>(option));
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    TextFormatEnum Handle_textFormat(HandleRef _this) {
        return static_cast<TextFormatEnum>(THIS->textFormat());
    }

    Flags<TextInteractionFlags> Handle_textInteractionFlags(HandleRef _this) {
        return static_cast<Flags<TextInteractionFlags>>(THIS->textInteractionFlags());
    }

    SignalConnectionRef Handle_connect_ButtonClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QMessageBox::buttonClicked, [handler](QAbstractButton *button) {
            handler->sig_buttonClicked(reinterpret_cast<AbstractButton::HandleRef>(button));
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QMessageBox(AS_QWIDGET_PTR(parent)));
    }

    HandleRef create(Icon icon, const std::string& title, const std::string& text, Flags<StandardButtons> buttons /* StandardButtons::NoButton */, Widget::HandleRef parent /* nullptr */, Flags<WindowFlags> flags_ /* WindowFlags::Dialog | WindowFlags::MSWindowsFixedSizeDialogHint */) {
        auto intFlags = std::bit_cast<int>(flags_.value()); // Qt flags silliness
        return reinterpret_cast<HandleRef>(new QMessageBox(static_cast<QMessageBox::Icon>(icon), QString::fromStdString(title), QString::fromStdString(text),
            static_cast<QMessageBox::StandardButtons>(buttons.value()), AS_QWIDGET_PTR(parent), static_cast<Qt::WindowFlags>(intFlags)));
    }

    void about(Widget::HandleRef parent, const std::string& title, const std::string& text) {
        QMessageBox::about(AS_QWIDGET_PTR(parent), QString::fromStdString(title), QString::fromStdString(text));
    }

    void aboutQt(Widget::HandleRef parent, const std::optional<std::string>& title) {
        const auto qTitle = optionalMap<std::string,QString>(title, [](auto t) { return QString::fromStdString(t); }).value_or(QString());
        QMessageBox::aboutQt(AS_QWIDGET_PTR(parent), qTitle);
    }

    StandardButton critical(Widget::HandleRef parent, const std::string& title, const std::string& text, Flags<StandardButtons> buttons /* StandardButtons::Ok */, StandardButton defaultButton /* StandardButton::NoButton */) {
        return static_cast<StandardButton>(QMessageBox::critical(AS_QWIDGET_PTR(parent), QString::fromStdString(title), QString::fromStdString(text),
            static_cast<QMessageBox::StandardButtons>(buttons.value()), static_cast<QMessageBox::StandardButton>(defaultButton)));
    }

    StandardButton information(Widget::HandleRef parent, const std::string& title, const std::string& text, Flags<StandardButtons> buttons /* StandardButtons::Ok */, StandardButton defaultButton /* StandardButton::NoButton */) {
        return static_cast<StandardButton>(QMessageBox::information(AS_QWIDGET_PTR(parent), QString::fromStdString(title), QString::fromStdString(text),
            static_cast<QMessageBox::StandardButtons>(buttons.value()), static_cast<QMessageBox::StandardButton>(defaultButton)));
    }

    StandardButton question(Widget::HandleRef parent, const std::string& title, const std::string& text, Flags<StandardButtons> buttons /* StandardButtons::Yes | StandardButtons::No */, StandardButton defaultButton /* StandardButton::NoButton */) {
        return static_cast<StandardButton>(QMessageBox::question(AS_QWIDGET_PTR(parent), QString::fromStdString(title), QString::fromStdString(text),
            static_cast<QMessageBox::StandardButtons>(buttons.value()), static_cast<QMessageBox::StandardButton>(defaultButton)));
    }

    StandardButton warning(Widget::HandleRef parent, const std::string& title, const std::string& text, Flags<StandardButtons> buttons /* StandardButtons::Ok */, StandardButton defaultButton /* StandardButton::NoButton */) {
        return static_cast<StandardButton>(QMessageBox::warning(AS_QWIDGET_PTR(parent), QString::fromStdString(title), QString::fromStdString(text),
            static_cast<QMessageBox::StandardButtons>(buttons.value()), static_cast<QMessageBox::StandardButton>(defaultButton)));
    }
}
