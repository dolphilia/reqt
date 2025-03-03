#include "QDialogBind.h"
#include "QDialogHandler.h"

QDialogBind::QDialogBind(QWidget* parent, Qt::WindowFlags f)
    : QDialog(parent, f)
    , handler(new QDialogHandler(this)) {
    connect(this, &QDialog::accepted, handler, &QDialogHandler::onDialogAccepted);
    connect(this, &QDialog::finished, handler, &QDialogHandler::onDialogFinished);
    connect(this, &QDialog::rejected, handler, &QDialogHandler::onDialogRejected);
}

QDialogBind::~QDialogBind() {
    delete handler;
}

void QDialogBind::setDialogAcceptedCallback(DialogAcceptedCallback callback) const {
    handler->setDialogAcceptedCallback(callback);
}

void QDialogBind::setDialogFinishedCallback(DialogFinishedCallback callback) const {
    handler->setDialogFinishedCallback(callback);
}

void QDialogBind::setDialogRejectedCallback(DialogRejectedCallback callback) const {
    handler->setDialogRejectedCallback(callback);
}
