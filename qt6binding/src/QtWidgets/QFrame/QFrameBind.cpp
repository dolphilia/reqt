#include "QFrameBind.h"
#include "QFrameHandler.h"

QFrameBind::QFrameBind(QWidget* parent, Qt::WindowFlags f)
    : QFrame(parent, f)
    , handler(new FrameHandler(this)) {
}

QFrameBind::~QFrameBind() {
    delete handler;
}
