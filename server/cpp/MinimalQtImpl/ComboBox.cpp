#include "generated/ComboBox.h"
#include "ComboBoxInternal.h"

#include "ObjectInternal.h"
#include "AbstractItemModelInternal.h"
#include "VariantInternal.h"
#include "IconInternal.h"
#include "ModelIndexInternal.h"
#include "ValidatorInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Common;
using namespace ::Enums;
using namespace ::Widget;
using namespace ::Variant;
using namespace ::AbstractItemModel;
using namespace ::AbstractItemDelegate;
using namespace ::AbstractItemView;
using namespace ::Icon;
using namespace ::Completer;
using namespace ::LineEdit;
using namespace ::Validator;
using namespace ::ModelIndex;

#define THIS (reinterpret_cast<QComboBox*>(_this))

namespace ComboBox
{
    void Handle_addItem(HandleRef _this, const std::string& text, const std::optional<Variant::HandleRef>& userData) {
        THIS->addItem(QString::fromStdString(text), Variant::fromOptional(userData));
    }

    void Handle_addItem(HandleRef _this, Icon::HandleRef icon, const std::string& text, const std::optional<Variant::HandleRef>& userData) {
        THIS->addItem(QICON_VALUE(icon), QString::fromStdString(text), Variant::fromOptional(userData));
    }

    void Handle_addItems(HandleRef _this, const std::vector<std::string>& texts) {
        THIS->addItems(toQStringList(texts));
    }

    Completer::HandleRef Handle_completer(HandleRef _this) {
        return reinterpret_cast<Completer::HandleRef>(THIS->completer());
    }

    int32_t Handle_count(HandleRef _this) {
        return THIS->count();
    }

    Variant::OwnedRef Handle_currentData(HandleRef _this, ItemDataRole role /* ItemDataRole::UserRole */) {
        return VARIANT_HEAP_NEW(THIS->currentData(static_cast<int>(role)));
    }

    int32_t Handle_currentIndex(HandleRef _this) {
        return THIS->currentIndex();
    }

    std::string Handle_currentText(HandleRef _this) {
        return THIS->currentText().toStdString();
    }

    bool Handle_duplicatesEnabled(HandleRef _this) {
        return THIS->duplicatesEnabled();
    }

    int32_t Handle_findData(HandleRef _this, Variant::HandleRef data, ItemDataRole role /* ItemDataRole::UserRole */, MatchFlags flags_ /* MatchFlags::MatchExactly | MatchFlags::MatchCaseSensitive */) {
        return THIS->findData(QVARIANT_VALUE(data), static_cast<int>(role), static_cast<Qt::MatchFlags>(flags_.value));
    }

    int32_t Handle_findText(HandleRef _this, const std::string& text, MatchFlags flags_ /* MatchFlags::MatchExactly | MatchFlags::MatchCaseSensitive */) {
        return THIS->findText(QString::fromStdString(text), static_cast<Qt::MatchFlags>(flags_.value));
    }

    bool Handle_hasFrame(HandleRef _this) {
        return THIS->hasFrame();
    }

    void Handle_hidePopup(HandleRef _this) {
        THIS->hidePopup();
    }

    Size Handle_iconSize(HandleRef _this) {
        return toSize(THIS->iconSize());
    }

    void Handle_insertItem(HandleRef _this, int32_t index, const std::string& text, const std::optional<Variant::HandleRef>& userData) {
        THIS->insertItem(index, QString::fromStdString(text), Variant::fromOptional(userData));
    }

    void Handle_insertItem(HandleRef _this, int32_t index, Icon::HandleRef icon, const std::string& text, const std::optional<Variant::HandleRef>& userData) {
        THIS->insertItem(index, QICON_VALUE(icon), QString::fromStdString(text), Variant::fromOptional(userData));
    }

    void Handle_insertItems(HandleRef _this, int32_t index, const std::vector<std::string>& list) {
        THIS->insertItems(index, toQStringList(list));
    }

    InsertPolicy Handle_getInsertPolicy(HandleRef _this) {
        return static_cast<InsertPolicy>(THIS->insertPolicy());
    }

    void Handle_insertSeparator(HandleRef _this, int32_t index) {
        THIS->insertSeparator(index);
    }

    bool Handle_isEditable(HandleRef _this) {
        return THIS->isEditable();
    }

    Variant::OwnedRef Handle_itemData(HandleRef _this, int32_t index, ItemDataRole role /* ItemDataRole::UserRole */) {
        return VARIANT_HEAP_NEW(THIS->itemData(index, static_cast<int>(role)));
    }

    AbstractItemDelegate::HandleRef Handle_itemDelegate(HandleRef _this) {
        return reinterpret_cast<AbstractItemDelegate::HandleRef>(THIS->itemDelegate());
    }

    Icon::OwnedRef Handle_itemIcon(HandleRef _this, int32_t index) {
        return ICON_HEAP_NEW(THIS->itemIcon(index));
    }

    std::string Handle_itemText(HandleRef _this, int32_t index) {
        return THIS->itemText(index).toStdString();
    }

    LineEdit::HandleRef Handle_lineEdit(HandleRef _this) {
        return reinterpret_cast<LineEdit::HandleRef>(THIS->lineEdit());
    }

    int32_t Handle_maxCount(HandleRef _this) {
        return THIS->maxCount();
    }

    int32_t Handle_maxVisibleItems(HandleRef _this) {
        return THIS->maxVisibleItems();
    }

    int32_t Handle_minimumContentsLength(HandleRef _this) {
        return THIS->minimumContentsLength();
    }

    AbstractItemModel::HandleRef Handle_model(HandleRef _this) {
        return reinterpret_cast<AbstractItemModel::HandleRef>(THIS->model());
    }

    int32_t Handle_modelColumn(HandleRef _this) {
        return THIS->modelColumn();
    }

    std::string Handle_placeholderText(HandleRef _this) {
        return THIS->placeholderText().toStdString();
    }

    void Handle_removeItem(HandleRef _this, int32_t index) {
        THIS->removeItem(index);
    }

    ModelIndex::OwnedRef Handle_rootModelIndex(HandleRef _this) {
        return MODELINDEX_HEAP_NEW(THIS->rootModelIndex());
    }

    void Handle_setCompleter(HandleRef _this, Completer::HandleRef completer) {
        THIS->setCompleter(reinterpret_cast<QCompleter*>(completer));
    }

    void Handle_setDuplicatesEnabled(HandleRef _this, bool enable) {
        THIS->setDuplicatesEnabled(enable);
    }

    void Handle_setEditable(HandleRef _this, bool editable) {
        THIS->setEditable(editable);
    }

    void Handle_setFrame(HandleRef _this, bool hasFrame) {
        THIS->setFrame(hasFrame);
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        THIS->setIconSize(toQSize(size));
    }

    void Handle_setInsertPolicy(HandleRef _this, InsertPolicy policy) {
        THIS->setInsertPolicy(static_cast<QComboBox::InsertPolicy>(policy));
    }

    void Handle_setItemData(HandleRef _this, int32_t index, Variant::HandleRef value, ItemDataRole role /* ItemDataRole::UserRole */) {
        THIS->setItemData(index, QVARIANT_VALUE(value), static_cast<int>(role));
    }

    void Handle_setItemDelegate(HandleRef _this, AbstractItemDelegate::HandleRef delegate_) {
        THIS->setItemDelegate(reinterpret_cast<QAbstractItemDelegate*>(delegate_));
    }

    void Handle_setItemIcon(HandleRef _this, int32_t index, Icon::HandleRef icon) {
        THIS->setItemIcon(index, QICON_VALUE(icon));
    }

    void Handle_setItemText(HandleRef _this, int32_t index, const std::string& text) {
        THIS->setItemText(index, QString::fromStdString(text));
    }

    void Handle_setLineEdit(HandleRef _this, LineEdit::HandleRef edit) {
        THIS->setLineEdit(reinterpret_cast<QLineEdit*>(edit));
    }

    void Handle_setMaxCount(HandleRef _this, int32_t max) {
        THIS->setMaxCount(max);
    }

    void Handle_setMaxVisibleItems(HandleRef _this, int32_t maxItems) {
        THIS->setMaxVisibleItems(maxItems);
    }

    void Handle_setMinimumContentsLength(HandleRef _this, int32_t characters) {
        THIS->setMinimumContentsLength(characters);
    }

    void Handle_setModel(HandleRef _this, AbstractItemModel::HandleRef model) {
        THIS->setModel(reinterpret_cast<QAbstractItemModel*>(model));
    }

    void Handle_setModelColumn(HandleRef _this, int32_t visibleColumn) {
        THIS->setModelColumn(visibleColumn);
    }

    void Handle_setPlaceholderText(HandleRef _this, const std::string& placeholderText) {
        THIS->setPlaceholderText(QString::fromStdString(placeholderText));
    }

    void Handle_setRootModelIndex(HandleRef _this, ModelIndex::HandleRef index) {
        THIS->setRootModelIndex(QMODELINDEX_VALUE(index));
    }

    void Handle_setSizeAdjustPolicy(HandleRef _this, SizeAdjustPolicy policy) {
        THIS->setSizeAdjustPolicy(static_cast<QComboBox::SizeAdjustPolicy>(policy));
    }

    void Handle_setValidator(HandleRef _this, ConstHandleRef validator) {
        THIS->setValidator(AS_QVALIDATOR_CONSTPTR(validator));
    }

    void Handle_setView(HandleRef _this, AbstractItemView::HandleRef itemView) {
        THIS->setView(reinterpret_cast<QAbstractItemView*>(itemView));
    }

    void Handle_showPopup(HandleRef _this) {
        THIS->showPopup();
    }

    SizeAdjustPolicy Handle_getSizeAdjustPolicy(HandleRef _this) {
        return static_cast<SizeAdjustPolicy>(THIS->sizeAdjustPolicy());
    }

    ConstHandleRef Handle_validator(HandleRef _this) {
        return AS_VALIDATOR_CONSTHANDLE(THIS->validator());
    }

    AbstractItemView::HandleRef Handle_view(HandleRef _this) {
        return reinterpret_cast<AbstractItemView::HandleRef>(THIS->view());
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_clearEditText(HandleRef _this) {
        THIS->clearEditText();
    }

    void Handle_setCurrentIndex(HandleRef _this, int32_t index) {
        THIS->setCurrentIndex(index);
    }

    void Handle_setCurrentText(HandleRef _this, const std::string& text) {
        THIS->setCurrentText(QString::fromStdString(text));
    }

    void Handle_setEditText(HandleRef _this, const std::string& text) {
        THIS->setEditText(QString::fromStdString(text));
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

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QComboBox(AS_QWIDGET_PTR(parent)));
    }

    HandleRef downcastFrom(Widget::HandleRef widget) {
        const auto combo = dynamic_cast<QComboBox*>(AS_QWIDGET_PTR(widget));
        return reinterpret_cast<HandleRef>(combo);
    }
}
