#ifndef BIND_Q_COLOR_H
#define BIND_Q_COLOR_H

#include <QColor>

class BindQColor : public QColor {
public:
    BindQColor();
    BindQColor(int r, int g, int b, int a = 255);
    explicit BindQColor(const QString &name);
    ~BindQColor();
};

#endif // BIND_Q_COLOR_H
