#include "QGroupBoxBind.h"
#include "QGroupBoxHandler.h"

QGroupBoxBind::QGroupBoxBind(QWidget* parent)
    : QGroupBox(parent)
    , handler(new GroupBoxHandler(this)) {
    connect(this, &QGroupBox::toggled, handler, &GroupBoxHandler::onToggled);
}

QGroupBoxBind::QGroupBoxBind(const QString& title, QWidget* parent)
    : QGroupBox(title, parent)
    , handler(new GroupBoxHandler(this)) {
    connect(this, &QGroupBox::toggled, handler, &GroupBoxHandler::onToggled);
}

QGroupBoxBind::~QGroupBoxBind() {
    delete handler;
}

void QGroupBoxBind::setToggledCallback(ToggledCallback callback) const {
    handler->setToggledCallback(callback);
}
