#include "QAbstractButtonBind.h"

extern "C" {

// コンストラクタ/デストラクタ
void* QAbstractButton_create(void* parent) {
    return new QAbstractButtonBind(static_cast<QWidget*>(parent));
}

void QAbstractButton_delete(void* button) {
    delete static_cast<QAbstractButtonBind*>(button);
}

// プロパティ取得
bool QAbstractButton_autoExclusive(void* button) {
    return static_cast<QAbstractButtonBind*>(button)->autoExclusive();
}

bool QAbstractButton_autoRepeat(void* button) {
    return static_cast<QAbstractButtonBind*>(button)->autoRepeat();
}

int QAbstractButton_autoRepeatDelay(void* button) {
    return static_cast<QAbstractButtonBind*>(button)->autoRepeatDelay();
}

int QAbstractButton_autoRepeatInterval(void* button) {
    return static_cast<QAbstractButtonBind*>(button)->autoRepeatInterval();
}

void* QAbstractButton_group(void* button) {
    return static_cast<QAbstractButtonBind*>(button)->group();
}

void* QAbstractButton_icon(void* button) {
    return new QIcon(static_cast<QAbstractButtonBind*>(button)->icon());
}

void* QAbstractButton_iconSize(void* button) {
    return new QSize(static_cast<QAbstractButtonBind*>(button)->iconSize());
}

bool QAbstractButton_isCheckable(void* button) {
    return static_cast<QAbstractButtonBind*>(button)->isCheckable();
}

bool QAbstractButton_isChecked(void* button) {
    return static_cast<QAbstractButtonBind*>(button)->isChecked();
}

bool QAbstractButton_isDown(void* button) {
    return static_cast<QAbstractButtonBind*>(button)->isDown();
}

void* QAbstractButton_shortcut(void* button) {
    return new QKeySequence(static_cast<QAbstractButtonBind*>(button)->shortcut());
}

const char * QAbstractButton_text(void* button) {
    const QString qstr = static_cast<QAbstractButtonBind*>(button)->text();
    return qstr.toUtf8().constData();
}

// プロパティ設定
void QAbstractButton_setAutoExclusive(void* button, bool autoExclusive) {
    static_cast<QAbstractButtonBind*>(button)->setAutoExclusive(autoExclusive);
}

void QAbstractButton_setAutoRepeat(void* button, bool autoRepeat) {
    static_cast<QAbstractButtonBind*>(button)->setAutoRepeat(autoRepeat);
}

void QAbstractButton_setAutoRepeatDelay(void* button, int delay) {
    static_cast<QAbstractButtonBind*>(button)->setAutoRepeatDelay(delay);
}

void QAbstractButton_setAutoRepeatInterval(void* button, int interval) {
    static_cast<QAbstractButtonBind*>(button)->setAutoRepeatInterval(interval);
}

void QAbstractButton_setCheckable(void* button, bool checkable) {
    static_cast<QAbstractButtonBind*>(button)->setCheckable(checkable);
}

void QAbstractButton_setDown(void* button, bool down) {
    static_cast<QAbstractButtonBind*>(button)->setDown(down);
}

void QAbstractButton_setIcon(void* button, void* icon) {
    static_cast<QAbstractButtonBind*>(button)->setIcon(*static_cast<QIcon*>(icon));
}

void QAbstractButton_setIconSize(void* button, void* size) {
    static_cast<QAbstractButtonBind*>(button)->setIconSize(*static_cast<QSize*>(size));
}

void QAbstractButton_setShortcut(void* button, void* shortcut) {
    static_cast<QAbstractButtonBind*>(button)->setShortcut(*static_cast<QKeySequence*>(shortcut));
}

void QAbstractButton_setText(void* button, const char* text) {
    static_cast<QAbstractButtonBind*>(button)->setText(text);
}

void QAbstractButton_setChecked(void* button, bool checked) {
    static_cast<QAbstractButtonBind*>(button)->setChecked(checked);
}

// アクション
void QAbstractButton_animateClick(void* button) {
    static_cast<QAbstractButtonBind*>(button)->animateClick();
}

void QAbstractButton_click(void* button) {
    static_cast<QAbstractButtonBind*>(button)->click();
}

void QAbstractButton_toggle(void* button) {
    static_cast<QAbstractButtonBind*>(button)->toggle();
}

typedef void (*ClickCallback)(void* data, bool checked);
typedef void (*PressCallback)(void* data);
typedef void (*ReleaseCallback)(void* data);
typedef void (*ToggleCallback)(void* data, bool checked);

// シグナルハンドラ設定
void QAbstractButton_setClickedCallback(void* button, ClickCallback callback) {
    static_cast<QAbstractButtonBind*>(button)->setClickedCallback(callback);
}

void QAbstractButton_setPressedCallback(void* button,PressCallback callback) {
    static_cast<QAbstractButtonBind*>(button)->setPressedCallback(callback);
}

void QAbstractButton_setReleasedCallback(void* button, ReleaseCallback callback) {
    static_cast<QAbstractButtonBind*>(button)->setReleasedCallback(callback);
}

void QAbstractButton_setToggledCallback(void* button, ToggleCallback callback) {
    static_cast<QAbstractButtonBind*>(button)->setToggledCallback(callback);
}

}
