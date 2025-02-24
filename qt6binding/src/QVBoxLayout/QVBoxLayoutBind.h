#ifndef QVBOXLAYOUT_BIND_H
#define QVBOXLAYOUT_BIND_H

#include <QVBoxLayout>

class QVBoxLayoutBind {
public:
    static QVBoxLayout* create(QWidget* parent = nullptr);
    static void destroy(QVBoxLayout* layout);
    static void addWidget(QVBoxLayout* layout, QWidget* widget);
    static void addLayout(QVBoxLayout* layout, QLayout* other);
    static void addStretch(QVBoxLayout* layout, int stretch = 0);
    static void addSpacing(QVBoxLayout* layout, int size);
    static void setSpacing(QVBoxLayout* layout, int spacing);
    static int spacing(QVBoxLayout* layout);
    static void setContentsMargins(QVBoxLayout* layout, int left, int top, int right, int bottom);
    static void getContentsMargins(QVBoxLayout* layout, int* left, int* top, int* right, int* bottom);
};

#endif // QVBOXLAYOUT_BIND_H
