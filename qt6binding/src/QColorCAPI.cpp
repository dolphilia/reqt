#include "qcolor.h"
#include "QColorBind.h"

extern "C" {

void* QColor_create()
{
    return new BindQColor();
}

void* QColor_createWithRgb(int r, int g, int b, int a)
{
    return new BindQColor(r, g, b, a);
}

void* QColor_createWithName(const char* name)
{
    return new BindQColor(QString::fromUtf8(name));
}

void QColor_delete(void* color)
{
    delete static_cast<BindQColor*>(color);
}

void QColor_setRgb(void* color, int r, int g, int b, int a)
{
    static_cast<BindQColor*>(color)->setRgb(r, g, b, a);
}

void QColor_getRgb(void* color, int* r, int* g, int* b, int* a)
{
    static_cast<BindQColor*>(color)->getRgb(r, g, b, a);
}

int QColor_red(void* color)
{
    return static_cast<BindQColor*>(color)->red();
}

int QColor_green(void* color)
{
    return static_cast<BindQColor*>(color)->green();
}

int QColor_blue(void* color)
{
    return static_cast<BindQColor*>(color)->blue();
}

int QColor_alpha(void* color)
{
    return static_cast<BindQColor*>(color)->alpha();
}

void QColor_setHsv(void* color, int h, int s, int v, int a)
{
    static_cast<BindQColor*>(color)->setHsv(h, s, v, a);
}

void QColor_getHsv(void* color, int* h, int* s, int* v, int* a)
{
    static_cast<BindQColor*>(color)->getHsv(h, s, v, a);
}

int QColor_hue(void* color)
{
    return static_cast<BindQColor*>(color)->hue();
}

int QColor_saturation(void* color)
{
    return static_cast<BindQColor*>(color)->saturation();
}

int QColor_value(void* color)
{
    return static_cast<BindQColor*>(color)->value();
}

void QColor_setHsl(void* color, int h, int s, int l, int a)
{
    static_cast<BindQColor*>(color)->setHsl(h, s, l, a);
}

void QColor_getHsl(void* color, int* h, int* s, int* l, int* a)
{
    static_cast<BindQColor*>(color)->getHsl(h, s, l, a);
}

int QColor_lightness(void* color)
{
    return static_cast<BindQColor*>(color)->lightness();
}

void QColor_setCmyk(void* color, int c, int m, int y, int k, int a)
{
    static_cast<BindQColor*>(color)->setCmyk(c, m, y, k, a);
}

void QColor_getCmyk(void* color, int* c, int* m, int* y, int* k, int* a)
{
    static_cast<BindQColor*>(color)->getCmyk(c, m, y, k, a);
}

int QColor_cyan(void* color)
{
    return static_cast<BindQColor*>(color)->cyan();
}

int QColor_magenta(void* color)
{
    return static_cast<BindQColor*>(color)->magenta();
}

int QColor_yellow(void* color)
{
    return static_cast<BindQColor*>(color)->yellow();
}

int QColor_black(void* color)
{
    return static_cast<BindQColor*>(color)->black();
}

const char* QColor_name(void* color)
{
    static QString name;
    name = static_cast<BindQColor*>(color)->name();
    return name.toUtf8().constData();
}

void QColor_setNamedColor(void* color, const char* name)
{
    static_cast<BindQColor*>(color)->fromString(QString::fromUtf8(name));
}

bool QColor_isValid(void* color)
{
    return static_cast<BindQColor*>(color)->isValid();
}

void* QColor_lighter(void* color, int factor)
{
    QColor lighter = static_cast<BindQColor*>(color)->lighter(factor);
    return new BindQColor(lighter.red(), lighter.green(), lighter.blue(), lighter.alpha());
}

void* QColor_darker(void* color, int factor)
{
    QColor darker = static_cast<BindQColor*>(color)->darker(factor);
    return new BindQColor(darker.red(), darker.green(), darker.blue(), darker.alpha());
}

}
