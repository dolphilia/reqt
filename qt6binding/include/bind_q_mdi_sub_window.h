#ifndef QMDISUBWINDOW_BIND_H
#define QMDISUBWINDOW_BIND_H

#include <QMdiSubWindow>
#include "handler_mdi_sub_window.h"

class QMdiSubWindowBind : public QMdiSubWindow {
    Q_OBJECT

public:
    explicit QMdiSubWindowBind(QWidget* parent = nullptr);
    ~QMdiSubWindowBind() override;

    void setWindowStateChangedCallback(void (*callback)(void*, int, int));
    void setAboutToActivateCallback(void (*callback)(void*));

private:
    MdiSubWindowHandler* handler;
};

#endif // QMDISUBWINDOW_BIND_H
