#ifndef BIND_Q_CURSOR_H
#define BIND_Q_CURSOR_H

#include <QCursor>

class BindQCursor : public QCursor {
public:
    explicit BindQCursor();
    explicit BindQCursor(Qt::CursorShape shape);
    ~BindQCursor();

    static void setPos(int x, int y);
    static void setPos(const QPoint &p);
    static QPoint pos();
};

#endif // BIND_Q_CURSOR_H
