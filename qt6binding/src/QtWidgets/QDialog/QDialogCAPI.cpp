#include "QDialogBind.h"

extern "C" {

void* QDialog_create(void* parent, unsigned int flags) {
    return new QDialogBind(static_cast<QWidget*>(parent), static_cast<Qt::WindowFlags>(flags));
}

void QDialog_delete(void* dialog) {
    delete static_cast<QDialogBind*>(dialog);
}

bool QDialog_isSizeGripEnabled(void* dialog) {
    return static_cast<QDialogBind*>(dialog)->isSizeGripEnabled();
}

int QDialog_result(void* dialog) {
    return static_cast<QDialogBind*>(dialog)->result();
}

void* QDialog_minimumSizeHint(void* dialog) {
    return new QSize(static_cast<QDialogBind*>(dialog)->minimumSizeHint());
}

void* QDialog_sizeHint(void* dialog) {
    return new QSize(static_cast<QDialogBind*>(dialog)->sizeHint());
}

void QDialog_setModal(void* dialog, bool modal) {
    static_cast<QDialogBind*>(dialog)->setModal(modal);
}

void QDialog_setResult(void* dialog, int result) {
    static_cast<QDialogBind*>(dialog)->setResult(result);
}

void QDialog_setSizeGripEnabled(void* dialog, bool enabled) {
    static_cast<QDialogBind*>(dialog)->setSizeGripEnabled(enabled);
}

void QDialog_setVisible(void* dialog, bool visible) {
    static_cast<QDialogBind*>(dialog)->setVisible(visible);
}

void QDialog_accept(void* dialog) {
    static_cast<QDialogBind*>(dialog)->accept();
}

void QDialog_done(void* dialog, int result) {
    static_cast<QDialogBind*>(dialog)->done(result);
}

int QDialog_exec(void* dialog) {
    return static_cast<QDialogBind*>(dialog)->exec();
}

void QDialog_open(void* dialog) {
    static_cast<QDialogBind*>(dialog)->open();
}

void QDialog_reject(void* dialog) {
    static_cast<QDialogBind*>(dialog)->reject();
}

typedef void (*QDialog_DialogAcceptedCallback)(void* dialog);
typedef void (*QDialog_DialogFinishedCallback)(void* dialog, int result);
typedef void (*QDialog_DialogRejectedCallback)(void* dialog);

void QDialog_setAcceptedCallback(void* dialog, QDialog_DialogAcceptedCallback callback) {
    static_cast<QDialogBind*>(dialog)->setDialogAcceptedCallback(callback);
}

void QDialog_setFinishedCallback(void* dialog, QDialog_DialogFinishedCallback callback) {
    static_cast<QDialogBind*>(dialog)->setDialogFinishedCallback(callback);
}

void QDialog_setRejectedCallback(void* dialog, QDialog_DialogRejectedCallback callback) {
    static_cast<QDialogBind*>(dialog)->setDialogRejectedCallback(callback);
}

}
