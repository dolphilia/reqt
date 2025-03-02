#ifndef QSTYLE_BIND_H
#define QSTYLE_BIND_H

#include <QStyle>
#include <QApplication>
#include <QStyleFactory>

class QStyleBind {
public:
    static QStyle* getStyle(const char* styleName);
    static void getAvailableStyles(const char*** styles, int* count);
    static void freeStyleList(const char** styles, int count);
    static void setStyle(QStyle* style);
};

#endif // QSTYLE_BIND_H
