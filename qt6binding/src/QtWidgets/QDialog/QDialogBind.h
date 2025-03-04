#ifndef QDIALOG_BIND_H
#define QDIALOG_BIND_H

#include "QDialogHandler.h"
#include <QDialog>

class QDialogBind : public QDialog {
    Q_OBJECT
    typedef void (*QDialog_DialogAcceptedCallback)(void* dialog);
    typedef void (*QDialog_DialogFinishedCallback)(void* dialog, int result);
    typedef void (*QDialog_DialogRejectedCallback)(void* dialog);
public:
    explicit QDialogBind(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~QDialogBind() override;

    void setDialogAcceptedCallback(QDialog_DialogAcceptedCallback callback) const;
    void setDialogFinishedCallback(QDialog_DialogFinishedCallback callback) const;
    void setDialogRejectedCallback(QDialog_DialogRejectedCallback callback) const;

private:
    QDialogHandler* handler;
};

#endif // QDIALOG_BIND_H
