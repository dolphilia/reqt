#ifndef QCOMBOBOX_BIND_H
#define QCOMBOBOX_BIND_H

#include "QComboBoxHandler.h"
#include <QComboBox>

class QComboBoxBind : public QComboBox {
    Q_OBJECT
    typedef void (*QComboBox_CurrentIndexChangedCallback)(void*, int);
    typedef void (*QComboBox_CurrentTextChangedCallback)(void*, const char*);
public:
    explicit QComboBoxBind(QWidget* parent = nullptr);
    ~QComboBoxBind() override;
    void setCurrentIndexChangedCallback(QComboBox_CurrentIndexChangedCallback callback) const;
    void setCurrentTextChangedCallback(QComboBox_CurrentTextChangedCallback callback) const;
private:
    QComboBoxHandler* handler;
};

#endif // QCOMBOBOX_BIND_H
