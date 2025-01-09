#include "generated/ComboBox.h"
#include "ComboBoxInternal.h"

#include <QStringList>

#include "ObjectInternal.h"
#include "AbstractItemModelInternal.h"
#include "VariantInternal.h"
#include "IconInternal.h"

#include "util/convert.h"

#define THIS (reinterpret_cast<QComboBox*>(_this))

namespace ComboBox
{
    int32_t Handle_count(HandleRef _this) {
        return THIS->count();
    }

    Variant::OwnedRef Handle_currentData(HandleRef _this) {
        const auto ret = THIS->currentData();
        return new Variant::__Owned(ret);
    }

    Variant::OwnedRef Handle_currentData(HandleRef _this, ItemDataRole role) {
        const auto ret = THIS->currentData(static_cast<Qt::ItemDataRole>(role));
        return new Variant::__Owned(ret);
    }

    int32_t Handle_currentIndex(HandleRef _this) {
        return THIS->currentIndex();
    }

    void Handle_setCurrentIndex(HandleRef _this, int32_t index) {
        THIS->setCurrentIndex(index);
    }

    std::string Handle_currentText(HandleRef _this) {
        return THIS->currentText().toStdString();
    }

    void Handle_setCurrentText(HandleRef _this, const std::string& text) {
        THIS->setCurrentText(QString::fromStdString(text));
    }

    bool Handle_duplicatesEnabled(HandleRef _this) {
        return THIS->duplicatesEnabled();
    }

    void Handle_setDuplicatesEnabled(HandleRef _this, bool enabled) {
        THIS->setDuplicatesEnabled(enabled);
    }

    bool Handle_isEditable(HandleRef _this) {
        return THIS->isEditable();
    }

    void Handle_setEditable(HandleRef _this, bool editable) {
        THIS->setEditable(editable);
    }

    bool Handle_hasFrame(HandleRef _this) {
        return THIS->hasFrame();
    }

    void Handle_setFrame(HandleRef _this, bool hasFrame) {
        THIS->setFrame(hasFrame);
    }

    Size Handle_iconSize(HandleRef _this) {
        return toSize(THIS->iconSize());
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        THIS->setIconSize(toQSize(size));
    }

    InsertPolicy Handle_getInsertPolicy(HandleRef _this) {
        return static_cast<InsertPolicy>(THIS->insertPolicy());
    }

    void Handle_setInsertPolicy(HandleRef _this, InsertPolicy policy) {
        THIS->setInsertPolicy(static_cast<QComboBox::InsertPolicy>(policy));
    }

    int32_t Handle_maxCount(HandleRef _this) {
        return THIS->maxCount();
    }

    void Handle_setMaxCount(HandleRef _this, int32_t count) {
        THIS->setMaxCount(count);
    }

    int32_t Handle_maxVisibleItems(HandleRef _this) {
        return THIS->maxVisibleItems();
    }

    void Handle_setMaxVisibleItems(HandleRef _this, int32_t count) {
        THIS->setMaxVisibleItems(count);
    }

    int32_t Handle_minimumContentsLength(HandleRef _this) {
        return THIS->minimumContentsLength();
    }

    void Handle_setMinimumContentsLength(HandleRef _this, int32_t length) {
        THIS->setMinimumContentsLength(length);
    }

    int32_t Handle_modelColumn(HandleRef _this) {
        return THIS->modelColumn();
    }

    void Handle_setModelColumn(HandleRef _this, int32_t column) {
        THIS->setModelColumn(column);
    }

    std::string Handle_placeholderText(HandleRef _this) {
        return THIS->placeholderText().toStdString();
    }

    void Handle_setPlaceholderText(HandleRef _this, const std::string& text) {
        THIS->setPlaceholderText(QString::fromStdString(text));
    }

    SizeAdjustPolicy Handle_getSizeAdjustPolicy(HandleRef _this) {
        return static_cast<SizeAdjustPolicy>(THIS->sizeAdjustPolicy());
    }

    void Handle_setSizeAdjustPolicy(HandleRef _this, SizeAdjustPolicy policy) {
        THIS->setSizeAdjustPolicy(static_cast<QComboBox::SizeAdjustPolicy>(policy));
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_addItem(HandleRef _this, const std::string& text, Variant::HandleRef userData) {
        THIS->addItem(QString::fromStdString(text), userData->value);
    }

    void Handle_addItem(HandleRef _this, Icon::HandleRef icon, const std::string& text, Variant::HandleRef userData) {
        THIS->addItem(QICON_VALUE(icon), QString::fromStdString(text), userData->value);
    }

    void Handle_addItems(HandleRef _this, const std::vector<std::string>& texts) {
        THIS->addItems(toQStringList(texts));
    }

    void Handle_setItemData(HandleRef _this, int32_t index, Variant::HandleRef value, ItemDataRole role) {
        THIS->setItemData(index, value->value, static_cast<Qt::ItemDataRole>(role));
    }

    void Handle_setItemIcon(HandleRef _this, int32_t index, Icon::HandleRef icon) {
        THIS->setItemIcon(index, QICON_VALUE(icon));
    }

    void Handle_setItemText(HandleRef _this, int32_t index, const std::string& text) {
        THIS->setItemText(index, QString::fromStdString(text));
    }

    void Handle_setModel(HandleRef _this, AbstractItemModel::HandleRef model) {
        THIS->setModel(reinterpret_cast<QAbstractItemModel*>(model));
    }

    SignalConnectionRef Handle_connect_Activated(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QComboBox::activated, [handler](int index) {
            handler->activated(index);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CurrentIndexChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QComboBox::currentIndexChanged, [handler](int index) {
            handler->currentIndexChanged(index);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CurrentTextChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QComboBox::currentTextChanged, [handler](const QString& text) {
            handler->currentTextChanged(text.toStdString());

        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_EditTextChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QComboBox::editTextChanged, [handler](const QString& text) {
            handler->editTextChanged(text.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Highlighted(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QComboBox::highlighted, [handler](int index) {
            handler->highlighted(index);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TextActivated(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QComboBox::textActivated, [handler](const QString& text) {
            handler->textActivated(text.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TextHighlighted(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QComboBox::textHighlighted, [handler](const QString& text) {
            handler->textHighlighted(text.toStdString());
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QComboBox());
    }

    HandleRef downcastFrom(Widget::HandleRef widget) {
        const auto combo = dynamic_cast<QComboBox*>(AS_QWIDGET_PTR(widget));
        return reinterpret_cast<HandleRef>(combo);
    }
}
