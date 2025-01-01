#pragma once

#include "generated/HeaderView.h"
#include "AbstractItemViewInternal.h"

#include <QHeaderView>

namespace HeaderView {
    class SignalWrapper : public AbstractItemView::SignalWrapper {
        Q_OBJECT
    private:
        QHeaderView *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { GeometriesChanged, SIGNAL(geometriesChanged()), SLOT(onGeometriesChanged()) },
            { SectionClicked, SIGNAL(sectionClicked(int)), SLOT(onSectionClicked(int)) },
            { SectionCountChanged, SIGNAL(sectionCountChanged(int,int)), SLOT(onSectionCountChanged(int,int)) },
            { SectionDoubleClicked, SIGNAL(onSectionDoubleClicked(int)), SLOT(onSectionDoubleClicked(int)) },
            { SectionEntered, SIGNAL(sectionEntered(int)), SLOT(onSectionEntered(int)) },
            { SectionHandleDoubleClicked, SIGNAL(sectionHandleDoubleClicked(int)), SLOT(onSectionHandleDoubleClicked(int)) },
            { SectionMoved, SIGNAL(sectionMoved(int,int,int)), SLOT(onSectionMoved(int,int,int)) },
            { SectionPressed, SIGNAL(sectionPressed(int)), SLOT(onSectionPressed(int)) },
            { SectionResized, SIGNAL(sectionResized(int,int,int)), SLOT(onSectionResized(int,int,int)) },
            { SortIndicatorChanged, SIGNAL(sortIndicatorChanged(int,Qt::SortOrder)), SLOT(onSortIndicatorChanged(int,Qt::SortOrder)) },
            { SortIndicatorClearableChanged, SIGNAL(sortIndicatorClearableChanged(bool)), SLOT(onSortIndicatorClearableChanged(bool)) },
        };
    public:
        QHeaderView *getActual() const {
            return actual;
        }
        SignalWrapper(QHeaderView *existing, const std::shared_ptr<SignalHandler>& handler)
            : AbstractItemView::SignalWrapper(existing, SignalHandler::as_AbstractItemView_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractItemView::SignalWrapper::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onGeometriesChanged() const {
            handler->geometriesChanged();
        }
        void onSectionClicked(int logicalIndex) const {
            handler->sectionClicked(logicalIndex);
        }
        void onSectionCountChanged(int oldCount, int newCount) const {
            handler->sectionCountChanged(oldCount, newCount);
        }
        void onSectionDoubleClicked(int logicalIndex) const {
            handler->sectionDoubleClicked(logicalIndex);
        }
        void onSectionEntered(int logicalIndex) const {
            handler->sectionEntered(logicalIndex);
        }
        void onSectionHandleDoubleClicked(int logicalIndex) const {
            handler->sectionHandleDoubleClicked(logicalIndex);
        }
        void onSectionMoved(int logicalIndex, int oldVisualIndex, int newVisualIndex) const {
            handler->sectionMoved(logicalIndex, oldVisualIndex, newVisualIndex);
        }
        void onSectionPressed(int logicalIndex) const {
            handler->sectionPressed(logicalIndex);
        }
        void onSectionResized(int logicalIndex, int oldSize, int newSize) const {
            handler->sectionResized(logicalIndex, oldSize, newSize);
        }
        void onSortIndicatorChanged(int logicalIndex, Qt::SortOrder order) const {
            handler->sortIndicatorChanged(logicalIndex, static_cast<SortOrder>(order));
        }
        void onSortIndicatorClearableChanged(bool clearable) const {
            handler->sortIndicatorClearableChanged(clearable);
        }
    };
}
