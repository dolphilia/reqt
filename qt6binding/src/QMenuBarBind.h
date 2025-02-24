#ifndef BIND_Q_MENU_BAR_H
#define BIND_Q_MENU_BAR_H

#include <QMenuBar>
#include "QMenuBarHandler.h"

class BindQMenuBar : public QMenuBar {
    Q_OBJECT
public:
    explicit BindQMenuBar(QWidget *parent = nullptr);
    ~BindQMenuBar();

    void setMenuBarHandler(MenuBarHandler *handler);
    MenuBarHandler *handler() const;

private:
    MenuBarHandler *m_handler;
};

#endif // BIND_Q_MENU_BAR_H
