#ifndef QMDISUBWINDOW_HANDLER_H
#define QMDISUBWINDOW_HANDLER_H

#include <QObject>
#include <QMdiSubWindow>

class QMdiSubWindowHandler : public QObject {
    Q_OBJECT
    typedef void (*QMdiSubWindow_WindowStateChangedCallback)(void*, int, int);
    typedef void (*QMdiSubWindow_AboutToActivateCallback)(void*);
public:
    explicit QMdiSubWindowHandler(QObject* parent = nullptr);
    void setWindowStateChangedCallback(QMdiSubWindow_WindowStateChangedCallback callback);
    void setAboutToActivateCallback(QMdiSubWindow_AboutToActivateCallback callback);

public slots:
    void onWindowStateChanged(Qt::WindowStates oldState, Qt::WindowStates newState) const;
    void onAboutToActivate() const;

private:
    QMdiSubWindow_WindowStateChangedCallback windowStateChangedCallback;
    QMdiSubWindow_AboutToActivateCallback aboutToActivateCallback;
};

#endif // QMDISUBWINDOW_HANDLER_H
