#ifndef QSIZEGRIP_H
#define QSIZEGRIP_H

#ifdef __cplusplus
extern "C" {
#endif

void* QSizeGrip_create(void* parent);
void QSizeGrip_delete(void* sizeGrip);
void QSizeGrip_setVisible(void* sizeGrip, bool visible);
bool QSizeGrip_isVisible(void* sizeGrip);
void QSizeGrip_setEnabled(void* sizeGrip, bool enabled);
bool QSizeGrip_isEnabled(void* sizeGrip);

#ifdef __cplusplus
}
#endif

#endif // QSIZEGRIP_H
