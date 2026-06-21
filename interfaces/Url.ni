module Url;

@nodispose
opaque Handle {
    string toAbsoluteInternal();
}
opaque Owned extends Handle;

Owned createFromAbsolute(string absoluteUrl);

// list ===============================

@nodispose
opaque List {
    int count();
    Owned itemAt(int index);
    Array<Owned> items();
    Array<string> itemsAbsolute();
}
opaque OwnedList extends List;

OwnedList createFromAbsoluteList(Array<string> absoluteUrls);
