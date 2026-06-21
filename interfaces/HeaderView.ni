module HeaderView;

import Object;
import AbstractItemView;
import Enums;
import Widget;
import Point;

interface SignalHandler extends AbstractItemView.SignalHandler {
    void geometriesChanged();
    void sectionClicked(int logicalIndex);
    void sectionCountChanged(int oldCount, int newCount);
    void sectionDoubleClicked(int logicalIndex);
    void sectionEntered(int logicalIndex);
    void sectionHandleDoubleClicked(int logicalIndex);
    void sectionMoved(int logicalIndex, int oldVisualIndex, int newVisualIndex);
    void sectionPressed(int logicalIndex);
    void sectionResized(int logicalIndex, int oldSize, int newSize);
    void sortIndicatorChanged(int logicalIndex, SortOrder order);
    void sortIndicatorClearableChanged(bool clearable);
}

enum ResizeMode
{
    Interactive,
    Stretch,
    Fixed,
    ResizeToContents,
    Custom = Fixed
}

opaque Handle extends AbstractItemView.Handle {
    bool cascadingSectionResizes();
    int count();
    Alignment defaultAlignment();
    int defaultSectionSize();
    int hiddenSectionCount();
    void hideSection(int logicalIndex);
    bool highlightSections();
    bool isFirstSectionMovable();
    bool isSectionHidden(int logicalIndex);
    bool isSortIndicatorClearable();
    bool isSortIndicatorShown();
    int length();
    int logicalIndex(int visualIndex);
    int logicalIndexAt(Point.Handle pos);
    int logicalIndexAt(int position);
    int logicalIndexAt(int x, int y);
    int maximumSectionSize();
    int minimumSectionSize();
    void moveSection(int from, int to);
    int offset();
    Orientation orientation();
    void resetDefaultSectionSize();
    int resizeContentsPrecision();
    void resizeSection(int logicalIndex, int size);
    void resizeSections(ResizeMode mode);
    bool restoreState(Array<byte> state);
    Array<byte> saveState();
    int sectionPosition(int logicalIndex);
    ResizeMode sectionResizeMode(int logicalIndex);
    int sectionSize(int logicalIndex);
    int sectionSizeHint(int logicalIndex);
    int sectionViewportPosition(int logicalIndex);
    bool sectionsClickable();
    bool sectionsHidden();
    bool sectionsMovable();
    bool sectionsMoved();
    void setCascadingSectionResizes(bool enable);
    void setDefaultAlignment(Alignment alignment);
    void setDefaultSectionSize(int size);
    void setFirstSectionMovable(bool movable);
    void setHighlightSections(bool highlight);
    void setMaximumSectionSize(int size);
    void setMinimumSectionSize(int size);
    void setResizeContentsPrecision(int precision);
    void setSectionHidden(int logicalIndex, bool hide);
    void setSectionResizeMode(ResizeMode mode);
    void setSectionResizeMode(int logicalIndex, ResizeMode mode);
    void setSectionsClickable(bool clickable);
    void setSectionsMovable(bool movable);
    void setSortIndicator(int logicalIndex, SortOrder order);
    void setSortIndicatorClearable(bool clearable);
    void setSortIndicatorShown(bool show);
    void setStretchLastSection(bool stretch);
    void showSection(int logicalIndex);
    SortOrder sortIndicatorOrder();
    int sortIndicatorSection();
    bool stretchLastSection();
    int stretchSectionCount();
    void swapSections(int first, int second);
    int visualIndex(int logicalIndex);
    int visualIndexAt(int position);
    void headerDataChanged(Orientation orientation, int logicalFirst, int logicalLast);
    void setOffset(int offset);
    void setOffsetToLastSection();
    void setOffsetToSectionPosition(int visualSectionNumber);

    // signals ==========================================
    SignalConnection connect_GeometriesChanged(SignalHandler handler);
    SignalConnection connect_SectionClicked(SignalHandler handler);
    SignalConnection connect_SectionCountChanged(SignalHandler handler);
    SignalConnection connect_SectionDoubleClicked(SignalHandler handler);
    SignalConnection connect_SectionEntered(SignalHandler handler);
    SignalConnection connect_SectionHandleDoubleClicked(SignalHandler handler);
    SignalConnection connect_SectionMoved(SignalHandler handler);
    SignalConnection connect_SectionPressed(SignalHandler handler);
    SignalConnection connect_SectionResized(SignalHandler handler);
    SignalConnection connect_SortIndicatorChanged(SignalHandler handler);
    SignalConnection connect_SortIndicatorClearableChanged(SignalHandler handler);
}

Handle create(Orientation orientation, Widget.Handle parent = null);
