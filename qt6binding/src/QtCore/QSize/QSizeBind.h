#ifndef QSIZE_BIND_H
#define QSIZE_BIND_H

#include <QSize>

class QSizeBind : public QSize {
public:
    explicit QSizeBind();
    explicit QSizeBind(int width, int height);
    ~QSizeBind();
};

#endif // QSIZE_BIND_H