#ifndef QMDISUBWINDOW_BIND_H
#define QMDISUBWINDOW_BIND_H

#include <QMdiSubWindow>
#include "QMdiSubWindowHandler.h"

class QMdiSubWindowHandler;

class QMdiSubWindowBind : public QMdiSubWindow {
    Q_OBJECT
    typedef void (*QMdiSubWindow_WindowStateChangedCallback)(void*, int, int);
    typedef void (*QMdiSubWindow_AboutToActivateCallback)(void*);
public:
    explicit QMdiSubWindowBind(QWidget* parent = nullptr);
    ~QMdiSubWindowBind() override;
    void setWindowStateChangedCallback(QMdiSubWindow_WindowStateChangedCallback callback) const;
    void setAboutToActivateCallback(QMdiSubWindow_AboutToActivateCallback callback) const;
private:
    QMdiSubWindowHandler* handler;
};

#endif // QMDISUBWINDOW_BIND_H
