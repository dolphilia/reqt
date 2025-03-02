#include "QPointBind.h"

QPoint* QPointBind::create() {
    return new QPoint();
}

QPoint* QPointBind::createWithCoords(int x, int y) {
    return new QPoint(x, y);
}

void QPointBind::destroy(QPoint* point) {
    if (point) {
        delete point;
    }
}

bool QPointBind::isNull(QPoint* point) {
    if (point) {
        return point->isNull();
    }
    return true;
}

int QPointBind::manhattanLength(QPoint* point) {
    if (point) {
        return point->manhattanLength();
    }
    return 0;
}

int QPointBind::x(QPoint* point) {
    if (point) {
        return point->x();
    }
    return 0;
}

int QPointBind::y(QPoint* point) {
    if (point) {
        return point->y();
    }
    return 0;
}

void QPointBind::setX(QPoint* point, int x) {
    if (point) {
        point->setX(x);
    }
}

void QPointBind::setY(QPoint* point, int y) {
    if (point) {
        point->setY(y);
    }
}

QPointF* QPointBind::toPointF(QPoint* point) {
    if (point) {
        return new QPointF(point->toPointF());
    }
    return nullptr;
}

QPoint* QPointBind::transposed(QPoint* point) {
    if (point) {
        return new QPoint(point->transposed());
    }
    return nullptr;
}

QPoint* QPointBind::add(QPoint* point1, QPoint* point2) {
    if (point1 && point2) {
        return new QPoint(*point1 + *point2);
    }
    return nullptr;
}

QPoint* QPointBind::subtract(QPoint* point1, QPoint* point2) {
    if (point1 && point2) {
        return new QPoint(*point1 - *point2);
    }
    return nullptr;
}

QPoint* QPointBind::multiplyInt(QPoint* point, int factor) {
    if (point) {
        return new QPoint(*point * factor);
    }
    return nullptr;
}

QPoint* QPointBind::multiplyFloat(QPoint* point, float factor) {
    if (point) {
        return new QPoint(*point * factor);
    }
    return nullptr;
}

QPoint* QPointBind::multiplyDouble(QPoint* point, double factor) {
    if (point) {
        return new QPoint(*point * factor);
    }
    return nullptr;
}

QPoint* QPointBind::divideReal(QPoint* point, double divisor) {
    if (point && divisor != 0.0) {
        return new QPoint(*point / divisor);
    }
    return nullptr;
}
