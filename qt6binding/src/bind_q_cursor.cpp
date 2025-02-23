#include "../include/bind_q_cursor.h"

BindQCursor::BindQCursor()
    : QCursor()
{
}

BindQCursor::BindQCursor(Qt::CursorShape shape)
    : QCursor(shape)
{
}

BindQCursor::~BindQCursor()
{
}

void BindQCursor::setPos(int x, int y)
{
    QCursor::setPos(x, y);
}

void BindQCursor::setPos(const QPoint &p)
{
    QCursor::setPos(p);
}

QPoint BindQCursor::pos()
{
    return QCursor::pos();
}
