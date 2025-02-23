#ifndef QCOLOR_C_H
#define QCOLOR_C_H

#ifdef __cplusplus
extern "C" {
#endif

// Creation/Deletion
void* QColor_create();
void* QColor_createWithRgb(int r, int g, int b, int a);
void* QColor_createWithName(const char* name);
void QColor_delete(void* color);

// RGB operations
void QColor_setRgb(void* color, int r, int g, int b, int a);
void QColor_getRgb(void* color, int* r, int* g, int* b, int* a);
int QColor_red(void* color);
int QColor_green(void* color);
int QColor_blue(void* color);
int QColor_alpha(void* color);

// HSV operations
void QColor_setHsv(void* color, int h, int s, int v, int a);
void QColor_getHsv(void* color, int* h, int* s, int* v, int* a);
int QColor_hue(void* color);
int QColor_saturation(void* color);
int QColor_value(void* color);

// HSL operations
void QColor_setHsl(void* color, int h, int s, int l, int a);
void QColor_getHsl(void* color, int* h, int* s, int* l, int* a);
int QColor_lightness(void* color);

// CMYK operations
void QColor_setCmyk(void* color, int c, int m, int y, int k, int a);
void QColor_getCmyk(void* color, int* c, int* m, int* y, int* k, int* a);
int QColor_cyan(void* color);
int QColor_magenta(void* color);
int QColor_yellow(void* color);
int QColor_black(void* color);

// Name operations
const char* QColor_name(void* color);
void QColor_setNamedColor(void* color, const char* name);

// Utility functions
bool QColor_isValid(void* color);
void* QColor_lighter(void* color, int factor);
void* QColor_darker(void* color, int factor);

#ifdef __cplusplus
}
#endif

#endif // QCOLOR_C_H
