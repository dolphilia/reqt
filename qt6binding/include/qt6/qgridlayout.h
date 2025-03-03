#ifndef C_Q_GRID_LAYOUT_H
#define C_Q_GRID_LAYOUT_H

#ifdef __cplusplus
extern "C" {
#endif

void* QGridLayout_create(void* parent);
void QGridLayout_delete(void* gridLayout);
void QGridLayout_addWidget(void* gridLayout, void* widget, int row, int column);
void QGridLayout_addLayout(void* gridLayout, void* layout, int row, int column);
void QGridLayout_addLayoutWithSpan(void* gridLayout, void* layout, int row, int column, int rowSpan, int columnSpan);
void QGridLayout_addWidgetWithSpan(void* gridLayout, void* widget, int row, int column, int rowSpan, int columnSpan);
int QGridLayout_rowCount(void* gridLayout);
int QGridLayout_columnCount(void* gridLayout);
void QGridLayout_setRowStretch(void* gridLayout, int row, int stretch);
void QGridLayout_setColumnStretch(void* gridLayout, int column, int stretch);
void QGridLayout_setRowMinimumHeight(void* gridLayout, int row, int minSize);
void QGridLayout_setColumnMinimumWidth(void* gridLayout, int column, int minSize);
void QGridLayout_setHorizontalSpacing(void* gridLayout, int spacing);
void QGridLayout_setVerticalSpacing(void* gridLayout, int spacing);
int QGridLayout_horizontalSpacing(void* gridLayout);
int QGridLayout_verticalSpacing(void* gridLayout);
void QGridLayout_setSpacing(void* gridLayout, int spacing);
int QGridLayout_spacing(void* gridLayout);

typedef void (*CellEmptyChangedCallback)(void*, int, int);

void QGridLayout_setCellEmptyChangedCallback(void* gridLayout, CellEmptyChangedCallback callback);

#ifdef __cplusplus
}
#endif

#endif // C_Q_GRID_LAYOUT_H
