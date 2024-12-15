#include "generated/StyledItemDelegate.h"

#include <QStyledItemDelegate>
#include "util/SignalStuff.h"

#define THIS ((StyledItemDelegateWithHandler*)_this)

namespace StyledItemDelegate
{
    class StyledItemDelegateWithHandler : public QStyledItemDelegate {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // AbstractItemDelegate:
            { CloseEditor, SIGNAL(closeEditor(QWidget, EndEditHint)), SLOT(onCloseEditor(QWidget,EndEditHint)) },
            { CommitData, SIGNAL(commitData(QWidget)), SLOT(onCommitData(QWidget)) },
            { SizeHintChanged, SIGNAL(sizeHintChanged(QModelIndex)), SLOT(onSizeHintChanged(QModelIndex)) }
            // StyledItemDelegateWithHandler:
            // (none)
        };
    public:
        explicit StyledItemDelegateWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanged_OLD(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            handler->
                inherited_AbstractItemDelegate_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_AbstractItemDelegate_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // AbstractItemDelegate =================
        void onCloseEditor(QWidget *editor, QAbstractItemDelegate::EndEditHint hint = NoHint) const {
            handler->
                inherited_AbstractItemDelegate_SignalHandler()->
                    closeEditor(reinterpret_cast<Widget::HandleRef>(editor), static_cast<AbstractItemDelegate::EndEditHint>(hint));
        }
        void onCommitData(QWidget *editor) const {
            handler->
                inherited_AbstractItemDelegate_SignalHandler()->
                    commitData(reinterpret_cast<Widget::HandleRef>(editor));
        }
        void onSizeHintChanged(const QModelIndex &index) const {
            handler->
                inherited_AbstractItemDelegate_SignalHandler()->
                    sizeHintChanged((ModelIndex::HandleRef)&index);
        }
        // StyledItemDelegate ===================
        // (none)
    };

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    // subclass stuff ============================================

    class StyledItemDelegateSubclass : public StyledItemDelegateWithHandler {
    private:
        std::shared_ptr<MethodDelegate> methodDelegate;
        MethodMask methodMask;
    public:
        StyledItemDelegateSubclass(
                const std::shared_ptr<MethodDelegate> &methodDelegate,
                MethodMask methodMask,
                const std::shared_ptr<SignalHandler> &handler)
                : StyledItemDelegateWithHandler(handler),
                  methodDelegate(methodDelegate),
                  methodMask(methodMask) {}
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

    HandleRef createdSubclassed(const std::shared_ptr<MethodDelegate>& methodDelegate, MethodMask methodMask, const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new StyledItemDelegateSubclass(methodDelegate, methodMask, handler));
    }
}

#include "StyledItemDelegate.moc"
