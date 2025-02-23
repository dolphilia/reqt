#ifndef QSTANDARDITEMMODEL_C_H
#define QSTANDARDITEMMODEL_C_H

#ifdef __cplusplus
extern "C" {
#endif

void* QStandardItemModel_create(int rows, int columns, void* parent);
void QStandardItemModel_delete(void* model);
void QStandardItemModel_setItem(void* model, void* item, int row, int column);

#ifdef __cplusplus
}
#endif

#endif // QSTANDARDITEMMODEL_C_H
