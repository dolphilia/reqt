#ifndef HANDLER_SPIN_BOX_H
#define HANDLER_SPIN_BOX_H

#include <QObject>

class SpinBoxHandler : public QObject {
    Q_OBJECT
public:
    explicit SpinBoxHandler(QObject *parent = nullptr);
    ~SpinBoxHandler();

    void setValueChangedCallback(void (*callback)(int value));
    void setTextChangedCallback(void (*callback)(const char* text));
    void setEditingFinishedCallback(void (*callback)());

public slots:
    void onValueChanged(int value);
    void onTextChanged(const QString &text);
    void onEditingFinished();

private:
    void (*m_valueChangedCallback)(int value);
    void (*m_textChangedCallback)(const char* text);
    void (*m_editingFinishedCallback)();
};

#endif // HANDLER_SPIN_BOX_H
