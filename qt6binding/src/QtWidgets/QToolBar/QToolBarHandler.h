#ifndef QTOOLBAR_HANDLER_H
#define QTOOLBAR_HANDLER_H

#include <QObject>
#include <QAction>

class QToolBarHandler : public QObject {
    Q_OBJECT
    typedef void (*QToolBar_ActionTriggeredCallback)(void*, void*);
    typedef void (*QToolBar_MovableChangedCallback)(void*, bool);
    typedef void (*QToolBar_OrientationChangedCallback)(void*, int);
    typedef void (*QToolBar_TopLevelChangedCallback)(void*, bool);
    typedef void (*QToolBar_VisibilityChangedCallback)(void*, bool);
    typedef void (*QToolBar_AllowedAreasChangedCallback)(void*, int);
public:
    explicit QToolBarHandler(QObject* parent = nullptr);
    void setActionTriggeredCallback(QToolBar_ActionTriggeredCallback callback);
    void setMovableChangedCallback(QToolBar_MovableChangedCallback callback);
    void setOrientationChangedCallback(QToolBar_OrientationChangedCallback callback);
    void setTopLevelChangedCallback(QToolBar_TopLevelChangedCallback callback);
    void setVisibilityChangedCallback(QToolBar_VisibilityChangedCallback callback);
    void setAllowedAreasChangedCallback(QToolBar_AllowedAreasChangedCallback callback);

public slots:
    void onActionTriggered(QAction* action) const;
    void onMovableChanged(bool movable) const;
    void onOrientationChanged(int orientation) const;
    void onTopLevelChanged(bool topLevel) const;
    void onVisibilityChanged(bool visible) const;
    void onAllowedAreasChanged(int areas) const;

private:
    QToolBar_ActionTriggeredCallback actionTriggeredCallback;
    QToolBar_MovableChangedCallback movableChangedCallback;
    QToolBar_OrientationChangedCallback orientationChangedCallback;
    QToolBar_TopLevelChangedCallback topLevelChangedCallback;
    QToolBar_VisibilityChangedCallback visibilityChangedCallback;
    QToolBar_AllowedAreasChangedCallback allowedAreasChangedCallback;
};

#endif // QTOOLBAR_HANDLER_H
