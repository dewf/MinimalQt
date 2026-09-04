module AbstractProxyModel;

import Object;
import Enums;
import AbstractItemModel;
import ModelIndex;
import PersistentModelIndex;
import ItemSelectionModel;

@methodprefix("sig_")
interface SignalHandler extends AbstractItemModel.SignalHandler {
    void sourceModelChanged();
}

@nodispose
opaque Handle extends AbstractItemModel.Handle {

    // QBindable<QAbstractItemModel *> bindableSourceModel()

    ModelIndex.Owned mapFromSource(ModelIndex.Handle sourceIndex);
    ItemSelection.Owned mapSelectionFromSource(ItemSelection.Handle sourceSelection);
    ItemSelection.Owned mapSelectionToSource(ItemSelection.Handle proxySelection);
    ModelIndex.Owned mapToSource(ModelIndex.Handle proxyIndex);
    void setSourceModel(AbstractItemModel.Handle sourceModel);
    AbstractItemModel.Handle sourceModel();

    // signals ============================
    SignalConnection connect_SourceModelChanged(SignalHandler handler);
}

// abstract, no create()
