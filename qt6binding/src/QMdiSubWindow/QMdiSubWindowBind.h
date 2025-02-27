#ifndef QMDISUBWINDOW_BIND_H
#define QMDISUBWINDOW_BIND_H

#include <QMdiSubWindow>
#include "QMdiSubWindowHandler.h"

class QMdiSubWindowBind : public QMdiSubWindow {
    Q_OBJECT

public:
    explicit QMdiSubWindowBind(QWidget* parent = nullptr);
    ~QMdiSubWindowBind() override;

    void setWindowStateChangedCallback(WindowStateChangedCallback callback);
    void setAboutToActivateCallback(AboutToActivateCallback callback);

private:
    MdiSubWindowHandler* handler;
};

#endif // QMDISUBWINDOW_BIND_H
