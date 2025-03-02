#ifndef HANDLER_MENU_H
#define HANDLER_MENU_H

#include <QObject>
#include <QAction>

class MenuHandler : public QObject {
    Q_OBJECT
public:
    explicit MenuHandler(QObject *parent = nullptr);
    ~MenuHandler();

    void setAboutToShowCallback(void (*callback)());
    void setAboutToHideCallback(void (*callback)());
    void setTriggeredCallback(void (*callback)(void* action));
    void setHoveredCallback(void (*callback)(void* action));

public slots:
    void onAboutToShow();
    void onAboutToHide();
    void onTriggered(QAction* action);
    void onHovered(QAction* action);

private:
    void (*m_aboutToShowCallback)();
    void (*m_aboutToHideCallback)();
    void (*m_triggeredCallback)(void* action);
    void (*m_hoveredCallback)(void* action);
};

#endif // HANDLER_MENU_H
