#include "QPointFBind.h"

QPointFBind::QPointFBind() {}
QPointFBind::QPointFBind(QPoint* point) {}
QPointFBind::QPointFBind(double x, double y) {}

// QPointF* QPointFBind::create() {
//     return new QPointF();
// }

// QPointF* QPointFBind::createFromPoint(QPoint* point) {
//     if (point) {
//         return new QPointF(*point);
//     }
//     return nullptr;
// }

// QPointF* QPointFBind::createWithCoords(double x, double y) {
//     return new QPointF(x, y);
// }

// void QPointFBind::destroy(QPointF* point) {
//     if (point) {
//         delete point;
//     }
// }

// bool QPointFBind::isNull(QPointF* point) {
//     if (point) {
//         return point->isNull();
//     }
//     return true;
// }

// double QPointFBind::manhattanLength(QPointF* point) {
//     if (point) {
//         return point->manhattanLength();
//     }
//     return 0.0;
// }

// double QPointFBind::x(QPointF* point) {
//     if (point) {
//         return point->x();
//     }
//     return 0.0;
// }

// double QPointFBind::y(QPointF* point) {
//     if (point) {
//         return point->y();
//     }
//     return 0.0;
// }

// void QPointFBind::setX(QPointF* point, double x) {
//     if (point) {
//         point->setX(x);
//     }
// }

// void QPointFBind::setY(QPointF* point, double y) {
//     if (point) {
//         point->setY(y);
//     }
// }

// QPoint* QPointFBind::toPoint(QPointF* point) {
//     if (point) {
//         return new QPoint(point->toPoint());
//     }
//     return nullptr;
// }

// QPointF* QPointFBind::transposed(QPointF* point) {
//     if (point) {
//         return new QPointF(point->transposed());
//     }
//     return nullptr;
// }

// QPointF* QPointFBind::add(QPointF* point1, QPointF* point2) {
//     if (point1 && point2) {
//         return new QPointF(*point1 + *point2);
//     }
//     return nullptr;
// }

// QPointF* QPointFBind::subtract(QPointF* point1, QPointF* point2) {
//     if (point1 && point2) {
//         return new QPointF(*point1 - *point2);
//     }
//     return nullptr;
// }

// QPointF* QPointFBind::multiply(QPointF* point, double factor) {
//     if (point) {
//         return new QPointF(*point * factor);
//     }
//     return nullptr;
// }

// QPointF* QPointFBind::divide(QPointF* point, double divisor) {
//     if (point && divisor != 0.0) {
//         return new QPointF(*point / divisor);
//     }
//     return nullptr;
// }

// double QPointFBind::dotProduct(QPointF* point1, QPointF* point2) {
//     if (point1 && point2) {
//         return QPointF::dotProduct(*point1, *point2);
//     }
//     return 0.0;
// }
