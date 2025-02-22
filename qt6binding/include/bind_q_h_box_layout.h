#ifndef QHBOXLAYOUT_BIND_H
#define QHBOXLAYOUT_BIND_H

#include <QHBoxLayout>

class QHBoxLayoutBind {
public:
    static QHBoxLayout* create(QWidget* parent = nullptr);
    static void destroy(QHBoxLayout* layout);
    static void addWidget(QHBoxLayout* layout, QWidget* widget);
    static void addLayout(QHBoxLayout* layout, QLayout* other);
    static void addStretch(QHBoxLayout* layout, int stretch = 0);
    static void addSpacing(QHBoxLayout* layout, int size);
    static void setSpacing(QHBoxLayout* layout, int spacing);
    static int spacing(QHBoxLayout* layout);
    static void setContentsMargins(QHBoxLayout* layout, int left, int top, int right, int bottom);
    static void getContentsMargins(QHBoxLayout* layout, int* left, int* top, int* right, int* bottom);
};

#endif // QHBOXLAYOUT_BIND_H
