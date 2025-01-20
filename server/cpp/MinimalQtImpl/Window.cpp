#include "generated/Window.h"
#include "WindowInternal.h"

#include "ObjectInternal.h"
#include "util/convert.h"

#define THIS (reinterpret_cast<QWindow*>(_this))

namespace Window
{
    SignalConnectionRef Handle_connect_ActiveChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::activeChanged, [handler] {
            handler->activeChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ContentOrientationChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::contentOrientationChanged, [handler](Qt::ScreenOrientation orientation) {
            handler->contentOrientationChanged(static_cast<ScreenOrientation>(orientation));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FocusObjectChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::focusObjectChanged, [handler](QObject *object) {
            handler->focusObjectChanged(reinterpret_cast<Object::HandleRef>(object));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_HeightChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::heightChanged, [handler](int arg) {
            handler->heightChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_MaximumHeightChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::maximumHeightChanged, [handler](int arg) {
            handler->maximumHeightChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_MaximumWidthChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::maximumWidthChanged, [handler](int arg) {
            handler->maximumWidthChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_MinimumHeightChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::minimumHeightChanged, [handler](int arg) {
            handler->minimumHeightChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_MinimumWidthChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::minimumWidthChanged, [handler](int arg) {
            handler->minimumWidthChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ModalityChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::modalityChanged, [handler](Qt::WindowModality modality) {
            handler->modalityChanged(static_cast<WindowModality>(modality));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_OpacityChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::opacityChanged, [handler](qreal opacity) {
            handler->opacityChanged(opacity);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ScreenChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::screenChanged, [handler](QScreen *screen) {
            handler->screenChanged(reinterpret_cast<Screen::HandleRef>(screen));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TransientParentChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::transientParentChanged, [handler](QWindow *transientParent) {
            handler->transientParentChanged(reinterpret_cast<HandleRef>(transientParent));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_VisibilityChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::visibilityChanged, [handler](QWindow::Visibility visibility) {
            handler->visibilityChanged(static_cast<Visibility>(visibility));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_VisibleChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::visibleChanged, [handler](bool arg) {
            handler->visibleChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_WidthChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::widthChanged, [handler](int arg) {
            handler->widthChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_WindowStateChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::windowStateChanged, [handler](Qt::WindowState windowState) {
            handler->windowStateChanged(static_cast<WindowState>(windowState));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_WindowTitleChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::windowTitleChanged, [handler](const QString &title) {
            handler->windowTitleChanged(title.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_XChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::xChanged, [handler](int arg) {
            handler->xChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_YChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::yChanged, [handler](int arg) {
            handler->yChanged(arg);
        });
        return new __SignalConnection { connection };
    }
}
