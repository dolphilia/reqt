#ifndef QDIALOG_C_H
#define QDIALOG_C_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// QDialog::DialogCode 列挙型の定数
#define QDIALOG_DIALOG_CODE_ACCEPTED 1
#define QDIALOG_DIALOG_CODE_REJECTED 0

// コンストラクタ/デストラクタ
void* QDialog_create(void* parent, unsigned int flags);
void QDialog_delete(void* dialog);

// プロパティ取得
bool QDialog_isSizeGripEnabled(void* dialog);
int QDialog_result(void* dialog);
void* QDialog_minimumSizeHint(void* dialog);
void* QDialog_sizeHint(void* dialog);

// プロパティ設定
void QDialog_setModal(void* dialog, bool modal);
void QDialog_setResult(void* dialog, int result);
void QDialog_setSizeGripEnabled(void* dialog, bool enabled);
void QDialog_setVisible(void* dialog, bool visible);

// アクション
void QDialog_accept(void* dialog);
void QDialog_done(void* dialog, int result);
int QDialog_exec(void* dialog);
void QDialog_open(void* dialog);
void QDialog_reject(void* dialog);

// シグナルハンドラ設定
void QDialog_setAcceptedCallback(void* dialog, void (*callback)(void*), void* data);
void QDialog_setFinishedCallback(void* dialog, void (*callback)(void*, int), void* data);
void QDialog_setRejectedCallback(void* dialog, void (*callback)(void*), void* data);

#ifdef __cplusplus
}
#endif

#endif // QDIALOG_C_H
