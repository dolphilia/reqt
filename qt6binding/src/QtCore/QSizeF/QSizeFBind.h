#ifndef QSIZEF_BIND_H
#define QSIZEF_BIND_H

#include <QSizeF>
#include <QSize>

class QSizeFBind : public QSizeF {
public:
    explicit QSizeFBind();
    explicit QSizeFBind(const QSize &size);
    explicit QSizeFBind(qreal width, qreal height);
    ~QSizeFBind();
};

#endif // QSIZEF_BIND_H