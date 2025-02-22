#ifndef QSTYLE_C_H
#define QSTYLE_C_H

#ifdef __cplusplus
extern "C" {
#endif

// QStyle
void* QStyle_getStyle(const char* styleName);
void QStyle_getAvailableStyles(const char*** styles, int* count);
void QStyle_freeStyleList(const char** styles, int count);
void QStyle_setStyle(void* style);

#ifdef __cplusplus
}
#endif

#endif // QSTYLE_C_H
