#include "QColorBind.h"

BindQColor::BindQColor()
    : QColor()
{
}

BindQColor::BindQColor(int r, int g, int b, int a)
    : QColor(r, g, b, a)
{
}

BindQColor::BindQColor(const QString &name)
    : QColor(name)
{
}

BindQColor::~BindQColor()
{
}
