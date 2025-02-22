#ifndef QDOCKWIDGET_BIND_H
#define QDOCKWIDGET_BIND_H

#include <QDockWidget>
#include "handler_dock_widget.h"

class QDockWidgetBind : public QDockWidget {
    Q_OBJECT

public:
    explicit QDockWidgetBind(const QString& title, QWidget* parent = nullptr);
    ~QDockWidgetBind() override;

    void setAllowedAreasChangedCallback(void (*callback)(void*, int));
    void setDockLocationChangedCallback(void (*callback)(void*, int));
    void setFeaturesChangedCallback(void (*callback)(void*, int));
    void setTopLevelChangedCallback(void (*callback)(void*, bool));
    void setVisibilityChangedCallback(void (*callback)(void*, bool));

private:
    DockWidgetHandler* handler;
};

#endif // QDOCKWIDGET_BIND_H
