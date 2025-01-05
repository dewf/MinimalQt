#pragma once

#include "generated/Widget.h"
#include "ObjectInternal.h"
#include "util/SignalStuff.h"
#include "util/convert.h"

#include <QWidget>

namespace Widget {
    class SignalWrapper : public Object::SignalWrapper {
        Q_OBJECT
    private:
        QWidget *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { CustomContextMenuRequested, SIGNAL(customContextMenuRequested(QPoint)), SLOT(onCustomContextMenuRequested(QPoint)) },
            { WindowIconChanged, SIGNAL(windowIconChanged(QIcon)), SLOT(onWindowIconChanged(QIcon)) },
            { WindowTitleChanged, SIGNAL(windowTitleChanged(QString)), SLOT(onWindowTitleChanged(QString)) },
        };
    public:
        QWidget *getActual() const {
            return actual;
        }
        // wrap existing (could be a delegated QWidget subclass)
        SignalWrapper(QWidget *existing, const std::shared_ptr<SignalHandler> &handler)
            : Object::SignalWrapper(existing, SignalHandler::as_Object_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Object::SignalWrapper::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->windowIconChanged((Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->windowTitleChanged(title.toStdString());
        }
    };

    inline QWidget *fromOptionalHandle(const std::optional<HandleRef>& handle) {
        QWidget *qParent = nullptr;
        if (handle.has_value()) {
            const auto parentWrapper = reinterpret_cast<SignalWrapper*>(handle.value());
            qParent = parentWrapper->getActual();
        }
        return qParent;
    }
}
