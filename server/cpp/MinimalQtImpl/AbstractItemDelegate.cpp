#include "generated/AbstractItemDelegate.h"

#include <QAbstractItemDelegate>

#include "ObjectInternal.h"
#include "ModelIndexInternal.h"

#define THIS (reinterpret_cast<QAbstractItemDelegate*>(_this))

namespace AbstractItemDelegate
{
    SignalConnectionRef Handle_connect_CloseEditor(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemDelegate::closeEditor, [handler](QWidget *editor, QAbstractItemDelegate::EndEditHint hint) {
            handler->closeEditor(reinterpret_cast<Widget::HandleRef>(editor), static_cast<AbstractItemDelegate::EndEditHint>(hint));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CommitData(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemDelegate::commitData, [handler](QWidget *editor) {
            handler->commitData(reinterpret_cast<Widget::HandleRef>(editor));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SizeHintChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemDelegate::sizeHintChanged, [handler](const QModelIndex &index) {
            ModelIndex::__Handle index2(index); // until we fix this with proxies or whatever we decide ...
            handler->sizeHintChanged(&index2);
        });
        return new __SignalConnection { connection };
    }
}
