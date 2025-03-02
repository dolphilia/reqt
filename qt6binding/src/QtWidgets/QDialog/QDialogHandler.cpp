#include "QDialogHandler.h"

QDialogHandler::QDialogHandler(QDialog* dialog, QObject* parent)
    : QObject(parent),
      acceptedCallback(nullptr),
      finishedCallback(nullptr),
      rejectedCallback(nullptr),
      acceptedData(nullptr),
      finishedData(nullptr),
      rejectedData(nullptr)
{
    // シグナルとスロットを接続
    connect(dialog, &QDialog::accepted, this, &QDialogHandler::onAccepted);
    connect(dialog, &QDialog::finished, this, &QDialogHandler::onFinished);
    connect(dialog, &QDialog::rejected, this, &QDialogHandler::onRejected);
}

QDialogHandler::~QDialogHandler()
{
    // 特に何もする必要はない
}

void QDialogHandler::onAccepted()
{
    if (acceptedCallback) {
        acceptedCallback(acceptedData);
    }
}

void QDialogHandler::onFinished(int result)
{
    if (finishedCallback) {
        finishedCallback(finishedData, result);
    }
}

void QDialogHandler::onRejected()
{
    if (rejectedCallback) {
        rejectedCallback(rejectedData);
    }
}
