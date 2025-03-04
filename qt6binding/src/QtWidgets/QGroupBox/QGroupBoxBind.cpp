#include "QGroupBoxBind.h"
#include "QGroupBoxHandler.h"

QGroupBoxBind::QGroupBoxBind(QWidget* parent)
    : QGroupBox(parent)
    , handler(new QGroupBoxHandler(this)) {
    connect(this, &QGroupBox::toggled, handler, &QGroupBoxHandler::onToggled);
}

QGroupBoxBind::QGroupBoxBind(const QString& title, QWidget* parent)
    : QGroupBox(title, parent)
    , handler(new QGroupBoxHandler(this)) {
    connect(this, &QGroupBox::toggled, handler, &QGroupBoxHandler::onToggled);
}

QGroupBoxBind::~QGroupBoxBind() {
    delete handler;
}

void QGroupBoxBind::setToggledCallback(QGroupBox_ToggledCallback callback) const {
    handler->setToggledCallback(callback);
}
