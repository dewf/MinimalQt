#include "generated/StyledItemDelegate.h"
#include "StyledItemDelegateInternal.h"

#include "ModelIndexInternal.h"
#include "ObjectInternal.h"

using namespace ::Object;
using namespace ::AbstractItemDelegate;
using namespace ::Widget;
using namespace ::AbstractItemModel;
using namespace ::ModelIndex;
using namespace ::StyleOption;

#define THIS (reinterpret_cast<QStyledItemDelegate*>(_this))

namespace StyledItemDelegate
{
    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QStyledItemDelegate(AS_QOBJECT_PTR(parent)));
    }

    // subclass stuff ============================================

#define DELEGATED_THIS (reinterpret_cast<Delegated*>(_this))

    class Delegated : public QStyledItemDelegate {
        std::shared_ptr<DelegatedMethods> methods;
        Flags<MethodMask> mask;
    public:
        Delegated(QObject *parent, const std::shared_ptr<DelegatedMethods> &methods, Flags<MethodMask> mask)
            : QStyledItemDelegate(parent),
              methods(methods),
              mask(mask) {}
    protected:
        QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
            if (mask & MethodMask::CreateEditor) {
                QStyleOptionViewItem option2(option);
                QModelIndex index2(index);
                const auto result = methods->createEditor(reinterpret_cast<Widget::HandleRef>(parent), reinterpret_cast<StyleOption::ViewItem::HandleRef>(&option2), reinterpret_cast<ModelIndex::HandleRef>(&index2));
                return reinterpret_cast<QWidget *>(result);
            } else {
                return QStyledItemDelegate::createEditor(parent, option, index);
            }
        }

        void setEditorData(QWidget *editor, const QModelIndex &index) const override {
            if (mask & MethodMask::SetEditorData) {
                QModelIndex index2(index);
                methods->setEditorData(reinterpret_cast<Widget::HandleRef>(editor), reinterpret_cast<ModelIndex::HandleRef>(&index2));
            } else {
                QStyledItemDelegate::setEditorData(editor, index);
            }
        }

        void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
            if (mask & MethodMask::SetModelData) {
                QModelIndex index2(index);
                methods->setModelData(reinterpret_cast<Widget::HandleRef>(editor), reinterpret_cast<AbstractItemModel::HandleRef>(model), reinterpret_cast<ModelIndex::HandleRef>(&index2));
            } else {
                QStyledItemDelegate::setModelData(editor, model, index);
            }
        }

        void destroyEditor(QWidget *editor, const QModelIndex &index) const override {
            if (mask & MethodMask::DestroyEditor) {
                QModelIndex index2(index);
                methods->destroyEditor(reinterpret_cast<Widget::HandleRef>(editor), reinterpret_cast<ModelIndex::HandleRef>(&index2));
            } else {
                QStyledItemDelegate::destroyEditor(editor, index);
            }
        }

    public:
        void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
            if (mask & MethodMask::UpdateEditorGeometry) {
                QStyleOptionViewItem option2(option);
                QModelIndex index2(index);
                methods->updateEditorGeometry(reinterpret_cast<Widget::HandleRef>(editor), reinterpret_cast<StyleOption::ViewItem::HandleRef>(&option2), reinterpret_cast<ModelIndex::HandleRef>(&index2));
            } else {
                QStyledItemDelegate::updateEditorGeometry(editor, option, index);
            }
        }
    };

    void Delegated_dispose(DelegatedRef _this) {
        delete DELEGATED_THIS;
    }

    DelegatedRef createDelegated(const std::shared_ptr<DelegatedMethods>& methods, Flags<MethodMask> mask, Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<DelegatedRef>(new Delegated(AS_QOBJECT_PTR(parent), methods, mask));
    }
}
