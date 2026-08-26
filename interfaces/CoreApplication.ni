module CoreApplication;

import Object;

@methodprefix("sig_")
interface SignalHandler extends Object.SignalHandler {
    void aboutToQuit();
    void applicationNameChanged();
    void applicationVersionChanged();
    void organizationDomainChanged();
    void organizationNameChanged();
}

@nodispose // because no ctors
opaque Handle extends Object.Handle {
    // others TODO

    void exit(int returnCode = 0);
    void quit();

    // signals ===========================
    SignalConnection connect_AboutToQuit(SignalHandler handler);
    SignalConnection connect_ApplicationNameChanged(SignalHandler handler);
    SignalConnection connect_ApplicationVersionChanged(SignalHandler handler);
    SignalConnection connect_OrganizationDomainChanged(SignalHandler handler);
    SignalConnection connect_OrganizationNameChanged(SignalHandler handler);
}

// no ctors (we only use Application)

// TODO: a gazillion static members
