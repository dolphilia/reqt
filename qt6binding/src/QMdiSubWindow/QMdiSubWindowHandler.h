#ifndef MDISUBWINDOW_HANDLER_H
#define MDISUBWINDOW_HANDLER_H

#include <QObject>
#include <QMdiSubWindow>

typedef void (*WindowStateChangedCallback)(void*, int, int);
typedef void (*AboutToActivateCallback)(void*);

class MdiSubWindowHandler : public QObject {
    Q_OBJECT
public:
    explicit MdiSubWindowHandler(QObject* parent = nullptr);
    MdiSubWindowHandler(const MdiSubWindowHandler&) = delete;
    MdiSubWindowHandler& operator=(const MdiSubWindowHandler&) = delete;

    void setSubWindow(QMdiSubWindow* subWindow);
    void setWindowStateChangedCallback(WindowStateChangedCallback callback);
    void setAboutToActivateCallback(AboutToActivateCallback callback);

public slots:
    void onWindowStateChanged(Qt::WindowStates oldState, Qt::WindowStates newState);
    void onAboutToActivate();

private:
    QMdiSubWindow* subWindow;
    WindowStateChangedCallback windowStateChangedCallback;
    AboutToActivateCallback aboutToActivateCallback;
};

#endif // MDISUBWINDOW_HANDLER_H
