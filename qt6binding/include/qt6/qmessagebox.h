#ifndef QMESSAGEBOX_C_H
#define QMESSAGEBOX_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// 列挙型
enum QMessageBox_ButtonRole {
    QMessageBox_InvalidRole = -1,
    QMessageBox_AcceptRole,
    QMessageBox_RejectRole,
    QMessageBox_DestructiveRole,
    QMessageBox_ActionRole,
    QMessageBox_HelpRole,
    QMessageBox_YesRole,
    QMessageBox_NoRole,
    QMessageBox_ResetRole,
    QMessageBox_ApplyRole,
    QMessageBox_NRoles
};

enum QMessageBox_Icon {
    QMessageBox_NoIcon = 0,
    QMessageBox_Information = 1,
    QMessageBox_Warning = 2,
    QMessageBox_Critical = 3,
    QMessageBox_Question = 4
};

enum QMessageBox_StandardButton {
    QMessageBox_NoButton = 0x00000000,
    QMessageBox_Ok = 0x00000400,
    QMessageBox_Save = 0x00000800,
    QMessageBox_SaveAll = 0x00001000,
    QMessageBox_Open = 0x00002000,
    QMessageBox_Yes = 0x00004000,
    QMessageBox_YesToAll = 0x00008000,
    QMessageBox_No = 0x00010000,
    QMessageBox_NoToAll = 0x00020000,
    QMessageBox_Abort = 0x00040000,
    QMessageBox_Retry = 0x00080000,
    QMessageBox_Ignore = 0x00100000,
    QMessageBox_Close = 0x00200000,
    QMessageBox_Cancel = 0x00400000,
    QMessageBox_Discard = 0x00800000,
    QMessageBox_Help = 0x01000000,
    QMessageBox_Apply = 0x02000000,
    QMessageBox_Reset = 0x04000000,
    QMessageBox_RestoreDefaults = 0x08000000,
    QMessageBox_FirstButton = QMessageBox_Ok,
    QMessageBox_LastButton = QMessageBox_RestoreDefaults,
    QMessageBox_YesAll = QMessageBox_YesToAll,
    QMessageBox_NoAll = QMessageBox_NoToAll,
    QMessageBox_Default = 0x00000100,
    QMessageBox_Escape = 0x00000200,
    QMessageBox_FlagMask = 0x00000300,
    QMessageBox_ButtonMask = ~QMessageBox_FlagMask
};

// コンストラクタ/デストラクタ
void* QMessageBox_create(void* parent);
void* QMessageBox_createWithIcon(int icon, const char* title, const char* text, int buttons, void* parent, int f);
void QMessageBox_delete(void* messageBox);

// プロパティ取得
const char* QMessageBox_detailedText(void* messageBox);
int QMessageBox_icon(void* messageBox);
void* QMessageBox_iconPixmap(void* messageBox);
const char* QMessageBox_informativeText(void* messageBox);
int QMessageBox_standardButtons(void* messageBox);
const char* QMessageBox_text(void* messageBox);
int QMessageBox_textFormat(void* messageBox);
int QMessageBox_textInteractionFlags(void* messageBox);

// プロパティ設定
void QMessageBox_setDetailedText(void* messageBox, const char* text);
void QMessageBox_setIcon(void* messageBox, int icon);
void QMessageBox_setIconPixmap(void* messageBox, void* pixmap);
void QMessageBox_setInformativeText(void* messageBox, const char* text);
void QMessageBox_setStandardButtons(void* messageBox, int buttons);
void QMessageBox_setText(void* messageBox, const char* text);
void QMessageBox_setTextFormat(void* messageBox, int format);
void QMessageBox_setTextInteractionFlags(void* messageBox, int flags);
void QMessageBox_setWindowTitle(void* messageBox, const char* title);

// ボタン関連
void* QMessageBox_addButton(void* messageBox, int button);
void* QMessageBox_addButtonWithText(void* messageBox, const char* text, int role);
void QMessageBox_removeButton(void* messageBox, void* button);
void* QMessageBox_button(void* messageBox, int which);
int QMessageBox_buttonRole(void* messageBox, void* button);
int QMessageBox_standardButton(void* messageBox, void* button);
void* QMessageBox_defaultButton(void* messageBox);
void QMessageBox_setDefaultButton(void* messageBox, void* button);
void QMessageBox_setDefaultButtonStandard(void* messageBox, int button);
void* QMessageBox_escapeButton(void* messageBox);
void QMessageBox_setEscapeButton(void* messageBox, void* button);
void QMessageBox_setEscapeButtonStandard(void* messageBox, int button);

// チェックボックス関連
void* QMessageBox_checkBox(void* messageBox);
void QMessageBox_setCheckBox(void* messageBox, void* cb);

// アクション
int QMessageBox_exec(void* messageBox);
void QMessageBox_open(void* messageBox);

// スタティック関数
void QMessageBox_about(void* parent, const char* title, const char* text);
void QMessageBox_aboutQt(void* parent, const char* title);
int QMessageBox_critical(void* parent, const char* title, const char* text, int buttons, int defaultButton);
int QMessageBox_information(void* parent, const char* title, const char* text, int buttons, int defaultButton);
int QMessageBox_question(void* parent, const char* title, const char* text, int buttons, int defaultButton);
int QMessageBox_warning(void* parent, const char* title, const char* text, int buttons, int defaultButton);

// シグナルハンドラ設定
void QMessageBox_setButtonClickedCallback(void* messageBox, void (*callback)(void*, void*), void* data);

#ifdef __cplusplus
}
#endif

#endif // QMESSAGEBOX_C_H
