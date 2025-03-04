#ifndef QTOOLBAR_BIND_H
#define QTOOLBAR_BIND_H

#include <QToolBar>
#include "QToolBarHandler.h"

class QToolBarHandler;

class QToolBarBind : public QToolBar {
    Q_OBJECT
    typedef void (*QToolBar_ActionTriggeredCallback)(void*, void*);
    typedef void (*QToolBar_MovableChangedCallback)(void*, bool);
    typedef void (*QToolBar_OrientationChangedCallback)(void*, int);
    typedef void (*QToolBar_TopLevelChangedCallback)(void*, bool);
    typedef void (*QToolBar_VisibilityChangedCallback)(void*, bool);
    typedef void (*QToolBar_AllowedAreasChangedCallback)(void*, int);
public:
    explicit QToolBarBind(QWidget* parent = nullptr);
    explicit QToolBarBind(const QString& title, QWidget* parent = nullptr);
    ~QToolBarBind() override;
    
    void setActionTriggeredCallback(QToolBar_ActionTriggeredCallback callback) const;
    void setMovableChangedCallback(QToolBar_MovableChangedCallback callback) const;
    void setOrientationChangedCallback(QToolBar_OrientationChangedCallback callback) const;
    void setTopLevelChangedCallback(QToolBar_TopLevelChangedCallback callback) const;
    void setVisibilityChangedCallback(QToolBar_VisibilityChangedCallback callback) const;
    void setAllowedAreasChangedCallback(QToolBar_AllowedAreasChangedCallback callback) const;
    
private:
    QToolBarHandler* handler;
};

#endif // QTOOLBAR_BIND_H
