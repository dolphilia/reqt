#include "QSizeGripBind.h"
#include "QSizeGripHandler.h"

QSizeGripBind::QSizeGripBind(QWidget* parent)
    : QSizeGrip(parent)
    , handler(new QSizeGripHandler(this)) {
    // QSizeGripには特定のシグナルがないため、必要に応じて接続を追加できます
}

QSizeGripBind::~QSizeGripBind() {
    delete handler;
}
