module String;

// the only reason we really need this, is for the odd function which takes a QStringList and provides a default value

@nodispose
opaque List {
    Array<string> getValues();
}
@useparenttype
opaque OwnedList extends List;

OwnedList createFromStrings(Array<string> values);
