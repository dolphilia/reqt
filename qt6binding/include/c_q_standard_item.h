#ifndef QSTANDARDITEM_C_H
#define QSTANDARDITEM_C_H

#ifdef __cplusplus
extern "C" {
#endif

void* QStandardItem_create(const char* text);
void QStandardItem_delete(void* item);
void QStandardItem_setText(void* item, const char* text);
void QStandardItem_appendRow(void* item, void* child);

#ifdef __cplusplus
}
#endif

#endif // QSTANDARDITEM_C_H
