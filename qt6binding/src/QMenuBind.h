#ifndef BIND_Q_MENU_H
#define BIND_Q_MENU_H

#include <QMenu>
#include "QMenuHandler.h"

class BindQMenu : public QMenu {
    Q_OBJECT
public:
    explicit BindQMenu(QWidget *parent = nullptr);
    explicit BindQMenu(const QString &title, QWidget *parent = nullptr);
    ~BindQMenu();

    void setMenuHandler(MenuHandler *handler);
    MenuHandler *handler() const;

private:
    MenuHandler *m_handler;
};

#endif // BIND_Q_MENU_H
