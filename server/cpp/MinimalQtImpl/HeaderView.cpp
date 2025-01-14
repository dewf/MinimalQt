#include "generated/HeaderView.h"
#include "HeaderViewInternal.h"

#include "ObjectInternal.h"

#define THIS (reinterpret_cast<QHeaderView*>(_this))

namespace HeaderView
{
    bool Handle_cascadingSectionResizes(HandleRef _this) {
        return THIS->cascadingSectionResizes();
    }

    void Handle_setCascadingSectionResizes(HandleRef _this, bool enable) {
        THIS->setCascadingSectionResizes(enable);
    }

    Alignment Handle_defaultAlignment(HandleRef _this) {
        return Alignment(THIS->defaultAlignment());
    }

    void Handle_setDefaultAlignment(HandleRef _this, Alignment align) {
        THIS->setDefaultAlignment(static_cast<Qt::Alignment>(align.value));
    }

    int32_t Handle_defaultSectionSize(HandleRef _this) {
        return THIS->defaultSectionSize();
    }

    void Handle_setDefaultSectionSize(HandleRef _this, int32_t size) {
        THIS->setDefaultSectionSize(size);
    }

    void Handle_resetDefaultSectionSize(HandleRef _this) {
        THIS->resetDefaultSectionSize();
    }

    bool Handle_isFirstSectionMovable(HandleRef _this) {
        return THIS->isFirstSectionMovable();
    }

    void Handle_setFirstSectionMovable(HandleRef _this, bool movable) {
        THIS->setFirstSectionMovable(movable);
    }

    bool Handle_highlightSections(HandleRef _this) {
        return THIS->highlightSections();
    }

    void Handle_setHighlightSections(HandleRef _this, bool highlight) {
        THIS->setHighlightSections(highlight);
    }

    int32_t Handle_maximumSectionSize(HandleRef _this) {
        return THIS->maximumSectionSize();
    }

    void Handle_setMaximumSectionSize(HandleRef _this, int32_t size) {
        THIS->setMaximumSectionSize(size);
    }

    int32_t Handle_minimumSectionSize(HandleRef _this) {
        return THIS->minimumSectionSize();
    }

    void Handle_setMinimumSectionSize(HandleRef _this, int32_t size) {
        THIS->setMinimumSectionSize(size);
    }

    bool Handle_sectionsClickable(HandleRef _this) {
        return THIS->sectionsClickable();
    }

    void Handle_setSectionsClickable(HandleRef _this, bool clickable) {
        THIS->setSectionsClickable(clickable);
    }

    bool Handle_sectionsMovable(HandleRef _this) {
        return THIS->sectionsMovable();
    }

    void Handle_setSectionsMovable(HandleRef _this, bool movable) {
        return THIS->setSectionsMovable(movable);
    }

    bool Handle_isSortIndicatorShown(HandleRef _this) {
        return THIS->isSortIndicatorShown();
    }

    void Handle_setSortIndicatorShown(HandleRef _this, bool show) {
        THIS->setSortIndicatorShown(show);
    }

    bool Handle_isSortIndicatorClearable(HandleRef _this) {
        return THIS->isSortIndicatorClearable();
    }

    void Handle_setSortIndicatorClearable(HandleRef _this, bool clearable) {
        THIS->setSortIndicatorClearable(clearable);
    }

    bool Handle_stretchLastSection(HandleRef _this) {
        return THIS->stretchLastSection();
    }

    void Handle_setStretchLastSection(HandleRef _this, bool stretch) {
        THIS->setStretchLastSection(stretch);
    }

    void Handle_resizeSection(HandleRef _this, int32_t logicalIndex, int32_t size) {
        THIS->resizeSection(logicalIndex, size);
    }

    SignalConnectionRef Handle_connect_GeometriesChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::geometriesChanged, [handler] {
            handler->geometriesChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionClicked, [handler](int logicalIndex) {
            handler->sectionClicked(logicalIndex);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionCountChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionCountChanged, [handler](int oldCount, int newCount) {
            handler->sectionCountChanged(oldCount, newCount);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionDoubleClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionDoubleClicked, [handler](int logicalIndex) {
            handler->sectionDoubleClicked(logicalIndex);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionEntered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionEntered, [handler](int logicalIndex) {
            handler->sectionEntered(logicalIndex);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionHandleDoubleClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionHandleDoubleClicked, [handler](int logicalIndex) {
            handler->sectionHandleDoubleClicked(logicalIndex);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionMoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionMoved, [handler](int logicalIndex, int oldVisualIndex, int newVisualIndex) {
            handler->sectionMoved(logicalIndex, oldVisualIndex, newVisualIndex);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionPressed(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionPressed, [handler](int logicalIndex) {
            handler->sectionPressed(logicalIndex);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SectionResized(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sectionResized, [handler](int logicalIndex, int oldSize, int newSize) {
            handler->sectionResized(logicalIndex, oldSize, newSize);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SortIndicatorChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sortIndicatorChanged, [handler](int logicalIndex, Qt::SortOrder order) {
            handler->sortIndicatorChanged(logicalIndex, static_cast<SortOrder>(order));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SortIndicatorClearableChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QHeaderView::sortIndicatorClearableChanged, [handler](bool clearable) {
            handler->sortIndicatorClearableChanged(clearable);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Orientation orientation) {
        return reinterpret_cast<HandleRef>(new QHeaderView(static_cast<Qt::Orientation>(orientation)));
    }
}
