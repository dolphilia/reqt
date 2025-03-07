#ifndef BIND_Q_COLOR_H
#define BIND_Q_COLOR_H

#include <QColor>

class BindQColor : public QColor {
public:
    explicit BindQColor();
    explicit BindQColor(QRgb color);
    explicit BindQColor(QRgba64 rgba64);
    explicit BindQColor(const QString &name);
    explicit BindQColor(int r, int g, int b, int a = 255);
    explicit BindQColor(QLatin1StringView name);
    explicit BindQColor(Qt::GlobalColor color);
    explicit BindQColor(const char *name);



    ~BindQColor();
};

#endif // BIND_Q_COLOR_H
