#ifndef QCHECKBOX_BIND_H
#define QCHECKBOX_BIND_H

#include <QCheckBox>

#include "QCheckBoxHandler.h"
#include "QAbstractButton/QAbstractButtonBind.h"

class CheckBoxHandler;

class QCheckBoxBind : public QCheckBox {
    Q_OBJECT
    typedef void (*StateCallback)(void*, int);
    typedef void (*ToggleCallback)(void*, bool);
    typedef void (*ClickCallback)(void*, bool);
public:
    explicit QCheckBoxBind(QString qstr, QWidget* parent = nullptr);
    ~QCheckBoxBind() override;
    void setStateChangedCallback(StateCallback callback) const;
    void setToggledCallback(ToggleCallback callback) const;
    void setClickedCallback(ClickCallback callback) const;
private:
    CheckBoxHandler* handler;
};

#endif // QCHECKBOX_BIND_H
