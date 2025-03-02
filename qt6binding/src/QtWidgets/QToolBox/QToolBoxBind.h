#ifndef BIND_Q_TOOL_BOX_H
#define BIND_Q_TOOL_BOX_H

#include <QToolBox>
#include "QToolBoxHandler.h"

class BindQToolBox : public QToolBox {
    Q_OBJECT
public:
    explicit BindQToolBox(QWidget *parent = nullptr);
    ~BindQToolBox();

    void setToolBoxHandler(ToolBoxHandler *handler);
    ToolBoxHandler *handler() const;

private:
    ToolBoxHandler *m_handler;
};

#endif // BIND_Q_TOOL_BOX_H
