#ifndef QHBOXLAYOUT_C_H
#define QHBOXLAYOUT_C_H

#ifdef __cplusplus
extern "C" {
#endif

// QHBoxLayout
void* QHBoxLayout_create(void* parent);
void QHBoxLayout_delete(void* layout);
void QHBoxLayout_addWidget(void* layout, void* widget);
void QHBoxLayout_addLayout(void* layout, void* other);
void QHBoxLayout_addStretch(void* layout, int stretch);
void QHBoxLayout_addSpacing(void* layout, int size);
void QHBoxLayout_setSpacing(void* layout, int spacing);
int QHBoxLayout_spacing(void* layout);
void QHBoxLayout_setContentsMargins(void* layout, int left, int top, int right, int bottom);
void QHBoxLayout_getContentsMargins(void* layout, int* left, int* top, int* right, int* bottom);

#ifdef __cplusplus
}
#endif

#endif // QHBOXLAYOUT_C_H
