#ifndef BIND_Q_TAB_BAR_H
#define BIND_Q_TAB_BAR_H

#include <QTabBar>
#include "QTabBarHandler.h"

class BindQTabBar : public QTabBar {
    Q_OBJECT
public:
    explicit BindQTabBar(QWidget *parent = nullptr);
    ~BindQTabBar();

    void setTabBarHandler(TabBarHandler *handler);
    TabBarHandler *handler() const;

private:
    TabBarHandler *m_handler;
};

#endif // BIND_Q_TAB_BAR_H
