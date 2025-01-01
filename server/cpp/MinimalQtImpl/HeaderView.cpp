#include "generated/HeaderView.h"
#include "HeaderViewInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define HEADERVIEW_THIS (WRAPPER->getActual())

namespace HeaderView
{
    bool Handle_cascadingSectionResizes(HandleRef _this) {
        return HEADERVIEW_THIS->cascadingSectionResizes();
    }

    void Handle_setCascadingSectionResizes(HandleRef _this, bool enable) {
        HEADERVIEW_THIS->setCascadingSectionResizes(enable);
    }

    Alignment Handle_defaultAlignment(HandleRef _this) {
        return HEADERVIEW_THIS->defaultAlignment();
    }

    void Handle_setDefaultAlignment(HandleRef _this, Alignment align) {
        HEADERVIEW_THIS->setDefaultAlignment(static_cast<Qt::Alignment>(align));
    }

    int32_t Handle_defaultSectionSize(HandleRef _this) {
        return HEADERVIEW_THIS->defaultSectionSize();
    }

    void Handle_setDefaultSectionSize(HandleRef _this, int32_t size) {
        HEADERVIEW_THIS->setDefaultSectionSize(size);
    }

    void Handle_resetDefaultSectionSize(HandleRef _this) {
        HEADERVIEW_THIS->resetDefaultSectionSize();
    }

    bool Handle_isFirstSectionMovable(HandleRef _this) {
        return HEADERVIEW_THIS->isFirstSectionMovable();
    }

    void Handle_setFirstSectionMovable(HandleRef _this, bool movable) {
        HEADERVIEW_THIS->setFirstSectionMovable(movable);
    }

    bool Handle_highlightSections(HandleRef _this) {
        return HEADERVIEW_THIS->highlightSections();
    }

    void Handle_setHighlightSections(HandleRef _this, bool highlight) {
        HEADERVIEW_THIS->setHighlightSections(highlight);
    }

    int32_t Handle_maximumSectionSize(HandleRef _this) {
        return HEADERVIEW_THIS->maximumSectionSize();
    }

    void Handle_setMaximumSectionSize(HandleRef _this, int32_t size) {
        HEADERVIEW_THIS->setMaximumSectionSize(size);
    }

    int32_t Handle_minimumSectionSize(HandleRef _this) {
        return HEADERVIEW_THIS->minimumSectionSize();
    }

    void Handle_setMinimumSectionSize(HandleRef _this, int32_t size) {
        HEADERVIEW_THIS->setMinimumSectionSize(size);
    }

    bool Handle_sectionsClickable(HandleRef _this) {
        return HEADERVIEW_THIS->sectionsClickable();
    }

    void Handle_setSectionsClickable(HandleRef _this, bool clickable) {
        HEADERVIEW_THIS->setSectionsClickable(clickable);
    }

    bool Handle_sectionsMovable(HandleRef _this) {
        return HEADERVIEW_THIS->sectionsMovable();
    }

    void Handle_setSectionsMovable(HandleRef _this, bool movable) {
        return HEADERVIEW_THIS->setSectionsMovable(movable);
    }

    bool Handle_isSortIndicatorShown(HandleRef _this) {
        return HEADERVIEW_THIS->isSortIndicatorShown();
    }

    void Handle_setSortIndicatorShown(HandleRef _this, bool show) {
        HEADERVIEW_THIS->setSortIndicatorShown(show);
    }

    bool Handle_isSortIndicatorClearable(HandleRef _this) {
        return HEADERVIEW_THIS->isSortIndicatorClearable();
    }

    void Handle_setSortIndicatorClearable(HandleRef _this, bool clearable) {
        HEADERVIEW_THIS->setSortIndicatorClearable(clearable);
    }

    bool Handle_stretchLastSection(HandleRef _this) {
        return HEADERVIEW_THIS->stretchLastSection();
    }

    void Handle_setStretchLastSection(HandleRef _this, bool stretch) {
        HEADERVIEW_THIS->setStretchLastSection(stretch);
    }

    void Handle_resizeSection(HandleRef _this, int32_t logicalIndex, int32_t size) {
        HEADERVIEW_THIS->resizeSection(logicalIndex, size);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(Orientation orientation, const std::shared_ptr<SignalHandler>& handler) {
        const auto header = new QHeaderView(static_cast<Qt::Orientation>(orientation));
        const auto wrapper = new SignalWrapper(header, handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
