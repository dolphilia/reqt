#ifndef MDISUBWINDOW_HANDLER_H
#define MDISUBWINDOW_HANDLER_H

#include <QObject>
#include <QMdiSubWindow>

class MdiSubWindowHandler : public QObject {
    Q_OBJECT
public:
    explicit MdiSubWindowHandler(QObject* parent = nullptr);
    void setSubWindow(QMdiSubWindow* subWindow);
    void setWindowStateChangedCallback(void (*callback)(void*, int, int));
    void setAboutToActivateCallback(void (*callback)(void*));

public slots:
    void onWindowStateChanged(Qt::WindowStates oldState, Qt::WindowStates newState);
    void onAboutToActivate();

private:
    QMdiSubWindow* subWindow;
    void (*windowStateChangedCallback)(void*, int, int);
    void (*aboutToActivateCallback)(void*);
};

#endif // MDISUBWINDOW_HANDLER_H
