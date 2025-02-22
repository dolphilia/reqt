#ifndef HANDLER_PROGRESS_BAR_H
#define HANDLER_PROGRESS_BAR_H

#include <QObject>

class ProgressBarHandler : public QObject {
    Q_OBJECT
public:
    explicit ProgressBarHandler(QObject *parent = nullptr);
    ~ProgressBarHandler();

    void setValueChangedCallback(void (*callback)(int value));

public slots:
    void onValueChanged(int value);

private:
    void (*m_valueChangedCallback)(int value);
};

#endif // HANDLER_PROGRESS_BAR_H
