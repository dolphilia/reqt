#ifndef BIND_Q_TOOL_BUTTON_H
#define BIND_Q_TOOL_BUTTON_H

#include <QToolButton>
#include "QToolButtonHandler.h"

class BindQToolButton : public QToolButton {
    Q_OBJECT
public:
    explicit BindQToolButton(QWidget *parent = nullptr);
    ~BindQToolButton();

    void setToolButtonHandler(ToolButtonHandler *handler);
    ToolButtonHandler *handler() const;

private:
    ToolButtonHandler *m_handler;
};

#endif // BIND_Q_TOOL_BUTTON_H
