#ifndef QSTATUSBAR_C_H
#define QSTATUSBAR_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void* QStatusBar_create(void* parent);
void QStatusBar_delete(void* statusBar);
void QStatusBar_showMessage(void* statusBar, const char* message);
void QStatusBar_clearMessage(void* statusBar);
void QStatusBar_setEnabled(void* statusBar, bool enabled);
bool QStatusBar_isEnabled(void* statusBar);

#ifdef __cplusplus
}
#endif

#endif // QSTATUSBAR_C_H
