#ifndef QSTRINGLISTMODEL_C_H
#define QSTRINGLISTMODEL_C_H

#ifdef __cplusplus
extern "C" {
#endif

void* QStringListModel_create(void* parent);
void QStringListModel_delete(void* model);
void QStringListModel_addItem(void* model, const char* text);
void QStringListModel_removeItem(void* model, int row);
void QStringListModel_setItem(void* model, int row, const char* text);
const char* QStringListModel_item(void* model, int row);
int QStringListModel_rowCount(void* model);
void QStringListModel_clear(void* model);

#ifdef __cplusplus
}
#endif

#endif // QSTRINGLISTMODEL_C_H
