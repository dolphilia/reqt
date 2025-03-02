#include "QAbstractButtonBind.h"
#include <QIcon>
#include <QSize>
#include <QKeySequence>

extern "C" {

// コンストラクタ/デストラクタ
// QAbstractButtonは抽象クラスなのでインスタンス化できない
// 実際には、QPushButtonなどの具体的なサブクラスを使用する
void* QAbstractButton_create(void* parent) {
    return QAbstractButtonBind::create(static_cast<QWidget*>(parent));
}

void QAbstractButton_delete(void* button) {
    QAbstractButtonBind::destroy(static_cast<QAbstractButton*>(button));
}

// プロパティ取得
bool QAbstractButton_autoExclusive(void* button) {
    return QAbstractButtonBind::autoExclusive(static_cast<QAbstractButton*>(button));
}

bool QAbstractButton_autoRepeat(void* button) {
    return QAbstractButtonBind::autoRepeat(static_cast<QAbstractButton*>(button));
}

int QAbstractButton_autoRepeatDelay(void* button) {
    return QAbstractButtonBind::autoRepeatDelay(static_cast<QAbstractButton*>(button));
}

int QAbstractButton_autoRepeatInterval(void* button) {
    return QAbstractButtonBind::autoRepeatInterval(static_cast<QAbstractButton*>(button));
}

void* QAbstractButton_group(void* button) {
    return QAbstractButtonBind::group(static_cast<QAbstractButton*>(button));
}

void* QAbstractButton_icon(void* button) {
    return QAbstractButtonBind::icon(static_cast<QAbstractButton*>(button));
}

void* QAbstractButton_iconSize(void* button) {
    return QAbstractButtonBind::iconSize(static_cast<QAbstractButton*>(button));
}

bool QAbstractButton_isCheckable(void* button) {
    return QAbstractButtonBind::isCheckable(static_cast<QAbstractButton*>(button));
}

bool QAbstractButton_isChecked(void* button) {
    return QAbstractButtonBind::isChecked(static_cast<QAbstractButton*>(button));
}

bool QAbstractButton_isDown(void* button) {
    return QAbstractButtonBind::isDown(static_cast<QAbstractButton*>(button));
}

void* QAbstractButton_shortcut(void* button) {
    return QAbstractButtonBind::shortcut(static_cast<QAbstractButton*>(button));
}

void* QAbstractButton_text(void* button) {
    return QAbstractButtonBind::text(static_cast<QAbstractButton*>(button));
}

// プロパティ設定
void QAbstractButton_setAutoExclusive(void* button, bool autoExclusive) {
    QAbstractButtonBind::setAutoExclusive(static_cast<QAbstractButton*>(button), autoExclusive);
}

void QAbstractButton_setAutoRepeat(void* button, bool autoRepeat) {
    QAbstractButtonBind::setAutoRepeat(static_cast<QAbstractButton*>(button), autoRepeat);
}

void QAbstractButton_setAutoRepeatDelay(void* button, int delay) {
    QAbstractButtonBind::setAutoRepeatDelay(static_cast<QAbstractButton*>(button), delay);
}

void QAbstractButton_setAutoRepeatInterval(void* button, int interval) {
    QAbstractButtonBind::setAutoRepeatInterval(static_cast<QAbstractButton*>(button), interval);
}

void QAbstractButton_setCheckable(void* button, bool checkable) {
    QAbstractButtonBind::setCheckable(static_cast<QAbstractButton*>(button), checkable);
}

void QAbstractButton_setDown(void* button, bool down) {
    QAbstractButtonBind::setDown(static_cast<QAbstractButton*>(button), down);
}

void QAbstractButton_setIcon(void* button, void* icon) {
    QAbstractButtonBind::setIcon(static_cast<QAbstractButton*>(button), static_cast<QIcon*>(icon));
}

void QAbstractButton_setIconSize(void* button, void* size) {
    QAbstractButtonBind::setIconSize(static_cast<QAbstractButton*>(button), static_cast<QSize*>(size));
}

void QAbstractButton_setShortcut(void* button, void* shortcut) {
    QAbstractButtonBind::setShortcut(static_cast<QAbstractButton*>(button), static_cast<QKeySequence*>(shortcut));
}

void QAbstractButton_setText(void* button, const char* text) {
    QAbstractButtonBind::setText(static_cast<QAbstractButton*>(button), text);
}

void QAbstractButton_setChecked(void* button, bool checked) {
    QAbstractButtonBind::setChecked(static_cast<QAbstractButton*>(button), checked);
}

// アクション
void QAbstractButton_animateClick(void* button) {
    QAbstractButtonBind::animateClick(static_cast<QAbstractButton*>(button));
}

void QAbstractButton_click(void* button) {
    QAbstractButtonBind::click(static_cast<QAbstractButton*>(button));
}

void QAbstractButton_toggle(void* button) {
    QAbstractButtonBind::toggle(static_cast<QAbstractButton*>(button));
}

// シグナルハンドラ設定
void QAbstractButton_setClickedCallback(void* button, void (*callback)(void*, bool), void* data) {
    QAbstractButtonBind::setClickedCallback(static_cast<QAbstractButton*>(button), callback, data);
}

void QAbstractButton_setPressedCallback(void* button, void (*callback)(void*), void* data) {
    QAbstractButtonBind::setPressedCallback(static_cast<QAbstractButton*>(button), callback, data);
}

void QAbstractButton_setReleasedCallback(void* button, void (*callback)(void*), void* data) {
    QAbstractButtonBind::setReleasedCallback(static_cast<QAbstractButton*>(button), callback, data);
}

void QAbstractButton_setToggledCallback(void* button, void (*callback)(void*, bool), void* data) {
    QAbstractButtonBind::setToggledCallback(static_cast<QAbstractButton*>(button), callback, data);
}

}
