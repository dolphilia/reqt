#ifndef HANDLER_TOOL_BUTTON_H
#define HANDLER_TOOL_BUTTON_H

#include <QObject>

class ToolButtonHandler : public QObject {
    Q_OBJECT
public:
    explicit ToolButtonHandler(QObject *parent = nullptr);
    ~ToolButtonHandler();

    void setClickedCallback(void (*callback)());
    void setToggledCallback(void (*callback)(bool checked));
    void setTriggeredCallback(void (*callback)());

public slots:
    void onClicked();
    void onToggled(bool checked);
    void onTriggered();

private:
    void (*m_clickedCallback)();
    void (*m_toggledCallback)(bool checked);
    void (*m_triggeredCallback)();
};

#endif // HANDLER_TOOL_BUTTON_H
