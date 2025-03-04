#ifndef QPROGRESSBAR_BIND_H
#define QPROGRESSBAR_BIND_H

#include "QProgressBarHandler.h"
#include <QProgressBar>

class QProgressBarBind : public QProgressBar {
    Q_OBJECT
    typedef void (*QProgressBar_ValueChangedCallback)(void*, int);
public:
    explicit QProgressBarBind(QWidget* parent = nullptr);
    ~QProgressBarBind() override;
    void setValueChangedCallback(QProgressBar_ValueChangedCallback callback) const;
private:
    QProgressBarHandler* handler;
};

#endif // QPROGRESSBAR_BIND_H
