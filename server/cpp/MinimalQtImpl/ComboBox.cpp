#include "generated/ComboBox.h"

#include <QObject>
#include <QComboBox>
#include <QStringList>

#include "util/SignalStuff.h"
#include "util/convert.h"
#include "VariantInternal.h"
#include "IconInternal.h"

#define THIS ((ComboBoxWithHandler*)_this)

namespace ComboBox
{
    class ComboBoxWithHandler : public QComboBox {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // Widget:
            { CustomContextMenuRequested, SIGNAL(customContextMenuRequested(QPoint)), SLOT(onCustomContextMenuRequested(QPoint)) },
            { WindowIconChanged, SIGNAL(windowIconChanged(QIcon)), SLOT(onWindowIconChanged(QIcon)) },
            { WindowTitleChanged, SIGNAL(windowTitleChanged(QString)), SLOT(onWindowTitleChanged(QString)) },
            // ComboBox:
            { Activated, SIGNAL(activated(int)), SLOT(onActivated(int)) },
            { CurrentIndexChanged, SIGNAL(currentIndexChanged(int)), SLOT(onCurrentIndexChanged(int)) },
            { CurrentTextChanged, SIGNAL(currentTextChanged(QString)), SLOT(onCurrentTextChanged(QString)) },
            { EditTextChanged, SIGNAL(editTextChanged(QString)), SLOT(onEditTextChanged(QString)) },
            { Highlighted, SIGNAL(highlighted(int)), SLOT(onHighlighted(int)) },
            { TextActivated, SIGNAL(textActivated(QString)), SLOT(onTextActivated(QString)) },
            { TextHighlighted, SIGNAL(textHighlighted(QString)), SLOT(onTextHighlighted(QString)) },
        };
    public:
        explicit ComboBoxWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            handler->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Widget ==================
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->
                inherited_Widget_SignalHandler()->
                    customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowIconChanged((Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowTitleChanged(title.toStdString());
        }
        // ComboBox ================
        void onActivated(int index) const {
            handler->activated(index);
        }
        void onCurrentIndexChanged(int index) const {
            handler->currentIndexChanged(index);
        }
        void onCurrentTextChanged(const QString& text) const {
            handler->currentTextChanged(text.toStdString());
        }
        void onEditTextChanged(const QString& text) const {
            handler->editTextChanged(text.toStdString());
        }
        void onHighlighted(int index) const {
            handler->highlighted(index);
        }
        void onTextActivated(const QString& text) const {
            handler->textActivated(text.toStdString());
        }
        void onTextHighlighted(const QString& text) const {
            handler->textHighlighted(text.toStdString());
        }
    };

    int32_t Handle_count(HandleRef _this) {
        return THIS->count();
    }

    Variant::OwnedRef Handle_currentData(HandleRef _this) {
        auto ret = THIS->currentData();
        return reinterpret_cast<Variant::OwnedRef>(new QVariant(ret));
    }

    Variant::OwnedRef Handle_currentData(HandleRef _this, ItemDataRole role) {
        auto ret = THIS->currentData(static_cast<Qt::ItemDataRole>(role));
        return reinterpret_cast<Variant::OwnedRef>(new QVariant(ret));
    }

    int32_t Handle_currentIndex(HandleRef _this) {
        return THIS->currentIndex();
    }

    void Handle_setCurrentIndex(HandleRef _this, int32_t index) {
        THIS->setCurrentIndex(index);
    }

    void Handle_setCurrentText(HandleRef _this, const std::string& text) {
        THIS->setCurrentText(QString::fromStdString(text));
    }

    void Handle_setDuplicatesEnabled(HandleRef _this, bool enabled) {
        THIS->setDuplicatesEnabled(enabled);
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

    void Handle_setMaxCount(HandleRef _this, int32_t count) {
        THIS->setMaxCount(count);
    }

    void Handle_setMaxVisibleItems(HandleRef _this, int32_t count) {
        THIS->setMaxVisibleItems(count);
    }

    void Handle_setMinimumContentsLength(HandleRef _this, int32_t length) {
        THIS->setMinimumContentsLength(length);
    }

    void Handle_setModelColumn(HandleRef _this, int32_t column) {
        THIS->setModelColumn(column);
    }

    void Handle_setPlaceholderText(HandleRef _this, const std::string& text) {
        THIS->setPlaceholderText(QString::fromStdString(text));
    }

    void Handle_setSizeAdjustPolicy(HandleRef _this, SizeAdjustPolicy policy) {
        THIS->setSizeAdjustPolicy(static_cast<QComboBox::SizeAdjustPolicy>(policy));
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_addItem(HandleRef _this, const std::string& text, const std::shared_ptr<Variant::Deferred::Base>& userData) {
        THIS->addItem(QString::fromStdString(text), fromDeferred(userData));
    }

    void Handle_addItem(HandleRef _this, Icon::HandleRef icon, const std::string& text, const std::shared_ptr<Variant::Deferred::Base>& userData) {
        THIS->addItem(ICON_VALUE(icon), QString::fromStdString(text), fromDeferred(userData));
    }

    void Handle_addItems(HandleRef _this, const std::vector<std::string>& texts) {
        THIS->addItems(toQStringList(texts));
    }

    void Handle_setModel(HandleRef _this, AbstractItemModel::HandleRef model) {
        THIS->setModel(reinterpret_cast<QAbstractItemModel *>(model));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new ComboBoxWithHandler(handler));
    }

    HandleRef downcastFrom(Widget::HandleRef widget) {
        return reinterpret_cast<HandleRef>(widget);
    }
}

#include "ComboBox.moc"
