#ifndef HANDLER_TOOL_BOX_H
#define HANDLER_TOOL_BOX_H

#include <QObject>

class ToolBoxHandler : public QObject {
    Q_OBJECT
public:
    explicit ToolBoxHandler(QObject *parent = nullptr);
    ~ToolBoxHandler();

    void setCurrentChangedCallback(void (*callback)(int index));

public slots:
    void onCurrentChanged(int index);

private:
    void (*m_currentChangedCallback)(int index);
};

#endif // HANDLER_TOOL_BOX_H
