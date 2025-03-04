#ifndef QDOCKWIDGET_BIND_H
#define QDOCKWIDGET_BIND_H

#include "QDockWidgetHandler.h"
#include <QDockWidget>

class QDockWidgetBind : public QDockWidget {
    Q_OBJECT
    typedef void (*QDockWidget_AllowedAreasChangedCallback)(void*, int);
    typedef void (*QDockWidget_DockLocationChangedCallback)(void*, int);
    typedef void (*QDockWidget_FeaturesChangedCallback)(void*, int);
    typedef void (*QDockWidget_TopLevelChangedCallback)(void*, bool);
    typedef void (*QDockWidget_VisibilityChangedCallback)(void*, bool);
public:
    explicit QDockWidgetBind(const QString& title, QWidget* parent = nullptr);
    ~QDockWidgetBind() override;
    void setAllowedAreasChangedCallback(QDockWidget_AllowedAreasChangedCallback callback) const;
    void setDockLocationChangedCallback(QDockWidget_DockLocationChangedCallback callback) const;
    void setFeaturesChangedCallback(QDockWidget_FeaturesChangedCallback callback) const;
    void setTopLevelChangedCallback(QDockWidget_TopLevelChangedCallback callback) const;
    void setVisibilityChangedCallback(QDockWidget_VisibilityChangedCallback callback) const;
private:
    QDockWidgetHandler* handler;
};

#endif // QDOCKWIDGET_BIND_H
