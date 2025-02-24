#ifndef QVBOXLAYOUT_C_H
#define QVBOXLAYOUT_C_H

#ifdef __cplusplus
extern "C" {
#endif

// QVBoxLayout
void* QVBoxLayout_create(void* parent);
void QVBoxLayout_delete(void* layout);
void QVBoxLayout_addWidget(void* layout, void* widget);
void QVBoxLayout_addLayout(void* layout, void* other);
void QVBoxLayout_addStretch(void* layout, int stretch);
void QVBoxLayout_addSpacing(void* layout, int size);
void QVBoxLayout_setSpacing(void* layout, int spacing);
int QVBoxLayout_spacing(void* layout);
void QVBoxLayout_setContentsMargins(void* layout, int left, int top, int right, int bottom);
void QVBoxLayout_getContentsMargins(void* layout, int* left, int* top, int* right, int* bottom);

#ifdef __cplusplus
}
#endif

#endif // QVBOXLAYOUT_C_H
