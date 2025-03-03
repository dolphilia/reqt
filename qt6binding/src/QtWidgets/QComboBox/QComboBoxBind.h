#ifndef QCOMBOBOX_BIND_H
#define QCOMBOBOX_BIND_H

#include "QComboBoxHandler.h"
#include <QComboBox>

class QComboBoxBind : public QComboBox {
    Q_OBJECT
    typedef void (*CurrentIndexChangedCallback)(void*, int);
    typedef void (*CurrentTextChangedCallback)(void*, const char*);
public:
    explicit QComboBoxBind(QWidget* parent = nullptr);
    ~QComboBoxBind() override;
    void setCurrentIndexChangedCallback(CurrentIndexChangedCallback callback) const;
    void setCurrentTextChangedCallback(CurrentTextChangedCallback callback) const;
private:
    ComboBoxHandler* handler;
};

#endif // QCOMBOBOX_BIND_H
