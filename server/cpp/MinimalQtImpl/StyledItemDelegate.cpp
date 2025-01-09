#include "generated/StyledItemDelegate.h"
#include "StyledItemDelegateInternal.h"

#define THIS (reinterpret_cast<QStyledItemDelegate*>(_this))

namespace StyledItemDelegate
{
    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    // subclass stuff ============================================

#define DELEGATED_THIS (reinterpret_cast<Delegated>(_this))

    class Delegated : public QStyledItemDelegate {
    private:
        std::shared_ptr<MethodDelegate> methodDelegate;
        MethodMask methodMask;
    public:
        Delegated(const std::shared_ptr<MethodDelegate> &methodDelegate, MethodMask methodMask)
            : methodDelegate(methodDelegate), methodMask(methodMask) {}
    protected:
        QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
            if (methodMask & CreateEditor) {
                return reinterpret_cast<QWidget *>(
                    methodDelegate->createEditor(
                        reinterpret_cast<Widget::HandleRef>(parent),
                        (StyleOptionViewItem::HandleRef) &option,
                        (ModelIndex::HandleRef) &index));
            } else {
                return QStyledItemDelegate::createEditor(parent, option, index);
            }
        }

        void setEditorData(QWidget *editor, const QModelIndex &index) const override {
            if (methodMask & SetEditorData) {
                methodDelegate->setEditorData(reinterpret_cast<Widget::HandleRef>(editor), (ModelIndex::HandleRef)&index);
            } else {
                QStyledItemDelegate::setEditorData(editor, index);
            }
        }

        void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
            if (methodMask & SetModelData) {
                methodDelegate->setModelData(reinterpret_cast<Widget::HandleRef>(editor), reinterpret_cast<AbstractItemModel::HandleRef>(model), (ModelIndex::HandleRef)&index);
            } else {
                QStyledItemDelegate::setModelData(editor, model, index);
            }
        }

        void destroyEditor(QWidget *editor, const QModelIndex &index) const override {
            if (methodMask & DestroyEditor) {
                methodDelegate->destroyEditor(reinterpret_cast<Widget::HandleRef>(editor), (ModelIndex::HandleRef)&index);
            } else {
                QStyledItemDelegate::destroyEditor(editor, index);
            }
        }
    };

    // note the return type, it's not a DelegatedRef or anything (which we don't have yet)
    // don't remember what this was all about, will look into it later
    HandleRef createdSubclassed(const std::shared_ptr<MethodDelegate>& methodDelegate, MethodMask methodMask) {
        return reinterpret_cast<HandleRef>(new Delegated(methodDelegate, methodMask));
    }
}
