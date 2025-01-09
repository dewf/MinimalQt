#include "generated/MessageBox.h"
#include "MessageBoxInternal.h"

#include "ObjectInternal.h"
#include "AbstractButtonInternal.h"
#include "WidgetInternal.h"
#include "PushButtonInternal.h"
#include "PixmapInternal.h"
#include "util/convert.h"

#define THIS (reinterpret_cast<QMessageBox*>(_this))

namespace MessageBox
{
    void Handle_addButton(HandleRef _this, AbstractButton::HandleRef button, ButtonRole role) {
        THIS->addButton(AS_QABSTRACTBUTTON_PTR(button), static_cast<QMessageBox::ButtonRole>(role));
    }

    std::string Handle_detailedText(HandleRef _this) {
        return THIS->detailedText().toStdString();
    }

    void Handle_setDetailedText(HandleRef _this, const std::string& text) {
        THIS->setDetailedText(QString::fromStdString(text));
    }

    Icon Handle_getIcon(HandleRef _this) {
        return static_cast<Icon>(THIS->icon());
    }

    void Handle_setIcon(HandleRef _this, Icon icon) {
        THIS->setIcon(static_cast<QMessageBox::Icon>(icon));
    }

    Pixmap::OwnedRef Handle_iconPixmap(HandleRef _this) {
        return new Pixmap::__Owned { THIS->iconPixmap() };
    }

    void Handle_setIconPixmap(HandleRef _this, Pixmap::HandleRef pixmap) {
        THIS->setIconPixmap(pixmap->qPixmap);
    }

    std::string Handle_informativeText(HandleRef _this) {
        return THIS->informativeText().toStdString();
    }

    void Handle_setInformativeText(HandleRef _this, const std::string& text) {
        THIS->setInformativeText(QString::fromStdString(text));
    }

    OptionEnumSet Handle_getOptions(HandleRef _this) {
        return THIS->options();
    }

    void Handle_setOptions(HandleRef _this, OptionEnumSet opts) {
        THIS->setOptions(static_cast<QMessageBox::Options>(opts));
    }

    StandardButtons Handle_getStandardButtons(HandleRef _this) {
        return THIS->standardButtons();
    }

    void Handle_setStandardButtons(HandleRef _this, StandardButtons buttons) {
        THIS->setStandardButtons(static_cast<QMessageBox::StandardButtons>(buttons));
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    TextFormat Handle_getTextFormat(HandleRef _this) {
        return static_cast<TextFormat>(THIS->textFormat());
    }

    void Handle_setTextFormat(HandleRef _this, TextFormat format) {
        THIS->setTextFormat(static_cast<Qt::TextFormat>(format));
    }

    TextInteractionFlags Handle_getTextInteractionFlags(HandleRef _this) {
        return THIS->textInteractionFlags();
    }

    void Handle_setTextInteractionFlags(HandleRef _this, TextInteractionFlags tiFlags) {
        THIS->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(tiFlags));
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

    ButtonRole Handle_buttonRole(HandleRef _this, AbstractButton::HandleRef button) {
        return static_cast<ButtonRole>(THIS->buttonRole(AS_QABSTRACTBUTTON_PTR(button)));
    }

    std::vector<AbstractButton::HandleRef> Handle_buttons(HandleRef _this) {
        return fromQList<QAbstractButton*,AbstractButton::HandleRef>(THIS->buttons(), [](auto button) {
            return reinterpret_cast<AbstractButton::HandleRef>(button);
        });
    }

    AbstractButton::HandleRef Handle_clickedButton(HandleRef _this) {
        return reinterpret_cast<AbstractButton::HandleRef>(THIS->clickedButton());
    }

    PushButton::HandleRef Handle_defaultButton(HandleRef _this) {
        return reinterpret_cast<PushButton::HandleRef>(THIS->defaultButton());
    }

    AbstractButton::HandleRef Handle_escapeButton(HandleRef _this) {
        return reinterpret_cast<AbstractButton::HandleRef>(THIS->escapeButton());
    }

    void Handle_removeButton(HandleRef _this, AbstractButton::HandleRef button) {
        THIS->removeButton(AS_QABSTRACTBUTTON_PTR(button));
    }

    void Handle_setDefaultButton(HandleRef _this, StandardButton button) {
        THIS->setDefaultButton(static_cast<QMessageBox::StandardButton>(button));
    }

    void Handle_setDefaultButton(HandleRef _this, PushButton::HandleRef button) {
        THIS->setDefaultButton(reinterpret_cast<QPushButton*>(button));
    }

    void Handle_setEscapeButton(HandleRef _this, AbstractButton::HandleRef button) {
        THIS->setEscapeButton(AS_QABSTRACTBUTTON_PTR(button));
    }

    void Handle_setEscapeButton(HandleRef _this, StandardButton button) {
        THIS->setEscapeButton(static_cast<QMessageBox::StandardButton>(button));
    }

    void Handle_setOption(HandleRef _this, OptionEnum option_, const std::optional<bool>& on) {
        THIS->setOption(static_cast<QMessageBox::Option>(option_), on.value_or(true));
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

    bool Handle_testOption(HandleRef _this, OptionEnum option_) {
        return THIS->testOption(static_cast<QMessageBox::Option>(option_));
    }

    SignalConnectionRef Handle_connect_ButtonClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QMessageBox::buttonClicked, [handler](QAbstractButton *button) {
            handler->buttonClicked(reinterpret_cast<AbstractButton::HandleRef>(button));
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        return reinterpret_cast<HandleRef>(new QMessageBox(qParent));
    }

    HandleRef create(Icon icon, const std::string& title, const std::string& text, const std::optional<StandardButtons>& buttons, const std::optional<Widget::HandleRef>& parent, const std::optional<WindowFlags>& flags_) {
        const auto qButtons = optionOrDefaultStaticCast(buttons, QMessageBox::NoButton);
        const auto qParent = Widget::fromOptionalHandle(parent);
        const auto qFlags = optionOrDefaultStaticCast(flags_, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        return reinterpret_cast<HandleRef>(new QMessageBox(static_cast<QMessageBox::Icon>(icon), QString::fromStdString(title), QString::fromStdString(text), qButtons, qParent, qFlags));
    }

    void about(Widget::HandleRef parent, const std::string& title, const std::string& text) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        QMessageBox::about(qParent, QString::fromStdString(title), QString::fromStdString(text));
    }

    void aboutQt(Widget::HandleRef parent, const std::optional<std::string>& title) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        const auto qTitle = optionalMap<std::string,QString>(title, [](auto t) { return QString::fromStdString(t); }).value_or(QString());
        QMessageBox::aboutQt(qParent, qTitle);
    }

    StandardButton critical(Widget::HandleRef parent, const std::string& title, const std::string& text, const std::optional<StandardButtons>& buttons, const std::optional<StandardButton>& defaultButton) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        QMessageBox::StandardButtons qButtons(Ok);
        if (buttons.has_value()) qButtons = static_cast<QMessageBox::StandardButtons>(buttons.value());
        const auto qDefault = optionOrDefaultStaticCast(defaultButton, QMessageBox::NoButton);
        return static_cast<StandardButton>(QMessageBox::critical(qParent, QString::fromStdString(title), QString::fromStdString(text), qButtons, qDefault));
    }

    StandardButton information(Widget::HandleRef parent, const std::string& title, const std::string& text, const std::optional<StandardButtons>& buttons, const std::optional<StandardButton>& defaultButton) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        QMessageBox::StandardButtons qButtons(Ok);
        if (buttons.has_value()) qButtons = static_cast<QMessageBox::StandardButtons>(buttons.value());
        const auto qDefault = optionOrDefaultStaticCast(defaultButton, QMessageBox::NoButton);
        return static_cast<StandardButton>(QMessageBox::information(qParent, QString::fromStdString(title), QString::fromStdString(text), qButtons, qDefault));
    }

    StandardButton question(Widget::HandleRef parent, const std::string& title, const std::string& text, const std::optional<StandardButtons>& buttons, const std::optional<StandardButton>& defaultButton) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        QMessageBox::StandardButtons qButtons(Yes | No);
        if (buttons.has_value()) qButtons = static_cast<QMessageBox::StandardButtons>(buttons.value());
        const auto qDefault = optionOrDefaultStaticCast(defaultButton, QMessageBox::NoButton);
        return static_cast<StandardButton>(QMessageBox::question(qParent, QString::fromStdString(title), QString::fromStdString(text), qButtons, qDefault));
    }

    StandardButton warning(Widget::HandleRef parent, const std::string& title, const std::string& text, const std::optional<StandardButtons>& buttons, const std::optional<StandardButton>& defaultButton) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        QMessageBox::StandardButtons qButtons(Ok);
        if (buttons.has_value()) qButtons = static_cast<QMessageBox::StandardButtons>(buttons.value());
        const auto qDefault = optionOrDefaultStaticCast(defaultButton, QMessageBox::NoButton);
        return static_cast<StandardButton>(QMessageBox::warning(qParent, QString::fromStdString(title), QString::fromStdString(text), qButtons, qDefault));
    }
}
