#pragma once

#include "generated/DockWidget.h"
#include "WidgetInternal.h"

#include <QDockWidget.h>

namespace DockWidget {
    class SignalWrapper : public Widget::SignalWrapper {
        Q_OBJECT
    private:
        QDockWidget *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { AllowedAreasChanged, SIGNAL(allowedAreasChanged(Qt::DockWidgetAreas)), SLOT(onAllowedAreasChanged(Qt::DockWidgetAreas)) },
            { DockLocationChanged, SIGNAL(dockLocationChanged(Qt::DockWidgetArea)), SLOT(onDockLocationChanged(Qt::DockWidgetArea)) },
            { FeaturesChanged, SIGNAL(featuresChanged(QDockWidget::DockWidgetFeatures)), SLOT(onFeaturesChanged(QDockWidget::DockWidgetFeatures)) },
            { TopLevelChanged, SIGNAL(topLevelChanged(bool)), SLOT(onTopLevelChanged(bool)) },
            { VisibilityChanged, SIGNAL(visibilityChanged(bool)), SLOT(onVisibilityChanged(bool)) },
        };
    public:
        QDockWidget *getActual() const {
            return actual;
        }
        SignalWrapper(QDockWidget *existing, const std::shared_ptr<SignalHandler>& handler)
            : Widget::SignalWrapper(existing, SignalHandler::as_Widget_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Widget::SignalWrapper::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onAllowedAreasChanged(Qt::DockWidgetAreas allowedAreas) const {
            handler->allowedAreasChanged(allowedAreas);
        }
        void onDockLocationChanged(Qt::DockWidgetArea area) const {
            handler->dockLocationChanged(static_cast<DockWidgetArea>(area));
        }
        void onFeaturesChanged(QDockWidget::DockWidgetFeatures features) const {
            handler->featuresChanged(features);
        }
        void onTopLevelChanged(bool topLevel) const {
            handler->topLevelChanged(topLevel);
        }
        void onVisibilityChanged(bool visible) const {
            handler->visibilityChanged(visible);
        }
    };
}

