module PushButton;

import Object;
import Widget;
import Icon;
import AbstractButton;
import Menu;

interface SignalHandler extends AbstractButton.SignalHandler;
// none extra

opaque Handle extends AbstractButton.Handle {
    bool autoDefault();
    bool isDefault();
    bool isFlat();
    Menu.Handle getMenu();
    void setAutoDefault(bool value);
    void setDefault(bool value);
    void setFlat(bool value);
    void setMenu(Menu.Handle menu);
    void showMenu();
}

Handle create(Widget.Handle parent = null);
Handle create(string text, Widget.Handle parent = null);
Handle create(Icon.Handle icon, string text, Widget.Handle parent = null);
