#pragma once

#include "generated/SortFilterProxyModel.h"
#include "AbstractProxyModelInternal.h"

#include <QSortFilterProxyModel>

namespace SortFilterProxyModel {
    class SignalWrapper : public AbstractProxyModel::SignalWrapper {
        Q_OBJECT
    private:
        QSortFilterProxyModel *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { AutoAcceptChildRowsChanged, SIGNAL(autoAcceptChildRowsChanged(bool)), SLOT(onAutoAcceptChildRowsChanged(bool)) },
            { FilterCaseSensitivityChanged, SIGNAL(filterCaseSensitivityChanged(CaseSensitivity)), SLOT(onFilterCaseSensitivityChanged(CaseSensitivity)) },
            { FilterRoleChanged, SIGNAL(filterRoleChanged(int)), SLOT(onFilterRoleChanged(int)) },
            { RecursiveFilteringEnabledChanged, SIGNAL(recursiveFilteringEnabledChanged(bool)), SLOT(onRecursiveFilteringEnabledChanged(bool)) },
            { SortCaseSensitivityChanged, SIGNAL(sortCaseSensitivityChanged(CaseSensitivity)), SLOT(onSortCaseSensitivityChanged(CaseSensitivity)) },
            { SortLocaleAwareChanged, SIGNAL(sortLocaleAwareChanged(bool)), SLOT(onSortLocaleAwareChanged(bool)) },
            { SortRoleChanged, SIGNAL(sortRoleChanged(int)), SLOT(onSortRoleChanged(int)) },
        };
    public:
        QSortFilterProxyModel *getActual() const {
            return actual;
        }
        SignalWrapper(QSortFilterProxyModel *existing, const std::shared_ptr<SignalHandler> &handler)
            : AbstractProxyModel::SignalWrapper(existing, SignalHandler::as_AbstractProxyModel_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractProxyModel::SignalWrapper::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onAutoAcceptChildRowsChanged(bool autoAcceptChildRows) const {
            handler->autoAcceptChildRowsChanged(autoAcceptChildRows);
        };
        void onFilterCaseSensitivityChanged(Qt::CaseSensitivity filterCaseSensitivity) const {
            handler->filterCaseSensitivityChanged(static_cast<CaseSensitivity>(filterCaseSensitivity));
        };
        void onFilterRoleChanged(int filterRole) const {
            handler->filterRoleChanged(static_cast<ItemDataRole>(filterRole));
        };
        void onRecursiveFilteringEnabledChanged(bool recursiveFilteringEnabled) const {
            handler->recursiveFilteringEnabledChanged(recursiveFilteringEnabled);
        };
        void onSortCaseSensitivityChanged(Qt::CaseSensitivity sortCaseSensitivity) const {
            handler->sortCaseSensitivityChanged(static_cast<CaseSensitivity>(sortCaseSensitivity));
        };
        void onSortLocaleAwareChanged(bool sortLocaleAware) const {
            handler->sortLocaleAwareChanged(sortLocaleAware);
        };
        void onSortRoleChanged(int sortRole) const {
            handler->sortRoleChanged(static_cast<ItemDataRole>(sortRole));
        };
    };
}
