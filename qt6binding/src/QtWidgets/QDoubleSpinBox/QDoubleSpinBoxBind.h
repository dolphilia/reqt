#ifndef QDOUBLESPINBOX_BIND_H
#define QDOUBLESPINBOX_BIND_H

#include "QDoubleSpinBoxHandler.h"
#include <QDoubleSpinBox>

class QDoubleSpinBoxBind : public QDoubleSpinBox {
    Q_OBJECT
    typedef void (*QDoubleSpinBox_ValueChangedCallback)(void*, double);
    typedef void (*QDoubleSpinBox_EditingFinishedCallback)(void*);
public:
    explicit QDoubleSpinBoxBind(QWidget* parent = nullptr);
    ~QDoubleSpinBoxBind() override;
    void setValueChangedCallback(QDoubleSpinBox_ValueChangedCallback callback) const;
    void setEditingFinishedCallback(QDoubleSpinBox_EditingFinishedCallback callback) const;
private:
    QDoubleSpinBoxHandler* handler;
};

#endif // QDOUBLESPINBOX_BIND_H
