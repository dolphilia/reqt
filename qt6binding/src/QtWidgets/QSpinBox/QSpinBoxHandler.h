#ifndef QSPINBOX_HANDLER_H
#define QSPINBOX_HANDLER_H

#include <QObject>

class QSpinBoxHandler : public QObject {
    Q_OBJECT
    typedef void (*QSpinBox_ValueChangedCallback)(void*, int);
    typedef void (*QSpinBox_TextChangedCallback)(void*, const char*);
    typedef void (*QSpinBox_EditingFinishedCallback)(void*);
public:
    explicit QSpinBoxHandler(QObject* parent = nullptr);
    ~QSpinBoxHandler();

    void setValueChangedCallback(QSpinBox_ValueChangedCallback callback);
    void setTextChangedCallback(QSpinBox_TextChangedCallback callback);
    void setEditingFinishedCallback(QSpinBox_EditingFinishedCallback callback);

public slots:
    void onValueChanged(int value) const;
    void onTextChanged(const QString &text) const;
    void onEditingFinished() const;

private:
    QSpinBox_ValueChangedCallback valueChangedCallback;
    QSpinBox_TextChangedCallback textChangedCallback;
    QSpinBox_EditingFinishedCallback editingFinishedCallback;
};

#endif // QSPINBOX_HANDLER_H
