#include "QDialogHandler.h"

QDialogHandler::QDialogHandler(QObject* parent)
    : QObject(parent)
    , acceptedCallback(nullptr)
    , finishedCallback(nullptr)
    , rejectedCallback(nullptr)
{
}

void QDialogHandler::setDialogAcceptedCallback(DialogAcceptedCallback callback) {
    acceptedCallback = callback;
}

void QDialogHandler::setDialogFinishedCallback(DialogFinishedCallback callback) {
    finishedCallback = callback;
}

void QDialogHandler::setDialogRejectedCallback(DialogRejectedCallback callback) {
    rejectedCallback = callback;
}

void QDialogHandler::onDialogAccepted() const {
    if (acceptedCallback) {
        acceptedCallback(parent());
    }
}

void QDialogHandler::onDialogFinished(int result) const {
    if (finishedCallback) {
        finishedCallback(parent(), result);
    }
}

void QDialogHandler::onDialogRejected() const {
    if (rejectedCallback) {
        rejectedCallback(parent());
    }
}
