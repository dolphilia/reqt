#ifndef BIND_Q_TOOL_BAR_H
#define BIND_Q_TOOL_BAR_H

#include <QToolBar>
#include "handler_tool_bar.h"

class BindQToolBar : public QToolBar {
    Q_OBJECT
public:
    explicit BindQToolBar(QWidget *parent = nullptr);
    explicit BindQToolBar(const QString &title, QWidget *parent = nullptr);
    ~BindQToolBar();

    void setToolBarHandler(ToolBarHandler *handler);
    ToolBarHandler *handler() const;

private:
    ToolBarHandler *m_handler;
};

#endif // BIND_Q_TOOL_BAR_H
