#ifndef QDIALOG_HANDLER_H
#define QDIALOG_HANDLER_H

#include <QObject>

class QDialogHandler : public QObject {
    Q_OBJECT
    typedef void (*QDialog_DialogAcceptedCallback)(void* dialog);
    typedef void (*QDialog_DialogFinishedCallback)(void* dialog, int result);
    typedef void (*QDialog_DialogRejectedCallback)(void* dialog);
public:
    explicit QDialogHandler(QObject* parent = nullptr);
    void setDialogAcceptedCallback(QDialog_DialogAcceptedCallback callback);
    void setDialogFinishedCallback(QDialog_DialogFinishedCallback callback);
    void setDialogRejectedCallback(QDialog_DialogRejectedCallback callback);

public slots:
    void onDialogAccepted() const;
    void onDialogFinished(int result) const;
    void onDialogRejected() const;

private:
    QDialog_DialogAcceptedCallback acceptedCallback;
    QDialog_DialogFinishedCallback finishedCallback;
    QDialog_DialogRejectedCallback rejectedCallback;
};

#endif // QDIALOG_HANDLER_H
