#ifndef HANDLER_TOOL_BAR_H
#define HANDLER_TOOL_BAR_H

#include <QObject>
#include <QAction>

class ToolBarHandler : public QObject {
    Q_OBJECT
public:
    explicit ToolBarHandler(QObject *parent = nullptr);
    ~ToolBarHandler();

    void setActionTriggeredCallback(void (*callback)(void* action));
    void setMovableChangedCallback(void (*callback)(bool movable));
    void setOrientationChangedCallback(void (*callback)(int orientation));
    void setTopLevelChangedCallback(void (*callback)(bool topLevel));
    void setVisibilityChangedCallback(void (*callback)(bool visible));
    void setAllowedAreasChangedCallback(void (*callback)(int areas));

public slots:
    void onActionTriggered(QAction* action);
    void onMovableChanged(bool movable);
    void onOrientationChanged(int orientation);
    void onTopLevelChanged(bool topLevel);
    void onVisibilityChanged(bool visible);
    void onAllowedAreasChanged(int areas);

private:
    void (*m_actionTriggeredCallback)(void* action);
    void (*m_movableChangedCallback)(bool movable);
    void (*m_orientationChangedCallback)(int orientation);
    void (*m_topLevelChangedCallback)(bool topLevel);
    void (*m_visibilityChangedCallback)(bool visible);
    void (*m_allowedAreasChangedCallback)(int areas);
};

#endif // HANDLER_TOOL_BAR_H
