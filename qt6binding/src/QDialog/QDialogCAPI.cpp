#include "QDialogBind.h"
#include <QSize>

extern "C" {

// QDialog::DialogCode 列挙型の定数
#define QDIALOG_DIALOG_CODE_ACCEPTED 1
#define QDIALOG_DIALOG_CODE_REJECTED 0

// コンストラクタ/デストラクタ
void* QDialog_create(void* parent, unsigned int flags) {
    return QDialogBind::create(static_cast<QWidget*>(parent), static_cast<Qt::WindowFlags>(flags));
}

void QDialog_delete(void* dialog) {
    QDialogBind::destroy(static_cast<QDialog*>(dialog));
}

// プロパティ取得
bool QDialog_isSizeGripEnabled(void* dialog) {
    return QDialogBind::isSizeGripEnabled(static_cast<QDialog*>(dialog));
}

int QDialog_result(void* dialog) {
    return QDialogBind::result(static_cast<QDialog*>(dialog));
}

void* QDialog_minimumSizeHint(void* dialog) {
    return QDialogBind::minimumSizeHint(static_cast<QDialog*>(dialog));
}

void* QDialog_sizeHint(void* dialog) {
    return QDialogBind::sizeHint(static_cast<QDialog*>(dialog));
}

// プロパティ設定
void QDialog_setModal(void* dialog, bool modal) {
    QDialogBind::setModal(static_cast<QDialog*>(dialog), modal);
}

void QDialog_setResult(void* dialog, int result) {
    QDialogBind::setResult(static_cast<QDialog*>(dialog), result);
}

void QDialog_setSizeGripEnabled(void* dialog, bool enabled) {
    QDialogBind::setSizeGripEnabled(static_cast<QDialog*>(dialog), enabled);
}

void QDialog_setVisible(void* dialog, bool visible) {
    QDialogBind::setVisible(static_cast<QDialog*>(dialog), visible);
}

// アクション
void QDialog_accept(void* dialog) {
    QDialogBind::accept(static_cast<QDialog*>(dialog));
}

void QDialog_done(void* dialog, int result) {
    QDialogBind::done(static_cast<QDialog*>(dialog), result);
}

int QDialog_exec(void* dialog) {
    return QDialogBind::exec(static_cast<QDialog*>(dialog));
}

void QDialog_open(void* dialog) {
    QDialogBind::open(static_cast<QDialog*>(dialog));
}

void QDialog_reject(void* dialog) {
    QDialogBind::reject(static_cast<QDialog*>(dialog));
}

// シグナルハンドラ設定
void QDialog_setAcceptedCallback(void* dialog, void (*callback)(void*), void* data) {
    QDialogBind::setAcceptedCallback(static_cast<QDialog*>(dialog), callback, data);
}

void QDialog_setFinishedCallback(void* dialog, void (*callback)(void*, int), void* data) {
    QDialogBind::setFinishedCallback(static_cast<QDialog*>(dialog), callback, data);
}

void QDialog_setRejectedCallback(void* dialog, void (*callback)(void*), void* data) {
    QDialogBind::setRejectedCallback(static_cast<QDialog*>(dialog), callback, data);
}

}
