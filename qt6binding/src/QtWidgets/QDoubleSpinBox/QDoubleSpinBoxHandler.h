#ifndef DOUBLESPINBOX_HANDLER_H
#define DOUBLESPINBOX_HANDLER_H

#include <QObject>

class DoubleSpinBoxHandler : public QObject {
    Q_OBJECT
    typedef void (*ValueChangedCallback)(void*, double);
    typedef void (*EditingFinishedCallback)(void*);
public:
    explicit DoubleSpinBoxHandler(QObject* parent = nullptr);
    void setValueChangedCallback(ValueChangedCallback callback);
    void setEditingFinishedCallback(EditingFinishedCallback callback);
public slots:
    void onValueChanged(double value) const;
    void onEditingFinished() const;
private:
    ValueChangedCallback valueCallback;
    EditingFinishedCallback editingCallback;
};

#endif // DOUBLESPINBOX_HANDLER_H
