#ifndef QTABBAR_BIND_H
#define QTABBAR_BIND_H

#include <QTabBar>
#include "QTabBarHandler.h"

class QTabBarHandler;

class QTabBarBind : public QTabBar {
    Q_OBJECT
    typedef void (*QTabBar_CurrentChangedCallback)(void*, int);
    typedef void (*QTabBar_TabCloseRequestedCallback)(void*, int);
public:
    explicit QTabBarBind(QWidget *parent = nullptr);
    ~QTabBarBind() override;
    void setCurrentChangedCallback(QTabBar_CurrentChangedCallback callback) const;
    void setTabCloseRequestedCallback(QTabBar_TabCloseRequestedCallback callback) const;
private:
    QTabBarHandler* handler;
};

#endif // QTABBAR_BIND_H
