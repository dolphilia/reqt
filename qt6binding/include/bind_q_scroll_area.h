#ifndef BIND_Q_SCROLL_AREA_H
#define BIND_Q_SCROLL_AREA_H

#include <QScrollArea>
#include "handler_scroll_area.h"

class BindQScrollArea : public QScrollArea {
    Q_OBJECT
public:
    explicit BindQScrollArea(QWidget *parent = nullptr);
    ~BindQScrollArea();

    void setScrollAreaHandler(ScrollAreaHandler *handler);
    ScrollAreaHandler *handler() const;

private:
    ScrollAreaHandler *m_handler;
};

#endif // BIND_Q_SCROLL_AREA_H
