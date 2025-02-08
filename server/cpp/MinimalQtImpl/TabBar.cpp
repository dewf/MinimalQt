#include "generated/TabBar.h"
#include "TabBarInternal.h"

#include "ColorInternal.h"
#include "ObjectInternal.h"
#include "IconInternal.h"
#include "PointInternal.h"
#include "VariantInternal.h"
#include "WidgetInternal.h"
#include "SizeInternal.h"
#include "RectInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Common;
using namespace ::Size;
using namespace ::Point;
using namespace ::Rect;
using namespace ::Icon;
using namespace ::Widget;
using namespace ::Enums;
using namespace ::Variant;
using namespace ::Color;

#define THIS (reinterpret_cast<QTabBar*>(_this))

namespace TabBar
{
    std::string Handle_accessibleTabName(HandleRef _this, int32_t index) {
        return THIS->accessibleTabName(index).toStdString();
    }

    int32_t Handle_addTab(HandleRef _this, const std::string& text) {
        return THIS->addTab(QString::fromStdString(text));
    }

    int32_t Handle_addTab(HandleRef _this, Icon::HandleRef icon, const std::string& text) {
        return THIS->addTab(QICON_VALUE(icon), QString::fromStdString(text));
    }

    bool Handle_autoHide(HandleRef _this) {
        return THIS->autoHide();
    }

    bool Handle_changeCurrentOnDrag(HandleRef _this) {
        return THIS->changeCurrentOnDrag();
    }

    int32_t Handle_count(HandleRef _this) {
        return THIS->count();
    }

    int32_t Handle_currentIndex(HandleRef _this) {
        return THIS->currentIndex();
    }

    bool Handle_documentMode(HandleRef _this) {
        return THIS->documentMode();
    }

    bool Handle_drawBase(HandleRef _this) {
        return THIS->drawBase();
    }

    TextElideMode Handle_elideMode(HandleRef _this) {
        return static_cast<TextElideMode>(THIS->elideMode());
    }

    bool Handle_expanding(HandleRef _this) {
        return THIS->expanding();
    }

    Size::OwnedRef Handle_iconSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->iconSize());
    }

    int32_t Handle_insertTab(HandleRef _this, int32_t index, const std::string& text) {
        return THIS->insertTab(index, QString::fromStdString(text));
    }

    int32_t Handle_insertTab(HandleRef _this, int32_t index, Icon::HandleRef icon, const std::string& text) {
        return THIS->insertTab(index, QICON_VALUE(icon), QString::fromStdString(text));
    }

    bool Handle_isMovable(HandleRef _this) {
        return THIS->isMovable();
    }

    bool Handle_isTabEnabled(HandleRef _this, int32_t index) {
        return THIS->isTabEnabled(index);
    }

    bool Handle_isTabVisible(HandleRef _this, int32_t index) {
        return THIS->isTabVisible(index);
    }

    void Handle_moveTab(HandleRef _this, int32_t from, int32_t to) {
        return THIS->moveTab(from, to);
    }

    void Handle_removeTab(HandleRef _this, int32_t index) {
        return THIS->removeTab(index);
    }

    SelectionBehavior Handle_selectionBehaviorOnRemove(HandleRef _this) {
        return static_cast<SelectionBehavior>(THIS->selectionBehaviorOnRemove());
    }

    void Handle_setAccessibleTabName(HandleRef _this, int32_t index, const std::string& name) {
        THIS->setAccessibleTabName(index, QString::fromStdString(name));
    }

    void Handle_setAutoHide(HandleRef _this, bool value) {
        THIS->setAutoHide(value);
    }

    void Handle_setChangeCurrentOnDrag(HandleRef _this, bool value) {
        THIS->setChangeCurrentOnDrag(value);
    }

    void Handle_setDocumentMode(HandleRef _this, bool value) {
        THIS->setDocumentMode(value);
    }

    void Handle_setDrawBase(HandleRef _this, bool value) {
        THIS->setDrawBase(value);
    }

    void Handle_setElideMode(HandleRef _this, TextElideMode mode) {
        THIS->setElideMode(static_cast<Qt::TextElideMode>(mode));
    }

    void Handle_setExpanding(HandleRef _this, bool value) {
        THIS->setExpanding(value);
    }

    void Handle_setIconSize(HandleRef _this, Size::HandleRef size) {
        THIS->setIconSize(QSIZE_VALUE(size));
    }

    void Handle_setMovable(HandleRef _this, bool value) {
        THIS->setMovable(value);
    }

    void Handle_setSelectionBehaviorOnRemove(HandleRef _this, SelectionBehavior value) {
        THIS->setSelectionBehaviorOnRemove(static_cast<QTabBar::SelectionBehavior>(value));
    }

    void Handle_setShape(HandleRef _this, Shape shape) {
        THIS->setShape(static_cast<QTabBar::Shape>(shape));
    }

    void Handle_setTabButton(HandleRef _this, int32_t index, ButtonPosition position, Widget::HandleRef widget) {
        THIS->setTabButton(index, static_cast<QTabBar::ButtonPosition>(position), AS_QWIDGET_PTR(widget));
    }

    void Handle_setTabData(HandleRef _this, int32_t index, Variant::HandleRef data) {
        THIS->setTabData(index, QVARIANT_VALUE(data));
    }

    void Handle_setTabEnabled(HandleRef _this, int32_t index, bool enabled) {
        THIS->setTabEnabled(index, enabled);
    }

    void Handle_setTabIcon(HandleRef _this, int32_t index, Icon::HandleRef icon) {
        THIS->setTabIcon(index, QICON_VALUE(icon));
    }

    void Handle_setTabText(HandleRef _this, int32_t index, const std::string& text) {
        THIS->setTabText(index, QString::fromStdString(text));
    }

    void Handle_setTabTextColor(HandleRef _this, int32_t index, Color::HandleRef color) {
        THIS->setTabTextColor(index, QCOLOR_VALUE(color));
    }

    void Handle_setTabToolTip(HandleRef _this, int32_t index, const std::string& tip) {
        THIS->setTabToolTip(index, QString::fromStdString(tip));
    }

    void Handle_setTabVisible(HandleRef _this, int32_t index, bool visible) {
        THIS->setTabVisible(index, visible);
    }

    void Handle_setTabWhatsThis(HandleRef _this, int32_t index, const std::string& text) {
        THIS->setTabWhatsThis(index, QString::fromStdString(text));
    }

    void Handle_setTabsClosable(HandleRef _this, bool value) {
        THIS->setTabsClosable(value);
    }

    void Handle_setUsesScrollButtons(HandleRef _this, bool value) {
        THIS->setUsesScrollButtons(value);
    }

    Shape Handle_getShape(HandleRef _this) {
        return static_cast<Shape>(THIS->shape());
    }

    int32_t Handle_tabAt(HandleRef _this, Point::HandleRef position) {
        return THIS->tabAt(QPOINT_VALUE(position));
    }

    Widget::HandleRef Handle_tabButton(HandleRef _this, int32_t index, ButtonPosition position) {
        return reinterpret_cast<Widget::HandleRef>(THIS->tabButton(index, static_cast<QTabBar::ButtonPosition>(position)));
    }

    Variant::OwnedRef Handle_tabData(HandleRef _this, int32_t index) {
        return VARIANT_HEAP_NEW(THIS->tabData(index));
    }

    Icon::OwnedRef Handle_tabIcon(HandleRef _this, int32_t index) {
        return ICON_HEAP_NEW(THIS->tabIcon(index));
    }

    Rect::OwnedRef Handle_tabRect(HandleRef _this, int32_t index) {
        return RECT_HEAP_NEW(THIS->tabRect(index));
    }

    std::string Handle_tabText(HandleRef _this, int32_t index) {
        return THIS->tabText(index).toStdString();
    }

    Color::OwnedRef Handle_tabTextColor(HandleRef _this, int32_t index) {
        return COLOR_HEAP_NEW(THIS->tabTextColor(index));
    }

    std::string Handle_tabToolTip(HandleRef _this, int32_t index) {
        return THIS->tabToolTip(index).toStdString();
    }

    std::string Handle_tabWhatsThis(HandleRef _this, int32_t index) {
        return THIS->tabWhatsThis(index).toStdString();
    }

    bool Handle_tabsClosable(HandleRef _this) {
        return THIS->tabsClosable();
    }

    bool Handle_usesScrollButtons(HandleRef _this) {
        return THIS->usesScrollButtons();
    }

    void Handle_setCurrentIndex(HandleRef _this, int32_t value) {
        THIS->setCurrentIndex(value);
    }

    SignalConnectionRef Handle_connect_CurrentChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTabBar::currentChanged, [handler](int index) {
            handler->currentChanged(index);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TabBarClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTabBar::tabBarClicked, [handler](int index) {
            handler->tabBarClicked(index);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TabBarDoubleClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTabBar::tabBarDoubleClicked, [handler](int index) {
            handler->tabBarDoubleClicked(index);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TabCloseRequested(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTabBar::tabCloseRequested, [handler](int index) {
            handler->tabCloseRequested(index);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TabMoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTabBar::tabMoved, [handler](int fromIndex, int toIndex) {
            handler->tabMoved(fromIndex, toIndex);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QTabBar(AS_QWIDGET_PTR(parent)));
    }
}
