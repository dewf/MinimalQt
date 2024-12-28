#include "generated/ComboBox.h"
#include "ComboBoxInternal.h"

#include <QComboBox>
#include <QStringList>

#include "AbstractItemModelInternal.h"
#include "util/convert.h"
#include "VariantInternal.h"
#include "IconInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define COMBO_THIS (WRAPPER->getActual())

namespace ComboBox
{
    int32_t Handle_count(HandleRef _this) {
        return COMBO_THIS->count();
    }

    Variant::OwnedRef Handle_currentData(HandleRef _this) {
        auto ret = COMBO_THIS->currentData();
        return VARIANT_HEAP_NEW(ret);
    }

    Variant::OwnedRef Handle_currentData(HandleRef _this, ItemDataRole role) {
        auto ret = COMBO_THIS->currentData(static_cast<Qt::ItemDataRole>(role));
        return VARIANT_HEAP_NEW(ret);
    }

    int32_t Handle_currentIndex(HandleRef _this) {
        return COMBO_THIS->currentIndex();
    }

    void Handle_setCurrentIndex(HandleRef _this, int32_t index) {
        COMBO_THIS->setCurrentIndex(index);
    }

    std::string Handle_currentText(HandleRef _this) {
        return COMBO_THIS->currentText().toStdString();
    }

    void Handle_setCurrentText(HandleRef _this, const std::string& text) {
        COMBO_THIS->setCurrentText(QString::fromStdString(text));
    }

    bool Handle_duplicatesEnabled(HandleRef _this) {
        return COMBO_THIS->duplicatesEnabled();
    }

    void Handle_setDuplicatesEnabled(HandleRef _this, bool enabled) {
        COMBO_THIS->setDuplicatesEnabled(enabled);
    }

    bool Handle_isEditable(HandleRef _this) {
        return COMBO_THIS->isEditable();
    }

    void Handle_setEditable(HandleRef _this, bool editable) {
        COMBO_THIS->setEditable(editable);
    }

    bool Handle_hasFrame(HandleRef _this) {
        return COMBO_THIS->hasFrame();
    }

    void Handle_setFrame(HandleRef _this, bool hasFrame) {
        COMBO_THIS->setFrame(hasFrame);
    }

    Size Handle_iconSize(HandleRef _this) {
        return toSize(COMBO_THIS->iconSize());
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        COMBO_THIS->setIconSize(toQSize(size));
    }

    InsertPolicy Handle_getInsertPolicy(HandleRef _this) {
        return static_cast<InsertPolicy>(COMBO_THIS->insertPolicy());
    }

    void Handle_setInsertPolicy(HandleRef _this, InsertPolicy policy) {
        COMBO_THIS->setInsertPolicy(static_cast<QComboBox::InsertPolicy>(policy));
    }

    int32_t Handle_maxCount(HandleRef _this) {
        return COMBO_THIS->maxCount();
    }

    void Handle_setMaxCount(HandleRef _this, int32_t count) {
        COMBO_THIS->setMaxCount(count);
    }

    int32_t Handle_maxVisibleItems(HandleRef _this) {
        return COMBO_THIS->maxVisibleItems();
    }

    void Handle_setMaxVisibleItems(HandleRef _this, int32_t count) {
        COMBO_THIS->setMaxVisibleItems(count);
    }

    int32_t Handle_minimumContentsLength(HandleRef _this) {
        return COMBO_THIS->minimumContentsLength();
    }

    void Handle_setMinimumContentsLength(HandleRef _this, int32_t length) {
        COMBO_THIS->setMinimumContentsLength(length);
    }

    int32_t Handle_modelColumn(HandleRef _this) {
        return COMBO_THIS->modelColumn();
    }

    void Handle_setModelColumn(HandleRef _this, int32_t column) {
        COMBO_THIS->setModelColumn(column);
    }

    std::string Handle_placeholderText(HandleRef _this) {
        return COMBO_THIS->placeholderText().toStdString();
    }

    void Handle_setPlaceholderText(HandleRef _this, const std::string& text) {
        COMBO_THIS->setPlaceholderText(QString::fromStdString(text));
    }

    SizeAdjustPolicy Handle_getSizeAdjustPolicy(HandleRef _this) {
        return static_cast<SizeAdjustPolicy>(COMBO_THIS->sizeAdjustPolicy());
    }

    void Handle_setSizeAdjustPolicy(HandleRef _this, SizeAdjustPolicy policy) {
        COMBO_THIS->setSizeAdjustPolicy(static_cast<QComboBox::SizeAdjustPolicy>(policy));
    }

    void Handle_clear(HandleRef _this) {
        COMBO_THIS->clear();
    }

    void Handle_addItem(HandleRef _this, const std::string& text, Variant::HandleRef userData) {
        COMBO_THIS->addItem(QString::fromStdString(text), QVARIANT_VALUE(userData));
    }

    void Handle_addItem(HandleRef _this, Icon::HandleRef icon, const std::string& text, Variant::HandleRef userData) {
        COMBO_THIS->addItem(QICON_VALUE(icon), QString::fromStdString(text), QVARIANT_VALUE(userData));
    }

    void Handle_addItems(HandleRef _this, const std::vector<std::string>& texts) {
        QStringList qStrings;
        for (auto &text : texts) {
            qStrings.append(QString::fromStdString(text));
        }
        COMBO_THIS->addItems(qStrings);
    }

    void Handle_setModel(HandleRef _this, AbstractItemModel::HandleRef model) {
        const auto modelWrapper = reinterpret_cast<AbstractItemModel::SignalWrapper*>(model);
        COMBO_THIS->setModel(modelWrapper->getActual());
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QComboBox(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    HandleRef downcastFrom(Widget::HandleRef widget) {
        auto widgetWrapper = reinterpret_cast<Widget::SignalWrapper*>(widget);
        auto comboWrapper = dynamic_cast<SignalWrapper*>(widgetWrapper);
        return reinterpret_cast<HandleRef>(comboWrapper);
    }
}
