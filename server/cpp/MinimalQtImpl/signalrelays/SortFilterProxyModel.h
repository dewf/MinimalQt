#pragma once

#include "../generated/SortFilterProxyModel.h"
#include "AbstractProxyModel.h"

namespace SortFilterProxyModel {
    class SignalRelay : public AbstractProxyModel::SignalRelay {
        Q_OBJECT
    private:
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
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler)
            : AbstractProxyModel::SignalRelay(relayFor, SignalHandler::as_AbstractProxyModel_SignalHandler(handler)),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractProxyModel::SignalRelay::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, relayFor, this);
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
