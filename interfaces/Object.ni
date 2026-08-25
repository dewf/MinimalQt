module Object;

@nodispose
opaque SignalConnection; // contains a MetaObject::Connection. @nodispose because they are automatically deleted on disconnection

interface SignalHandler {
    // for internal use
    void destroyedByQt();

    void destroyed(Handle obj);
    void objectNameChanged(string objectName);
}

@nodispose
opaque Handle {
    // properties =======================
    string objectName();
    void setObjectName(string name);

    // methods ==========================
    void setParent(Handle parent);
    void dumpObjectTree();

    void deleteLater();

    SignalConnection connect_DestroyedByQt(SignalHandler handler);
    SignalConnection connect_Destroyed(SignalHandler handler);
    SignalConnection connect_ObjectNameChanged(SignalHandler handler);
}

// no create() because abstract

// static methods:
void disconnect(SignalConnection connection); // disconnect + delete SignalConnection wrapper
