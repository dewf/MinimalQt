#include "generated/MessageBox.h"
#include "MessageBoxInternal.h"
#include "PushButtonInternal.h"
#include "PixmapInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define MESSAGEBOX_THIS (WRAPPER->getActual())

namespace MessageBox
{
    void Handle_addButton(HandleRef _this, AbstractButton::HandleRef button, ButtonRole role) {
        const auto buttonWrapper = reinterpret_cast<AbstractButton::SignalWrapper*>(button);
        MESSAGEBOX_THIS->addButton(buttonWrapper->getActual(), static_cast<QMessageBox::ButtonRole>(role));
    }

    std::string Handle_detailedText(HandleRef _this) {
        return MESSAGEBOX_THIS->detailedText().toStdString();
    }

    void Handle_setDetailedText(HandleRef _this, const std::string& text) {
        MESSAGEBOX_THIS->setDetailedText(QString::fromStdString(text));
    }

    Icon Handle_getIcon(HandleRef _this) {
        return static_cast<Icon>(MESSAGEBOX_THIS->icon());
    }

    void Handle_setIcon(HandleRef _this, Icon icon) {
        MESSAGEBOX_THIS->setIcon(static_cast<QMessageBox::Icon>(icon));
    }

    Pixmap::OwnedRef Handle_iconPixmap(HandleRef _this) {
        return new Pixmap::__Owned { MESSAGEBOX_THIS->iconPixmap() };
    }

    void Handle_setIconPixmap(HandleRef _this, Pixmap::HandleRef pixmap) {
        MESSAGEBOX_THIS->setIconPixmap(pixmap->qPixmap);
    }

    std::string Handle_informativeText(HandleRef _this) {
        return MESSAGEBOX_THIS->informativeText().toStdString();
    }

    void Handle_setInformativeText(HandleRef _this, const std::string& text) {
        MESSAGEBOX_THIS->setInformativeText(QString::fromStdString(text));
    }

    OptionEnumSet Handle_getOptions(HandleRef _this) {
        return MESSAGEBOX_THIS->options();
    }

    void Handle_setOptions(HandleRef _this, OptionEnumSet opts) {
        MESSAGEBOX_THIS->setOptions(static_cast<QMessageBox::Options>(opts));
    }

    StandardButtons Handle_getStandardButtons(HandleRef _this) {
        return MESSAGEBOX_THIS->standardButtons();
    }

    void Handle_setStandardButtons(HandleRef _this, StandardButtons buttons) {
        MESSAGEBOX_THIS->setStandardButtons(static_cast<QMessageBox::StandardButtons>(buttons));
    }

    std::string Handle_text(HandleRef _this) {
        return MESSAGEBOX_THIS->text().toStdString();
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        MESSAGEBOX_THIS->setText(QString::fromStdString(text));
    }

    TextFormat Handle_getTextFormat(HandleRef _this) {
        return static_cast<TextFormat>(MESSAGEBOX_THIS->textFormat());
    }

    void Handle_setTextFormat(HandleRef _this, TextFormat format) {
        MESSAGEBOX_THIS->setTextFormat(static_cast<Qt::TextFormat>(format));
    }

    TextInteractionFlags Handle_getTextInteractionFlags(HandleRef _this) {
        return MESSAGEBOX_THIS->textInteractionFlags();
    }

    void Handle_setTextInteractionFlags(HandleRef _this, TextInteractionFlags tiFlags) {
        MESSAGEBOX_THIS->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(tiFlags));
    }

    PushButton::HandleRef Handle_addButton(HandleRef _this, StandardButton button, const std::shared_ptr<PushButton::SignalHandler>& buttonHandler) {
        const auto qButtonType = static_cast<QMessageBox::StandardButton>(button);
        if (const auto addedButton = MESSAGEBOX_THIS->addButton(qButtonType); addedButton != nullptr) {
            assert(wrapperForQObject(addedButton) == nullptr);
            const auto wrapper = new PushButton::SignalWrapper(addedButton, buttonHandler);
            return reinterpret_cast<PushButton::HandleRef>(wrapper);
        }
        return nullptr;
    }

    PushButton::HandleRef Handle_addButton(HandleRef _this, const std::string& text, ButtonRole role, const std::shared_ptr<PushButton::SignalHandler>& buttonHandler) {
        const auto qButtonRole = static_cast<QMessageBox::ButtonRole>(role);
        if (const auto addedButton = MESSAGEBOX_THIS->addButton(QString::fromStdString(text), qButtonRole); addedButton != nullptr) {
            assert(wrapperForQObject(addedButton) == nullptr);
            const auto wrapper = new PushButton::SignalWrapper(addedButton, buttonHandler);
            return reinterpret_cast<PushButton::HandleRef>(wrapper);
        }
        return nullptr;
    }

    std::shared_ptr<AbstractButtonResult::Base> Handle_button(HandleRef _this, StandardButton which) {
        const auto qWhich = static_cast<QMessageBox::StandardButton>(which);
        if (const auto abstractButton = MESSAGEBOX_THIS->button(qWhich); abstractButton != nullptr) {
            // a button exists, but do we know about it already?
            if (const auto existing = wrapperForQObject(abstractButton); existing != nullptr) {
                // its ours
                return std::make_shared<AbstractButtonResult::Existing>(reinterpret_cast<AbstractButton::HandleRef>(existing));
            }
            // else, it was Qt-created, so wrap it:
            const auto createFunc = [abstractButton](const std::shared_ptr<AbstractButton::SignalHandler>& handler) {
                const auto wrapper = new AbstractButton::SignalWrapper(abstractButton, handler);
                return reinterpret_cast<AbstractButton::HandleRef>(wrapper);
            };
            return std::make_shared<AbstractButtonResult::NeedsWrapper>(createFunc);
        }
        return std::make_shared<AbstractButtonResult::NoButton>();
    }


    ButtonRole Handle_buttonRole(HandleRef _this, AbstractButton::HandleRef button) {
        const auto wrapper = reinterpret_cast<AbstractButton::SignalWrapper*>(button);
        return static_cast<ButtonRole>(MESSAGEBOX_THIS->buttonRole(wrapper->getActual()));
    }

    std::vector<std::shared_ptr<AbstractButtonResult::Base>> Handle_buttons(HandleRef _this) {
        // doing it "manually" (vs fromQList) because the latter was showing us memory leak linting errors, not sure if legit or macro-related
        std::vector<std::shared_ptr<AbstractButtonResult::Base>> ret;
        for (auto &abstractButton : MESSAGEBOX_THIS->buttons()) {
            if (const auto wrapper = wrapperForQObject(abstractButton); wrapper != nullptr) {
                const auto value = std::make_shared<AbstractButtonResult::Existing>(reinterpret_cast<AbstractButton::HandleRef>(wrapper));
                ret.push_back(value);
            }
            // else, it was Qt-created, so wrap it:
            const auto createFunc = [abstractButton](const std::shared_ptr<AbstractButton::SignalHandler>& handler) {
                const auto wrapper = new AbstractButton::SignalWrapper(abstractButton, handler);
                return reinterpret_cast<AbstractButton::HandleRef>(wrapper);
            };
            const auto value = std::make_shared<AbstractButtonResult::NeedsWrapper>(createFunc);
            ret.push_back(value);
        }
        return ret;
    }

    std::shared_ptr<AbstractButtonResult::Base> Handle_clickedButton(HandleRef _this) {
        if (const auto clicked = MESSAGEBOX_THIS->clickedButton(); clicked != nullptr) {
            if (const auto wrapper = wrapperForQObject(clicked); wrapper != nullptr) {
                return std::make_shared<AbstractButtonResult::Existing>(reinterpret_cast<AbstractButton::HandleRef>(wrapper));
            }
            // else was Qt-created, so wrap it
            const auto createFunc = [clicked](const std::shared_ptr<AbstractButton::SignalHandler>& handler) {
                const auto wrapper = new AbstractButton::SignalWrapper(clicked, handler);
                return reinterpret_cast<AbstractButton::HandleRef>(wrapper);
            };
            return std::make_shared<AbstractButtonResult::NeedsWrapper>(createFunc);
        }
        return std::make_shared<AbstractButtonResult::NoButton>();
    }

    std::shared_ptr<PushButtonResult::Base> Handle_defaultButton(HandleRef _this) {
        if (const auto defaultButton = MESSAGEBOX_THIS->defaultButton(); defaultButton != nullptr) {
            if (const auto wrapper = wrapperForQObject(defaultButton); wrapper != nullptr) {
                return std::make_shared<PushButtonResult::Existing>(reinterpret_cast<PushButton::HandleRef>(wrapper));
            }
            // else was Qt-created, wrap it
            const auto createFunc = [defaultButton](const std::shared_ptr<PushButton::SignalHandler>& handler) {
                const auto wrapper = new PushButton::SignalWrapper(defaultButton, handler);
                return reinterpret_cast<PushButton::HandleRef>(wrapper);
            };
            return std::make_shared<PushButtonResult::NeedsWrapper>(createFunc);
        }
        return std::make_shared<PushButtonResult::NoButton>();
    }

    std::shared_ptr<AbstractButtonResult::Base> Handle_escapeButton(HandleRef _this) {
        if (const auto escapeButton = MESSAGEBOX_THIS->escapeButton(); escapeButton != nullptr) {
            if (const auto wrapper = wrapperForQObject(escapeButton); wrapper != nullptr) {
                return std::make_shared<AbstractButtonResult::Existing>(reinterpret_cast<AbstractButton::HandleRef>(wrapper));
            }
            // else was Qt-created, so wrap it
            const auto createFunc = [escapeButton](const std::shared_ptr<AbstractButton::SignalHandler>& handler) {
                const auto wrapper = new AbstractButton::SignalWrapper(escapeButton, handler);
                return reinterpret_cast<AbstractButton::HandleRef>(wrapper);
            };
            return std::make_shared<AbstractButtonResult::NeedsWrapper>(createFunc);
        }
        return std::make_shared<AbstractButtonResult::NoButton>();
    }

    void Handle_removeButton(HandleRef _this, AbstractButton::HandleRef button) {
        const auto wrapper = reinterpret_cast<AbstractButton::SignalWrapper*>(button);
        MESSAGEBOX_THIS->removeButton(wrapper->getActual());
    }

    void Handle_setDefaultButton(HandleRef _this, StandardButton button) {
        MESSAGEBOX_THIS->setDefaultButton(static_cast<QMessageBox::StandardButton>(button));
    }

    void Handle_setDefaultButton(HandleRef _this, PushButton::HandleRef button) {
        const auto wrapper = reinterpret_cast<PushButton::SignalWrapper*>(button);
        MESSAGEBOX_THIS->setDefaultButton(wrapper->getActual());
    }

    void Handle_setEscapeButton(HandleRef _this, AbstractButton::HandleRef button) {
        const auto wrapper = reinterpret_cast<AbstractButton::SignalWrapper*>(button);
        MESSAGEBOX_THIS->setEscapeButton(wrapper->getActual());
    }

    void Handle_setEscapeButton(HandleRef _this, StandardButton button) {
        MESSAGEBOX_THIS->setEscapeButton(static_cast<QMessageBox::StandardButton>(button));
    }

    void Handle_setOption(HandleRef _this, OptionEnum option_, const std::optional<bool>& on) {
        MESSAGEBOX_THIS->setOption(static_cast<QMessageBox::Option>(option_), on.value_or(true));
    }

    void Handle_setWindowModality(HandleRef _this, WindowModality windowModality) {
        MESSAGEBOX_THIS->setWindowModality(static_cast<Qt::WindowModality>(windowModality));
    }

    void Handle_setWindowTitle(HandleRef _this, const std::string& title) {
        MESSAGEBOX_THIS->setWindowTitle(QString::fromStdString(title));
    }

    StandardButton Handle_getStandardButton(HandleRef _this, AbstractButton::HandleRef button) {
        const auto wrapper = reinterpret_cast<AbstractButton::SignalWrapper*>(button);
        return static_cast<StandardButton>(MESSAGEBOX_THIS->standardButton(wrapper->getActual()));
    }

    bool Handle_testOption(HandleRef _this, OptionEnum option_) {
        return MESSAGEBOX_THIS->testOption(static_cast<QMessageBox::Option>(option_));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler, const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        const auto wrapper = new SignalWrapper(new QMessageBox(qParent), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler, Icon icon, const std::string& title, const std::string& text, const std::optional<StandardButtons>& buttons, const std::optional<Widget::HandleRef>& parent, const std::optional<WindowFlags>& flags_) {
        const auto qButtons = optionOrDefaultStaticCast(buttons, QMessageBox::NoButton);
        const auto qParent = Widget::fromOptionalHandle(parent);
        const auto qFlags = optionOrDefaultStaticCast(flags_, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        const auto box = new QMessageBox(static_cast<QMessageBox::Icon>(icon), QString::fromStdString(title), QString::fromStdString(text), qButtons, qParent, qFlags);
        const auto wrapper = new SignalWrapper(box, handler);
        return reinterpret_cast<HandleRef>(wrapper);
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
