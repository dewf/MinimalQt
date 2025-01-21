#include "generated/Completer.h"
#include "CompleterInternal.h"

#include "ModelIndexInternal.h"
#include "ObjectInternal.h"
#include "WidgetInternal.h"
#include "util/convert.h"

#define THIS (reinterpret_cast<QCompleter*>(_this))

namespace Completer
{
    CaseSensitivity Handle_caseSensitivity(HandleRef _this) {
        return static_cast<CaseSensitivity>(THIS->caseSensitivity());
    }

    int32_t Handle_completionColumn(HandleRef _this) {
        return THIS->completionColumn();
    }

    int32_t Handle_completionCount(HandleRef _this) {
        return THIS->completionCount();
    }

    CompletionMode Handle_getCompletionMode(HandleRef _this) {
        return static_cast<CompletionMode>(THIS->completionMode());
    }

    AbstractItemModel::HandleRef Handle_completionModel(HandleRef _this) {
        return reinterpret_cast<AbstractItemModel::HandleRef>(THIS->completionModel());
    }

    std::string Handle_completionPrefix(HandleRef _this) {
        return THIS->completionPrefix().toStdString();
    }

    int32_t Handle_completionRole(HandleRef _this) {
        return THIS->completionRole();
    }

    std::string Handle_currentCompletion(HandleRef _this) {
        return THIS->currentCompletion().toStdString();
    }

    ModelIndex::OwnedRef Handle_currentIndex(HandleRef _this) {
        return new ModelIndex::__Owned { THIS->currentIndex() };
    }

    int32_t Handle_currentRow(HandleRef _this) {
        return THIS->currentRow();
    }

    MatchFlags Handle_filterMode(HandleRef _this) {
        return static_cast<MatchFlags>(THIS->filterMode());
    }

    int32_t Handle_maxVisibleItems(HandleRef _this) {
        return THIS->maxVisibleItems();
    }

    AbstractItemModel::HandleRef Handle_model(HandleRef _this) {
        return reinterpret_cast<AbstractItemModel::HandleRef>(THIS->model());
    }

    ModelSorting Handle_getModelSorting(HandleRef _this) {
        return static_cast<ModelSorting>(THIS->modelSorting());
    }

    std::string Handle_pathFromIndex(HandleRef _this, ModelIndex::HandleRef index) {
        return THIS->pathFromIndex(index->value).toStdString();
    }

    AbstractItemView::HandleRef Handle_popup(HandleRef _this) {
        return reinterpret_cast<AbstractItemView::HandleRef>(THIS->popup());
    }

    void Handle_setCaseSensitivity(HandleRef _this, CaseSensitivity caseSensitivity) {
        return THIS->setCaseSensitivity(static_cast<Qt::CaseSensitivity>(caseSensitivity));
    }

    void Handle_setCompletionColumn(HandleRef _this, int32_t column) {
        THIS->setCompletionColumn(column);
    }

    void Handle_setCompletionMode(HandleRef _this, CompletionMode mode) {
        THIS->setCompletionMode(static_cast<QCompleter::CompletionMode>(mode));
    }

    void Handle_setCompletionRole(HandleRef _this, int32_t role) {
        THIS->setCompletionRole(role);
    }

    bool Handle_setCurrentRow(HandleRef _this, int32_t row) {
        return THIS->setCurrentRow(row);
    }

    void Handle_setFilterMode(HandleRef _this, MatchFlags filterMode) {
        THIS->setFilterMode(static_cast<Qt::MatchFlags>(filterMode.value));
    }

    void Handle_setMaxVisibleItems(HandleRef _this, int32_t maxItems) {
        THIS->setMaxVisibleItems(maxItems);
    }

    void Handle_setModel(HandleRef _this, AbstractItemModel::HandleRef model) {
        THIS->setModel(reinterpret_cast<QAbstractItemModel*>(model));
    }

    void Handle_setModelSorting(HandleRef _this, ModelSorting sorting) {
        THIS->setModelSorting(static_cast<QCompleter::ModelSorting>(sorting));
    }

    void Handle_setPopup(HandleRef _this, AbstractItemView::HandleRef popup) {
        THIS->setPopup(reinterpret_cast<QAbstractItemView*>(popup));
    }

    void Handle_setWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->setWidget(AS_QWIDGET_PTR(widget));
    }

    std::vector<std::string> Handle_splitPath(HandleRef _this, const std::string& path) {
        return toVectorStrings(THIS->splitPath(QString::fromStdString(path)));
    }

    Widget::HandleRef Handle_widget(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->widget());
    }

    bool Handle_wrapAround(HandleRef _this) {
        return THIS->wrapAround();
    }

    void Handle_complete(HandleRef _this, const std::optional<Rect>& rect) {
        QRect qRect;
        if (rect.has_value()) qRect = toQRect(rect.value());
        THIS->complete(qRect);
    }

    void Handle_setCompletionPrefix(HandleRef _this, const std::string& prefix) {
        THIS->setCompletionPrefix(QString::fromStdString(prefix));
    }

    void Handle_setWrapAround(HandleRef _this, bool wrap) {
        THIS->setWrapAround(wrap);
    }

    SignalConnectionRef Handle_connect_ActivatedIndex(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, qOverload<const QModelIndex&>(&QCompleter::activated), [handler](const QModelIndex &index) {
            ModelIndex::__Owned index2(index);
            handler->activatedIndex(&index2);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ActivatedString(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, qOverload<const QString&>(&QCompleter::activated), [handler](const QString& text) {
            handler->activatedString(text.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_HighlightedIndex(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, qOverload<const QModelIndex&>(&QCompleter::highlighted), [handler](const QModelIndex& index) {
            ModelIndex::__Owned index2(index);
            handler->highlightedIndex(&index2);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_HighlightedString(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, qOverload<const QString&>(&QCompleter::highlighted), [handler](const QString& text) {
            handler->highlightedString(text.toStdString());
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QCompleter(AS_QOBJECT_PTR(parent)));
    }

    HandleRef create(AbstractItemModel::HandleRef model, Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QCompleter(reinterpret_cast<QAbstractItemModel*>(model), AS_QOBJECT_PTR(parent)));
    }

    HandleRef create(const std::vector<std::string>& list, Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QCompleter(toQStringList(list), AS_QOBJECT_PTR(parent)));
    }
}
