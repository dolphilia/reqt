#ifndef QABSTRACTBUTTON_C_H
#define QABSTRACTBUTTON_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// コンストラクタ/デストラクタ
// QAbstractButtonは抽象クラスなのでインスタンス化できない
// 実際には、QPushButtonなどの具体的なサブクラスを使用する
void* QAbstractButton_create(void* parent);
void QAbstractButton_delete(void* button);

// プロパティ取得
bool QAbstractButton_autoExclusive(void* button);
bool QAbstractButton_autoRepeat(void* button);
int QAbstractButton_autoRepeatDelay(void* button);
int QAbstractButton_autoRepeatInterval(void* button);
void* QAbstractButton_group(void* button);
void* QAbstractButton_icon(void* button);
void* QAbstractButton_iconSize(void* button);
bool QAbstractButton_isCheckable(void* button);
bool QAbstractButton_isChecked(void* button);
bool QAbstractButton_isDown(void* button);
void* QAbstractButton_shortcut(void* button);
void* QAbstractButton_text(void* button);

// プロパティ設定
void QAbstractButton_setAutoExclusive(void* button, bool autoExclusive);
void QAbstractButton_setAutoRepeat(void* button, bool autoRepeat);
void QAbstractButton_setAutoRepeatDelay(void* button, int delay);
void QAbstractButton_setAutoRepeatInterval(void* button, int interval);
void QAbstractButton_setCheckable(void* button, bool checkable);
void QAbstractButton_setDown(void* button, bool down);
void QAbstractButton_setIcon(void* button, void* icon);
void QAbstractButton_setIconSize(void* button, void* size);
void QAbstractButton_setShortcut(void* button, void* shortcut);
void QAbstractButton_setText(void* button, const char* text);
void QAbstractButton_setChecked(void* button, bool checked);

// アクション
void QAbstractButton_animateClick(void* button);
void QAbstractButton_click(void* button);
void QAbstractButton_toggle(void* button);

// シグナルハンドラ設定
void QAbstractButton_setClickedCallback(void* button, void (*callback)(void*, bool), void* data);
void QAbstractButton_setPressedCallback(void* button, void (*callback)(void*), void* data);
void QAbstractButton_setReleasedCallback(void* button, void (*callback)(void*), void* data);
void QAbstractButton_setToggledCallback(void* button, void (*callback)(void*, bool), void* data);

#ifdef __cplusplus
}
#endif

#endif // QABSTRACTBUTTON_C_H
