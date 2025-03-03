#ifndef QDIALOG_HANDLER_H
#define QDIALOG_HANDLER_H

#include <QObject>

class QDialogHandler : public QObject {
    Q_OBJECT
    typedef void (*DialogAcceptedCallback)(void* dialog);
    typedef void (*DialogFinishedCallback)(void* dialog, int result);
    typedef void (*DialogRejectedCallback)(void* dialog);
public:
    explicit QDialogHandler(QObject* parent = nullptr);
    void setDialogAcceptedCallback(DialogAcceptedCallback callback);
    void setDialogFinishedCallback(DialogFinishedCallback callback);
    void setDialogRejectedCallback(DialogRejectedCallback callback);

public slots:
    void onDialogAccepted() const;
    void onDialogFinished(int result) const;
    void onDialogRejected() const;

private:
    DialogAcceptedCallback acceptedCallback;
    DialogFinishedCallback finishedCallback;
    DialogRejectedCallback rejectedCallback;
};

#endif // QDIALOG_HANDLER_H
