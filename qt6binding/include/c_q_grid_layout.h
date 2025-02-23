#ifndef C_Q_GRID_LAYOUT_H
#define C_Q_GRID_LAYOUT_H

#ifdef __cplusplus
extern "C" {
#endif

void* QGridLayout_create();
void QGridLayout_addWidget(void* layout, void* widget, int row, int column);

#ifdef __cplusplus
}
#endif

#endif // C_Q_GRID_LAYOUT_H
