#ifndef QDOUBLESPINBOX_BIND_H
#define QDOUBLESPINBOX_BIND_H

#include "QDoubleSpinBoxHandler.h"
#include <QDoubleSpinBox>

class QDoubleSpinBoxBind : public QDoubleSpinBox {
    Q_OBJECT
    typedef void (*ValueChangedCallback)(void*, double);
    typedef void (*EditingFinishedCallback)(void*);
public:
    explicit QDoubleSpinBoxBind(QWidget* parent = nullptr);
    ~QDoubleSpinBoxBind() override;
    void setValueChangedCallback(ValueChangedCallback callback) const;
    void setEditingFinishedCallback(EditingFinishedCallback callback) const;
private:
    DoubleSpinBoxHandler* handler;
};

#endif // QDOUBLESPINBOX_BIND_H
