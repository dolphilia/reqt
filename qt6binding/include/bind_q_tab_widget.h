#ifndef BIND_Q_TAB_WIDGET_H
#define BIND_Q_TAB_WIDGET_H

#include <QTabWidget>
#include "handler_tab_widget.h"

class BindQTabWidget : public QTabWidget {
    Q_OBJECT
public:
    explicit BindQTabWidget(QWidget *parent = nullptr);
    ~BindQTabWidget();

    void setTabWidgetHandler(TabWidgetHandler *handler);
    TabWidgetHandler *handler() const;

private:
    TabWidgetHandler *m_handler;
};

#endif // BIND_Q_TAB_WIDGET_H
