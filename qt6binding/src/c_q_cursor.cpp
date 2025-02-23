#include "../include/c_q_cursor.h"
#include "../include/bind_q_cursor.h"
#include <QPoint>

void* QCursor_create() {
    return new BindQCursor();
}

void* QCursor_create_with_shape(int shape) {
    return new BindQCursor(static_cast<Qt::CursorShape>(shape));
}

void QCursor_delete(void* cursor) {
    delete static_cast<BindQCursor*>(cursor);
}

void QCursor_setShape(void* cursor, int shape) {
    static_cast<BindQCursor*>(cursor)->setShape(static_cast<Qt::CursorShape>(shape));
}

int QCursor_shape(void* cursor) {
    return static_cast<int>(static_cast<BindQCursor*>(cursor)->shape());
}

void QCursor_setPos(int x, int y) {
    BindQCursor::setPos(x, y);
}

void QCursor_setPos_point(void* point) {
    BindQCursor::setPos(*static_cast<QPoint*>(point));
}

void QCursor_pos(int* x, int* y) {
    QPoint pos = BindQCursor::pos();
    *x = pos.x();
    *y = pos.y();
}
