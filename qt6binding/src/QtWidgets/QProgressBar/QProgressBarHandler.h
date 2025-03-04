#ifndef PROGRESSBAR_HANDLER_H
#define PROGRESSBAR_HANDLER_H

#include <QObject>

class QProgressBarHandler : public QObject {
    Q_OBJECT
    typedef void (*QProgressBar_ValueChangedCallback)(void*, int);
public:
    explicit QProgressBarHandler(QObject* parent = nullptr);
    void setValueChangedCallback(QProgressBar_ValueChangedCallback callback);
public slots:
    void onValueChanged(int value) const;
private:
    QProgressBar_ValueChangedCallback valueChangedCallback;
};

#endif // PROGRESSBAR_HANDLER_H
