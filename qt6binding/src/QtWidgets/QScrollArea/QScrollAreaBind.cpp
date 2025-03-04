#include "QScrollAreaBind.h"
#include "QScrollAreaHandler.h"
#include <QScrollBar>

QScrollAreaBind::QScrollAreaBind(QWidget* parent)
    : QScrollArea(parent)
    , handler(new QScrollAreaHandler(this)) {
    connect(verticalScrollBar(), &QScrollBar::valueChanged, handler, &QScrollAreaHandler::onVerticalScrollBarValueChanged);
    connect(horizontalScrollBar(), &QScrollBar::valueChanged, handler, &QScrollAreaHandler::onHorizontalScrollBarValueChanged);
}

QScrollAreaBind::~QScrollAreaBind() {
    delete handler;
}

void QScrollAreaBind::setVerticalScrollBarValueChangedCallback(QScrollArea_VerticalScrollBarValueChangedCallback callback) const {
    handler->setVerticalScrollCallback(callback);
}

void QScrollAreaBind::setHorizontalScrollBarValueChangedCallback(QScrollArea_HorizontalScrollBarValueChangedCallback callback) const {
    handler->setHorizontalScrollCallback(callback);
}
