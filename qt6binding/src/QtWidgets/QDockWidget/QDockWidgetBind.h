#ifndef QDOCKWIDGET_BIND_H
#define QDOCKWIDGET_BIND_H

#include "QDockWidgetHandler.h"
#include <QDockWidget>

class QDockWidgetBind : public QDockWidget {
    Q_OBJECT
    typedef void (*AllowedAreasChangedCallback)(void*, int);
    typedef void (*DockLocationChangedCallback)(void*, int);
    typedef void (*FeaturesChangedCallback)(void*, int);
    typedef void (*TopLevelChangedCallback)(void*, bool);
    typedef void (*VisibilityChangedCallback)(void*, bool);
public:
    explicit QDockWidgetBind(const QString& title, QWidget* parent = nullptr);
    ~QDockWidgetBind() override;
    void setAllowedAreasChangedCallback(AllowedAreasChangedCallback callback) const;
    void setDockLocationChangedCallback(DockLocationChangedCallback callback) const;
    void setFeaturesChangedCallback(FeaturesChangedCallback callback) const;
    void setTopLevelChangedCallback(TopLevelChangedCallback callback) const;
    void setVisibilityChangedCallback(VisibilityChangedCallback callback) const;
private:
    DockWidgetHandler* handler;
};

#endif // QDOCKWIDGET_BIND_H
