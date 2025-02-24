#ifndef BIND_Q_SCROLL_BAR_H
#define BIND_Q_SCROLL_BAR_H

#include <QScrollBar>
#include "QScrollBarHandler.h"

class BindQScrollBar : public QScrollBar {
    Q_OBJECT
public:
    explicit BindQScrollBar(QWidget *parent = nullptr);
    explicit BindQScrollBar(Qt::Orientation orientation, QWidget *parent = nullptr);
    ~BindQScrollBar();

    void setScrollBarHandler(ScrollBarHandler *handler);
    ScrollBarHandler *handler() const;

private:
    ScrollBarHandler *m_handler;
};

#endif // BIND_Q_SCROLL_BAR_H
