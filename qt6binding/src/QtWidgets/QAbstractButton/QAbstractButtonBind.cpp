#include "QAbstractButtonBind.h"
#include "QAbstractButtonHandler.h"
#include <QPainter>

QAbstractButtonBind::QAbstractButtonBind(QWidget* parent)
    : QAbstractButton(parent)
    , handler(new QAbstractButtonHandler(this))
{
    connect(this, &QAbstractButton::clicked, handler, &QAbstractButtonHandler::onClicked);
    connect(this, &QAbstractButton::pressed, handler, &QAbstractButtonHandler::onPressed);
    connect(this, &QAbstractButton::released, handler, &QAbstractButtonHandler::onReleased);
    connect(this, &QAbstractButton::toggled, handler, &QAbstractButtonHandler::onToggled);
}

QAbstractButtonBind::~QAbstractButtonBind() {
    delete handler;
}

void QAbstractButtonBind::setClickedCallback(ClickCallback callback) const {
    handler->setClickedCallback(callback);
}

void QAbstractButtonBind::setPressedCallback(PressCallback callback) const {
    handler->setPressedCallback(callback);
}

void QAbstractButtonBind::setReleasedCallback(ReleaseCallback callback) const {
    handler->setReleasedCallback(callback);
}

void QAbstractButtonBind::setToggledCallback(ToggleCallback callback) const {
    handler->setToggledCallback(callback);
}

bool QAbstractButtonBind::hitButton(const QPoint &pos) const {
    return rect().contains(pos); // 単純にウィジェット全体をクリック可能領域とする
}

void QAbstractButtonBind::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawRect(rect()); // 最小限の描画：背景の矩形などを描く（本来は適切なスタイルを適用するべき）
}