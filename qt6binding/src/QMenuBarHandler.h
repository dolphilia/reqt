#ifndef HANDLER_MENU_BAR_H
#define HANDLER_MENU_BAR_H

#include <QObject>
#include <QAction>

class MenuBarHandler : public QObject {
    Q_OBJECT
public:
    explicit MenuBarHandler(QObject *parent = nullptr);
    ~MenuBarHandler();

    void setTriggeredCallback(void (*callback)(void* action));
    void setHoveredCallback(void (*callback)(void* action));

public slots:
    void onTriggered(QAction* action);
    void onHovered(QAction* action);

private:
    void (*m_triggeredCallback)(void* action);
    void (*m_hoveredCallback)(void* action);
};

#endif // HANDLER_MENU_BAR_H
