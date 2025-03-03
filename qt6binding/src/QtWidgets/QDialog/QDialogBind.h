#ifndef QDIALOG_BIND_H
#define QDIALOG_BIND_H

#include "QDialogHandler.h"
#include <QDialog>

class QDialogBind : public QDialog {
    Q_OBJECT
    typedef void (*DialogAcceptedCallback)(void* dialog);
    typedef void (*DialogFinishedCallback)(void* dialog, int result);
    typedef void (*DialogRejectedCallback)(void* dialog);
public:
    explicit QDialogBind(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~QDialogBind() override;

    void setDialogAcceptedCallback(DialogAcceptedCallback callback) const;
    void setDialogFinishedCallback(DialogFinishedCallback callback) const;
    void setDialogRejectedCallback(DialogRejectedCallback callback) const;

private:
    QDialogHandler* handler;
};

#endif // QDIALOG_BIND_H
