#include "generated/HeaderView.h"
#include "HeaderViewInternal.h"

#include "ObjectInternal.h"
#include "PointInternal.h"
#include "WidgetInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::AbstractItemView;
using namespace ::Enums;
using namespace ::Widget;
using namespace ::Point;

#define THIS (reinterpret_cast<QHeaderView*>(_this))

namespace HeaderView
{
    bool Handle_cascadingSectionResizes(HandleRef _this) {
        return THIS->cascadingSectionResizes();
    }

    int32_t Handle_count(HandleRef _this) {
        return THIS->count();
    }

    Flags<Alignment> Handle_defaultAlignment(HandleRef _this) {
        return static_cast<Flags<Alignment>>(THIS->defaultAlignment());
    }

    int32_t Handle_defaultSectionSize(HandleRef _this) {
        return THIS->defaultSectionSize();
    }

    int32_t Handle_hiddenSectionCount(HandleRef _this) {
        return THIS->hiddenSectionCount();
    }

    void Handle_hideSection(HandleRef _this, int32_t logicalIndex) {
        THIS->hideSection(logicalIndex);
    }

    bool Handle_highlightSections(HandleRef _this) {
        return THIS->highlightSections();
    }

    bool Handle_isFirstSectionMovable(HandleRef _this) {
        return THIS->isFirstSectionMovable();
    }

    bool Handle_isSectionHidden(HandleRef _this, int32_t logicalIndex) {
        return THIS->isSectionHidden(logicalIndex);
    }

    bool Handle_isSortIndicatorClearable(HandleRef _this) {
        return THIS->isSortIndicatorClearable();
    }

    bool Handle_isSortIndicatorShown(HandleRef _this) {
        return THIS->isSortIndicatorShown();
    }

    int32_t Handle_length(HandleRef _this) {
        return THIS->length();
    }

    int32_t Handle_logicalIndex(HandleRef _this, int32_t visualIndex) {
        return THIS->logicalIndex(visualIndex);
    }

    int32_t Handle_logicalIndexAt(HandleRef _this, Point::HandleRef pos) {
        return THIS->logicalIndexAt(QPOINT_VALUE(pos));
    }

    int32_t Handle_logicalIndexAt(HandleRef _this, int32_t position) {
        return THIS->logicalIndexAt(position);
    }

    int32_t Handle_logicalIndexAt(HandleRef _this, int32_t x, int32_t y) {
        return THIS->logicalIndexAt(x, y);
    }

    int32_t Handle_maximumSectionSize(HandleRef _this) {
        return THIS->maximumSectionSize();
    }

    int32_t Handle_minimumSectionSize(HandleRef _this) {
        return THIS->minimumSectionSize();
    }

    void Handle_moveSection(HandleRef _this, int32_t from, int32_t to) {
        THIS->moveSection(from, to);
    }

    int32_t Handle_offset(HandleRef _this) {
        return THIS->offset();
    }

    Orientation Handle_orientation(HandleRef _this) {
        return static_cast<Orientation>(THIS->orientation());
    }

    void Handle_resetDefaultSectionSize(HandleRef _this) {
        THIS->resetDefaultSectionSize();
    }

    int32_t Handle_resizeContentsPrecision(HandleRef _this) {
        return THIS->resizeContentsPrecision();
    }

    void Handle_resizeSection(HandleRef _this, int32_t logicalIndex, int32_t size) {
        THIS->resizeSection(logicalIndex, size);
    }

    void Handle_resizeSections(HandleRef _this, ResizeMode mode) {
        THIS->resizeSections(static_cast<QHeaderView::ResizeMode>(mode));
    }

    bool Handle_restoreState(HandleRef _this, const std::vector<uint8_t>& state) {
        return THIS->restoreState(toQByteArray(state));
    }

    std::vector<uint8_t> Handle_saveState(HandleRef _this) {
        return fromQByteArray(THIS->saveState());
    }

    int32_t Handle_sectionPosition(HandleRef _this, int32_t logicalIndex) {
        return THIS->sectionPosition(logicalIndex);
    }

    ResizeMode Handle_sectionResizeMode(HandleRef _this, int32_t logicalIndex) {
        return static_cast<ResizeMode>(logicalIndex);
    }

    int32_t Handle_sectionSize(HandleRef _this, int32_t logicalIndex) {
        return THIS->sectionSize(logicalIndex);
    }

    int32_t Handle_sectionSizeHint(HandleRef _this, int32_t logicalIndex) {
        return THIS->sectionSizeHint(logicalIndex);
    }

    int32_t Handle_sectionViewportPosition(HandleRef _this, int32_t logicalIndex) {
        return THIS->sectionViewportPosition(logicalIndex);
    }

    bool Handle_sectionsClickable(HandleRef _this) {
        return THIS->sectionsClickable();
    }

    bool Handle_sectionsHidden(HandleRef _this) {
        return THIS->sectionsHidden();
    }

    bool Handle_sectionsMovable(HandleRef _this) {
        return THIS->sectionsMovable();
    }

    bool Handle_sectionsMoved(HandleRef _this) {
        return THIS->sectionsMoved();
    }

    void Handle_setCascadingSectionResizes(HandleRef _this, bool enable) {
        THIS->setCascadingSectionResizes(enable);
    }

    void Handle_setDefaultAlignment(HandleRef _this, Flags<Alignment> align) {
        THIS->setDefaultAlignment(static_cast<Qt::Alignment>(align.value()));
    }

    void Handle_setDefaultSectionSize(HandleRef _this, int32_t size) {
        THIS->setDefaultSectionSize(size);
    }

    void Handle_setFirstSectionMovable(HandleRef _this, bool movable) {
        THIS->setFirstSectionMovable(movable);
    }

    void Handle_setHighlightSections(HandleRef _this, bool highlight) {
        THIS->setHighlightSections(highlight);
    }

    void Handle_setMaximumSectionSize(HandleRef _this, int32_t size) {
        THIS->setMaximumSectionSize(size);
    }

    void Handle_setMinimumSectionSize(HandleRef _this, int32_t size) {
        THIS->setMinimumSectionSize(size);
    }

    void Handle_setResizeContentsPrecision(HandleRef _this, int32_t precision) {
        THIS->setResizeContentsPrecision(precision);
    }

    void Handle_setSectionHidden(HandleRef _this, int32_t logicalIndex, bool hide) {
        THIS->setSectionHidden(logicalIndex, hide);
    }

    void Handle_setSectionResizeMode(HandleRef _this, ResizeMode mode) {
        THIS->setSectionResizeMode(static_cast<QHeaderView::ResizeMode>(mode));
    }

    void Handle_setSectionResizeMode(HandleRef _this, int32_t logicalIndex, ResizeMode mode) {
        THIS->setSectionResizeMode(logicalIndex, static_cast<QHeaderView::ResizeMode>(mode));
    }

    void Handle_setSectionsClickable(HandleRef _this, bool clickable) {
        THIS->setSectionsClickable(clickable);
    }

    void Handle_setSectionsMovable(HandleRef _this, bool movable) {
        return THIS->setSectionsMovable(movable);
    }

    void Handle_setSortIndicator(HandleRef _this, int32_t logicalIndex, SortOrder order) {
        THIS->setSortIndicator(logicalIndex, static_cast<Qt::SortOrder>(order));
    }

    void Handle_setSortIndicatorClearable(HandleRef _this, bool clearable) {
        THIS->setSortIndicatorClearable(clearable);
    }

    void Handle_setSortIndicatorShown(HandleRef _this, bool show) {
        THIS->setSortIndicatorShown(show);
    }

    void Handle_setStretchLastSection(HandleRef _this, bool stretch) {
        THIS->setStretchLastSection(stretch);
    }

    void Handle_showSection(HandleRef _this, int32_t logicalIndex) {
        THIS->showSection(logicalIndex);
    }

    SortOrder Handle_sortIndicatorOrder(HandleRef _this) {
        return static_cast<SortOrder>(THIS->sortIndicatorOrder());
    }

    int32_t Handle_sortIndicatorSection(HandleRef _this) {
        return THIS->sortIndicatorSection();
    }

    bool Handle_stretchLastSection(HandleRef _this) {
        return THIS->stretchLastSection();
    }

    int32_t Handle_stretchSectionCount(HandleRef _this) {
        return THIS->stretchSectionCount();
    }

    void Handle_swapSections(HandleRef _this, int32_t first, int32_t second) {
        THIS->swapSections(first, second);
    }

    int32_t Handle_visualIndex(HandleRef _this, int32_t logicalIndex) {
        return THIS->visualIndex(logicalIndex);
    }

    int32_t Handle_visualIndexAt(HandleRef _this, int32_t position) {
        return THIS->visualIndexAt(position);
    }

    void Handle_headerDataChanged(HandleRef _this, Orientation orientation, int32_t logicalFirst, int32_t logicalLast) {
        THIS->headerDataChanged(static_cast<Qt::Orientation>(orientation), logicalFirst, logicalLast);
    }

    void Handle_setOffset(HandleRef _this, int32_t offset) {
        THIS->setOffset(offset);
    }

    void Handle_setOffsetToLastSection(HandleRef _this) {
        THIS->setOffsetToLastSection();
    }

    void Handle_setOffsetToSectionPosition(HandleRef _this, int32_t visualSectionNumber) {
        THIS->setOffsetToSectionPosition(visualSectionNumber);
    }

    SignalConnectionRef Handle_connect_GeometriesChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::geometriesChanged, [handler] {
            handler->sig_geometriesChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionClicked, [handler](int logicalIndex) {
            handler->sig_sectionClicked(logicalIndex);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionCountChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionCountChanged, [handler](int oldCount, int newCount) {
            handler->sig_sectionCountChanged(oldCount, newCount);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionDoubleClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionDoubleClicked, [handler](int logicalIndex) {
            handler->sig_sectionDoubleClicked(logicalIndex);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionEntered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionEntered, [handler](int logicalIndex) {
            handler->sig_sectionEntered(logicalIndex);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionHandleDoubleClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionHandleDoubleClicked, [handler](int logicalIndex) {
            handler->sig_sectionHandleDoubleClicked(logicalIndex);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionMoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionMoved, [handler](int logicalIndex, int oldVisualIndex, int newVisualIndex) {
            handler->sig_sectionMoved(logicalIndex, oldVisualIndex, newVisualIndex);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionPressed(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionPressed, [handler](int logicalIndex) {
            handler->sig_sectionPressed(logicalIndex);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionResized(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionResized, [handler](int logicalIndex, int oldSize, int newSize) {
            handler->sig_sectionResized(logicalIndex, oldSize, newSize);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SortIndicatorChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sortIndicatorChanged, [handler](int logicalIndex, Qt::SortOrder order) {
            handler->sig_sortIndicatorChanged(logicalIndex, static_cast<SortOrder>(order));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SortIndicatorClearableChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sortIndicatorClearableChanged, [handler](bool clearable) {
            handler->sig_sortIndicatorClearableChanged(clearable);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto header = AS_QHEADERVIEW_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(header);
        case Handle_CastTarget::Widget_Handle:
            return static_cast<QWidget*>(header);
        case Handle_CastTarget::Frame_Handle:
            return static_cast<QFrame*>(header);
        case Handle_CastTarget::AbstractScrollArea_Handle:
            return static_cast<QAbstractScrollArea*>(header);
        case Handle_CastTarget::AbstractItemView_Handle:
            return static_cast<QAbstractItemView*>(header);
        }
        std::unreachable();
    }

    HandleRef create(Orientation orientation, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QHeaderView(static_cast<Qt::Orientation>(orientation), AS_QWIDGET_PTR(parent)));
    }
}
