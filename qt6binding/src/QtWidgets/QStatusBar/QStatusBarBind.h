#ifndef QSTATUSBAR_BIND_H
#define QSTATUSBAR_BIND_H

#include <QStatusBar>

#include "QStatusBarHandler.h"

class QStatusBarHandler;

class QStatusBarBind : public QStatusBar {
    Q_OBJECT
    typedef void (*QStatusBar_MessageChangedCallback)(void*, const char*);
public:
    explicit QStatusBarBind(QWidget* parent = nullptr);
    ~QStatusBarBind() override;
    void setMessageChangedCallback(QStatusBar_MessageChangedCallback callback) const;

private:
    QStatusBarHandler* handler;
};

#endif // QSTATUSBAR_BIND_H
