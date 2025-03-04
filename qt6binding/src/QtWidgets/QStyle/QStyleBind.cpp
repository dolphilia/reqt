#include "QStyleBind.h"
#include "QStyleHandler.h"

QStyleBind::QStyleBind(QObject* parent)
    : QObject(parent)
    , handler(new QStyleHandler(this)) {
    // QStyleはシグナルを持たないため、現時点では特別な接続は必要ありません
}

QStyleBind::~QStyleBind() {
    delete handler;
}
