#ifndef QCHECKBOX_HANDLER_H
#define QCHECKBOX_HANDLER_H

#include "QAbstractButton/QAbstractButtonHandler.h"
#include <QObject>

class QCheckBoxHandler : public QObject {
    Q_OBJECT
    typedef void (*QCheckBox_StateChangedCallback)(void*, int);
    typedef void (*QCheckBox_ToggledCallback)(void*, bool);
    typedef void (*QCheckBox_ClickedCallback)(void*, bool);
public:
    explicit QCheckBoxHandler(QObject* parent = nullptr);
    void setStateChangedCallback(QCheckBox_StateChangedCallback callback);
    void setToggledCallback(QCheckBox_ToggledCallback callback);
    void setClickedCallback(QCheckBox_ClickedCallback callback);

public slots:
    void onStateChanged(int state) const;
    void onToggled(bool checked) const;
    void onClicked(bool checked) const;

private:
    QCheckBox_StateChangedCallback stateCallback;
    QCheckBox_ToggledCallback toggleCallback;
    QCheckBox_ClickedCallback clickedCallback;
};

#endif // QCHECKBOX_HANDLER_H
