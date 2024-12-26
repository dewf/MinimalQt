#include "generated/ComboBox.h"
#include "ComboBoxInternal.h"

#include <QComboBox>
#include <QStringList>

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
        return reinterpret_cast<Variant::OwnedRef>(new QVariant(ret));
    }

    Variant::OwnedRef Handle_currentData(HandleRef _this, ItemDataRole role) {
        auto ret = COMBO_THIS->currentData(static_cast<Qt::ItemDataRole>(role));
        return reinterpret_cast<Variant::OwnedRef>(new QVariant(ret));
    }

    int32_t Handle_currentIndex(HandleRef _this) {
        return COMBO_THIS->currentIndex();
    }

    void Handle_setCurrentIndex(HandleRef _this, int32_t index) {
        COMBO_THIS->setCurrentIndex(index);
    }

    void Handle_setCurrentText(HandleRef _this, const std::string& text) {
        COMBO_THIS->setCurrentText(QString::fromStdString(text));
    }

    void Handle_setDuplicatesEnabled(HandleRef _this, bool enabled) {
        COMBO_THIS->setDuplicatesEnabled(enabled);
    }

    void Handle_setEditable(HandleRef _this, bool editable) {
        COMBO_THIS->setEditable(editable);
    }

    void Handle_setFrame(HandleRef _this, bool hasFrame) {
        COMBO_THIS->setFrame(hasFrame);
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        COMBO_THIS->setIconSize(toQSize(size));
    }

    void Handle_setInsertPolicy(HandleRef _this, InsertPolicy policy) {
        COMBO_THIS->setInsertPolicy(static_cast<QComboBox::InsertPolicy>(policy));
    }

    void Handle_setMaxCount(HandleRef _this, int32_t count) {
        COMBO_THIS->setMaxCount(count);
    }

    void Handle_setMaxVisibleItems(HandleRef _this, int32_t count) {
        COMBO_THIS->setMaxVisibleItems(count);
    }

    void Handle_setMinimumContentsLength(HandleRef _this, int32_t length) {
        COMBO_THIS->setMinimumContentsLength(length);
    }

    void Handle_setModelColumn(HandleRef _this, int32_t column) {
        COMBO_THIS->setModelColumn(column);
    }

    void Handle_setPlaceholderText(HandleRef _this, const std::string& text) {
        COMBO_THIS->setPlaceholderText(QString::fromStdString(text));
    }

    void Handle_setSizeAdjustPolicy(HandleRef _this, SizeAdjustPolicy policy) {
        COMBO_THIS->setSizeAdjustPolicy(static_cast<QComboBox::SizeAdjustPolicy>(policy));
    }

    void Handle_clear(HandleRef _this) {
        COMBO_THIS->clear();
    }

    void Handle_addItem(HandleRef _this, const std::string& text, const std::shared_ptr<Variant::Deferred::Base>& userData) {
        COMBO_THIS->addItem(QString::fromStdString(text), fromDeferred(userData));
    }

    void Handle_addItem(HandleRef _this, Icon::HandleRef icon, const std::string& text, const std::shared_ptr<Variant::Deferred::Base>& userData) {
        COMBO_THIS->addItem(QICON_VALUE(icon), QString::fromStdString(text), fromDeferred(userData));
    }

    void Handle_addItems(HandleRef _this, const std::vector<std::string>& texts) {
        COMBO_THIS->addItems(toQStringList(texts));
    }

    void Handle_setModel(HandleRef _this, AbstractItemModel::HandleRef model) {
        COMBO_THIS->setModel(reinterpret_cast<QAbstractItemModel *>(model));
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
