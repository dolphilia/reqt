#ifndef QCHECKBOX_BIND_H
#define QCHECKBOX_BIND_H

#include <QCheckBox>

#include "QCheckBoxHandler.h"
#include "QAbstractButton/QAbstractButtonBind.h"

class QCheckBoxHandler;

class QCheckBoxBind : public QCheckBox {
    Q_OBJECT
    typedef void (*QCheckBox_StateChangedCallback)(void*, int);
    typedef void (*QCheckBox_ToggledCallback)(void*, bool);
    typedef void (*QCheckBox_ClickedCallback)(void*, bool);
public:
    explicit QCheckBoxBind(QString qstr, QWidget* parent = nullptr);
    ~QCheckBoxBind() override;
    void setStateChangedCallback(QCheckBox_StateChangedCallback callback) const;
    void setToggledCallback(QCheckBox_ToggledCallback callback) const;
    void setClickedCallback(QCheckBox_ClickedCallback callback) const;
private:
    QCheckBoxHandler* handler;
};

#endif // QCHECKBOX_BIND_H
