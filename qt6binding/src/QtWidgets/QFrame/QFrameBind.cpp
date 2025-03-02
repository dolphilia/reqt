#include "QFrameBind.h"

QFrame* QFrameBind::create(QWidget* parent, Qt::WindowFlags f) {
    return new QFrame(parent, f);
}

void QFrameBind::destroy(QFrame* frame) {
    if (frame) {
        delete frame;
    }
}

QRect* QFrameBind::frameRect(QFrame* frame) {
    if (frame) {
        return new QRect(frame->frameRect());
    }
    return nullptr;
}

QFrame::Shadow QFrameBind::frameShadow(QFrame* frame) {
    if (frame) {
        return frame->frameShadow();
    }
    return QFrame::Plain;
}

QFrame::Shape QFrameBind::frameShape(QFrame* frame) {
    if (frame) {
        return frame->frameShape();
    }
    return QFrame::NoFrame;
}

int QFrameBind::frameStyle(QFrame* frame) {
    if (frame) {
        return frame->frameStyle();
    }
    return 0;
}

int QFrameBind::frameWidth(QFrame* frame) {
    if (frame) {
        return frame->frameWidth();
    }
    return 0;
}

int QFrameBind::lineWidth(QFrame* frame) {
    if (frame) {
        return frame->lineWidth();
    }
    return 0;
}

int QFrameBind::midLineWidth(QFrame* frame) {
    if (frame) {
        return frame->midLineWidth();
    }
    return 0;
}

QSize* QFrameBind::sizeHint(QFrame* frame) {
    if (frame) {
        return new QSize(frame->sizeHint());
    }
    return nullptr;
}

void QFrameBind::setFrameRect(QFrame* frame, QRect* rect) {
    if (frame && rect) {
        frame->setFrameRect(*rect);
    }
}

void QFrameBind::setFrameShadow(QFrame* frame, QFrame::Shadow shadow) {
    if (frame) {
        frame->setFrameShadow(shadow);
    }
}

void QFrameBind::setFrameShape(QFrame* frame, QFrame::Shape shape) {
    if (frame) {
        frame->setFrameShape(shape);
    }
}

void QFrameBind::setFrameStyle(QFrame* frame, int style) {
    if (frame) {
        frame->setFrameStyle(style);
    }
}

void QFrameBind::setLineWidth(QFrame* frame, int width) {
    if (frame) {
        frame->setLineWidth(width);
    }
}

void QFrameBind::setMidLineWidth(QFrame* frame, int width) {
    if (frame) {
        frame->setMidLineWidth(width);
    }
}
