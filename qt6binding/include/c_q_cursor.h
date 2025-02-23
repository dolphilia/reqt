#ifndef C_Q_CURSOR_H
#define C_Q_CURSOR_H

#ifdef __cplusplus
extern "C" {
#endif

// カーソル形状の定数
#define QCURSOR_ARROW 0
#define QCURSOR_UP_ARROW 1
#define QCURSOR_CROSS 2
#define QCURSOR_WAIT 3
#define QCURSOR_IBEAM 4
#define QCURSOR_SIZE_VER 5
#define QCURSOR_SIZE_HOR 6
#define QCURSOR_SIZE_BDIAG 7
#define QCURSOR_SIZE_FDIAG 8
#define QCURSOR_SIZE_ALL 9
#define QCURSOR_BLANK 10
#define QCURSOR_SPLIT_V 11
#define QCURSOR_SPLIT_H 12
#define QCURSOR_POINTING_HAND 13
#define QCURSOR_FORBIDDEN 14
#define QCURSOR_WHATS_THIS 15
#define QCURSOR_BUSY 16
#define QCURSOR_OPEN_HAND 17
#define QCURSOR_CLOSED_HAND 18
#define QCURSOR_DRAG_COPY 19
#define QCURSOR_DRAG_MOVE 20
#define QCURSOR_DRAG_LINK 21

// 関数プロトタイプ
void* QCursor_create();
void* QCursor_create_with_shape(int shape);
void QCursor_delete(void* cursor);
void QCursor_setShape(void* cursor, int shape);
int QCursor_shape(void* cursor);
void QCursor_setPos(int x, int y);
void QCursor_setPos_point(void* point);
void QCursor_pos(int* x, int* y);

#ifdef __cplusplus
}
#endif

#endif // C_Q_CURSOR_H
