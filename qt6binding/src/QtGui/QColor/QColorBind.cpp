#include "QColorBind.h"

BindQColor::BindQColor()
    : QColor() {
}

BindQColor::BindQColor(QRgb color) 
    : QColor(color) {
}

BindQColor::BindQColor(QRgba64 rgba64)
    : QColor(rgba64) {
}

BindQColor::BindQColor(const QString &name)
    : QColor(name) {
}

BindQColor::BindQColor(int r, int g, int b, int a)
    : QColor(r, g, b, a) {
}

BindQColor::BindQColor(QLatin1StringView name)
    : QColor(name) {
}

BindQColor::BindQColor(Qt::GlobalColor color)
    : QColor(color) {
}

BindQColor::BindQColor(const char *name)
    : QColor(QString::fromUtf8(name)) {
}

BindQColor::~BindQColor() {
}
