#ifndef QMAINWINDOW_BIND_H
#define QMAINWINDOW_BIND_H

#include "QMainWindowHandler.h"
#include <QMainWindow>

class QMainWindowBind : public QMainWindow {
    Q_OBJECT
    typedef void (*QMainWindow_WindowTitleChangedCallback)(void*, const char*);
public:
    explicit QMainWindowBind(QWidget* parent = nullptr);
    ~QMainWindowBind() override;
    void setWindowTitleChangedCallback(QMainWindow_WindowTitleChangedCallback callback) const;
private:
    QMainWindowHandler* handler;
};

#endif // QMAINWINDOW_BIND_H
