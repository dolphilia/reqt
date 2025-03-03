#ifndef QMAINWINDOW_BIND_H
#define QMAINWINDOW_BIND_H

#include "QMainWindowHandler.h"
#include <QMainWindow>

class QMainWindowBind : public QMainWindow {
    Q_OBJECT
    typedef void (*WindowTitleChangedCallback)(void*, const char*);
public:
    explicit QMainWindowBind(QWidget* parent = nullptr);
    ~QMainWindowBind() override;
    void setWindowTitleChangedCallback(WindowTitleChangedCallback callback) const;
private:
    MainWindowHandler* handler;
};

#endif // QMAINWINDOW_BIND_H
